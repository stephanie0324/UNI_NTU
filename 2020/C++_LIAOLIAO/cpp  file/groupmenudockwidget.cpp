#include "groupmenudockwidget.h"
#include "ui_groupmenudockwidget.h"

GroupMenuDockWidget::GroupMenuDockWidget(QWidget *parent) :
    QDockWidget(parent),
    ui(new Ui::GroupMenuDockWidget)
{
    ui->setupUi(this);
}

GroupMenuDockWidget::~GroupMenuDockWidget()
{
    delete ui;
}
