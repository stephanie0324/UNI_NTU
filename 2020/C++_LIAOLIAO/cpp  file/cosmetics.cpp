#include "cosmetics.h"
#include "ui_cosmetics.h"

cosmetics::cosmetics(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cosmetics)
{
    ui->setupUi(this);
}

cosmetics::~cosmetics()
{
    delete ui;
}
