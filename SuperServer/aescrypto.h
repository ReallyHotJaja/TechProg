#ifndef AESCRYPTO_H
#define AESCRYPTO_H

#include <QString>
#include <QByteArray>

class AESCrypto {
public:
    static QByteArray aesEncrypt(const QString &plainText);
    static QString aesDecrypt(const QByteArray &cipherText);

private:
    static const QByteArray aesKey;  // 🔐 объявление ключа
    static const QByteArray aesIv;   // 🔐 объявление IV
};

#endif // AESCRYPTO_H
