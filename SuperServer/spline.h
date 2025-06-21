#pragma once
#include <QJsonArray>

class Spline {
public:
    static double interpolate(const QJsonArray &data);
};
