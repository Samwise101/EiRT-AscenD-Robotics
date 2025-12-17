#pragma once

#ifndef BACK_END_MANAGER_H
#define BACK_END_MANAGER_H

#include <QObject>
#include <QProcess>
#include <QTimer>
#include <QThread>

class BackEndManager : public QObject
{
    Q_OBJECT

public:
    explicit BackEndManager(QObject* parent = nullptr);
    ~BackEndManager();

public:

    void startBackend(void);
    void stopBackend(void);
    void forceKillBackend(void);
    void setMissedHeartBeat(int);

signals:
    void backEndStarted();
    void backEndStopped();
    void backEndCrashed();

private slots:
    void onBackEndFinished(int exitCode, QProcess::ExitStatus status);
    void onBackEndError(QProcess::ProcessError error);
    void checkHeartBeat();

private:
    QProcess proc;
    QTimer heartBeatTimer;
    int missedHeartBeats;
    int timeToProcessFinish;
    int timeToProcessStart;
    int hearthBeatInterval;
};

#endif