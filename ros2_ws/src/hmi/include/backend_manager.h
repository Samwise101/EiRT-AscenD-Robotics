#pragma once

#ifndef BACK_END_MANAGER_H
#define BACK_END_MANAGER_H

#include <QThread>
#include <QProcess>
#include <QString>

class BackEndManger : public QObject
{
    Q_OBJECT

public:
    explicit BackEndManger(QObject* parent = nullptr);
    ~BackEndManger();

public:

    void start_backend(void);
    void stop_backend(void);
    void force_kill_backend(void);

private:

};

#endif