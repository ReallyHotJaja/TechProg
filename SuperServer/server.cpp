#include "server.h"
#include "clienthandler.h"
#include <QThread>
#include <QDebug>

Server::Server(QObject *parent) : QTcpServer(parent) {
}

bool Server::startServer(quint16 port) {
    return listen(QHostAddress::Any, port);
}

void Server::incomingConnection(qintptr handle) {
    qDebug() << "Новое соединение!";

    ClientHandler *handler = new ClientHandler(handle);

    QThread *thread = new QThread(this);
    handler->moveToThread(thread);

    connect(thread, &QThread::started, handler, &ClientHandler::process);
    connect(handler, &ClientHandler::disconnected, this, [=]() {
        qDebug() << "Клиент отключился";
        clients.removeOne(handler);
        handler->deleteLater();
        thread->quit();
        thread->wait();
        thread->deleteLater();
    });

    thread->start();
    clients.append(handler);
}
