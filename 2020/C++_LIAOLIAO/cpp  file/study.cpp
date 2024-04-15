#include "study.h"
#include "ui_study.h"

study::study(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::study)
{
    ui->setupUi(this);
}

study::~study()
{
    delete ui;
}
