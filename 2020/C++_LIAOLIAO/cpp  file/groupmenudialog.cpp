#include <QDesktopWidget>

#include "groupmenudialog.h"
#include "ui_groupmenudialog.h"
#include "politics.h"
#include "travel.h"
#include "study.h"
#include "cosmetics.h"


GroupMenuDialog::GroupMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GroupMenuDialog)
{
    ui->setupUi(this);
}

GroupMenuDialog::~GroupMenuDialog()
{
    delete ui;
}

void GroupMenuDialog::on_pushButton_clicked()
{
    Politics politics;
    politics.setModal(true);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-politics.width()) / 2;
    int y = (screenGeometry.height()-politics.height()) / 2;
    politics.move(x, y);
    politics.show();

    politics.exec();
}

void GroupMenuDialog::on_pushButton_2_clicked()
{
    travel travel;
    travel.setModal(true);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-travel.width()) / 2;
    int y = (screenGeometry.height()-travel.height()) / 2;
    travel.move(x, y);
    travel.show();

    travel.exec();
}

void GroupMenuDialog::on_pushButton_4_clicked()
{
    study study;
    study.setModal(true);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-study.width()) / 2;
    int y = (screenGeometry.height()-study.height()) / 2;
    study.move(x, y);
    study.show();

    study.exec();
}

void GroupMenuDialog::on_pushButton_5_clicked()
{
    cosmetics cosmetics;
    cosmetics.setModal(true);

    QRect screenGeometry = QApplication::desktop()->screenGeometry();
    int x = (screenGeometry.width()-cosmetics.width()) / 2;
    int y = (screenGeometry.height()-cosmetics.height()) / 2;
    cosmetics.move(x, y);
    cosmetics.show();

    cosmetics.exec();
}
