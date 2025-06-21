#include <QJsonObject>
#include "ml_gradient.h"

// Простая модель: y = ax + b, считаем "a"
double Gradient::compute(const QJsonArray &data) {
    if (data.size() < 2) return 0.0;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    for (const auto &val : data) {
        auto obj = val.toObject();
        double x = obj["x"].toDouble();
        double y = obj["y"].toDouble();
        sumX += x; sumY += y; sumXY += x*y; sumX2 += x*x;
    }
    int n = data.size();
    return (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX + 1e-9);
}
