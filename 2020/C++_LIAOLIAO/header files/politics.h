#ifndef POLITICS_H
#define POLITICS_H

# include <QDialog>
# include <QStringListModel>
# include <QTcpSocket>
# include "worker.h"
# include "func_client.h"

namespace Ui {
class Politics;
}

class Politics : public QDialog
{
    Q_OBJECT
//    friend void WorkerThread::run();

public:
    explicit Politics(QWidget *parent = nullptr);
    ~Politics();
    void getOtherMessage();

private slots:
    void on_sendBtn_clicked();

private:
    QStringListModel* model = new QStringListModel(this);
    Ui::Politics *ui;
    QTcpSocket* socket;
    WorkerThread* workerThread;
    void disJoinServer();
    void startWorkInAThread();
    void handleResults();
};

#endif // POLITICS_H
