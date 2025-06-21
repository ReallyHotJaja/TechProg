#pragma once
#include <QString>

class RequestParser {
public:
    static QString handleRequest(const QString &json);
};
