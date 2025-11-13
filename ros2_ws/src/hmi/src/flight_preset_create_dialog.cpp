#include <iostream>
#include "flight_preset_create_dialog.h"

FlightCreationDialog::FlightCreationDialog(QWidget* parent)
{
    ui.setupUi(this);

    connect(this->ui.listWidget, &QListWidget::itemDoubleClicked,
    this, &FlightCreationDialog::onListItemDoubleClicked);

    connect(this->ui.listWidget, &QListWidget::itemClicked,
    this, &FlightCreationDialog::onListItemClicked);

    this->curr_list_widget_index = -1;
    this->state = PathPlanStates::NONE;

    scatter3D = new QtDataVisualization::Q3DScatter();
    scatterContainer = QWidget::createWindowContainer(scatter3D);

    scatter3D->activeTheme()->setType(QtDataVisualization::Q3DTheme::ThemeQt);
    scatter3D->setShadowQuality(QtDataVisualization::QAbstract3DGraph::ShadowQualityNone);
    scatter3D->scene()->activeCamera()->setCameraPreset(QtDataVisualization::Q3DCamera::CameraPresetIsometricRight);

    scatter3D->axisX()->setTitle("X");
    scatter3D->axisY()->setTitle("Z");
    scatter3D->axisZ()->setTitle("Y");

    QtDataVisualization::Q3DCamera *camera = scatter3D->scene()->activeCamera();
    camera->setCameraPreset(QtDataVisualization::Q3DCamera::CameraPresetIsometricRight); // starting view
    camera->setZoomLevel(100.0f);     // optional starting zoom

    scatter3D->scene()->activeCamera()->setZoomLevel(100.0f);    // zoom
    scatter3D->scene()->activeCamera()->setCameraPreset(QtDataVisualization::Q3DCamera::CameraPresetFront);
    
    // You can show this container in your UI (e.g. side-by-side)
    scatterContainer = QWidget::createWindowContainer(scatter3D, this);
    scatterContainer->setMinimumSize(100, 100);
    scatterContainer->setFocusPolicy(Qt::StrongFocus);

    this->ui.verticalLayout_2->addWidget(scatterContainer, 1);

    this->cw = nullptr;
}

FlightCreationDialog::~FlightCreationDialog()
{
    for (int i = 0; i < this->ui.listWidget->count(); ++i)
    {
        delete this->ui.listWidget->item(i);
    }

    delete this->cw;

    const auto existingSeries = scatter3D->seriesList();
    for (auto *series : existingSeries) {
        scatter3D->removeSeries(series);
        delete series;
    }

    const auto existingItems = scatter3D->customItems();
    for (auto *item : existingItems) {
        scatter3D->removeCustomItem(item);
        delete item;
    }

    delete this->scatter3D;
    delete this->trajectorySeries;
    delete this->scatterContainer;
}

std::vector<QVector3D> FlightCreationDialog::getWaypoints()
{
    return this->waypoints;
}

void FlightCreationDialog::on_cancleButton_pushButton_clicked()
{
    std::cout << "Hello from cancle button" << std::endl;
    this->reject();
}

void FlightCreationDialog::on_createPlanButton_pushButton_clicked()
{
    std::cout << "Hello from create path plan button" << std::endl;
    this->state = PathPlanStates::CREATE_PLAN;
    this->accept();
}

void FlightCreationDialog::on_choosePreset_pushButton_clicked()
{

    QString presetDirPath = QDir(QCoreApplication::applicationDirPath())
                            .filePath("../src/hmi/presets");

    this->file_name = QFileDialog::getOpenFileName(
        this,           
        "Open Preset File",
        presetDirPath,
        "Document files (*.xml)"
    );

    if(file_name.isEmpty()) return;

    this->loadTrajectoryFromXmlFile(file_name);
}

QString FlightCreationDialog::getFileName()
{
    return this->file_name;
}

void FlightCreationDialog::loadTrajectoryFromXmlFile(QString& filename)
{
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;

    QXmlStreamReader xml(&file);

    DroneVis current;
    bool insideDrone = false;

    while (!xml.atEnd())
    {
        xml.readNext();

        // <drone ...>
        if (xml.isStartElement() && xml.name() == "drone")
        {
            insideDrone = true;
            current = DroneVis(); // reset
            current.display = true;

            auto attrs = xml.attributes();
            current.drone_id = attrs.value("id").toString().toStdString();
            current.drone_color = QColor(attrs.value("color").toString());
        }

        // <point x="" y=""/>
        if (xml.isStartElement() && xml.name() == "point" && insideDrone)
        {
            auto attrs = xml.attributes();
            Point p;
            p.x = attrs.value("x").toDouble();
            p.y = attrs.value("y").toDouble();
            p.z = attrs.value("z").toDouble();
            current.drone_waypoints.push_back(p);
        }

        // </drone>
        if (xml.isEndElement() && xml.name() == "drone")
        {
            drones.push_back(current);
            insideDrone = false;
            this->addItemToList(current);
        }
    }

    file.close();
}

void FlightCreationDialog::addItemToList(DroneVis& drone)
{           
    QListWidgetItem* item = new QListWidgetItem();

    ColorListWidget* widget = new ColorListWidget(this->ui.listWidget, QString::fromStdString(drone.drone_id), drone.drone_color);

    item->setSizeHint(widget->sizeHint());
    this->ui.listWidget->addItem(item);
    this->ui.listWidget->setItemWidget(item, widget);
}

void FlightCreationDialog::onListItemDoubleClicked(QListWidgetItem* item)
{
    curr_list_widget_index = this->ui.listWidget->row(item);
    std::cout << "Item at index = " << curr_list_widget_index << "was selected" << std::endl;

    ColorListWidget *cw_new = qobject_cast<ColorListWidget*>(this->ui.listWidget->itemWidget(item));
    if (cw_new)
    {
        cw_new->setEnabled(true);
        cw_new->setChecked(true);
    }

    std::cout << "hello double clicked" << std::endl; 
    this->state = PathPlanStates::ACCEPTED;
    this->accept();
}

void FlightCreationDialog::onListItemClicked(QListWidgetItem* item)
{
    curr_list_widget_index = this->ui.listWidget->row(item);
    std::cout << "Item at index = " << curr_list_widget_index << "was selected" << std::endl;

    ColorListWidget *cw_new = qobject_cast<ColorListWidget*>(this->ui.listWidget->itemWidget(item));
    if (cw_new)
    {
        cw_new->setEnabled(true);
        cw_new->setChecked(true);
    }

    this->update3DTrajectories();
}

int FlightCreationDialog::getSelectedItemIndex()
{
    return this->curr_list_widget_index;
}

int FlightCreationDialog::getState()
{
    return this->state;
}

void FlightCreationDialog::update3DTrajectories()
{
    if (!scatter3D)
        return;

    // --- Remove old series manually ---
    const auto existingSeries = scatter3D->seriesList();
    for (auto *series : existingSeries) {
        scatter3D->removeSeries(series);
        delete series;
    }

    const auto existingItems = scatter3D->customItems();
    for (auto *item : existingItems) {
        scatter3D->removeCustomItem(item);
        delete item;
    }

    if (this->curr_list_widget_index < 0) return;
    if (this->drones.empty()) return;

    const auto &drone = drones[curr_list_widget_index];

    // --- Create scatter points (waypoints) ---
    auto *series = new QtDataVisualization::QScatter3DSeries();
    series->setMesh(QtDataVisualization::QAbstract3DSeries::MeshSphere);
    series->setItemSize(0.15f);
    series->setBaseColor(drone.drone_color);

    auto *dataArray = new QtDataVisualization::QScatterDataArray;
    dataArray->resize(drone.drone_waypoints.size());

    QVector<QVector3D> waypoints;
    for (int i = 0; i < drone.drone_waypoints.size(); ++i)
    {
        QVector3D wp;
        wp.setX(drone.drone_waypoints[i].x);
        wp.setY(drone.drone_waypoints[i].y); // assuming z is height
        wp.setZ(drone.drone_waypoints[i].z);

        (*dataArray)[i].setPosition(wp);
        waypoints.append(wp);
    }

    series->dataProxy()->resetArray(dataArray);
    scatter3D->addSeries(series);

    scatter3D->activeTheme()->setType(scatter3D->activeTheme()->type()); // force visual refresh
}