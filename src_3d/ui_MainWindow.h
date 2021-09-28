/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>
#include <widget/ClusteringWidget.h>
#include <widget/TrackingWidget.h>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionError;
    QAction *actionWarning;
    QAction *actionInfo;
    QAction *actionDebug;
    QAction *actionUse_simulation;
    QAction *actionDepthImgDefault_mode;
    QAction *actionDepthImgSXGA_15Hz;
    QAction *actionDepthImgVGA_30Hz;
    QAction *actionDepthImgVGA_25Hz;
    QAction *actionDepthImgQVGA_25_Hz;
    QAction *actionDepthImgQVGA_30Hz;
    QAction *actionDepthImgQQVGA_60Hz;
    QAction *actionDepthImgQQVGA_30Hz;
    QAction *actionImageDefault_mode;
    QAction *actionImageSXGA_15Hz;
    QAction *actionImageVGA_30Hz;
    QAction *actionImageVGA_25Hz;
    QAction *actionImageQVGA_25Hz;
    QAction *actionImageQVGA_30Hz;
    QAction *actionImageQVGA_60Hz;
    QAction *actionImageQQVGA_25Hz;
    QAction *actionImageQQVGA_30Hz;
    QAction *actionImageQQVGA_60Hz;
    QAction *actionDepthImgQVGA_60Hz;
    QAction *actionDepthImgQQVGA_25Hz;
    QWidget *tabMain;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QTabWidget *maintab;
    TrackingWidget *tracking;
    ClusteringWidget *clustering;
    QWidget *recognition;
    QMenuBar *menuBar;
    QMenu *menu3D_Camera;
    QMenu *menuCamera_settings;
    QMenu *menuDepthImgMode;
    QMenu *menuImage_mode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1000, 750);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QFont font;
        font.setPointSize(10);
        actionExit->setFont(font);
        actionError = new QAction(MainWindow);
        actionError->setObjectName(QStringLiteral("actionError"));
        actionWarning = new QAction(MainWindow);
        actionWarning->setObjectName(QStringLiteral("actionWarning"));
        actionInfo = new QAction(MainWindow);
        actionInfo->setObjectName(QStringLiteral("actionInfo"));
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QStringLiteral("actionDebug"));
        actionUse_simulation = new QAction(MainWindow);
        actionUse_simulation->setObjectName(QStringLiteral("actionUse_simulation"));
        actionUse_simulation->setCheckable(true);
        actionUse_simulation->setChecked(true);
        actionDepthImgDefault_mode = new QAction(MainWindow);
        actionDepthImgDefault_mode->setObjectName(QStringLiteral("actionDepthImgDefault_mode"));
        actionDepthImgDefault_mode->setCheckable(true);
        actionDepthImgDefault_mode->setChecked(true);
        actionDepthImgSXGA_15Hz = new QAction(MainWindow);
        actionDepthImgSXGA_15Hz->setObjectName(QStringLiteral("actionDepthImgSXGA_15Hz"));
        actionDepthImgSXGA_15Hz->setCheckable(true);
        actionDepthImgVGA_30Hz = new QAction(MainWindow);
        actionDepthImgVGA_30Hz->setObjectName(QStringLiteral("actionDepthImgVGA_30Hz"));
        actionDepthImgVGA_30Hz->setCheckable(true);
        actionDepthImgVGA_25Hz = new QAction(MainWindow);
        actionDepthImgVGA_25Hz->setObjectName(QStringLiteral("actionDepthImgVGA_25Hz"));
        actionDepthImgVGA_25Hz->setCheckable(true);
        actionDepthImgQVGA_25_Hz = new QAction(MainWindow);
        actionDepthImgQVGA_25_Hz->setObjectName(QStringLiteral("actionDepthImgQVGA_25_Hz"));
        actionDepthImgQVGA_25_Hz->setCheckable(true);
        actionDepthImgQVGA_30Hz = new QAction(MainWindow);
        actionDepthImgQVGA_30Hz->setObjectName(QStringLiteral("actionDepthImgQVGA_30Hz"));
        actionDepthImgQVGA_30Hz->setCheckable(true);
        actionDepthImgQQVGA_60Hz = new QAction(MainWindow);
        actionDepthImgQQVGA_60Hz->setObjectName(QStringLiteral("actionDepthImgQQVGA_60Hz"));
        actionDepthImgQQVGA_60Hz->setCheckable(true);
        actionDepthImgQQVGA_30Hz = new QAction(MainWindow);
        actionDepthImgQQVGA_30Hz->setObjectName(QStringLiteral("actionDepthImgQQVGA_30Hz"));
        actionDepthImgQQVGA_30Hz->setCheckable(true);
        actionImageDefault_mode = new QAction(MainWindow);
        actionImageDefault_mode->setObjectName(QStringLiteral("actionImageDefault_mode"));
        actionImageDefault_mode->setCheckable(true);
        actionImageDefault_mode->setChecked(true);
        actionImageSXGA_15Hz = new QAction(MainWindow);
        actionImageSXGA_15Hz->setObjectName(QStringLiteral("actionImageSXGA_15Hz"));
        actionImageSXGA_15Hz->setCheckable(true);
        actionImageVGA_30Hz = new QAction(MainWindow);
        actionImageVGA_30Hz->setObjectName(QStringLiteral("actionImageVGA_30Hz"));
        actionImageVGA_30Hz->setCheckable(true);
        actionImageVGA_25Hz = new QAction(MainWindow);
        actionImageVGA_25Hz->setObjectName(QStringLiteral("actionImageVGA_25Hz"));
        actionImageVGA_25Hz->setCheckable(true);
        actionImageQVGA_25Hz = new QAction(MainWindow);
        actionImageQVGA_25Hz->setObjectName(QStringLiteral("actionImageQVGA_25Hz"));
        actionImageQVGA_25Hz->setCheckable(true);
        actionImageQVGA_30Hz = new QAction(MainWindow);
        actionImageQVGA_30Hz->setObjectName(QStringLiteral("actionImageQVGA_30Hz"));
        actionImageQVGA_30Hz->setCheckable(true);
        actionImageQVGA_60Hz = new QAction(MainWindow);
        actionImageQVGA_60Hz->setObjectName(QStringLiteral("actionImageQVGA_60Hz"));
        actionImageQVGA_60Hz->setCheckable(true);
        actionImageQQVGA_25Hz = new QAction(MainWindow);
        actionImageQQVGA_25Hz->setObjectName(QStringLiteral("actionImageQQVGA_25Hz"));
        actionImageQQVGA_25Hz->setCheckable(true);
        actionImageQQVGA_30Hz = new QAction(MainWindow);
        actionImageQQVGA_30Hz->setObjectName(QStringLiteral("actionImageQQVGA_30Hz"));
        actionImageQQVGA_30Hz->setCheckable(true);
        actionImageQQVGA_60Hz = new QAction(MainWindow);
        actionImageQQVGA_60Hz->setObjectName(QStringLiteral("actionImageQQVGA_60Hz"));
        actionImageQQVGA_60Hz->setCheckable(true);
        actionDepthImgQVGA_60Hz = new QAction(MainWindow);
        actionDepthImgQVGA_60Hz->setObjectName(QStringLiteral("actionDepthImgQVGA_60Hz"));
        actionDepthImgQVGA_60Hz->setCheckable(true);
        actionDepthImgQQVGA_25Hz = new QAction(MainWindow);
        actionDepthImgQQVGA_25Hz->setObjectName(QStringLiteral("actionDepthImgQQVGA_25Hz"));
        actionDepthImgQQVGA_25Hz->setCheckable(true);
        tabMain = new QWidget(MainWindow);
        tabMain->setObjectName(QStringLiteral("tabMain"));
        horizontalLayout_2 = new QHBoxLayout(tabMain);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        maintab = new QTabWidget(tabMain);
        maintab->setObjectName(QStringLiteral("maintab"));
        maintab->setFont(font);
        tracking = new TrackingWidget();
        tracking->setObjectName(QStringLiteral("tracking"));
        maintab->addTab(tracking, QString());
        clustering = new ClusteringWidget();
        clustering->setObjectName(QStringLiteral("clustering"));
        maintab->addTab(clustering, QString());
        recognition = new QWidget();
        recognition->setObjectName(QStringLiteral("recognition"));
        recognition->setContextMenuPolicy(Qt::NoContextMenu);
        maintab->addTab(recognition, QString());

        horizontalLayout->addWidget(maintab);


        horizontalLayout_2->addLayout(horizontalLayout);

        MainWindow->setCentralWidget(tabMain);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1000, 31));
        menu3D_Camera = new QMenu(menuBar);
        menu3D_Camera->setObjectName(QStringLiteral("menu3D_Camera"));
        menuCamera_settings = new QMenu(menuBar);
        menuCamera_settings->setObjectName(QStringLiteral("menuCamera_settings"));
        menuDepthImgMode = new QMenu(menuCamera_settings);
        menuDepthImgMode->setObjectName(QStringLiteral("menuDepthImgMode"));
        menuImage_mode = new QMenu(menuCamera_settings);
        menuImage_mode->setObjectName(QStringLiteral("menuImage_mode"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu3D_Camera->menuAction());
        menuBar->addAction(menuCamera_settings->menuAction());
        menu3D_Camera->addAction(actionExit);
        menuCamera_settings->addAction(actionUse_simulation);
        menuCamera_settings->addAction(menuDepthImgMode->menuAction());
        menuCamera_settings->addAction(menuImage_mode->menuAction());
        menuDepthImgMode->addAction(actionDepthImgDefault_mode);
        menuDepthImgMode->addAction(actionDepthImgSXGA_15Hz);
        menuDepthImgMode->addAction(actionDepthImgVGA_30Hz);
        menuDepthImgMode->addAction(actionDepthImgVGA_25Hz);
        menuDepthImgMode->addAction(actionDepthImgQVGA_25_Hz);
        menuDepthImgMode->addAction(actionDepthImgQVGA_30Hz);
        menuDepthImgMode->addAction(actionDepthImgQVGA_60Hz);
        menuDepthImgMode->addAction(actionDepthImgQQVGA_25Hz);
        menuDepthImgMode->addAction(actionDepthImgQQVGA_30Hz);
        menuDepthImgMode->addAction(actionDepthImgQQVGA_60Hz);
        menuImage_mode->addAction(actionImageDefault_mode);
        menuImage_mode->addAction(actionImageSXGA_15Hz);
        menuImage_mode->addAction(actionImageVGA_30Hz);
        menuImage_mode->addAction(actionImageVGA_25Hz);
        menuImage_mode->addAction(actionImageQVGA_25Hz);
        menuImage_mode->addAction(actionImageQVGA_30Hz);
        menuImage_mode->addAction(actionImageQVGA_60Hz);
        menuImage_mode->addAction(actionImageQQVGA_25Hz);
        menuImage_mode->addAction(actionImageQQVGA_30Hz);
        menuImage_mode->addAction(actionImageQQVGA_60Hz);

        retranslateUi(MainWindow);

        maintab->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Expt-o 3D", nullptr));
        actionExit->setText(QApplication::translate("MainWindow", "Sair", nullptr));
        actionError->setText(QApplication::translate("MainWindow", "Error", nullptr));
        actionWarning->setText(QApplication::translate("MainWindow", "Warning", nullptr));
        actionInfo->setText(QApplication::translate("MainWindow", "Info", nullptr));
        actionDebug->setText(QApplication::translate("MainWindow", "Debug", nullptr));
        actionUse_simulation->setText(QApplication::translate("MainWindow", "Use simulation", nullptr));
        actionDepthImgDefault_mode->setText(QApplication::translate("MainWindow", "Default mode", nullptr));
        actionDepthImgSXGA_15Hz->setText(QApplication::translate("MainWindow", "SXGA 15Hz", nullptr));
        actionDepthImgVGA_30Hz->setText(QApplication::translate("MainWindow", "VGA 30Hz", nullptr));
        actionDepthImgVGA_25Hz->setText(QApplication::translate("MainWindow", "VGA 25Hz", nullptr));
        actionDepthImgQVGA_25_Hz->setText(QApplication::translate("MainWindow", "QVGA 25Hz", nullptr));
        actionDepthImgQVGA_30Hz->setText(QApplication::translate("MainWindow", "QVGA 30Hz", nullptr));
        actionDepthImgQQVGA_60Hz->setText(QApplication::translate("MainWindow", "QQVGA 60Hz", nullptr));
        actionDepthImgQQVGA_30Hz->setText(QApplication::translate("MainWindow", "QQVGA 30Hz", nullptr));
        actionImageDefault_mode->setText(QApplication::translate("MainWindow", "Default mode", nullptr));
        actionImageSXGA_15Hz->setText(QApplication::translate("MainWindow", "SXGA 15Hz", nullptr));
        actionImageVGA_30Hz->setText(QApplication::translate("MainWindow", "VGA 30Hz", nullptr));
        actionImageVGA_25Hz->setText(QApplication::translate("MainWindow", "VGA 25Hz", nullptr));
        actionImageQVGA_25Hz->setText(QApplication::translate("MainWindow", "QVGA 25Hz", nullptr));
        actionImageQVGA_30Hz->setText(QApplication::translate("MainWindow", "QVGA 30Hz", nullptr));
        actionImageQVGA_60Hz->setText(QApplication::translate("MainWindow", "QVGA 60Hz", nullptr));
        actionImageQQVGA_25Hz->setText(QApplication::translate("MainWindow", "QQVGA 25Hz", nullptr));
        actionImageQQVGA_30Hz->setText(QApplication::translate("MainWindow", "QQVGA 30Hz", nullptr));
        actionImageQQVGA_60Hz->setText(QApplication::translate("MainWindow", "QQVGA 60Hz", nullptr));
        actionDepthImgQVGA_60Hz->setText(QApplication::translate("MainWindow", "QVGA 60Hz", nullptr));
        actionDepthImgQQVGA_25Hz->setText(QApplication::translate("MainWindow", "QQVGA 25Hz", nullptr));
        maintab->setTabText(maintab->indexOf(tracking), QApplication::translate("MainWindow", "Rastreamento", nullptr));
        maintab->setTabText(maintab->indexOf(clustering), QApplication::translate("MainWindow", "Segmenta\303\247\303\243o", nullptr));
        maintab->setTabText(maintab->indexOf(recognition), QApplication::translate("MainWindow", "Reconhecimento", nullptr));
        menu3D_Camera->setTitle(QApplication::translate("MainWindow", "Principal", nullptr));
        menuCamera_settings->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\243o", nullptr));
        menuDepthImgMode->setTitle(QApplication::translate("MainWindow", "Depth image mode", nullptr));
        menuImage_mode->setTitle(QApplication::translate("MainWindow", "Image mode", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
