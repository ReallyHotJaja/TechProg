#include <QJsonObject>
#include "spline.h"

// Простейшая реализация: возвращает среднее значение y

double Spline::interpolate(const QJsonArray &data) {
    if (data.isEmpty()) return 0.0;
    double sum = 0;
    for (const auto &val : data)
        sum += val.toObject().value("y").toDouble();
    return sum / data.size();
}
