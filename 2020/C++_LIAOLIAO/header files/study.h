#ifndef STUDY_H
#define STUDY_H

#include <QDialog>

namespace Ui {
class study;
}

class study : public QDialog
{
    Q_OBJECT

public:
    explicit study(QWidget *parent = nullptr);
    ~study();

private:
    Ui::study *ui;
};

#endif // STUDY_H
