/********************************************************************************
** Form generated from reading UI file 'ClusteringWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUSTERINGWIDGET_H
#define UI_CLUSTERINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <widget/ClusteringOptionWidget.h>
#include <widget/FileWidget.h>
#include <widget/FilterOptionWidget.h>
#include <widget/MinCutOptionWidget.h>
#include <widget/SegmentationOptionWidget.h>
#include <widget/VideoQVTKOpenGLWidget.h>

QT_BEGIN_NAMESPACE

class Ui_ClusteringWidget
{
public:
    QHBoxLayout *horizontalLayout;
    VideoQVTKOpenGLWidget *qvtkGLWidget;
    QFrame *frmClustering;
    QVBoxLayout *verticalLayout_2;
    QToolBox *toolBox;
    FilterOptionWidget *wgtFilterOptionView;
    MinCutOptionWidget *wgtMinCutOptionView;
    SegmentationOptionWidget *wgtSegOptionView;
    ClusteringOptionWidget *wgtClusterOptionView;
    QLabel *label;
    QLCDNumber *_displayElapsed;
    QLabel *lblSegInputFile;
    FileWidget *fileWidget;
    QPushButton *btnSegment;

    void setupUi(QWidget *ClusteringWidget)
    {
        if (ClusteringWidget->objectName().isEmpty())
            ClusteringWidget->setObjectName(QStringLiteral("ClusteringWidget"));
        ClusteringWidget->resize(1277, 869);
        horizontalLayout = new QHBoxLayout(ClusteringWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        qvtkGLWidget = new VideoQVTKOpenGLWidget(ClusteringWidget);
        qvtkGLWidget->setObjectName(QStringLiteral("qvtkGLWidget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(qvtkGLWidget->sizePolicy().hasHeightForWidth());
        qvtkGLWidget->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(qvtkGLWidget);

        frmClustering = new QFrame(ClusteringWidget);
        frmClustering->setObjectName(QStringLiteral("frmClustering"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frmClustering->sizePolicy().hasHeightForWidth());
        frmClustering->setSizePolicy(sizePolicy1);
        frmClustering->setMinimumSize(QSize(300, 0));
        frmClustering->setFrameShape(QFrame::StyledPanel);
        frmClustering->setFrameShadow(QFrame::Sunken);
        verticalLayout_2 = new QVBoxLayout(frmClustering);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        toolBox = new QToolBox(frmClustering);
        toolBox->setObjectName(QStringLiteral("toolBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy2);
        toolBox->setMinimumSize(QSize(300, 0));
        QFont font;
        font.setPointSize(12);
        toolBox->setFont(font);
        wgtFilterOptionView = new FilterOptionWidget();
        wgtFilterOptionView->setObjectName(QStringLiteral("wgtFilterOptionView"));
        wgtFilterOptionView->setGeometry(QRect(0, 0, 300, 338));
        toolBox->addItem(wgtFilterOptionView, QStringLiteral("Filtragem"));
        wgtMinCutOptionView = new MinCutOptionWidget();
        wgtMinCutOptionView->setObjectName(QStringLiteral("wgtMinCutOptionView"));
        wgtMinCutOptionView->setGeometry(QRect(0, 0, 300, 338));
        toolBox->addItem(wgtMinCutOptionView, QString::fromUtf8("Segmenta\303\247\303\243o Min Cut"));
        wgtSegOptionView = new SegmentationOptionWidget();
        wgtSegOptionView->setObjectName(QStringLiteral("wgtSegOptionView"));
        wgtSegOptionView->setGeometry(QRect(0, 0, 300, 338));
        toolBox->addItem(wgtSegOptionView, QString::fromUtf8("Segmentaca\303\247\303\243o SAC"));
        wgtClusterOptionView = new ClusteringOptionWidget();
        wgtClusterOptionView->setObjectName(QStringLiteral("wgtClusterOptionView"));
        wgtClusterOptionView->setGeometry(QRect(0, 0, 300, 338));
        toolBox->addItem(wgtClusterOptionView, QStringLiteral("Agrupamento"));

        verticalLayout_2->addWidget(toolBox);

        label = new QLabel(frmClustering);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        _displayElapsed = new QLCDNumber(frmClustering);
        _displayElapsed->setObjectName(QStringLiteral("_displayElapsed"));
        _displayElapsed->setMinimumSize(QSize(0, 70));

        verticalLayout_2->addWidget(_displayElapsed);

        lblSegInputFile = new QLabel(frmClustering);
        lblSegInputFile->setObjectName(QStringLiteral("lblSegInputFile"));
        sizePolicy2.setHeightForWidth(lblSegInputFile->sizePolicy().hasHeightForWidth());
        lblSegInputFile->setSizePolicy(sizePolicy2);
        lblSegInputFile->setFont(font);
        lblSegInputFile->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_2->addWidget(lblSegInputFile);

        fileWidget = new FileWidget(frmClustering);
        fileWidget->setObjectName(QStringLiteral("fileWidget"));
        sizePolicy2.setHeightForWidth(fileWidget->sizePolicy().hasHeightForWidth());
        fileWidget->setSizePolicy(sizePolicy2);
        fileWidget->setMinimumSize(QSize(0, 50));
        fileWidget->setStyleSheet(QStringLiteral(""));

        verticalLayout_2->addWidget(fileWidget);

        btnSegment = new QPushButton(frmClustering);
        btnSegment->setObjectName(QStringLiteral("btnSegment"));
        btnSegment->setMinimumSize(QSize(0, 70));
        btnSegment->setFont(font);

        verticalLayout_2->addWidget(btnSegment);


        horizontalLayout->addWidget(frmClustering);


        retranslateUi(ClusteringWidget);

        toolBox->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ClusteringWidget);
    } // setupUi

    void retranslateUi(QWidget *ClusteringWidget)
    {
        ClusteringWidget->setWindowTitle(QApplication::translate("ClusteringWidget", "Form", nullptr));
        toolBox->setItemText(toolBox->indexOf(wgtFilterOptionView), QApplication::translate("ClusteringWidget", "Filtragem", nullptr));
        toolBox->setItemText(toolBox->indexOf(wgtMinCutOptionView), QApplication::translate("ClusteringWidget", "Segmenta\303\247\303\243o Min Cut", nullptr));
        toolBox->setItemText(toolBox->indexOf(wgtSegOptionView), QApplication::translate("ClusteringWidget", "Segmentaca\303\247\303\243o SAC", nullptr));
        toolBox->setItemText(toolBox->indexOf(wgtClusterOptionView), QApplication::translate("ClusteringWidget", "Agrupamento", nullptr));
        label->setText(QApplication::translate("ClusteringWidget", "Tempo processamento (ms)", nullptr));
        lblSegInputFile->setText(QApplication::translate("ClusteringWidget", "Arquivo", nullptr));
        btnSegment->setText(QApplication::translate("ClusteringWidget", "Segmentar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClusteringWidget: public Ui_ClusteringWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUSTERINGWIDGET_H
