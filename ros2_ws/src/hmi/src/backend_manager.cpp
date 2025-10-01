#include <iostream>
#include <backend_manager.h>
#include <QDebug>

BackEndManager::BackEndManager(QObject* parent) : QObject(parent), timeToProcessFinish(20000), timeToProcessStart(3000), hearthBeatInterval(1500)
{
    connect(&proc,
            QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this,
            &BackEndManager::onBackEndFinished);

    connect(&proc, SIGNAL(errorOccurred(QProcess::ProcessError)),this, SLOT(onBackendError(QProcess::ProcessError)));

    this->heartBeatTimer.setInterval(this->hearthBeatInterval);
    connect(&this->heartBeatTimer, &QTimer::timeout, this, &BackEndManager::checkHeartBeat);
}

BackEndManager::~BackEndManager()
{
    this->proc.kill();
    this->proc.waitForFinished();
}

void BackEndManager::setMissedHeartBeat(int value)
{
    this->missedHeartBeats = value;
}


void BackEndManager::startBackend()
{
    if(this->proc.state() != QProcess::NotRunning) return;

    // The command: source workspace + run the node
    QString command = "bash";
    QStringList args;
    args << "-c" << "source /opt/ros/humble/setup.bash && source ~/EiRT-AscenD-Robotics/ros2_ws/install/setup.bash && ros2 run hmi_backend backend_node";

    this->proc.start(command, args);

    if(!proc.waitForStarted(this->timeToProcessStart))
    {
        qWarning() << "Failed to start the backend\n";
        emit this->backEndCrashed();
        return;
    }

    qDebug() << "Started the backend\n";

    this->heartBeatTimer.start();
    this->missedHeartBeats = 0;
    emit this->backEndStarted();
}

void BackEndManager::stopBackend(void)
{
    if(this->proc.state() == QProcess::Running)
    {
        this->proc.terminate();
        if(!this->proc.waitForFinished(this->timeToProcessFinish))
        {
            this->proc.kill();
            this->proc.waitForFinished(this->timeToProcessFinish);
        }
    }
    this->heartBeatTimer.stop();
    emit this->backEndStopped();
}

void BackEndManager::forceKillBackend(void)
{
    if(proc.state() != QProcess::NotRunning)
    {
        proc.terminate(); // ask backend to exit gracefully
        if(!proc.waitForFinished()) { // wait 3s
            qWarning() << "Backend did not exit gracefully, killing...";
            proc.kill(); // force kill as fallback
            proc.waitForFinished();
        }
    }

    heartBeatTimer.stop();
    missedHeartBeats = 0;
    emit backEndStopped();
}

void BackEndManager::onBackEndFinished(int exitCode, QProcess::ExitStatus status)
{
    qDebug() << "Backend finished with code" << exitCode << "status" << status;

    if (status == QProcess::CrashExit) {
        emit this->backEndCrashed();
    } else {
        emit this->backEndStopped();
    }
}

void BackEndManager::onBackEndError(QProcess::ProcessError error)
{
    qWarning() << "Backend process error:" << error;
    emit this->backEndCrashed();
}

void BackEndManager::checkHeartBeat()
{
    this->missedHeartBeats++;
    if (this->missedHeartBeats > 10) {
        this->proc.terminate(); 
        qWarning() << "Heartbeat missed, restarting backend";
        this->forceKillBackend();
        this->startBackend();
    }
}