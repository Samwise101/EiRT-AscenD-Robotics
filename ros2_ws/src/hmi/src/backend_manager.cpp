#include <iostream>
#include <backend_manager.h>
#include <QDebug>

BackEndManger::BackEndManger(QObject* parent) : QObject(parent), timeToProcessFinish(2000), timeToProcessStart(3000), hearthBeatInterval(1500)
{
    connect(&proc,
            QOverload<int, QProcess::ExitStatus>::of(&QProcess::finished),
            this,
            &BackEndManger::onBackEndFinished);

    connect(&proc, SIGNAL(errorOccurred(QProcess::ProcessError)),this, SLOT(onBackendError(QProcess::ProcessError)));

    this->heartBeatTimer.setInterval(this->hearthBeatInterval);
    connect(&this->heartBeatTimer, &QTimer::timeout, this, &BackEndManger::checkHeartBeat);
}

BackEndManger::~BackEndManger(){}




void BackEndManger::startBackend(void)
{
    if(this->proc.state() != QProcess::NotRunning) return;
    QString program{"~/hmi_backend/EiRT-AscenD-Robotics/ros2_ws"};
    QStringList args;

    this->proc.start(program, args);

    if(!proc.waitForStarted(this->timeToProcessStart))
    {
        qWarning() << "Failed to start the backend\n";
        emit this->backEndCrashed();
        return;
    }

    this->heartBeatTimer.start();
    this->missedHeartBeats = 0;
    emit this->backEndStarted();
}

void BackEndManger::stopBackend(void)
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

void BackEndManger::forceKillBackend(void)
{
    if(this->proc.state() == QProcess::Running)
    {
        this->proc.kill();
        this->proc.waitForFinished(this->timeToProcessFinish);
    }

    this->heartBeatTimer.stop();
    emit this->backEndStopped();
}

void BackEndManger::onBackEndFinished(int exitCode, QProcess::ExitStatus status)
{
    qDebug() << "Backend finished with code" << exitCode << "status" << status;

    if (status == QProcess::CrashExit) {
        emit this->backEndCrashed();
    } else {
        emit this->backEndStopped();
    }
}

void BackEndManger::onBackEndError(QProcess::ProcessError error)
{
    qWarning() << "Backend process error:" << error;
    emit this->backEndCrashed();
}

void BackEndManger::checkHeartBeat()
{
    this->missedHeartBeats++;
    if (this->missedHeartBeats > 3) {
        qWarning() << "Heartbeat missed, restarting backend";
        this->forceKillBackend();
        this->startBackend();
    }
}