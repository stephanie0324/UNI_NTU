#ifndef TRAVEL_H
#define TRAVEL_H

#include <QDialog>

namespace Ui {
class travel;
}

class travel : public QDialog
{
    Q_OBJECT

public:
    explicit travel(QWidget *parent = nullptr);
    ~travel();

private:
    Ui::travel *ui;
};

#endif // TRAVEL_H
