#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qaesencryption.h"

#include <QCryptographicHash>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 🔐 Кнопка: зашифровать
void MainWindow::on_pushButtonEncrypt_clicked()
{
    QString input = ui->lineEditInput->toPlainText().trimmed();
    QByteArray plainData = input.toUtf8();

    // Ключ: "superpassword" (дополняем до 32 байт)
    QByteArray password = "superpassword";
    password.resize(32, '\0');  // дополнение нулями до 32 байт
    QByteArray key = password;

    // ECB не использует IV
    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB, QAESEncryption::PKCS7);
    QByteArray encrypted = encryption.encode(plainData, key);

    QString base64 = encrypted.toBase64();
    ui->lineEditOutput->setPlainText(base64);

    qDebug() << "Input (hex):" << plainData.toHex();
    qDebug() << "Key (hex):" << key.toHex();
    qDebug() << "Encrypted (base64):" << base64;
}

// 🔓 Кнопка: расшифровать
void MainWindow::on_pushButtonDecrypt_clicked()
{
    QString inputBase64 = ui->lineEditOutput->toPlainText().trimmed();
    QByteArray encryptedData = QByteArray::fromBase64(inputBase64.toUtf8());

    QByteArray password = "superpassword";
    password.resize(32, '\0');  // дополнение до 32 байт
    QByteArray key = password;

    QAESEncryption encryption(QAESEncryption::AES_256, QAESEncryption::ECB, QAESEncryption::PKCS7);
    QByteArray decrypted = encryption.decode(encryptedData, key);

    // Удаление паддинга PKCS7
    if (!decrypted.isEmpty()) {
        char pad = decrypted.at(decrypted.size() - 1);
        int padVal = static_cast<unsigned char>(pad);
        if (padVal > 0 && padVal <= 16) {
            decrypted.chop(padVal);
        }
    }

    QString result = QString::fromUtf8(decrypted);
    ui->lineEditInput->setPlainText(result);

    qDebug() << "Decrypted (hex):" << decrypted.toHex();
}

void MainWindow::on_pushButtonHash_clicked()
{
    // Получаем ввод
    QString input = ui->lineEditHashInput->toPlainText().trimmed();
    QByteArray inputData = input.toUtf8();

    // Вычисляем SHA-256
    QByteArray hash = QCryptographicHash::hash(inputData, QCryptographicHash::Sha256);

    // Конвертируем в строку hex
    QString hashHex = hash.toHex();

    // Показываем результат в поле вывода
    ui->lineEditHashOutput->setPlainText(hashHex);

    // Отладка
    qDebug() << "Input:" << input;
    qDebug() << "SHA-256 (hex):" << hashHex;
}
