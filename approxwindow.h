#ifndef APPROXWINDOW_H
#define APPROXWINDOW_H

#include <QDialog>

namespace Ui {
class approxwindow;
}

class approxwindow : public QDialog
{
    Q_OBJECT

public:
    explicit approxwindow(QWidget *parent = nullptr);
    ~approxwindow();

private:
    Ui::approxwindow *ui;
private slots:
    void approximation(const QString &str);
    void test();
};

#endif // APPROXWINDOW_H
