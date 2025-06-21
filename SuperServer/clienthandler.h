#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H

#include <QObject>
#include <QTcpSocket>
#include <QThread> // Add this line

class ClientHandler : public QObject {
    Q_OBJECT
public:
    explicit ClientHandler(qintptr handle, QObject *parent = nullptr);
    ~ClientHandler();

signals:
    void disconnected();

public slots:
    void process(); // New slot for handling socket setup in the thread
private slots:
    void onReadyRead();
    void onDisconnected();
    void socketError(QAbstractSocket::SocketError socketError);

private:
    QTcpSocket *socket;
    qintptr socketDescriptor;
};

#endif // CLIENTHANDLER_H

