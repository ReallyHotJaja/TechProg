#include "crypto.h"
#include <QCryptographicHash>

QString Crypto::sha256(const QString &input) {
    QByteArray hash = QCryptographicHash::hash(input.toUtf8(), QCryptographicHash::Sha256);
    return QString(hash.toHex());
}
