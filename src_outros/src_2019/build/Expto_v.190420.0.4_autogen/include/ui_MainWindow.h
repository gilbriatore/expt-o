/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <ArenaView.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QTabWidget *tabViewPrincipal;
    QWidget *tabCaptura;
    QGridLayout *gridLayout_3;
    QFrame *frmCapturar;
    QLabel *lblFPS;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblLatencia;
    QLCDNumber *displayLatencia;
    QLabel *lblDistancia;
    QLCDNumber *displayDistancia;
    QLabel *lblVelocidade;
    QLCDNumber *displayVelocidade;
    QSpacerItem *verticalSpacer;
    QLabel *lblId;
    QFrame *frame;
    QGridLayout *gridLayout;
    QTextEdit *txtIdentificacao;
    QPushButton *btnCapturar;
    QCheckBox *chkGravar;
    ArenaView *viewCaptura;
    QWidget *tabArena;
    QGridLayout *gridLayout_6;
    QFrame *frmCapturar_2;
    QLabel *lblFPS_2;
    QGroupBox *groupBox_4;
    QRadioButton *rdbNO;
    QRadioButton *rdbNE;
    QRadioButton *rdbSO;
    QRadioButton *rdbSE;
    QFrame *line;
    QFrame *line_2;
    QLabel *lblFPSIR_15;
    QLabel *lblFPSIR_16;
    QLabel *lblFPSIR_17;
    QLabel *lblFPSIR_18;
    QLabel *lblFPSIR_9;
    QSlider *sliderCirculoY;
    QSlider *sliderCirculoPlay;
    QSlider *sliderCirculoX;
    QLabel *lblFPSIR_11;
    QLabel *lblFPSIR_14;
    ArenaView *viewArena;
    QWidget *horizontalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *btnSelecionar;
    QPushButton *btnArena;
    QPushButton *btnPlataforma;
    QPushButton *btnSalvarArena;
    QWidget *tabDeteccao;
    QLabel *lblPrimeira;
    QLabel *lblSegunda;
    QLabel *lblTerceira;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *layFiltrosHSV;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *layFiltrosRGB;
    QWidget *verticalLayoutWidget_5;
    QVBoxLayout *layFiltrosContraste;
    ArenaView *vPrimeira;
    ArenaView *vSegunda;
    ArenaView *vTerceira;
    QWidget *tabHistorico;
    QGridLayout *gridLayout_4;
    QFrame *frmHistorico;
    QTableView *tableView;
    QWidget *tabConfig;
    QCheckBox *chkInvertido;
    QCheckBox *chkInvertido_2;
    QCheckBox *chkInvertido_3;
    QCheckBox *chkTrack;
    QCheckBox *chkPararAuto;
    QGroupBox *grpFormato;
    QRadioButton *rdb2Dinfra;
    QRadioButton *rdb3Dcinza;
    QRadioButton *rdb2Dcinza;
    QTimeEdit *cboTimerPlay;
    QTimeEdit *cboTimerLimite;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QWidget *tab;

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
        tabCaptura = new QWidget();
        tabCaptura->setObjectName(QStringLiteral("tabCaptura"));
        gridLayout_3 = new QGridLayout(tabCaptura);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        frmCapturar = new QFrame(tabCaptura);
        frmCapturar->setObjectName(QStringLiteral("frmCapturar"));
        frmCapturar->setMinimumSize(QSize(640, 530));
        frmCapturar->setMaximumSize(QSize(913, 530));
        frmCapturar->setAutoFillBackground(false);
        frmCapturar->setStyleSheet(QStringLiteral(""));
        frmCapturar->setFrameShape(QFrame::StyledPanel);
        frmCapturar->setFrameShadow(QFrame::Raised);
        lblFPS = new QLabel(frmCapturar);
        lblFPS->setObjectName(QStringLiteral("lblFPS"));
        lblFPS->setGeometry(QRect(540, 489, 89, 34));
        QFont font1;
        font1.setPointSize(14);
        lblFPS->setFont(font1);
        lblFPS->setAlignment(Qt::AlignCenter);
        verticalLayoutWidget_3 = new QWidget(frmCapturar);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(670, 0, 243, 549));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lblLatencia = new QLabel(verticalLayoutWidget_3);
        lblLatencia->setObjectName(QStringLiteral("lblLatencia"));
        lblLatencia->setMaximumSize(QSize(16777215, 20));
        QFont font2;
        font2.setPointSize(12);
        lblLatencia->setFont(font2);

        verticalLayout_2->addWidget(lblLatencia);

        displayLatencia = new QLCDNumber(verticalLayoutWidget_3);
        displayLatencia->setObjectName(QStringLiteral("displayLatencia"));
        displayLatencia->setMinimumSize(QSize(240, 70));
        displayLatencia->setMaximumSize(QSize(240, 80));
        displayLatencia->setFrameShape(QFrame::Box);
        displayLatencia->setFrameShadow(QFrame::Raised);
        displayLatencia->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_2->addWidget(displayLatencia);

        lblDistancia = new QLabel(verticalLayoutWidget_3);
        lblDistancia->setObjectName(QStringLiteral("lblDistancia"));
        lblDistancia->setMaximumSize(QSize(16777215, 20));
        lblDistancia->setFont(font2);

        verticalLayout_2->addWidget(lblDistancia);

        displayDistancia = new QLCDNumber(verticalLayoutWidget_3);
        displayDistancia->setObjectName(QStringLiteral("displayDistancia"));
        displayDistancia->setMinimumSize(QSize(240, 70));
        displayDistancia->setMaximumSize(QSize(240, 80));
        displayDistancia->setFrameShape(QFrame::Box);
        displayDistancia->setFrameShadow(QFrame::Raised);
        displayDistancia->setDigitCount(5);
        displayDistancia->setSegmentStyle(QLCDNumber::Filled);

        verticalLayout_2->addWidget(displayDistancia);

        lblVelocidade = new QLabel(verticalLayoutWidget_3);
        lblVelocidade->setObjectName(QStringLiteral("lblVelocidade"));
        lblVelocidade->setMaximumSize(QSize(16777215, 20));
        lblVelocidade->setFont(font2);

        verticalLayout_2->addWidget(lblVelocidade);

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

        verticalLayout_2->addWidget(displayVelocidade);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        lblId = new QLabel(verticalLayoutWidget_3);
        lblId->setObjectName(QStringLiteral("lblId"));
        lblId->setFont(font2);

        verticalLayout_2->addWidget(lblId);

        frame = new QFrame(verticalLayoutWidget_3);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(240, 0));
        frame->setMaximumSize(QSize(240, 60));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QLatin1String("QFrame {\n"
"    border: 1px solid gray;\n"
"    background-color: white;\n"
"}"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(frame);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, 12, -1, 0);
        txtIdentificacao = new QTextEdit(frame);
        txtIdentificacao->setObjectName(QStringLiteral("txtIdentificacao"));
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

        gridLayout->addWidget(txtIdentificacao, 0, 0, 1, 1);


        verticalLayout_2->addWidget(frame);

        btnCapturar = new QPushButton(verticalLayoutWidget_3);
        btnCapturar->setObjectName(QStringLiteral("btnCapturar"));
        btnCapturar->setMinimumSize(QSize(240, 70));
        btnCapturar->setMaximumSize(QSize(240, 16777215));
        QFont font4;
        font4.setPointSize(12);
        font4.setBold(true);
        font4.setWeight(75);
        btnCapturar->setFont(font4);

        verticalLayout_2->addWidget(btnCapturar);

        chkGravar = new QCheckBox(verticalLayoutWidget_3);
        chkGravar->setObjectName(QStringLiteral("chkGravar"));
        chkGravar->setFont(font);

        verticalLayout_2->addWidget(chkGravar);

        viewCaptura = new ArenaView(frmCapturar);
        viewCaptura->setObjectName(QStringLiteral("viewCaptura"));
        viewCaptura->setGeometry(QRect(0, 0, 640, 530));
        viewCaptura->setMinimumSize(QSize(640, 530));
        viewCaptura->setMaximumSize(QSize(640, 530));
        viewCaptura->setBaseSize(QSize(640, 530));
        viewCaptura->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        viewCaptura->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        viewCaptura->raise();
        lblFPS->raise();
        verticalLayoutWidget_3->raise();

        gridLayout_3->addWidget(frmCapturar, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabCaptura, QString());
        tabArena = new QWidget();
        tabArena->setObjectName(QStringLiteral("tabArena"));
        gridLayout_6 = new QGridLayout(tabArena);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        frmCapturar_2 = new QFrame(tabArena);
        frmCapturar_2->setObjectName(QStringLiteral("frmCapturar_2"));
        frmCapturar_2->setMinimumSize(QSize(640, 530));
        frmCapturar_2->setMaximumSize(QSize(913, 530));
        frmCapturar_2->setAutoFillBackground(false);
        frmCapturar_2->setStyleSheet(QStringLiteral(""));
        frmCapturar_2->setFrameShape(QFrame::StyledPanel);
        frmCapturar_2->setFrameShadow(QFrame::Raised);
        lblFPS_2 = new QLabel(frmCapturar_2);
        lblFPS_2->setObjectName(QStringLiteral("lblFPS_2"));
        lblFPS_2->setGeometry(QRect(540, 489, 89, 34));
        lblFPS_2->setFont(font1);
        lblFPS_2->setAlignment(Qt::AlignCenter);
        groupBox_4 = new QGroupBox(frmCapturar_2);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(673, 298, 196, 176));
        groupBox_4->setFont(font2);
        rdbNO = new QRadioButton(groupBox_4);
        rdbNO->setObjectName(QStringLiteral("rdbNO"));
        rdbNO->setGeometry(QRect(65, 70, 18, 17));
        rdbNO->setChecked(true);
        rdbNE = new QRadioButton(groupBox_4);
        rdbNE->setObjectName(QStringLiteral("rdbNE"));
        rdbNE->setGeometry(QRect(112, 70, 18, 17));
        rdbSO = new QRadioButton(groupBox_4);
        rdbSO->setObjectName(QStringLiteral("rdbSO"));
        rdbSO->setGeometry(QRect(64, 107, 18, 17));
        rdbSE = new QRadioButton(groupBox_4);
        rdbSE->setObjectName(QStringLiteral("rdbSE"));
        rdbSE->setGeometry(QRect(111, 108, 18, 17));
        line = new QFrame(groupBox_4);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(90, 50, 16, 105));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(groupBox_4);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setGeometry(QRect(41, 90, 126, 16));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);
        lblFPSIR_15 = new QLabel(groupBox_4);
        lblFPSIR_15->setObjectName(QStringLiteral("lblFPSIR_15"));
        lblFPSIR_15->setGeometry(QRect(63, 45, 23, 27));
        lblFPSIR_15->setFont(font);
        lblFPSIR_16 = new QLabel(groupBox_4);
        lblFPSIR_16->setObjectName(QStringLiteral("lblFPSIR_16"));
        lblFPSIR_16->setGeometry(QRect(111, 45, 23, 27));
        lblFPSIR_16->setFont(font);
        lblFPSIR_17 = new QLabel(groupBox_4);
        lblFPSIR_17->setObjectName(QStringLiteral("lblFPSIR_17"));
        lblFPSIR_17->setGeometry(QRect(62, 119, 23, 27));
        lblFPSIR_17->setFont(font);
        lblFPSIR_18 = new QLabel(groupBox_4);
        lblFPSIR_18->setObjectName(QStringLiteral("lblFPSIR_18"));
        lblFPSIR_18->setGeometry(QRect(110, 119, 23, 27));
        lblFPSIR_18->setFont(font);
        lblFPSIR_9 = new QLabel(frmCapturar_2);
        lblFPSIR_9->setObjectName(QStringLiteral("lblFPSIR_9"));
        lblFPSIR_9->setGeometry(QRect(681, 52, 64, 27));
        QFont font5;
        font5.setPointSize(10);
        font5.setBold(true);
        font5.setWeight(75);
        lblFPSIR_9->setFont(font5);
        sliderCirculoY = new QSlider(frmCapturar_2);
        sliderCirculoY->setObjectName(QStringLiteral("sliderCirculoY"));
        sliderCirculoY->setGeometry(QRect(679, 217, 194, 22));
        sliderCirculoY->setMinimum(0);
        sliderCirculoY->setMaximum(424);
        sliderCirculoY->setSingleStep(10);
        sliderCirculoY->setPageStep(1);
        sliderCirculoY->setValue(208);
        sliderCirculoY->setSliderPosition(208);
        sliderCirculoY->setOrientation(Qt::Horizontal);
        sliderCirculoPlay = new QSlider(frmCapturar_2);
        sliderCirculoPlay->setObjectName(QStringLiteral("sliderCirculoPlay"));
        sliderCirculoPlay->setGeometry(QRect(681, 89, 189, 22));
        sliderCirculoPlay->setMinimum(100);
        sliderCirculoPlay->setMaximum(212);
        sliderCirculoPlay->setValue(180);
        sliderCirculoPlay->setSliderPosition(180);
        sliderCirculoPlay->setOrientation(Qt::Horizontal);
        sliderCirculoX = new QSlider(frmCapturar_2);
        sliderCirculoX->setObjectName(QStringLiteral("sliderCirculoX"));
        sliderCirculoX->setGeometry(QRect(681, 154, 190, 22));
        sliderCirculoX->setMinimum(0);
        sliderCirculoX->setMaximum(512);
        sliderCirculoX->setSingleStep(10);
        sliderCirculoX->setPageStep(1);
        sliderCirculoX->setValue(250);
        sliderCirculoX->setSliderPosition(250);
        sliderCirculoX->setOrientation(Qt::Horizontal);
        lblFPSIR_11 = new QLabel(frmCapturar_2);
        lblFPSIR_11->setObjectName(QStringLiteral("lblFPSIR_11"));
        lblFPSIR_11->setGeometry(QRect(680, 119, 64, 27));
        lblFPSIR_11->setFont(font5);
        lblFPSIR_14 = new QLabel(frmCapturar_2);
        lblFPSIR_14->setObjectName(QStringLiteral("lblFPSIR_14"));
        lblFPSIR_14->setGeometry(QRect(680, 181, 64, 27));
        lblFPSIR_14->setFont(font5);
        viewArena = new ArenaView(frmCapturar_2);
        viewArena->setObjectName(QStringLiteral("viewArena"));
        viewArena->setGeometry(QRect(0, 0, 640, 530));
        viewArena->setMinimumSize(QSize(640, 530));
        viewArena->setMaximumSize(QSize(640, 530));
        viewArena->setBaseSize(QSize(640, 530));
        viewArena->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        viewArena->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        horizontalLayoutWidget = new QWidget(frmCapturar_2);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 47, 155));
        verticalLayout = new QVBoxLayout(horizontalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        btnSelecionar = new QPushButton(horizontalLayoutWidget);
        btnSelecionar->setObjectName(QStringLiteral("btnSelecionar"));
        btnSelecionar->setMinimumSize(QSize(45, 45));
        btnSelecionar->setMaximumSize(QSize(45, 45));
        btnSelecionar->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"   background-color: gray;\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/select.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnSelecionar->setIcon(icon);
        btnSelecionar->setIconSize(QSize(24, 24));
        btnSelecionar->setCheckable(true);
        btnSelecionar->setAutoExclusive(false);

        verticalLayout->addWidget(btnSelecionar);

        btnArena = new QPushButton(horizontalLayoutWidget);
        btnArena->setObjectName(QStringLiteral("btnArena"));
        btnArena->setMinimumSize(QSize(45, 45));
        btnArena->setMaximumSize(QSize(45, 45));
        btnArena->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"   background-color: gray;\n"
"}"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/icons/arena.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnArena->setIcon(icon1);
        btnArena->setIconSize(QSize(36, 36));
        btnArena->setCheckable(true);
        btnArena->setAutoExclusive(false);

        verticalLayout->addWidget(btnArena);

        btnPlataforma = new QPushButton(horizontalLayoutWidget);
        btnPlataforma->setObjectName(QStringLiteral("btnPlataforma"));
        btnPlataforma->setMinimumSize(QSize(45, 45));
        btnPlataforma->setMaximumSize(QSize(45, 45));
        btnPlataforma->setStyleSheet(QLatin1String("QPushButton:checked\n"
"{\n"
"   background-color: gray;\n"
"}"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/icons/plataforma.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnPlataforma->setIcon(icon2);
        btnPlataforma->setIconSize(QSize(24, 24));
        btnPlataforma->setCheckable(true);
        btnPlataforma->setAutoExclusive(false);

        verticalLayout->addWidget(btnPlataforma);

        btnSalvarArena = new QPushButton(frmCapturar_2);
        btnSalvarArena->setObjectName(QStringLiteral("btnSalvarArena"));
        btnSalvarArena->setGeometry(QRect(673, 477, 164, 49));

        gridLayout_6->addWidget(frmCapturar_2, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabArena, QString());
        tabDeteccao = new QWidget();
        tabDeteccao->setObjectName(QStringLiteral("tabDeteccao"));
        lblPrimeira = new QLabel(tabDeteccao);
        lblPrimeira->setObjectName(QStringLiteral("lblPrimeira"));
        lblPrimeira->setGeometry(QRect(63, 26, 43, 16));
        lblPrimeira->setFont(font);
        lblSegunda = new QLabel(tabDeteccao);
        lblSegunda->setObjectName(QStringLiteral("lblSegunda"));
        lblSegunda->setGeometry(QRect(385, 26, 66, 16));
        lblSegunda->setFont(font);
        lblTerceira = new QLabel(tabDeteccao);
        lblTerceira->setObjectName(QStringLiteral("lblTerceira"));
        lblTerceira->setGeometry(QRect(716, 27, 43, 16));
        lblTerceira->setFont(font);
        verticalLayoutWidget = new QWidget(tabDeteccao);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(59, 280, 253, 227));
        layFiltrosHSV = new QVBoxLayout(verticalLayoutWidget);
        layFiltrosHSV->setObjectName(QStringLiteral("layFiltrosHSV"));
        layFiltrosHSV->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(tabDeteccao);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(716, 281, 253, 221));
        layFiltrosRGB = new QVBoxLayout(verticalLayoutWidget_2);
        layFiltrosRGB->setObjectName(QStringLiteral("layFiltrosRGB"));
        layFiltrosRGB->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_5 = new QWidget(tabDeteccao);
        verticalLayoutWidget_5->setObjectName(QStringLiteral("verticalLayoutWidget_5"));
        verticalLayoutWidget_5->setGeometry(QRect(57, 516, 254, 61));
        layFiltrosContraste = new QVBoxLayout(verticalLayoutWidget_5);
        layFiltrosContraste->setObjectName(QStringLiteral("layFiltrosContraste"));
        layFiltrosContraste->setContentsMargins(0, 0, 0, 0);
        vPrimeira = new ArenaView(tabDeteccao);
        vPrimeira->setObjectName(QStringLiteral("vPrimeira"));
        vPrimeira->setGeometry(QRect(60, 49, 256, 212));
        vPrimeira->setMinimumSize(QSize(256, 212));
        vPrimeira->setMaximumSize(QSize(256, 212));
        vPrimeira->setBaseSize(QSize(640, 530));
        vPrimeira->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vPrimeira->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vSegunda = new ArenaView(tabDeteccao);
        vSegunda->setObjectName(QStringLiteral("vSegunda"));
        vSegunda->setGeometry(QRect(383, 50, 256, 212));
        vSegunda->setMinimumSize(QSize(256, 212));
        vSegunda->setMaximumSize(QSize(256, 212));
        vSegunda->setBaseSize(QSize(640, 530));
        vSegunda->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vSegunda->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vTerceira = new ArenaView(tabDeteccao);
        vTerceira->setObjectName(QStringLiteral("vTerceira"));
        vTerceira->setGeometry(QRect(709, 47, 256, 212));
        vTerceira->setMinimumSize(QSize(256, 212));
        vTerceira->setMaximumSize(QSize(256, 212));
        vTerceira->setBaseSize(QSize(640, 530));
        vTerceira->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        vTerceira->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabViewPrincipal->addTab(tabDeteccao, QString());
        tabHistorico = new QWidget();
        tabHistorico->setObjectName(QStringLiteral("tabHistorico"));
        gridLayout_4 = new QGridLayout(tabHistorico);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        frmHistorico = new QFrame(tabHistorico);
        frmHistorico->setObjectName(QStringLiteral("frmHistorico"));
        frmHistorico->setMinimumSize(QSize(640, 530));
        frmHistorico->setMaximumSize(QSize(913, 530));
        frmHistorico->setAutoFillBackground(true);
        frmHistorico->setStyleSheet(QStringLiteral(""));
        frmHistorico->setFrameShape(QFrame::StyledPanel);
        frmHistorico->setFrameShadow(QFrame::Raised);
        tableView = new QTableView(frmHistorico);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(652, 5, 188, 361));

        gridLayout_4->addWidget(frmHistorico, 0, 0, 1, 1);

        tabViewPrincipal->addTab(tabHistorico, QString());
        tabConfig = new QWidget();
        tabConfig->setObjectName(QStringLiteral("tabConfig"));
        chkInvertido = new QCheckBox(tabConfig);
        chkInvertido->setObjectName(QStringLiteral("chkInvertido"));
        chkInvertido->setGeometry(QRect(264, 53, 183, 17));
        chkInvertido->setFont(font2);
        chkInvertido->setChecked(false);
        chkInvertido_2 = new QCheckBox(tabConfig);
        chkInvertido_2->setObjectName(QStringLiteral("chkInvertido_2"));
        chkInvertido_2->setGeometry(QRect(264, 83, 284, 17));
        chkInvertido_2->setFont(font2);
        chkInvertido_2->setChecked(false);
        chkInvertido_3 = new QCheckBox(tabConfig);
        chkInvertido_3->setObjectName(QStringLiteral("chkInvertido_3"));
        chkInvertido_3->setGeometry(QRect(264, 113, 282, 17));
        chkInvertido_3->setFont(font2);
        chkInvertido_3->setChecked(false);
        chkTrack = new QCheckBox(tabConfig);
        chkTrack->setObjectName(QStringLiteral("chkTrack"));
        chkTrack->setGeometry(QRect(264, 140, 221, 23));
        chkTrack->setFont(font2);
        chkPararAuto = new QCheckBox(tabConfig);
        chkPararAuto->setObjectName(QStringLiteral("chkPararAuto"));
        chkPararAuto->setGeometry(QRect(621, 32, 221, 23));
        chkPararAuto->setFont(font2);
        chkPararAuto->setChecked(true);
        grpFormato = new QGroupBox(tabConfig);
        grpFormato->setObjectName(QStringLiteral("grpFormato"));
        grpFormato->setGeometry(QRect(273, 189, 221, 200));
        grpFormato->setMaximumSize(QSize(16777215, 200));
        grpFormato->setBaseSize(QSize(0, 0));
        grpFormato->setFont(font2);
        rdb2Dinfra = new QRadioButton(grpFormato);
        rdb2Dinfra->setObjectName(QStringLiteral("rdb2Dinfra"));
        rdb2Dinfra->setGeometry(QRect(26, 74, 84, 27));
        rdb2Dinfra->setFont(font2);
        rdb3Dcinza = new QRadioButton(grpFormato);
        rdb3Dcinza->setObjectName(QStringLiteral("rdb3Dcinza"));
        rdb3Dcinza->setGeometry(QRect(25, 111, 102, 27));
        rdb3Dcinza->setFont(font2);
        rdb2Dcinza = new QRadioButton(grpFormato);
        rdb2Dcinza->setObjectName(QStringLiteral("rdb2Dcinza"));
        rdb2Dcinza->setGeometry(QRect(26, 36, 105, 27));
        rdb2Dcinza->setFont(font2);
        rdb2Dcinza->setChecked(true);
        cboTimerPlay = new QTimeEdit(tabConfig);
        cboTimerPlay->setObjectName(QStringLiteral("cboTimerPlay"));
        cboTimerPlay->setGeometry(QRect(749, 96, 85, 40));
        cboTimerPlay->setMinimumSize(QSize(0, 40));
        cboTimerPlay->setFont(font1);
        cboTimerPlay->setAlignment(Qt::AlignCenter);
        cboTimerPlay->setTime(QTime(0, 2, 0));
        cboTimerLimite = new QTimeEdit(tabConfig);
        cboTimerLimite->setObjectName(QStringLiteral("cboTimerLimite"));
        cboTimerLimite->setGeometry(QRect(639, 97, 86, 40));
        cboTimerLimite->setMinimumSize(QSize(0, 40));
        cboTimerLimite->setFont(font1);
        cboTimerLimite->setAlignment(Qt::AlignCenter);
        cboTimerLimite->setTime(QTime(0, 0, 3));
        label = new QLabel(tabConfig);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(638, 61, 172, 28));
        label->setFont(font2);
        label_2 = new QLabel(tabConfig);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(101, 454, 853, 53));
        QFont font6;
        font6.setPointSize(18);
        label_2->setFont(font6);
        label_3 = new QLabel(tabConfig);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(98, 405, 169, 53));
        QFont font7;
        font7.setPointSize(24);
        label_3->setFont(font7);
        label_4 = new QLabel(tabConfig);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 497, 829, 53));
        label_4->setFont(font6);
        label_5 = new QLabel(tabConfig);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(96, 587, 829, 53));
        label_5->setFont(font6);
        label_6 = new QLabel(tabConfig);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(99, 554, 169, 53));
        label_6->setFont(font7);
        tabViewPrincipal->addTab(tabConfig, QString());
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        tabViewPrincipal->addTab(tab, QString());

        gridLayout_2->addWidget(tabViewPrincipal, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabViewPrincipal->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Expt-o Morris v.190420.0.4 (Beta)", Q_NULLPTR));
        lblFPS->setText(QApplication::translate("MainWindow", "FPS 29", Q_NULLPTR));
        lblLatencia->setText(QApplication::translate("MainWindow", "Lat\303\252ncia (s)", Q_NULLPTR));
        lblDistancia->setText(QApplication::translate("MainWindow", "Dist\303\242ncia (cm)", Q_NULLPTR));
        lblVelocidade->setText(QApplication::translate("MainWindow", "Velocidade (m/s)", Q_NULLPTR));
        lblId->setText(QApplication::translate("MainWindow", "Identifica\303\247\303\243o", Q_NULLPTR));
        btnCapturar->setText(QApplication::translate("MainWindow", "Capturar", Q_NULLPTR));
        chkGravar->setText(QApplication::translate("MainWindow", "Gravar v\303\255deo", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabCaptura), QApplication::translate("MainWindow", "Rastreamento", Q_NULLPTR));
        lblFPS_2->setText(QApplication::translate("MainWindow", "FPS 29", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "Quadrante", Q_NULLPTR));
        rdbNO->setText(QString());
        rdbNE->setText(QString());
        rdbSO->setText(QString());
        rdbSE->setText(QString());
        lblFPSIR_15->setText(QApplication::translate("MainWindow", "NO", Q_NULLPTR));
        lblFPSIR_16->setText(QApplication::translate("MainWindow", "NE", Q_NULLPTR));
        lblFPSIR_17->setText(QApplication::translate("MainWindow", "SO", Q_NULLPTR));
        lblFPSIR_18->setText(QApplication::translate("MainWindow", "SE", Q_NULLPTR));
        lblFPSIR_9->setText(QApplication::translate("MainWindow", "Di\303\242metro", Q_NULLPTR));
        lblFPSIR_11->setText(QApplication::translate("MainWindow", "Eixo X", Q_NULLPTR));
        lblFPSIR_14->setText(QApplication::translate("MainWindow", "Eixo Y", Q_NULLPTR));
        btnSelecionar->setText(QString());
        btnArena->setText(QString());
        btnPlataforma->setText(QString());
        btnSalvarArena->setText(QApplication::translate("MainWindow", "Salvar", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabArena), QApplication::translate("MainWindow", "Arena", Q_NULLPTR));
        lblPrimeira->setText(QApplication::translate("MainWindow", "Matiz", Q_NULLPTR));
        lblSegunda->setText(QApplication::translate("MainWindow", "Satura\303\247\303\243o", Q_NULLPTR));
        lblTerceira->setText(QApplication::translate("MainWindow", "Brilho", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabDeteccao), QApplication::translate("MainWindow", "Detec\303\247\303\243o", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabHistorico), QApplication::translate("MainWindow", "Hist\303\263rico", Q_NULLPTR));
        chkInvertido->setText(QApplication::translate("MainWindow", "Contraste invertido", Q_NULLPTR));
        chkInvertido_2->setText(QApplication::translate("MainWindow", "Mostrar v\303\255deo em cores na aquisi\303\247\303\243o", Q_NULLPTR));
        chkInvertido_3->setText(QApplication::translate("MainWindow", "Exibir hist\303\263rico de testes anterirores", Q_NULLPTR));
        chkTrack->setText(QApplication::translate("MainWindow", "Quantificar na grava\303\247\303\243o", Q_NULLPTR));
        chkPararAuto->setText(QApplication::translate("MainWindow", "Capturar automaticamente", Q_NULLPTR));
        grpFormato->setTitle(QApplication::translate("MainWindow", "Formato", Q_NULLPTR));
        rdb2Dinfra->setText(QApplication::translate("MainWindow", "2D (IR)", Q_NULLPTR));
        rdb3Dcinza->setText(QApplication::translate("MainWindow", "3D (cinza)", Q_NULLPTR));
        rdb2Dcinza->setText(QApplication::translate("MainWindow", "2D (cor)", Q_NULLPTR));
        cboTimerPlay->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", Q_NULLPTR));
        cboTimerLimite->setDisplayFormat(QApplication::translate("MainWindow", "mm:ss", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Limite inicial e dura\303\247\303\243o", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Definir 2. Contour Area e 4. Contour Approximation, evitar erro", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Usar m/s", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "http://docs.opencv.org/trunk/dd/d49/tutorial_py_contour_features.html", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "http://www.mathworks.com/help/images/ref/regionprops.html", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "Orientation", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tabConfig), QApplication::translate("MainWindow", "Configura\303\247\303\265es", Q_NULLPTR));
        tabViewPrincipal->setTabText(tabViewPrincipal->indexOf(tab), QApplication::translate("MainWindow", "Sobre", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
