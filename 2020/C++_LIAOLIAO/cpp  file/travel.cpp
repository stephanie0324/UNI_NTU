#include "travel.h"
#include "ui_travel.h"

travel::travel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::travel)
{
    ui->setupUi(this);
}

travel::~travel()
{
    delete ui;
}
