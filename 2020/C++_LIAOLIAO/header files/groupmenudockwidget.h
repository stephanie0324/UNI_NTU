#ifndef GROUPMENUDOCKWIDGET_H
#define GROUPMENUDOCKWIDGET_H

#include <QDockWidget>

namespace Ui {
class GroupMenuDockWidget;
}

class GroupMenuDockWidget : public QDockWidget
{
    Q_OBJECT

public:
    explicit GroupMenuDockWidget(QWidget *parent = nullptr);
    ~GroupMenuDockWidget();

private:
    Ui::GroupMenuDockWidget *ui;
};

#endif // GROUPMENUDOCKWIDGET_H
