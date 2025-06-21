#include "database.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QDebug>

Database::Database() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName("server.db");
    m_db.open();
    QSqlQuery q(m_db);
    q.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, username TEXT UNIQUE, password TEXT)");
}

Database& Database::instance() {
    static Database instance;
    return instance;
}

QSqlDatabase& Database::db() {
    return m_db;
}
