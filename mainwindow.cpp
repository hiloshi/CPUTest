#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //serial = new QSerialPort(this);
    //connect(serial, &QSerialPort::readyRead, this, &MainWindow::UART_Receiver2);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    MainLoopTimer = new QTimer();
    connect(MainLoopTimer, SIGNAL(timeout()), this, SLOT(UART_Receiver2()));
    MainLoopTimer->start(1000);
    //----------------------------------------
    MySeries = new QSplineSeries();
    MySeries->setName("QChart");
    Mychart = new QChart();
    Mychart->addSeries(MySeries);
    Mychart->setTitle("Display");
    Mychart->createDefaultAxes();
    Mychart->axisY()->setRange(0,15000);
    Mychart->axisX()->setRange(0,100);

    MychartView = new QChartView(Mychart);

    setCentralWidget(MychartView);

    My_chart_max =100;
    elapse_time =0;

    My_x=My_y=My_y_max=0;
    MyData.clear();

    for(int i=0;i<My_chart_max;i++)
        MySeries->append(i, i);
}

void MainWindow::UART_Receiver2()
{

    UART_Read_Buffer = UART_Read_Buffer; // + serial->readAll().toHex();

    //--------------------------------------------                      //count number of input data. .byJC
        elapse_time++;
        QString s = QString::number(elapse_time);                       //convert int to string. . byJC
        Mychart->axisX()->setTitleText(s);
    //-------------------------------------------
        UART_Read_Buffer.clear();
        //MainLoopTimer->start(1000);
//    }

}
