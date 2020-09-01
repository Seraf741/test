#include "approxwindow.h"
#include "ui_approxwindow.h"
#include "QPushButton"

approxwindow::approxwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::approxwindow)
{
    ui->setupUi(this);
    connect(ui->);
}

void approxwindow::approximation(const QString &arr)
{

}

approxwindow::~approxwindow()
{
    delete ui;
}


