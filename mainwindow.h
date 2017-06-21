#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSplineSeries>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>

using namespace QtCharts;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void UART_Receiver2();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QSerialPort     *serial;
    QByteArray      UART_Read_Buffer;                        //UART Read Buffer
  //---------------------------------------------------------
    QSplineSeries   *MySeries;
    QChart          *Mychart;
    QChartView      *MychartView;
    int             My_x;
    int             My_y,My_y_max;
    QList           <int>MyData;
    int             My_chart_max;
    int             elapse_time;

};

#endif // MAINWINDOW_H
