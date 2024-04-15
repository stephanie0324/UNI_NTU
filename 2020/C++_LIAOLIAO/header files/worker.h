# ifndef WORKER_H
# define WORKER_H
# include <QThread>
# include <QObject>
# include <QDebug>
# include <QTcpSocket>
# include <QListView>
# include <QStringListModel>

class WorkerThread : public QThread
{
    Q_OBJECT

    void run() override;

public:
    QTcpSocket* socket;
    QStringListModel* model;
    QListView* chatRecord;
    bool stop;
    void setSocket(QTcpSocket* s);
    void setStringListModel(QStringListModel* slm);
    void setListView(QListView* qsv);

signals:
    void resultReady(const QString &s);
};

# endif


