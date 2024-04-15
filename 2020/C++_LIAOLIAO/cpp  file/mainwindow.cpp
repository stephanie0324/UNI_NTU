#include <QDesktopWidget>
#include <QApplication>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "groupmenudialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    GroupMenuDialog groupmenudockwidget;
    groupmenudockwidget.setModal(true);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-groupmenudockwidget.width()) / 2;
    int y = (screenGeometry.height()-groupmenudockwidget.height()) / 2;
    groupmenudockwidget.move(x, y);
    groupmenudockwidget.show();

    groupmenudockwidget.exec();
}
