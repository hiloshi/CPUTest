#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSerialPort/QSerialPort>
#include <QSplineSeries>
#include <QChart>
#include <QChartView>
#include <QTimer>

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
    QTimer          *MainLoopTimer;

};

#endif // MAINWINDOW_H
