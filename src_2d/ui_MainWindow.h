/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <TelaCapturar.h>
#include <libs/ClickableLabel.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabViewPrincipal;
    TelaCapturar *tabRastreamento;
    QGridLayout *gridGeral;
    QFrame *frmCapturar;
    QLabel *lblFPS;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *layCapturar;
    QLabel *lblLatencia;
    QLCDNumber *displayLatencia;
    QLabel *lblDistancia;
    QLCDNumber *displayDistancia;
    QLabel *lblVelocidade;
    QLCDNumber *displayVelocidade;
    QLabel *lblId;
    QFrame *frame;
    QTextEdit *txtIdentificacao;
    QPushButton *btnRastrear;
    QCheckBox *chkRastrearAuto_2;
    QCheckBox *chkGravar;
    ClickableLabel *viewCaptura;
    QPushButton *btnConnect;
    QWidget *tabArena;
    QGridLayout *gridLayout_6;
    QFrame *frmArena;
    QPushButton *btnSalvarArena;
    ClickableLabel *viewArena;
    QGroupBox *grpArena;
    QLabel *lblFPSIR_9;
    QSlider *sldArenaRaio;
    QLabel *lblFPSIR_11;
    QSlider *sldArenaEixoX;
    QLabel *lblFPSIR_14;
    QSlider *sldArenaEixoY;
    QSpinBox *cboArenaRaio;
    QSpinBox *cboArenaEixoX;
    QSpinBox *cboArenaEixoY;
    QGroupBox *grpPlataforma;
    QLabel *lblFPSIR_10;
    QSlider *sldPlataRaio;
    QLabel *lblFPSIR_12;
    QSlider *sldPlataEixoX;
    QLabel *lblFPSIR_15;
    QSlider *sldPlataEixoY;
    QSpinBox *cboPlataEixoY;
    QSpinBox *cboPlataEixoX;
    QSpinBox *cboPlataRaio;
    QWidget *horizontalLayoutWidget;
    QVBoxLayout *vlFerramentas;
    QPushButton *btnSelecionar_2;
    QPushButton *btnArena_2;
    QPushButton *btnPlataforma_2;
    QWidget *tabDeteccao;
    QGridLayout *gridLayout_3;
    QFrame *frmDetectar;
    QPushButton *btnSalvarDetecta;
    QGroupBox *grpArena_3;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *layFiltrosRGB;
    QGroupBox *grpPlataforma_4;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layFiltrosHSV;
    ClickableLabel *viewDetectar;
    QGroupBox *grpPlataforma_5;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layFiltrosContraste;
    QWidget *tabHistorico;
    QGridLayout *gridLayout_4;
    QFrame *frmHistorico;
    QTableView *tableView;
    QPushButton *btnExportarXlsx;
    QPushButton *btnApagarDados;
    QFrame *frame_2;
    QGridLayout *gridLayout_8;
    QTextEdit *txtPlanilha;
    QCheckBox *chkHistorico;
    QDateEdit *dateEdit;
    QWidget *tabConfig;
    QGridLayout *gridLayout_5;
    QFrame *frmConfiguracoes;
    QPushButton *btnSalvarConfiguracoes;
    QCheckBox *chkRastrearAuto;
    QLabel *label;
    QTimeEdit *cboLimiteInicial;
    QTimeEdit *cboLimiteFinal;
    QGroupBox *grpExibir;
    QCheckBox *chkPlataforma;
    QCheckBox *chkBordaInternaArena;
    QCheckBox *chkQuadrantes;
    QCheckBox *chkBordaExternaArena;
    QCheckBox *chkContorno;
    QCheckBox *chkQuadrantes_2;
    QCheckBox *chkQuadrantes_3;
    QCheckBox *chkContorno_2;
    QGroupBox *grpCalcular;
    QCheckBox *chkDistancia;
    QCheckBox *chkVelocidade;
    QCheckBox *chkTempoContorno;
    QCheckBox *chkTempoQuadrantes;
    QCheckBox *chkTempoBordas;
    QCheckBox *chkLatencia;
    QGroupBox *grpVideo;
    QCheckBox *chkVideoEmCores;
    QCheckBox *chkInverterImagem;
    QLabel *label_7;
    QComboBox *cboResolucao;
    QLabel *label_2;
    QTimeEdit *cboIntervalo;
    QCheckBox *chkRastrearAuto_3;
    QWidget *tabSobre;
    QGridLayout *gridLayout_7;
    QFrame *frmSobre;
    QPlainTextEdit *plainTextEdit;
    QPlainTextEdit *plainTextEdit_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 690);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 1, 0, 0);
        tabViewPrincipal = new QTabWidget(centralwidget);
        tabViewPrincipal->setObjectName(QStringLiteral("tabViewPrincipal"));
        tabViewPrincipal->setBaseSize(QSize(1024, 690));
        QFont font;
        font.setPointSize(10);
        tabViewPrincipal->setFont(font);
        tabViewPrincipal->setAutoFillBackground(false);
        tabViewPrincipal->setStyleSheet(QLatin1String("QTabWidget::pane { /* The tab widget frame */\n"
"    border: 0px solid #C2C7CB;\n"
"}"));
        tabViewPrincipal->setTabPosition(QTabWidget::North);
        tabViewPrincipal->setMovable(false);
        tabRastreamento = new TelaCapturar();
        tabRastreamento->setObjectName(QStringLiteral("tabRastreamento"));
        gridGeral = new QGridLayout(tabRastreamento);
        gridGeral->setObjectName(QStringLiteral("gridGeral"));
        frmCapturar = new QFrame(tabRastreamento);
        frmCapturar->setObjectName(QStringLiteral("frmCapturar"));
        frmCapturar->setMinimumSize(QSize(850, 540));
        frmCapturar->setMaximumSize(QSize(850, 540));
        frmCapturar->setAutoFillBackground(false);
        frmCapturar->setStyleSheet(QStringLiteral(""));
        frmCapturar->setFrameShape(QFrame::StyledPanel);
        frmCapturar->setFrameShadow(QFrame::Raised);
        lblFPS = new QLabel(frmCapturar);
        lblFPS->setObjectName(QStringLiteral("lblFPS"));
        lblFPS->setGeometry(QRect(394, 495, 131, 34));
        QFont font1;
        font1.setPointSize(14);
        lblFPS->setFont(font1);
        lblFPS->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_3 = new QWidget(frmCapturar);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(588, 2, 243, 531));
        layCapturar = new QVBoxLayout(verticalLayoutWidget_3);
        layCapturar->setObjectName(QStringLiteral("layCapturar"));
        layCapturar->setContentsMargins(0, 0, 0, 0);
        lblLatencia = new QLabel(verticalLayoutWidget_3);
        lblLatencia->setObjectName(QStringLiteral("lblLatencia"));
        lblLatencia->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(12);
        lblLatencia->setFont(font2);

        layCapturar->addWidget(lblLatencia);

        displayLatencia = new QLCDNumber(verticalLayoutWidget_3);
        displayLatencia->setObjectName(QStringLiteral("displayLatencia"));
        displayLatencia->setMinimumSize(QSize(240, 70));
        displayLatencia->setMaximumSize(QSize(240, 80));
        displayLatencia->setFrameShape(QFrame::Box);
        displayLatencia->setFrameShadow(QFrame::Raised);
        displayLatencia->setSegmentStyle(QLCDNumber::Filled);

        layCapturar->addWidget(displayLatencia);

        lblDistancia = new QLabel(verticalLayoutWidget_3);
        lblDistancia->setObjectName(QStringLiteral("lblDistancia"));
        lblDistancia->setMaximumSize(QSize(16777215, 20));
        lblDistancia->setFont(font2);

        layCapturar->addWidget(lblDistancia);

        displayDistancia = new QLCDNumber(verticalLayoutWidget_3);
        displayDistancia->setObjectName(QStringLiteral("displayDistancia"));
        displayDistancia->setMinimumSize(QSize(240, 70));
        displayDistancia->setMaximumSize(QSize(240, 80));
        displayDistancia->setFrameShape(QFrame::Box);
        displayDistancia->setFrameShadow(QFrame::Raised);
        displayDistancia->setDigitCount(5);
        displayDistancia->setSegmentStyle(QLCDNumber::Filled);

        layCapturar->addWidget(displayDistancia);

        lblVelocidade = new QLabel(verticalLayoutWidget_3);
        lblVelocidade->setObjectName(QStringLiteral("lblVelocidade"));
        lblVelocidade->setMaximumSize(QSize(16777215, 20));
        lblVelocidade->setFont(font2);

        layCapturar->addWidget(lblVelocidade);

        displayVelocidade = new QLCDNumber(verticalLayoutWidget_3);
        displayVelocidade->setObjectName(QStringLiteral("displayVelocidade"));
        displayVelocidade->setMinimumSize(QSize(240, 70));
        displayVelocidade->setMaximumSize(QSize(240, 80));
        displayVelocidade->setLayoutDirection(Qt::LeftToRight);
        displayVelocidade->setStyleSheet(QStringLiteral(""));
        displayVelocidade->setFrameShape(QFrame::Box);
        displayVelocidade->setFrameShadow(QFrame::Raised);
        displayVelocidade->setSmallDecimalPoint(false);
        displayVelocidade->setDigitCount(5);
        displayVelocidade->setSegmentStyle(QLCDNumber::Filled);

        layCapturar->addWidget(displayVelocidade);

        lblId = new QLabel(verticalLayoutWidget_3);
        lblId->setObjectName(QStringLiteral("lblId"));
        lblId->setFont(font2);

        layCapturar->addWidget(lblId);

        frame = new QFrame(verticalLayoutWidget_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(240, 50));
        frame->setMaximumSize(QSize(240, 60));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"    border: 1px solid gray;\n"
"    background-color: white;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        txtIdentificacao = new QTextEdit(frame);
        txtIdentificacao->setObjectName(QStringLiteral("txtIdentificacao"));
        txtIdentificacao->setGeometry(QRect(10, 10, 220, 31));
        QFont font3;
        font3.setPointSize(14);
        font3.setBold(false);
        font3.setWeight(50);
        txtIdentificacao->setFont(font3);
        txtIdentificacao->setStyleSheet(QLatin1String("QTextEdit {\n"
"    border:  0px;\n"
"}"));
        txtIdentificacao->setFrameShape(QFrame::NoFrame);
        txtIdentificacao->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtIdentificacao->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        layCapturar->addWidget(frame);

        btnRastrear = new QPushButton(verticalLayoutWidget_3);
        btnRastrear->setObjectName(QStringLiteral("btnRastrear"));
        btnRastrear->setMinimumSize(QSize(240, 70));
        btnRastrear->setMaximumSize(QSize(240, 16777215));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        btnRastrear->setFont(font4);
        btnRastrear->setStyleSheet(QLatin1String("QPushButton:default\n"
"{\n"
"   background-color: red;\n"
"   color: red;\n"
"}\n"
"\n"
"QPushButton:checked\n"
"{\n"
"    background-color: green;\n"
"    color: black;\n"
"}"));

        layCapturar->addWidget(btnRastrear);

        chkRastrearAuto_2 = new QCheckBox(verticalLayoutWidget_3);
        chkRastrearAuto_2->setObjectName(QStringLiteral("chkRastrearAuto_2"));
        chkRastrearAuto_2->setFont(font);
        chkRastrearAuto_2->setCheckable(true);
        chkRastrearAuto_2->setChecked(true);

        layCapturar->addWidget(chkRastrearAuto_2);

        chkGravar = new QCheckBox(verticalLayoutWidget_3);
        chkGravar->setObjectName(QStringLiteral("chkGravar"));
        chkGravar->setFont(font);
        chkGravar->setChecked(false);

        layCapturar->addWidget(chkGravar);

        viewCaptura = new ClickableLabel(frmCapturar);
        viewCaptura->setObjectName(QStringLiteral("viewCaptura"));
        viewCaptura->setGeometry(QRect(0, 0, 540, 540));
        viewCaptura->setMinimumSize(QSize(0, 0));
        viewCaptura->setMaximumSize(QSize(540, 540));
        viewCaptura->setAutoFillBackground(true);
        viewCaptura->setFrameShape(QFrame::StyledPanel);
        viewCaptura->setFrameShadow(QFrame::Plain);
        viewCaptura->setAlignment(Qt::AlignCenter);
        btnConnect = new QPushButton(frmCapturar);
        btnConnect->setObjectName(QStringLiteral("btnConnect"));
        btnConnect->setGeometry(QRect(10, 500, 33, 33));
        btnConnect->setMinimumSize(QSize(33, 33));
        btnConnect->setMaximumSize(QSize(33, 33));
        QFont font5;
        font5.setFamily(QStringLiteral("Terminal"));
        font5.setPointSize(14);
        font5.setBold(true);
        font5.setWeight(75);
        btnConnect->setFont(font5);
        btnConnect->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"   color: red;\n"
"   border: 1px outset red;\n"
"   background-color: white;\n"
"}\n"
"\n"
"QPushButton::checked\n"
"{\n"
"   color: green;\n"
"   border: 1px outset green;\n"
"   background-color: transparent;\n"
"}"));
        btnConnect->setIconSize(QSize(30, 30));
        btnConnect->setCheckable(true);
        btnConnect->setAutoExclusive(false);
        viewCaptura->raise();
        lblFPS->raise();
        verticalLayoutWidget_3->raise();
        btnConnect->raise();

        gridGeral->addWidget(frmCapturar, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabRastreamento, QString());
        tabArena = new QWidget();
        tabArena->setObjectName(QStringLiteral("tabArena"));
        gridLayout_6 = new QGridLayout(tabArena);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frmArena = new QFrame(tabArena);
        frmArena->setObjectName(QStringLiteral("frmArena"));
        frmArena->setMinimumSize(QSize(560, 540));
        frmArena->setMaximumSize(QSize(850, 540));
        frmArena->setAutoFillBackground(false);
        frmArena->setStyleSheet(QStringLiteral(""));
        frmArena->setFrameShape(QFrame::StyledPanel);
        frmArena->setFrameShadow(QFrame::Raised);
        btnSalvarArena = new QPushButton(frmArena);
        btnSalvarArena->setObjectName(QStringLiteral("btnSalvarArena"));
        btnSalvarArena->setGeometry(QRect(577, 490, 271, 49));
        btnSalvarArena->setFont(font2);
        viewArena = new ClickableLabel(frmArena);
        viewArena->setObjectName(QStringLiteral("viewArena"));
        viewArena->setGeometry(QRect(0, 0, 540, 540));
        viewArena->setMinimumSize(QSize(0, 0));
        viewArena->setMaximumSize(QSize(540, 540));
        viewArena->setAutoFillBackground(true);
        viewArena->setFrameShape(QFrame::StyledPanel);
        viewArena->setFrameShadow(QFrame::Plain);
        viewArena->setAlignment(Qt::AlignCenter);
        grpArena = new QGroupBox(frmArena);
        grpArena->setObjectName(QStringLiteral("grpArena"));
        grpArena->setGeometry(QRect(579, -2, 267, 229));
        grpArena->setFont(font2);
        lblFPSIR_9 = new QLabel(grpArena);
        lblFPSIR_9->setObjectName(QStringLiteral("lblFPSIR_9"));
        lblFPSIR_9->setGeometry(QRect(16, 30, 64, 27));
        QFont font6;
        font6.setPointSize(10);
        font6.setBold(true);
        font6.setWeight(75);
        lblFPSIR_9->setFont(font6);
        sldArenaRaio = new QSlider(grpArena);
        sldArenaRaio->setObjectName(QStringLiteral("sldArenaRaio"));
        sldArenaRaio->setGeometry(QRect(15, 65, 175, 22));
        sldArenaRaio->setMinimum(150);
        sldArenaRaio->setMaximum(270);
        sldArenaRaio->setValue(210);
        sldArenaRaio->setSliderPosition(210);
        sldArenaRaio->setOrientation(Qt::Horizontal);
        lblFPSIR_11 = new QLabel(grpArena);
        lblFPSIR_11->setObjectName(QStringLiteral("lblFPSIR_11"));
        lblFPSIR_11->setGeometry(QRect(14, 95, 64, 27));
        lblFPSIR_11->setFont(font6);
        sldArenaEixoX = new QSlider(grpArena);
        sldArenaEixoX->setObjectName(QStringLiteral("sldArenaEixoX"));
        sldArenaEixoX->setGeometry(QRect(15, 125, 175, 22));
        sldArenaEixoX->setMinimum(0);
        sldArenaEixoX->setMaximum(540);
        sldArenaEixoX->setSingleStep(10);
        sldArenaEixoX->setPageStep(1);
        sldArenaEixoX->setValue(270);
        sldArenaEixoX->setSliderPosition(270);
        sldArenaEixoX->setOrientation(Qt::Horizontal);
        lblFPSIR_14 = new QLabel(grpArena);
        lblFPSIR_14->setObjectName(QStringLiteral("lblFPSIR_14"));
        lblFPSIR_14->setGeometry(QRect(15, 158, 64, 27));
        lblFPSIR_14->setFont(font6);
        sldArenaEixoY = new QSlider(grpArena);
        sldArenaEixoY->setObjectName(QStringLiteral("sldArenaEixoY"));
        sldArenaEixoY->setGeometry(QRect(15, 190, 175, 22));
        sldArenaEixoY->setMinimum(0);
        sldArenaEixoY->setMaximum(540);
        sldArenaEixoY->setSingleStep(10);
        sldArenaEixoY->setPageStep(1);
        sldArenaEixoY->setValue(270);
        sldArenaEixoY->setSliderPosition(270);
        sldArenaEixoY->setOrientation(Qt::Horizontal);
        cboArenaRaio = new QSpinBox(grpArena);
        cboArenaRaio->setObjectName(QStringLiteral("cboArenaRaio"));
        cboArenaRaio->setGeometry(QRect(200, 64, 45, 22));
        cboArenaRaio->setFont(font);
        cboArenaRaio->setAlignment(Qt::AlignCenter);
        cboArenaRaio->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboArenaRaio->setMinimum(150);
        cboArenaRaio->setMaximum(270);
        cboArenaRaio->setValue(210);
        cboArenaEixoX = new QSpinBox(grpArena);
        cboArenaEixoX->setObjectName(QStringLiteral("cboArenaEixoX"));
        cboArenaEixoX->setGeometry(QRect(200, 123, 45, 22));
        cboArenaEixoX->setFont(font);
        cboArenaEixoX->setAlignment(Qt::AlignCenter);
        cboArenaEixoX->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboArenaEixoX->setMaximum(540);
        cboArenaEixoX->setValue(270);
        cboArenaEixoY = new QSpinBox(grpArena);
        cboArenaEixoY->setObjectName(QStringLiteral("cboArenaEixoY"));
        cboArenaEixoY->setGeometry(QRect(200, 188, 45, 22));
        cboArenaEixoY->setFont(font);
        cboArenaEixoY->setAlignment(Qt::AlignCenter);
        cboArenaEixoY->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboArenaEixoY->setMaximum(540);
        cboArenaEixoY->setValue(270);
        grpPlataforma = new QGroupBox(frmArena);
        grpPlataforma->setObjectName(QStringLiteral("grpPlataforma"));
        grpPlataforma->setGeometry(QRect(578, 242, 269, 237));
        grpPlataforma->setFont(font2);
        lblFPSIR_10 = new QLabel(grpPlataforma);
        lblFPSIR_10->setObjectName(QStringLiteral("lblFPSIR_10"));
        lblFPSIR_10->setGeometry(QRect(12, 30, 64, 27));
        lblFPSIR_10->setFont(font6);
        sldPlataRaio = new QSlider(grpPlataforma);
        sldPlataRaio->setObjectName(QStringLiteral("sldPlataRaio"));
        sldPlataRaio->setGeometry(QRect(15, 64, 175, 22));
        sldPlataRaio->setMinimum(5);
        sldPlataRaio->setMaximum(35);
        sldPlataRaio->setValue(20);
        sldPlataRaio->setSliderPosition(20);
        sldPlataRaio->setOrientation(Qt::Horizontal);
        lblFPSIR_12 = new QLabel(grpPlataforma);
        lblFPSIR_12->setObjectName(QStringLiteral("lblFPSIR_12"));
        lblFPSIR_12->setGeometry(QRect(15, 99, 64, 27));
        lblFPSIR_12->setFont(font6);
        sldPlataEixoX = new QSlider(grpPlataforma);
        sldPlataEixoX->setObjectName(QStringLiteral("sldPlataEixoX"));
        sldPlataEixoX->setGeometry(QRect(15, 136, 175, 22));
        sldPlataEixoX->setMinimum(0);
        sldPlataEixoX->setMaximum(540);
        sldPlataEixoX->setSingleStep(10);
        sldPlataEixoX->setPageStep(1);
        sldPlataEixoX->setValue(270);
        sldPlataEixoX->setSliderPosition(270);
        sldPlataEixoX->setOrientation(Qt::Horizontal);
        lblFPSIR_15 = new QLabel(grpPlataforma);
        lblFPSIR_15->setObjectName(QStringLiteral("lblFPSIR_15"));
        lblFPSIR_15->setGeometry(QRect(14, 170, 64, 27));
        lblFPSIR_15->setFont(font6);
        sldPlataEixoY = new QSlider(grpPlataforma);
        sldPlataEixoY->setObjectName(QStringLiteral("sldPlataEixoY"));
        sldPlataEixoY->setGeometry(QRect(15, 201, 175, 22));
        sldPlataEixoY->setMinimum(0);
        sldPlataEixoY->setMaximum(540);
        sldPlataEixoY->setSingleStep(10);
        sldPlataEixoY->setPageStep(1);
        sldPlataEixoY->setValue(270);
        sldPlataEixoY->setSliderPosition(270);
        sldPlataEixoY->setOrientation(Qt::Horizontal);
        cboPlataEixoY = new QSpinBox(grpPlataforma);
        cboPlataEixoY->setObjectName(QStringLiteral("cboPlataEixoY"));
        cboPlataEixoY->setGeometry(QRect(200, 198, 45, 22));
        cboPlataEixoY->setFont(font);
        cboPlataEixoY->setAlignment(Qt::AlignCenter);
        cboPlataEixoY->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboPlataEixoY->setMaximum(540);
        cboPlataEixoY->setValue(270);
        cboPlataEixoX = new QSpinBox(grpPlataforma);
        cboPlataEixoX->setObjectName(QStringLiteral("cboPlataEixoX"));
        cboPlataEixoX->setGeometry(QRect(200, 134, 45, 22));
        cboPlataEixoX->setFont(font);
        cboPlataEixoX->setAlignment(Qt::AlignCenter);
        cboPlataEixoX->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboPlataEixoX->setMaximum(540);
        cboPlataEixoX->setValue(270);
        cboPlataRaio = new QSpinBox(grpPlataforma);
        cboPlataRaio->setObjectName(QStringLiteral("cboPlataRaio"));
        cboPlataRaio->setGeometry(QRect(200, 61, 45, 22));
        cboPlataRaio->setFont(font);
        cboPlataRaio->setAlignment(Qt::AlignCenter);
        cboPlataRaio->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboPlataRaio->setMinimum(5);
        cboPlataRaio->setMaximum(35);
        cboPlataRaio->setValue(20);
        horizontalLayoutWidget = new QWidget(frmArena);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(258, 190, 47, 149));
        vlFerramentas = new QVBoxLayout(horizontalLayoutWidget);
        vlFerramentas->setObjectName(QStringLiteral("vlFerramentas"));
        vlFerramentas->setContentsMargins(0, 0, 0, 0);
        btnSelecionar_2 = new QPushButton(horizontalLayoutWidget);
        btnSelecionar_2->setObjectName(QStringLiteral("btnSelecionar_2"));
        btnSelecionar_2->setMinimumSize(QSize(45, 45));
        btnSelecionar_2->setMaximumSize(QSize(45, 45));
        btnSelecionar_2->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"   background-color: gray;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSelecionar_2->setIcon(icon);
        btnSelecionar_2->setIconSize(QSize(24, 24));
        btnSelecionar_2->setCheckable(true);
        btnSelecionar_2->setAutoExclusive(false);

        vlFerramentas->addWidget(btnSelecionar_2);

        btnArena_2 = new QPushButton(horizontalLayoutWidget);
        btnArena_2->setObjectName(QStringLiteral("btnArena_2"));
        btnArena_2->setMinimumSize(QSize(45, 45));
        btnArena_2->setMaximumSize(QSize(45, 45));
        btnArena_2->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"   background-color: gray;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/arena.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnArena_2->setIcon(icon1);
        btnArena_2->setIconSize(QSize(36, 36));
        btnArena_2->setCheckable(true);
        btnArena_2->setAutoExclusive(false);

        vlFerramentas->addWidget(btnArena_2);

        btnPlataforma_2 = new QPushButton(horizontalLayoutWidget);
        btnPlataforma_2->setObjectName(QStringLiteral("btnPlataforma_2"));
        btnPlataforma_2->setMinimumSize(QSize(45, 45));
        btnPlataforma_2->setMaximumSize(QSize(45, 45));
        btnPlataforma_2->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"   background-color: gray;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/plataforma.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlataforma_2->setIcon(icon2);
        btnPlataforma_2->setIconSize(QSize(24, 24));
        btnPlataforma_2->setCheckable(true);
        btnPlataforma_2->setAutoExclusive(false);

        vlFerramentas->addWidget(btnPlataforma_2);

        btnPlataforma_2->raise();
        btnArena_2->raise();
        btnSelecionar_2->raise();
        btnSalvarArena->raise();
        grpArena->raise();
        grpPlataforma->raise();
        horizontalLayoutWidget->raise();
        viewArena->raise();

        gridLayout_6->addWidget(frmArena, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabArena, QString());
        tabDeteccao = new QWidget();
        tabDeteccao->setObjectName(QStringLiteral("tabDeteccao"));
        gridLayout_3 = new QGridLayout(tabDeteccao);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        frmDetectar = new QFrame(tabDeteccao);
        frmDetectar->setObjectName(QStringLiteral("frmDetectar"));
        frmDetectar->setMinimumSize(QSize(850, 540));
        frmDetectar->setMaximumSize(QSize(850, 540));
        frmDetectar->setAutoFillBackground(false);
        frmDetectar->setStyleSheet(QStringLiteral(""));
        frmDetectar->setFrameShape(QFrame::StyledPanel);
        frmDetectar->setFrameShadow(QFrame::Raised);
        btnSalvarDetecta = new QPushButton(frmDetectar);
        btnSalvarDetecta->setObjectName(QStringLiteral("btnSalvarDetecta"));
        btnSalvarDetecta->setGeometry(QRect(578, 491, 269, 49));
        btnSalvarDetecta->setFont(font2);
        grpArena_3 = new QGroupBox(frmDetectar);
        grpArena_3->setObjectName(QStringLiteral("grpArena_3"));
        grpArena_3->setGeometry(QRect(160, 160, 267, 191));
        grpArena_3->setFont(font2);
        verticalLayoutWidget_5 = new QWidget(grpArena_3);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(18, 30, 228, 141));
        layFiltrosRGB = new QVBoxLayout(verticalLayoutWidget_5);
        layFiltrosRGB->setObjectName(QStringLiteral("layFiltrosRGB"));
        layFiltrosRGB->setContentsMargins(0, 0, 0, 0);
        grpPlataforma_4 = new QGroupBox(frmDetectar);
        grpPlataforma_4->setObjectName(QStringLiteral("grpPlataforma_4"));
        grpPlataforma_4->setGeometry(QRect(580, 0, 269, 341));
        grpPlataforma_4->setFont(font2);
        verticalLayoutWidget = new QWidget(grpPlataforma_4);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(19, 33, 229, 281));
        layFiltrosHSV = new QVBoxLayout(verticalLayoutWidget);
        layFiltrosHSV->setObjectName(QStringLiteral("layFiltrosHSV"));
        layFiltrosHSV->setContentsMargins(0, 0, 0, 0);
        viewDetectar = new ClickableLabel(frmDetectar);
        viewDetectar->setObjectName(QStringLiteral("viewDetectar"));
        viewDetectar->setGeometry(QRect(0, 0, 540, 540));
        viewDetectar->setMinimumSize(QSize(0, 0));
        viewDetectar->setMaximumSize(QSize(540, 540));
        viewDetectar->setAutoFillBackground(true);
        viewDetectar->setFrameShape(QFrame::StyledPanel);
        viewDetectar->setFrameShadow(QFrame::Plain);
        viewDetectar->setAlignment(Qt::AlignCenter);
        grpPlataforma_5 = new QGroupBox(frmDetectar);
        grpPlataforma_5->setObjectName(QStringLiteral("grpPlataforma_5"));
        grpPlataforma_5->setGeometry(QRect(150, 340, 269, 101));
        grpPlataforma_5->setFont(font2);
        verticalLayoutWidget_2 = new QWidget(grpPlataforma_5);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(19, 33, 229, 51));
        layFiltrosContraste = new QVBoxLayout(verticalLayoutWidget_2);
        layFiltrosContraste->setObjectName(QStringLiteral("layFiltrosContraste"));
        layFiltrosContraste->setContentsMargins(0, 0, 0, 0);
        grpPlataforma_5->raise();
        grpArena_3->raise();
        viewDetectar->raise();
        btnSalvarDetecta->raise();
        grpPlataforma_4->raise();

        gridLayout_3->addWidget(frmDetectar, 0, 1, 1, 1);

        tabViewPrincipal->addTab(tabDeteccao, QString());
        tabHistorico = new QWidget();
        tabHistorico->setObjectName(QStringLiteral("tabHistorico"));
        gridLayout_4 = new QGridLayout(tabHistorico);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frmHistorico = new QFrame(tabHistorico);
        frmHistorico->setObjectName(QStringLiteral("frmHistorico"));
        frmHistorico->setMinimumSize(QSize(640, 530));
        frmHistorico->setMaximumSize(QSize(850, 540));
        frmHistorico->setAutoFillBackground(true);
        frmHistorico->setStyleSheet(QStringLiteral(""));
        frmHistorico->setFrameShape(QFrame::StyledPanel);
        frmHistorico->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frmHistorico);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(0, 0, 850, 421));
        QFont font7;
        font7.setPointSize(11);
        tableView->setFont(font7);
        tableView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableView->horizontalHeader()->setDefaultSectionSize(75);
        tableView->horizontalHeader()->setMinimumSectionSize(50);
        tableView->horizontalHeader()->setStretchLastSection(true);
        tableView->verticalHeader()->setMinimumSectionSize(10);
        btnExportarXlsx = new QPushButton(frmHistorico);
        btnExportarXlsx->setObjectName(QStringLiteral("btnExportarXlsx"));
        btnExportarXlsx->setGeometry(QRect(330, 470, 251, 61));
        btnExportarXlsx->setFont(font4);
        btnApagarDados = new QPushButton(frmHistorico);
        btnApagarDados->setObjectName(QStringLiteral("btnApagarDados"));
        btnApagarDados->setGeometry(QRect(590, 470, 251, 61));
        QFont font8;
        font8.setPointSize(12);
        font8.setBold(false);
        font8.setWeight(50);
        btnApagarDados->setFont(font8);
        frame_2 = new QFrame(frmHistorico);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setGeometry(QRect(10, 470, 311, 60));
        frame_2->setMinimumSize(QSize(240, 0));
        frame_2->setMaximumSize(QSize(350, 60));
        frame_2->setAutoFillBackground(false);
        frame_2->setStyleSheet(QLatin1String("QFrame {\n"
"    border: 1px solid gray;\n"
"    background-color: white;\n"
"}"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        gridLayout_8 = new QGridLayout(frame_2);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_8->setContentsMargins(-1, 12, -1, 0);
        txtPlanilha = new QTextEdit(frame_2);
        txtPlanilha->setObjectName(QStringLiteral("txtPlanilha"));
        txtPlanilha->setFont(font3);
        txtPlanilha->setStyleSheet(QLatin1String("QTextEdit {\n"
"    border:  0px;\n"
"}"));
        txtPlanilha->setFrameShape(QFrame::NoFrame);
        txtPlanilha->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        txtPlanilha->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_8->addWidget(txtPlanilha, 0, 0, 1, 1);

        chkHistorico = new QCheckBox(frmHistorico);
        chkHistorico->setObjectName(QStringLiteral("chkHistorico"));
        chkHistorico->setEnabled(false);
        chkHistorico->setGeometry(QRect(150, 430, 341, 31));
        chkHistorico->setFont(font2);
        chkHistorico->setChecked(true);
        dateEdit = new QDateEdit(frmHistorico);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        dateEdit->setEnabled(false);
        dateEdit->setGeometry(QRect(10, 430, 111, 31));
        dateEdit->setFont(font2);
        dateEdit->setButtonSymbols(QAbstractSpinBox::UpDownArrows);
        dateEdit->setDateTime(QDateTime(QDate(2017, 1, 1), QTime(0, 0, 0)));
        dateEdit->setCalendarPopup(true);

        gridLayout_4->addWidget(frmHistorico, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabHistorico, QString());
        tabConfig = new QWidget();
        tabConfig->setObjectName(QStringLiteral("tabConfig"));
        gridLayout_5 = new QGridLayout(tabConfig);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        frmConfiguracoes = new QFrame(tabConfig);
        frmConfiguracoes->setObjectName(QStringLiteral("frmConfiguracoes"));
        frmConfiguracoes->setMinimumSize(QSize(850, 540));
        frmConfiguracoes->setMaximumSize(QSize(850, 540));
        frmConfiguracoes->setAutoFillBackground(false);
        frmConfiguracoes->setStyleSheet(QStringLiteral(""));
        frmConfiguracoes->setFrameShape(QFrame::StyledPanel);
        frmConfiguracoes->setFrameShadow(QFrame::Raised);
        btnSalvarConfiguracoes = new QPushButton(frmConfiguracoes);
        btnSalvarConfiguracoes->setObjectName(QStringLiteral("btnSalvarConfiguracoes"));
        btnSalvarConfiguracoes->setGeometry(QRect(580, 470, 251, 49));
        btnSalvarConfiguracoes->setFont(font2);
        chkRastrearAuto = new QCheckBox(frmConfiguracoes);
        chkRastrearAuto->setObjectName(QStringLiteral("chkRastrearAuto"));
        chkRastrearAuto->setGeometry(QRect(310, 283, 211, 23));
        chkRastrearAuto->setFont(font2);
        chkRastrearAuto->setChecked(true);
        label = new QLabel(frmConfiguracoes);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(330, 310, 172, 21));
        label->setFont(font2);
        cboLimiteInicial = new QTimeEdit(frmConfiguracoes);
        cboLimiteInicial->setObjectName(QStringLiteral("cboLimiteInicial"));
        cboLimiteInicial->setGeometry(QRect(330, 340, 71, 25));
        cboLimiteInicial->setMinimumSize(QSize(0, 20));
        cboLimiteInicial->setFont(font2);
        cboLimiteInicial->setAlignment(Qt::AlignCenter);
        cboLimiteInicial->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboLimiteInicial->setCurrentSection(QDateTimeEdit::MinuteSection);
        cboLimiteInicial->setTime(QTime(0, 0, 3));
        cboLimiteFinal = new QTimeEdit(frmConfiguracoes);
        cboLimiteFinal->setObjectName(QStringLiteral("cboLimiteFinal"));
        cboLimiteFinal->setGeometry(QRect(420, 340, 71, 25));
        cboLimiteFinal->setMinimumSize(QSize(0, 20));
        cboLimiteFinal->setFont(font2);
        cboLimiteFinal->setAlignment(Qt::AlignCenter);
        cboLimiteFinal->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboLimiteFinal->setTime(QTime(0, 2, 0));
        grpExibir = new QGroupBox(frmConfiguracoes);
        grpExibir->setObjectName(QStringLiteral("grpExibir"));
        grpExibir->setGeometry(QRect(10, 20, 261, 501));
        grpExibir->setFont(font2);
        chkPlataforma = new QCheckBox(grpExibir);
        chkPlataforma->setObjectName(QStringLiteral("chkPlataforma"));
        chkPlataforma->setGeometry(QRect(20, 30, 105, 24));
        chkPlataforma->setFont(font2);
        chkPlataforma->setChecked(false);
        chkBordaInternaArena = new QCheckBox(grpExibir);
        chkBordaInternaArena->setObjectName(QStringLiteral("chkBordaInternaArena"));
        chkBordaInternaArena->setGeometry(QRect(20, 120, 189, 21));
        chkBordaInternaArena->setFont(font2);
        chkBordaInternaArena->setChecked(false);
        chkQuadrantes = new QCheckBox(grpExibir);
        chkQuadrantes->setObjectName(QStringLiteral("chkQuadrantes"));
        chkQuadrantes->setGeometry(QRect(20, 150, 181, 21));
        chkQuadrantes->setFont(font2);
        chkQuadrantes->setChecked(true);
        chkBordaExternaArena = new QCheckBox(grpExibir);
        chkBordaExternaArena->setObjectName(QStringLiteral("chkBordaExternaArena"));
        chkBordaExternaArena->setGeometry(QRect(20, 90, 194, 23));
        chkBordaExternaArena->setFont(font2);
        chkBordaExternaArena->setChecked(true);
        chkContorno = new QCheckBox(grpExibir);
        chkContorno->setObjectName(QStringLiteral("chkContorno"));
        chkContorno->setGeometry(QRect(20, 60, 201, 24));
        chkContorno->setFont(font2);
        chkContorno->setChecked(false);
        chkQuadrantes_2 = new QCheckBox(grpExibir);
        chkQuadrantes_2->setObjectName(QStringLiteral("chkQuadrantes_2"));
        chkQuadrantes_2->setEnabled(false);
        chkQuadrantes_2->setGeometry(QRect(20, 210, 201, 21));
        chkQuadrantes_2->setFont(font2);
        chkQuadrantes_2->setChecked(true);
        chkQuadrantes_3 = new QCheckBox(grpExibir);
        chkQuadrantes_3->setObjectName(QStringLiteral("chkQuadrantes_3"));
        chkQuadrantes_3->setEnabled(false);
        chkQuadrantes_3->setGeometry(QRect(20, 240, 191, 21));
        chkQuadrantes_3->setFont(font2);
        chkQuadrantes_3->setChecked(true);
        chkContorno_2 = new QCheckBox(grpExibir);
        chkContorno_2->setObjectName(QStringLiteral("chkContorno_2"));
        chkContorno_2->setGeometry(QRect(20, 180, 201, 21));
        chkContorno_2->setFont(font2);
        chkContorno_2->setChecked(false);
        grpCalcular = new QGroupBox(frmConfiguracoes);
        grpCalcular->setObjectName(QStringLiteral("grpCalcular"));
        grpCalcular->setGeometry(QRect(290, 20, 261, 221));
        grpCalcular->setFont(font2);
        chkDistancia = new QCheckBox(grpCalcular);
        chkDistancia->setObjectName(QStringLiteral("chkDistancia"));
        chkDistancia->setGeometry(QRect(20, 60, 135, 21));
        chkDistancia->setFont(font2);
        chkDistancia->setChecked(true);
        chkVelocidade = new QCheckBox(grpCalcular);
        chkVelocidade->setObjectName(QStringLiteral("chkVelocidade"));
        chkVelocidade->setGeometry(QRect(20, 90, 140, 21));
        chkVelocidade->setFont(font2);
        chkVelocidade->setChecked(true);
        chkTempoContorno = new QCheckBox(grpCalcular);
        chkTempoContorno->setObjectName(QStringLiteral("chkTempoContorno"));
        chkTempoContorno->setEnabled(false);
        chkTempoContorno->setGeometry(QRect(20, 150, 194, 21));
        chkTempoContorno->setFont(font2);
        chkTempoContorno->setChecked(false);
        chkTempoQuadrantes = new QCheckBox(grpCalcular);
        chkTempoQuadrantes->setObjectName(QStringLiteral("chkTempoQuadrantes"));
        chkTempoQuadrantes->setEnabled(false);
        chkTempoQuadrantes->setGeometry(QRect(20, 120, 201, 21));
        chkTempoQuadrantes->setFont(font2);
        chkTempoQuadrantes->setChecked(false);
        chkTempoBordas = new QCheckBox(grpCalcular);
        chkTempoBordas->setObjectName(QStringLiteral("chkTempoBordas"));
        chkTempoBordas->setEnabled(false);
        chkTempoBordas->setGeometry(QRect(20, 180, 171, 21));
        chkTempoBordas->setFont(font2);
        chkTempoBordas->setChecked(false);
        chkLatencia = new QCheckBox(grpCalcular);
        chkLatencia->setObjectName(QStringLiteral("chkLatencia"));
        chkLatencia->setGeometry(QRect(20, 30, 111, 21));
        chkLatencia->setFont(font2);
        chkLatencia->setChecked(true);
        grpVideo = new QGroupBox(frmConfiguracoes);
        grpVideo->setObjectName(QStringLiteral("grpVideo"));
        grpVideo->setGeometry(QRect(570, 20, 261, 221));
        grpVideo->setFont(font2);
        chkVideoEmCores = new QCheckBox(grpVideo);
        chkVideoEmCores->setObjectName(QStringLiteral("chkVideoEmCores"));
        chkVideoEmCores->setGeometry(QRect(20, 40, 101, 20));
        chkVideoEmCores->setFont(font2);
        chkVideoEmCores->setChecked(true);
        chkInverterImagem = new QCheckBox(grpVideo);
        chkInverterImagem->setObjectName(QStringLiteral("chkInverterImagem"));
        chkInverterImagem->setGeometry(QRect(20, 70, 111, 22));
        chkInverterImagem->setFont(font2);
        chkInverterImagem->setChecked(true);
        label_7 = new QLabel(grpVideo);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(20, 120, 141, 16));
        label_7->setFont(font2);
        cboResolucao = new QComboBox(grpVideo);
        cboResolucao->setObjectName(QStringLiteral("cboResolucao"));
        cboResolucao->setEnabled(false);
        cboResolucao->setGeometry(QRect(20, 140, 211, 25));
        cboResolucao->setFont(font2);
        label_2 = new QLabel(frmConfiguracoes);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(330, 370, 161, 21));
        label_2->setFont(font2);
        cboIntervalo = new QTimeEdit(frmConfiguracoes);
        cboIntervalo->setObjectName(QStringLiteral("cboIntervalo"));
        cboIntervalo->setGeometry(QRect(330, 400, 71, 25));
        cboIntervalo->setMinimumSize(QSize(0, 20));
        cboIntervalo->setFont(font2);
        cboIntervalo->setAlignment(Qt::AlignCenter);
        cboIntervalo->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        cboIntervalo->setCurrentSection(QDateTimeEdit::MinuteSection);
        cboIntervalo->setTime(QTime(0, 3, 0));
        chkRastrearAuto_3 = new QCheckBox(frmConfiguracoes);
        chkRastrearAuto_3->setObjectName(QStringLiteral("chkRastrearAuto_3"));
        chkRastrearAuto_3->setGeometry(QRect(310, 253, 191, 23));
        chkRastrearAuto_3->setFont(font2);
        chkRastrearAuto_3->setChecked(true);

        gridLayout_5->addWidget(frmConfiguracoes, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabConfig, QString());
        tabSobre = new QWidget();
        tabSobre->setObjectName(QStringLiteral("tabSobre"));
        gridLayout_7 = new QGridLayout(tabSobre);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        frmSobre = new QFrame(tabSobre);
        frmSobre->setObjectName(QStringLiteral("frmSobre"));
        frmSobre->setMinimumSize(QSize(640, 530));
        frmSobre->setMaximumSize(QSize(850, 540));
        frmSobre->setAutoFillBackground(true);
        frmSobre->setStyleSheet(QStringLiteral(""));
        frmSobre->setFrameShape(QFrame::StyledPanel);
        frmSobre->setFrameShadow(QFrame::Raised);
        plainTextEdit = new QPlainTextEdit(frmSobre);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(240, 180, 421, 31));
        plainTextEdit->setFont(font4);
        plainTextEdit->setStyleSheet(QLatin1String("QPlainTextEdit\n"
"{\n"
"   background-color: transparent;\n"
"}"));
        plainTextEdit->setFrameShape(QFrame::NoFrame);
        plainTextEdit->setReadOnly(true);
        plainTextEdit_2 = new QPlainTextEdit(frmSobre);
        plainTextEdit_2->setObjectName(QStringLiteral("plainTextEdit_2"));
        plainTextEdit_2->setGeometry(QRect(240, 220, 421, 111));
        plainTextEdit_2->setFont(font2);
        plainTextEdit_2->setStyleSheet(QLatin1String("QPlainTextEdit\n"
"{\n"
"   background-color: transparent;\n"
"}"));
        plainTextEdit_2->setFrameShape(QFrame::NoFrame);
        plainTextEdit_2->setReadOnly(true);

        gridLayout_7->addWidget(frmSobre, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabSobre, QString());

        gridLayout_2->addWidget(tabViewPrincipal, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabViewPrincipal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Expt-o Morris v.170526.0.1 (Beta)", Q_NULLPTR));
        lblFPS->setText(QApplication::translate("MainWindow", "29.97 fps", Q_NULLPTR));
        lblLatencia->setText(QApplication::translate("MainWindow", "Lat\303\252ncia (mm:ss)", Q_NULLPTR));
        lblDistancia->setText(QApplication::translate("MainWindow", "Dist\303\242ncia (cm)", Q_NULLPTR));
        lblVelocidade->setText(QApplication::translate("MainWindow", "Velocidade (m/s)", Q_NULLPTR));
        lblId->setText(QApplication::translate("MainWindow", "Identifica\303\247\303\243o", Q_NULLPTR));
        txtIdentificacao->setPlaceholderText(QApplication::translate("MainWindow", "Digitar ID do animal...", Q_NULLPTR));
        btnRastrear->setText(QApplication::translate("MainWindow", "Rastrear", Q_NULLPTR));
        chkRastrearAuto_2->setText(QApplication::translate("MainWindow", "Rastrear automaticamente", Q_NULLPTR));
        chkGravar->setText(QApplication::translate("MainWindow", "Gravar v\303\255deo", Q_NULLPTR));
        viewCaptura->setText(QString());
        btnConnect->setText(QApplication::translate("MainWindow", "C", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabRastreamento), QApplication::translate("MainWindow", "Rastreamento", Q_NULLPTR));
        btnSalvarArena->setText(QApplication::translate("MainWindow", "Salvar", Q_NULLPTR));
        viewArena->setText(QString());
        grpArena->setTitle(QApplication::translate("MainWindow", "Arena", Q_NULLPTR));
        lblFPSIR_9->setText(QApplication::translate("MainWindow", "Di\303\242metro", Q_NULLPTR));
        lblFPSIR_11->setText(QApplication::translate("MainWindow", "Eixo X", Q_NULLPTR));
        lblFPSIR_14->setText(QApplication::translate("MainWindow", "Eixo Y", Q_NULLPTR));
        grpPlataforma->setTitle(QApplication::translate("MainWindow", "Plataforma", Q_NULLPTR));
        lblFPSIR_10->setText(QApplication::translate("MainWindow", "Di\303\242metro", Q_NULLPTR));
        lblFPSIR_12->setText(QApplication::translate("MainWindow", "Eixo X", Q_NULLPTR));
        lblFPSIR_15->setText(QApplication::translate("MainWindow", "Eixo Y", Q_NULLPTR));
        btnSelecionar_2->setText(QString());
        btnArena_2->setText(QString());
        btnPlataforma_2->setText(QString());
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabArena), QApplication::translate("MainWindow", "Arena", Q_NULLPTR));
        btnSalvarDetecta->setText(QApplication::translate("MainWindow", "Salvar", Q_NULLPTR));
        grpArena_3->setTitle(QApplication::translate("MainWindow", "RGB", Q_NULLPTR));
        grpPlataforma_4->setTitle(QApplication::translate("MainWindow", "HSVC", Q_NULLPTR));
        viewDetectar->setText(QString());
        grpPlataforma_5->setTitle(QApplication::translate("MainWindow", "Contraste", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabDeteccao), QApplication::translate("MainWindow", "Detec\303\247\303\243o", Q_NULLPTR));
        btnExportarXlsx->setText(QApplication::translate("MainWindow", "Exportar XLSX", Q_NULLPTR));
        btnApagarDados->setText(QApplication::translate("MainWindow", "Apagar Dados", Q_NULLPTR));
        txtPlanilha->setPlaceholderText(QApplication::translate("MainWindow", "Informe o nome da planilha...", Q_NULLPTR));
        chkHistorico->setText(QApplication::translate("MainWindow", "Exibir hist\303\263ricos de experimentos anteriores", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabHistorico), QApplication::translate("MainWindow", "Hist\303\263rico", Q_NULLPTR));
        btnSalvarConfiguracoes->setText(QApplication::translate("MainWindow", "Salvar", Q_NULLPTR));
        chkRastrearAuto->setText(QApplication::translate("MainWindow", "Rastrear automaticamente", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Limite inicial e dura\303\247\303\243o", Q_NULLPTR));
        cboLimiteInicial->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", Q_NULLPTR));
        cboLimiteFinal->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", Q_NULLPTR));
        grpExibir->setTitle(QApplication::translate("MainWindow", "Exibir", Q_NULLPTR));
        chkPlataforma->setText(QApplication::translate("MainWindow", "Plataforma", Q_NULLPTR));
        chkBordaInternaArena->setText(QApplication::translate("MainWindow", "Borda interna da arena", Q_NULLPTR));
        chkQuadrantes->setText(QApplication::translate("MainWindow", "Eixos dos quadrantes", Q_NULLPTR));
        chkBordaExternaArena->setText(QApplication::translate("MainWindow", "Borda externa da arena", Q_NULLPTR));
        chkContorno->setText(QApplication::translate("MainWindow", "Contorno da plataforma", Q_NULLPTR));
        chkQuadrantes_2->setText(QApplication::translate("MainWindow", "Rastros no experimento", Q_NULLPTR));
        chkQuadrantes_3->setText(QApplication::translate("MainWindow", "Rastros na reprodu\303\247\303\243o", Q_NULLPTR));
        chkContorno_2->setText(QApplication::translate("MainWindow", "Contorno do animal", Q_NULLPTR));
        grpCalcular->setTitle(QApplication::translate("MainWindow", "Calcular", Q_NULLPTR));
        chkDistancia->setText(QApplication::translate("MainWindow", "Dist\303\242ncia (cm)", Q_NULLPTR));
        chkVelocidade->setText(QApplication::translate("MainWindow", "Velocidade (m/s)", Q_NULLPTR));
        chkTempoContorno->setText(QApplication::translate("MainWindow", "Tempo no contorno", Q_NULLPTR));
        chkTempoQuadrantes->setText(QApplication::translate("MainWindow", "Tempo nos quadrantes", Q_NULLPTR));
        chkTempoBordas->setText(QApplication::translate("MainWindow", "Tempo nas bordas", Q_NULLPTR));
        chkLatencia->setText(QApplication::translate("MainWindow", "Lat\303\252ncia (s)", Q_NULLPTR));
        grpVideo->setTitle(QApplication::translate("MainWindow", "V\303\255deo", Q_NULLPTR));
        chkVideoEmCores->setText(QApplication::translate("MainWindow", "Colorido", Q_NULLPTR));
        chkInverterImagem->setText(QApplication::translate("MainWindow", "Invertido", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "Resolu\303\247\303\243o", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Intervalo entre testes", Q_NULLPTR));
        cboIntervalo->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", Q_NULLPTR));
        chkRastrearAuto_3->setText(QApplication::translate("MainWindow", "Rastrear na reprodu\303\247\303\243o", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabConfig), QApplication::translate("MainWindow", "Configura\303\247\303\265es", Q_NULLPTR));
        plainTextEdit->setPlainText(QApplication::translate("MainWindow", "Projeto Expt-o Morris v.170526.0.1 (Beta)", Q_NULLPTR));
        plainTextEdit_2->setPlainText(QApplication::translate("MainWindow", "Software desenvolvido como requisito parcial no Mestrado em Biotecnologia da Universidade Positivo.\n"
"\n"
"Orientador Prof. Dr. Ilton Santos da Silva\n"
"Mestrando e desenvolvedor Geucimar Brilhador", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabSobre), QApplication::translate("MainWindow", "Sobre", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
