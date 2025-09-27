#include <iostream>
#include <backend_manager.h>
#include <QDebug>

BackEndManager::BackEndManager(QObject* parent) : QObject(parent), timeToProcessFinish(2000), timeToProcessStart(3000), hearthBeatInterval(1500)
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
    this->proc.waitForFinished(this->timeToProcessFinish);
}

void BackEndManager::setMissedHeartBeat(int value)
{
    this->missedHeartBeats = value;
}


void BackEndManager::startBackend()
{
    if(this->proc.state() != QProcess::NotRunning) return;

    QString program = "/bin/bash";
    QStringList args;

    // Full path to your workspace
    QString wsPath = "hmoe/samuel/hmi_backend/EiRT-AscenD-Robotics/ros2_ws";

    // The command: source workspace + run the node
    QString command = QString("source %1/install/setup.bash && ros2 run hmi_backend backend_node")
                          .arg(wsPath);

    args << "-c" << command;

    this->proc.start(program, args);

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
    if(this->proc.state() == QProcess::Running)
    {
        this->proc.kill();
        this->proc.waitForFinished(this->timeToProcessFinish);
    }

    this->heartBeatTimer.stop();
    emit this->backEndStopped();
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
        qWarning() << "Heartbeat missed, restarting backend";
        this->forceKillBackend();
        this->startBackend();
    }
}