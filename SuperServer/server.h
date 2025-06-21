#pragma once
#include <QTcpServer>
#include <QHostAddress>
#include <QThread>
#include <QTcpSocket>

class ClientHandler; // Forward declaration

class Server : public QTcpServer {
    Q_OBJECT // <- Убедиться, что этот макрос находится ЗДЕСЬ
public:
    Server(QObject *parent = nullptr);
    bool startServer(quint16 port);
protected:
    void incomingConnection(qintptr handle) override;
private:
    QList<ClientHandler*> clients;
};
