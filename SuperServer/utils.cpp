#include "utils.h"

QString cleanInput(const QByteArray& data) {
    QByteArray result;
    bool skipNext = false;
    for (int i = 0; i < data.size(); ++i) {
        unsigned char byte = static_cast<unsigned char>(data[i]);
        if (byte == 0xFF) { skipNext = true; continue; }
        if (skipNext) { skipNext = false; continue; }
        result.append(byte);
    }
    return QString::fromUtf8(result).trimmed();
}
