TEMPLATE = app
CONFIG += console c++17
QT += core network sql

# Путь к OpenSSL на Windows
INCLUDEPATH += "C:/OpenSSL-Win64/include"
LIBS += -L"C:/OpenSSL-Win64/lib/VC/x64/MD" -llibssl -llibcrypto

SOURCES += main.cpp \
           server.cpp \
           clienthandler.cpp \
           database.cpp \
           requestparser.cpp \
           utils.cpp \
           crypto.cpp \
           ml_gradient.cpp \
           spline.cpp

HEADERS += server.h \
           clienthandler.h \
           database.h \
           requestparser.h \
           utils.h \
           crypto.h \
           ml_gradient.h \
           spline.h

# Укажи имя проекта и исполняемого файла
TARGET = SuperServer
