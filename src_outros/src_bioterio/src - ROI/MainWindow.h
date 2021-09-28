#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <chrono>
#include <strsafe.h>
#include <fstream>
#include <thread>
#include <mutex>
#include "stdafx.h"
#include "Utils.h"
#include "KinectSensor.h"
#include "KinectWriter.h"
#include "KinectReader.h"
#include <QThread>
#include <QLabel>
#include <QTimer>
#include <boost/format.hpp>
#include "Cronometro.h"
#include <opencv2/opencv.hpp>
#include <ctkRangeSlider.h>

// InfraredSourceValueMaximum is the highest value that can be returned in the InfraredFrame.
// It is cast to a float for readability in the visualization code.
#define InfraredSourceValueMaximum static_cast<float>(USHRT_MAX)

// The InfraredOutputValueMinimum value is used to set the lower limit, post processing, of the
// infrared data that we will render.
// Increasing or decreasing this value sets a brightness "wall" either closer or further away.
#define InfraredOutputValueMinimum 0.01f

// The InfraredOutputValueMaximum value is the upper limit, post processing, of the
// infrared data that we will render.
#define InfraredOutputValueMaximum 1.0f

// The InfraredSceneValueAverage value specifies the average infrared value of the scene.
// This value was selected by analyzing the average pixel intensity for a given scene.
// Depending on the visualization requirements for a given application, this value can be
// hard coded, as was done here, or calculated by averaging the intensity for each pixel prior
// to rendering.
#define InfraredSceneValueAverage 0.08f

/// The InfraredSceneStandardDeviations value specifies the number of standard deviations
/// to apply to InfraredSceneValueAverage. This value was selected by analyzing data
/// from a given scene.
/// Depending on the visualization requirements for a given application, this value can be
/// hard coded, as was done here, or calculated at runtime.
#define InfraredSceneStandardDeviations 3.0f

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public Q_SLOTS:
    void abrirTrack();
    void tocarTrack(QString str);
    void atualizarTela();
    void gravarTrack();
    void setPararGravacaoAuto();
    void atualizarLCD();
    void atualizarDisplayPlay();
    void atualizarFrame();
    void alterarStatus();
    void dimensionarCirculo(int valor);
    void posicionarX(int valor);
    void posicionarY(int valor);
    void ajustarContraste(int valor);
    void inverterContraste();
    void quantificar();
    void ajustarMatiz(int,int);
    void ajustarSaturacao(int,int);
    void ajustarValor(int, int);
    void ajustarContraste(int, int);

    void ajustarVerde(int,int);
    void ajustarVermelho(int, int);
    void ajustarAzul(int, int);

private:
    Ui::MainWindow *ui;
    QString nomeArquivoAtual;
    Cronometro _cron;
    Cronometro _cronPlay;
    QTimer _timer;
    QTimer _timerPlay;


    void showImage(cv::Mat img, QLabel *lbl);

    const std::string hsvWindow = "HSV Image";

    IKinectSensor* sensorKinect;
    KinectWriter kinectWriter;

    ICoordinateMapper* mapper;
    IMultiSourceFrameReader* msFrameReader;

    INT64 timeInicial;
    INT64 ultimaContagem;
    INT64 proximaAtualizacaoTime;
    DWORD totalDeframesAtualizados;
    double frequencia;

    int contraste = 127;

    bool _deveProcessar = true;
    bool _deveGravar = false; 
    bool _pararGravacaoAuto  = true;
    bool _invertido = false;
    bool deveQuantificar = false;

    INT64 _colorTime;
    INT64 _infraTime;
    INT64 _depthTime;
    INT64 _playTime;
    int _raio  = 180;  //180
    int _eixoX = 250;  //256
    int _eixoY = 208;  //212

    int _minMatiz   = 0;
    int _minSaturar = 0;
    int _minBrilho  = 0;
    int _minContraste = 0;
    int _minVerde     = 0;
    int _minVermelho  = 0;
    int _minAzul      = 0;

    int _maxMatiz   = 255;
    int _maxSaturar = 255;
    int _maxBrilho  = 255;
    int _maxContraste  = 255;
    int _maxVerde   = 255;
    int _maxVermelho = 255;
    int _maxAzul  = 255;

    const USHORT _minDepth = 500;
    const USHORT _maxDepth = 4500;

    //cor
    RGBQUAD* _1920x1080_cor_buffer;
    RGBQUAD* _1304x1080_cor_buffer;
    RGBQUAD* _512x424_cor_buffer;
    std::vector<BYTE> colorBuffer;
    cv::Mat frameColor;

    //infra
    UINT16*  _512x424_infraInt_buffer;
    RGBQUAD* _512x424_infraCor_buffer;

    //depth
    UINT16*  _512x424_depthInt_buffer;
    RGBQUAD* _512x424_depthCor_buffer;
    std::vector<UINT16> depthBuffer;

    HRESULT inicializarSensorKinect();

    void FPS(QLabel *label, INT64 time);

    void definirTela();
    void processarCor();
    void processarInfrared();
    void processarDepth();
    void mousePressEvent(QMouseEvent *event);
};

#endif // MAINWINDOW_H
