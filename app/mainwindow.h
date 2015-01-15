//---------------------------------------------------------
//
// This file is part of MellowPlayer.
//
// MellowPlayer is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// MellowPlayer is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with MellowPlayer.  If not, see <http://www.gnu.org/licenses/>.
//
//---------------------------------------------------------

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QWidget>
#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QCloseEvent>

namespace Ui {
class MainWindow;
}

//! Implements the main window of the application.
class MainWindow : public QMainWindow
{
    Q_OBJECT

    friend class DlgPreferences;

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showWebPage();
    void showHomePage();
    void saveGeometryAndState();

private slots:
    void onLinkClicked(QUrl url);
    void onPlayPauseTriggered();
    void onStopTriggered();
    void onNextTriggered();
    void onPreviousTriggered();
    void onTrayIconActivated(QSystemTrayIcon::ActivationReason reason);
    void onSelectServiceTriggered();
    void onPreferencesTriggered();
    void updatePlayer();
    void onAboutTriggered();

private:
    void closeEvent(QCloseEvent* event);
    void setupIcons();
    void setupActions();
    void setupTrayIcon();
    void setupUpdateTimer();
    void setupWebView();
    void connectSlots();

    void restoreGeometryAndState();

    Ui::MainWindow *ui;
    QTimer* updateTimer;
    QSystemTrayIcon* trayIcon;
};

#endif // MAINWINDOW_H
