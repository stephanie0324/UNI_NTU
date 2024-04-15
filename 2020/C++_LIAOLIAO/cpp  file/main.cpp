#include <QApplication>
#include <QDesktopWidget>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow mainWindow;

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-mainWindow.width()) / 2;
    int y = (screenGeometry.height()-mainWindow.height()) / 2;
    mainWindow.move(x, y);
    mainWindow.show();

    return a.exec();
}
