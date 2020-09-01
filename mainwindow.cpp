#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QFile>
#include <QDir>
#include "QTextStream"
#include "dialog.h"
#include "approxwindow.h"
#include "grafik.h"

void MNK_Lin_Reg(double &b0,double &b1,double *x,double *y);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    Grafik *grf = new Grafik(this);
    ui->setupUi(this);
    setCentralWidget(ui->textEdit);
    connect(ui->actionapproximation,SIGNAL(triggered()),grf,SLOT(show()));
    connect(this,SIGNAL(buildGraph(double*,double*,double*)),grf,SLOT(showGraph(double*,double*,double*)));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionread_triggered()
{
    Dialog *wnd = new Dialog(this);
    wnd->show();
    connect(wnd,SIGNAL(getFilePath(QString)),this,SLOT(ReadTheFile(QString)));
}

void MainWindow::ReadTheFile(const QString &filepath)
{
    QFile myFile(filepath);

    if (!(myFile.open(QFile::ReadOnly | QFile::Text)))
    {
        QMessageBox::warning(this,"Ошибка","Неправильный путь к файлу!");
    }
    else
    {
        QTextStream stream(&myFile);
        ui->textEdit->setText(stream.readAll());


    }
    myFile.flush();
    myFile.close();
}

void MainWindow::on_actionwrite_triggered()
{
    QFile myFile(".//file.txt");

    if(!(myFile.open(QFile::WriteOnly | QFile::Text)))
    {
        QMessageBox::warning(this,"error","я хз что не так");
    }
    else
    {
        QTextStream stream(&myFile);
        stream << ui->textEdit->toPlainText();
        QMessageBox::information(this,"Успех","Данные записаны в файл.");

    }

    myFile.close();

}



void MainWindow::on_actionapproximation_triggered()
{
    QString DataforApprox = ui->textEdit->toPlainText().trimmed();
    QStringList list = DataforApprox.split(" ",QString::SkipEmptyParts);
    double x[10],y[10],y_Approx[10],b0,b1;
    int i = 0;
    foreach(QString num, list)
    {
        y[i] = num.toDouble();
        x[i] = i * 0.1;
        i++;
        if (i>=10)
        {
            break;
        }
    }

    MNK_Lin_Reg(b0,b1,x,y);
    for(int i = 0; i<10; i++)
    {
        y_Approx[i] = b1 * x[i] + b0;
    }

    emit buildGraph(x,y,y_Approx);
}

void MNK_Lin_Reg(double &b0,double &b1,double *x,double *y)
{
    double n = 10;
    double x_ = 0,y_ = 0,x2_ = 0,xy_ = 0;
    for(int i = 0;i < n; i++)
    {
        x_ += x[i];
        y_ += y[i];
        x2_ += x[i] * x[i];
        xy_ += x[i] * y[i];
    }
    b1 = (xy_ * n - x_ * y_)/(x2_ * n - x_ * x_);
    b0 = (y_ - x_ * b1)/n;
}
