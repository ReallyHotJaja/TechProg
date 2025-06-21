#include "clienthandler.h"
#include "requestparser.h"
#include "utils.h"
#include <QDebug>
#include <QTcpSocket>

ClientHandler::ClientHandler(qintptr handle, QObject *parent) : QObject(parent), socketDescriptor(handle), socket(nullptr)  //Initialization to nullptr
{
    qDebug() << "ClientHandler created for descriptor: " << socketDescriptor;
}

ClientHandler::~ClientHandler() {
    qDebug() << "ClientHandler destroyed for descriptor: " << socketDescriptor;

    //Check if the pointer socket is valid before attempting deletion
    if (socket) {
        if (socket->isOpen()) {
            socket->close();
        }
        socket->deleteLater();
        socket = nullptr;  // To prevent a double delete
    }
}

void ClientHandler::process() {
    qDebug() << "Starting client processing in thread: " << QThread::currentThreadId();

    //Create the QTcpSocket in the same thread as the ClientHandler.
    socket = new QTcpSocket(this);

    //Set the socket descriptor and check for errors.
    if (!socket->setSocketDescriptor(socketDescriptor)) {
        qDebug() << "Error setting socket descriptor: " << socket->errorString();
        //The socket couldn't be associated with this QTcpSocket instance.
        delete socket;
        socket = nullptr; //Set the pointer to nullptr
        emit disconnected(); //Signal that the socket is disconnected.
        return;
    }

    //Connect the signals and slots for QTcpSocket
    connect(socket, &QTcpSocket::readyRead, this, &ClientHandler::onReadyRead);
    connect(socket, &QTcpSocket::disconnected, this, &ClientHandler::onDisconnected);
    connect(socket, &QAbstractSocket::errorOccurred, this, &ClientHandler::socketError);

    //Send an initial message
    socket->write("Введите JSON-запрос:\n");

    qDebug() << "Client connected: " << socket->peerAddress().toString() << ":" << socket->peerPort();
}

void ClientHandler::onReadyRead() {
    QByteArray data = socket->readAll();
    QString cleaned = cleanInput(data);
    if (cleaned.isEmpty()) return;
    QString response = RequestParser::handleRequest(cleaned);
    socket->write(response.toUtf8() + '\n');
    socket->flush(); // Force sending the data immediately

    qDebug() << "Response sent to client " << socketDescriptor;
}

void ClientHandler::onDisconnected() {
    qDebug() << "Client disconnected from socket: " << socketDescriptor;

    //It is safe to emit disconnected here, since the socket is in the thread now.
    emit disconnected();
}

// New slot to handle socket errors:
void ClientHandler::socketError (QAbstractSocket::SocketError socketError)
{
    qDebug() << "Socket error " << socketError << " on socket " << socketDescriptor << ": " << socket->errorString();
    socket->deleteLater();
    socket = nullptr;
    emit disconnected();
}
