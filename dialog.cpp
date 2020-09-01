#include "dialog.h"
#include "ui_dialog.h"
#include <QPushButton>
#include <QFile>
#include <QDir>
#include <QFileDialog>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox->button(QDialogButtonBox::Ok),SIGNAL(clicked()),SLOT(okClicked()));
    connect(ui->buttonBox->button(QDialogButtonBox::Cancel),SIGNAL(clicked()),SLOT(close()));
}

void Dialog::on_pushButton_clicked()
{
    QString path = QFileDialog::getOpenFileName(0,QObject::tr("Укажите файл"),QDir::homePath(), QObject::tr("Файл file (*.txt);; Файл file (*.pro);;Все файлы (*.*)"));
    ui->lineEdit->setText(path);
}

void Dialog::okClicked()
{
    emit getFilePath(ui->lineEdit->text());
    close();
}

Dialog::~Dialog()
{
    delete ui;
}



