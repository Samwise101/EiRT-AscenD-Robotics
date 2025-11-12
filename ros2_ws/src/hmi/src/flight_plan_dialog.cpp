#include <iostream>
#include "flight_plan_dialog.h"

FlightDialog::FlightDialog(QWidget* parent, QColor drone_color, std::string drone_id) : drone_id(drone_id), drone_color(drone_color)
{
    ui.setupUi(this);

    this->ui.label_5->setText(QString::fromStdString(this->drone_id));

    std::cout << "Got color " << this->drone_color.name().toStdString() << std::endl;

    QPalette palette = this->ui.label_6->palette();
    palette.setColor(QPalette::Window, this->drone_color);
    ui.label_6->setAutoFillBackground(true);   // <-- Important!
    this->ui.label_6->setPalette(palette);

    this->ui.latLineEdit->setText("0.0");
    this->ui.lonLineEdit->setText("0.0");
    this->ui.altLineEdit->setText("0.0");

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

    this->ui.verticalLayout_4->addWidget(scatterContainer, 1);
}

FlightDialog::~FlightDialog()
{}


void FlightDialog::on_cancleButton_pushButton_clicked()
{
    std::cout << "Hello from cancle button" << std::endl;
    this->reject();
}

void FlightDialog::on_applyButton_pushButton_clicked()
{
    std::cout << "Hello from apply button" << std::endl;
    this->accept();
}

void FlightDialog::on_removeWaypointButton_pushButton_clicked()
{
    std::cout << "Hello from remove waypoint button" << std::endl;
}

void FlightDialog::on_addNewWaypointButton_pushButton_clicked()
{
    std::cout << "Hello from add new waypoint button" << std::endl;

    float alt = this->ui.altLineEdit->text().toFloat();
    float lat = this->ui.latLineEdit->text().toFloat();
    float lon = this->ui.lonLineEdit->text().toFloat();

    QVector3D waypoint{lat, lon, alt};
    this->waypoints.push_back(waypoint);

    this->update3DTrajectories();
}

void FlightDialog::on_clearWaypointsButton_pushButton_clicked()
{
    std::cout << "Hello from clear waypoints button" << std::endl;
    this->waypoints.clear();
}

void FlightDialog::on_latLineEdit_editingFinished()
{
    std::cout << this->ui.latLineEdit->text().toStdString() << std::endl;
}

void FlightDialog::on_lonLineEdit_editingFinished()
{
    std::cout << this->ui.lonLineEdit->text().toStdString() << std::endl;
}

void FlightDialog::on_altLineEdit_editingFinished()
{
    std::cout << this->ui.altLineEdit->text().toStdString() << std::endl;
}

void FlightDialog::on_saveAsPresetButton_pushButton_clicked()
{
    std::cout << "Hello from save as preset button" << std::endl;
}

void FlightDialog::update3DTrajectories()
{
    if (!scatter3D)
        return;

    if(this->waypoints.empty()) return;

    // --- Remove old series manually ---
    const auto existingSeries = scatter3D->seriesList();
    for (auto *series : existingSeries)
        scatter3D->removeSeries(series);

    // --- Remove old custom items manually ---
    const auto existingItems = scatter3D->customItems();
    for (auto *item : existingItems)
        scatter3D->removeCustomItem(item);

    // Create scatter points (waypoints)
    auto *series = new QtDataVisualization::QScatter3DSeries();
    series->setMesh(QtDataVisualization::QAbstract3DSeries::MeshSphere);
    series->setItemSize(0.15f);
    series->setBaseColor(this->drone_color);

    auto *dataArray = new QtDataVisualization::QScatterDataArray;
    dataArray->resize(this->waypoints.size());

    for (int i = 0; i < this->waypoints.size(); ++i)
    {
        const auto &wp = this->waypoints[i];
        float z = i * 0.2f;  // artificial altitude or index
        (*dataArray)[i].setPosition(wp);
    }

    series->dataProxy()->resetArray(dataArray);
    scatter3D->addSeries(series);
}