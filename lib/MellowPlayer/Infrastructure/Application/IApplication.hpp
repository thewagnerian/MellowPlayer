#pragma once

#include <QtCore/QObject>

class QSessionManager;

namespace MellowPlayer::Infrastructure
{
    class IApplication: public QObject
    {
        Q_OBJECT
    public:
        virtual ~IApplication() = default;

        virtual void initialize() = 0;
        virtual int run() = 0;
        virtual void quit() = 0;
        virtual void restart() = 0;
        virtual void restoreWindow() = 0;

    signals:
        void initialized();
        void started();
        void restoreWindowRequest();
        void commitDataRequest();
    };
}