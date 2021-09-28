/********************************************************************************
** Form generated from reading UI file 'TrackingWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRACKINGWIDGET_H
#define UI_TRACKINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <widget/FileWidget.h>
#include <widget/VideoQVTKOpenGLWidget.h>

QT_BEGIN_NAMESPACE

class Ui_TrackingWidget
{
public:
    QHBoxLayout *horizontalLayout;
    VideoQVTKOpenGLWidget *qvtkGLWidget;
    QVBoxLayout *verticalLayout;
    QFrame *frmCameraCmd;
    QVBoxLayout *verticalLayout_3;
    QLabel *title;
    QPushButton *btnStartCamera;
    QPushButton *btnStopCamera;
    QFrame *frmAcquisition;
    QVBoxLayout *verticalLayout_2;
    QLabel *lblAcquisition;
    QLabel *lblOutputFile;
    FileWidget *fileWidget;
    QPushButton *btnCapture;
    QCheckBox *chkDisableUpdates;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *TrackingWidget)
    {
        if (TrackingWidget->objectName().isEmpty())
            TrackingWidget->setObjectName(QStringLiteral("TrackingWidget"));
        TrackingWidget->resize(1277, 747);
        horizontalLayout = new QHBoxLayout(TrackingWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qvtkGLWidget = new VideoQVTKOpenGLWidget(TrackingWidget);
        qvtkGLWidget->setObjectName(QStringLiteral("qvtkGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkGLWidget->sizePolicy().hasHeightForWidth());
        qvtkGLWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(qvtkGLWidget);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        frmCameraCmd = new QFrame(TrackingWidget);
        frmCameraCmd->setObjectName(QStringLiteral("frmCameraCmd"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frmCameraCmd->sizePolicy().hasHeightForWidth());
        frmCameraCmd->setSizePolicy(sizePolicy1);
        frmCameraCmd->setFrameShape(QFrame::StyledPanel);
        frmCameraCmd->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frmCameraCmd);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        title = new QLabel(frmCameraCmd);
        title->setObjectName(QStringLiteral("title"));
        title->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(title->sizePolicy().hasHeightForWidth());
        title->setSizePolicy(sizePolicy2);
        QFont font;
        font.setPointSize(12);
        title->setFont(font);
        title->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(title);

        btnStartCamera = new QPushButton(frmCameraCmd);
        btnStartCamera->setObjectName(QStringLiteral("btnStartCamera"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(btnStartCamera->sizePolicy().hasHeightForWidth());
        btnStartCamera->setSizePolicy(sizePolicy3);
        btnStartCamera->setMinimumSize(QSize(300, 70));
        btnStartCamera->setFont(font);

        verticalLayout_3->addWidget(btnStartCamera);

        btnStopCamera = new QPushButton(frmCameraCmd);
        btnStopCamera->setObjectName(QStringLiteral("btnStopCamera"));
        sizePolicy3.setHeightForWidth(btnStopCamera->sizePolicy().hasHeightForWidth());
        btnStopCamera->setSizePolicy(sizePolicy3);
        btnStopCamera->setMinimumSize(QSize(300, 70));
        btnStopCamera->setFont(font);

        verticalLayout_3->addWidget(btnStopCamera);


        verticalLayout->addWidget(frmCameraCmd);

        frmAcquisition = new QFrame(TrackingWidget);
        frmAcquisition->setObjectName(QStringLiteral("frmAcquisition"));
        frmAcquisition->setEnabled(true);
        sizePolicy1.setHeightForWidth(frmAcquisition->sizePolicy().hasHeightForWidth());
        frmAcquisition->setSizePolicy(sizePolicy1);
        frmAcquisition->setFrameShape(QFrame::StyledPanel);
        frmAcquisition->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frmAcquisition);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lblAcquisition = new QLabel(frmAcquisition);
        lblAcquisition->setObjectName(QStringLiteral("lblAcquisition"));
        sizePolicy2.setHeightForWidth(lblAcquisition->sizePolicy().hasHeightForWidth());
        lblAcquisition->setSizePolicy(sizePolicy2);
        lblAcquisition->setFont(font);
        lblAcquisition->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(lblAcquisition);

        lblOutputFile = new QLabel(frmAcquisition);
        lblOutputFile->setObjectName(QStringLiteral("lblOutputFile"));
        sizePolicy2.setHeightForWidth(lblOutputFile->sizePolicy().hasHeightForWidth());
        lblOutputFile->setSizePolicy(sizePolicy2);
        lblOutputFile->setFont(font);
        lblOutputFile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(lblOutputFile);

        fileWidget = new FileWidget(frmAcquisition);
        fileWidget->setObjectName(QStringLiteral("fileWidget"));
        fileWidget->setMinimumSize(QSize(0, 50));

        verticalLayout_2->addWidget(fileWidget);

        btnCapture = new QPushButton(frmAcquisition);
        btnCapture->setObjectName(QStringLiteral("btnCapture"));
        sizePolicy3.setHeightForWidth(btnCapture->sizePolicy().hasHeightForWidth());
        btnCapture->setSizePolicy(sizePolicy3);
        btnCapture->setMinimumSize(QSize(300, 70));
        btnCapture->setFont(font);

        verticalLayout_2->addWidget(btnCapture);


        verticalLayout->addWidget(frmAcquisition);

        chkDisableUpdates = new QCheckBox(TrackingWidget);
        chkDisableUpdates->setObjectName(QStringLiteral("chkDisableUpdates"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(chkDisableUpdates->sizePolicy().hasHeightForWidth());
        chkDisableUpdates->setSizePolicy(sizePolicy4);
        chkDisableUpdates->setFont(font);

        verticalLayout->addWidget(chkDisableUpdates);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(TrackingWidget);

        QMetaObject::connectSlotsByName(TrackingWidget);
    } // setupUi

    void retranslateUi(QWidget *TrackingWidget)
    {
        TrackingWidget->setWindowTitle(QApplication::translate("TrackingWidget", "Form", Q_NULLPTR));
        title->setText(QApplication::translate("TrackingWidget", "Controle da c\303\242mera 3D", Q_NULLPTR));
        btnStartCamera->setText(QApplication::translate("TrackingWidget", "Iniciar", Q_NULLPTR));
        btnStopCamera->setText(QApplication::translate("TrackingWidget", "Parar", Q_NULLPTR));
        lblAcquisition->setText(QApplication::translate("TrackingWidget", "Captura", Q_NULLPTR));
        lblOutputFile->setText(QApplication::translate("TrackingWidget", "Arquivo de sa\303\255da", Q_NULLPTR));
        btnCapture->setText(QApplication::translate("TrackingWidget", "Capturar", Q_NULLPTR));
        chkDisableUpdates->setText(QApplication::translate("TrackingWidget", "Desativar tela", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrackingWidget: public Ui_TrackingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRACKINGWIDGET_H
