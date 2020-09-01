#include "grafik.h"
#include "ui_grafik.h"

Grafik::Grafik(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Grafik)
{
    ui->setupUi(this);
}

Grafik::~Grafik()
{
    delete ui;
}

void Grafik::showGraph(double *x,double *y,double *y_Approx)
{
    int size = 10;
    QVector<double> X_vec(size),Y_vec(size),Y_Approx_vec(size);
    for(int i = 0; i<size; i++)
    {
        X_vec[i] = x[i];
        Y_vec[i] = y[i];
        Y_Approx_vec[i] = y_Approx[i];
    }

    ui->widget->clearGraphs();
    ui->widget->addGraph();
    ui->widget->addGraph();
    ui->widget->graph(0)->setData(X_vec, Y_vec);
    ui->widget->graph(0)->setPen(QPen(Qt::red));
    ui->widget->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->widget->graph(0)->setScatterStyle(QCPScatterStyle(QCPScatterStyle::ssCircle,5));
    ui->widget->graph(1)->setData(X_vec,Y_Approx_vec);
    ui->widget->xAxis->setLabel("x");
    ui->widget->yAxis->setLabel("y");
    ui->widget->xAxis->setRange(0,1);

    double yMax = y[0], yMin = y[0];
    for(int i = 0; i<size; i++)
    {
        if(y[i] > yMax){yMax = y[i];}
        if(y[i] < yMin){yMin = y[i];}
    }
    ui->widget->yAxis->setRange(yMin,yMax);
    ui->widget->replot();
}
