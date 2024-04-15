# include "worker.h"

void WorkerThread::setSocket(QTcpSocket* s)
{
    socket = s;
}

void WorkerThread::setStringListModel(QStringListModel* slm)
{
    model = slm;
}

void WorkerThread::setListView(QListView* qsv)
{
    chatRecord = qsv;
}

void WorkerThread::run()
{
    QString result;
    stop = false;
    /* ... here is the expensive or blocking operation ... */
    qDebug() << "in thread";

    while (stop == false)
    {
        QStringList list;

        // get from server
        QByteArray recv = "N/A, server is busy";
        socket->waitForReadyRead();
        recv = socket->readAll();
        qDebug() << "Recv message --> " << recv << "w/ length: " << recv.length();

        // project to chatRecords
        list << recv;
        if (recv.length() > 0)
        {
            list = model->stringList() + list;
            model->setStringList(list);
            chatRecord->setModel(model);
        }
    }

    emit resultReady(result);
}
