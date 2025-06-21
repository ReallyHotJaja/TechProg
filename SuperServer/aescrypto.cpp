include <openssl/evp.h>
#include <openssl/err.h>
#include "aescrypto.h"
#include <QDebug>

const QByteArray AESCrypto::aesKey = "12345678901234567890123456789012";
const QByteArray AESCrypto::aesIv  = "abcdefghijklmnop";

QByteArray AESCrypto::aesEncrypt(const QString &plainText) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    QByteArray output;
    int outLen1 = 0, outLen2 = 0;
    unsigned char outBuf[1024];

    EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                       reinterpret_cast<const unsigned char*>(aesKey.constData()),
                       reinterpret_cast<const unsigned char*>(aesIv.constData()));

    EVP_EncryptUpdate(ctx, outBuf, &outLen1,
                      reinterpret_cast<const unsigned char*>(plainText.toUtf8().constData()),
                      plainText.size());

    EVP_EncryptFinal_ex(ctx, outBuf + outLen1, &outLen2);
    output.append(reinterpret_cast<char*>(outBuf), outLen1 + outLen2);

    EVP_CIPHER_CTX_free(ctx);
    return output.toBase64();
}

QString AESCrypto::aesDecrypt(const QByteArray &cipherTextBase64) {
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();
    QByteArray cipherText = QByteArray::fromBase64(cipherTextBase64);
    QByteArray output;
    int outLen1 = 0, outLen2 = 0;
    unsigned char outBuf[1024];

    EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), nullptr,
                       reinterpret_cast<const unsigned char*>(aesKey.constData()),
                       reinterpret_cast<const unsigned char*>(aesIv.constData()));

    EVP_DecryptUpdate(ctx, outBuf, &outLen1,
                      reinterpret_cast<const unsigned char*>(cipherText.constData()),
                      cipherText.size());

    EVP_DecryptFinal_ex(ctx, outBuf + outLen1, &outLen2);
    output.append(reinterpret_cast<char*>(outBuf), outLen1 + outLen2);

    EVP_CIPHER_CTX_free(ctx);
    return QString::fromUtf8(output);
}
