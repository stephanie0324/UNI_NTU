#ifndef COSMETICS_H
#define COSMETICS_H

#include <QDialog>

namespace Ui {
class cosmetics;
}

class cosmetics : public QDialog
{
    Q_OBJECT

public:
    explicit cosmetics(QWidget *parent = nullptr);
    ~cosmetics();

private:
    Ui::cosmetics *ui;
};

#endif // COSMETICS_H
