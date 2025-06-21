#pragma once
#include <QSqlDatabase>

class Database {
public:
    static Database& instance();
    QSqlDatabase& db();
private:
    Database();
    QSqlDatabase m_db;
};
