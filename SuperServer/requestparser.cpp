#include "requestparser.h"
#include "database.h"
#include "crypto.h"
#include "ml_gradient.h"
#include "spline.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QSqlQuery>
#include <aescrypto.h>

QString RequestParser::handleRequest(const QString &jsonStr) {
    QJsonParseError err;
    QJsonDocument doc = QJsonDocument::fromJson(jsonStr.toUtf8(), &err);

    if (err.error != QJsonParseError::NoError || !doc.isObject())
        return R"({"status":"error","message":"Invalid JSON"})";

    QJsonObject obj = doc.object();
    QString type = obj.value("type").toString();
    if (type == "register") {
        QString user = obj.value("username").toString();
        QString pass = obj.value("password").toString();
        QString hash = Crypto::sha256(pass);
        QSqlQuery q(Database::instance().db());
        q.prepare("INSERT INTO users (username, password) VALUES (?, ?)");
        q.addBindValue(user);
        q.addBindValue(hash);
        if (!q.exec()) return R"({"status":"error","message":"User exists"})";
        return R"({"status":"ok","message":"Registered"})";
    }

    if (type == "login") {
        QString user = obj.value("username").toString();
        QString pass = obj.value("password").toString();
        QString hash = Crypto::sha256(pass);
        QSqlQuery q(Database::instance().db());
        q.prepare("SELECT id FROM users WHERE username = ? AND password = ?");
        q.addBindValue(user);
        q.addBindValue(hash);
        q.exec();
        if (q.next()) return R"({"status":"ok","message":"Login success"})";
        return R"({"status":"error","message":"Wrong credentials"})";
    }

    if (type == "gradient") {
        auto values = obj.value("data").toArray();
        double result = Gradient::compute(values);
        return QString(R"({"status":"ok","result":%1})").arg(result);
    }

    if (type == "spline") {
        auto values = obj.value("data").toArray();
        double result = Spline::interpolate(values);
        return QString(R"({"status":"ok","result":%1})").arg(result);
    }

    return R"({"status":"ok","message":"Stub - not implemented"})";
}
