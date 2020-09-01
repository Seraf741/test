#ifndef GRAFIK_H
#define GRAFIK_H

#include <QDialog>

namespace Ui {
class Grafik;
}

class Grafik : public QDialog
{
    Q_OBJECT

public:
    explicit Grafik(QWidget *parent = nullptr);
    ~Grafik();

private:
    Ui::Grafik *ui;
private slots:
    void showGraph(double *x,double *y,double *y_Approx);

};

#endif // GRAFIK_H
