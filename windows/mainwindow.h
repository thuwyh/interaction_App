﻿#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qserialport.h"
#include "qserialportinfo.h"
#include <QTimer>
#include <QList>
#include "plot/qcustomplot.h"
#include "recognizor.h"

#include "camerawindow.h"
#include "gestureeditor.h"
#include "calibrationwindow.h"

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
    void updateUI();

    // serial port list slots
    void on_freshButton_clicked();
    void on_onEMGButton_clicked();

    void on_beginButton_clicked();
    void on_stopButton_clicked();

    void on_ResetButton_clicked();
    void on_clearButton_clicked();
    void on_saveButton_clicked();
    void on_initButton_clicked();
    void on_pushButtonRLD_clicked();
    void on_pushButton_2_clicked();
    void on_noiseButton_clicked();
    void on_normalMeaButton_clicked();

    // plot slots
    void addDatatoEMGPlots(float *emgdata,int n_datacount);
    void addDatatoIMUPlots(float *angles,int n_datacount);

    // command response slots
    void responseReceived(unsigned char res);

    // gesture response slots
    void showGesture(QString gesture);
    void clearGesture();

    void on_onIMUButton_clicked();
    void on_loadButton_clicked();

    void on_Slider_sliderReleased();

    void on_playButton_clicked();

    void on_editorButton_clicked();

    void on_pauseButton_clicked();

    void on_squaretestButton_clicked();

    void on_fb1Button_clicked();

    void on_fb2Button_clicked();

    void on_fb3Button_clicked();

    void on_fb4Button_clicked();

    void on_fb5Button_clicked();

    void on_pushButton_clicked();

    void on_onRobotButton_clicked();

    void on_radioButton_toggled(bool checked);

    void on_radioButton_2_toggled(bool checked);

    void on_play3XButton_clicked();

    void on_stepButton_clicked();
    void checkRadioButton();

private:
    Ui::MainWindow *ui;
    QSerialPortInfo portinfo;
    QSerialPort serialport;
    qint64 m_bytesWritten;
    qint64 m_bytesRead;
    QByteArray  m_readData;
    int imucount,emgcount;
    QTimer updatetimer;

    QCustomPlot* plots[8];

    Recognizor recognizor;

    int fileLength,datapoint;

    GestureEditor *gwin;
    CalibrationWindow *cawin;
    CameraWindow *cwin;

    bool isplaying;

};

#endif // MAINWINDOW_H
