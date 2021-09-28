/********************************************************************************
** Form generated from reading UI file 'SegmentationOptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SEGMENTATIONOPTIONWIDGET_H
#define UI_SEGMENTATIONOPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SegmentationOptionWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lblModelType;
    QLabel *lblMaxIterations;
    QCheckBox *chkEnableSegmentation;
    QSpinBox *spnMaxIterations;
    QCheckBox *chkOptimazeCoef;
    QLabel *lblMethodType;
    QDoubleSpinBox *spnDistanceThreshold;
    QComboBox *cmbModelType;
    QLabel *lblDistanceThreshold;
    QComboBox *cmbMethodType;
    QLabel *lblUDMmeters_3;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *SegmentationOptionWidget)
    {
        if (SegmentationOptionWidget->objectName().isEmpty())
            SegmentationOptionWidget->setObjectName(QStringLiteral("SegmentationOptionWidget"));
        SegmentationOptionWidget->resize(391, 513);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SegmentationOptionWidget->sizePolicy().hasHeightForWidth());
        SegmentationOptionWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(SegmentationOptionWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblModelType = new QLabel(SegmentationOptionWidget);
        lblModelType->setObjectName(QStringLiteral("lblModelType"));
        QFont font;
        font.setPointSize(10);
        lblModelType->setFont(font);
        lblModelType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblModelType, 2, 0, 1, 1);

        lblMaxIterations = new QLabel(SegmentationOptionWidget);
        lblMaxIterations->setObjectName(QStringLiteral("lblMaxIterations"));
        lblMaxIterations->setFont(font);
        lblMaxIterations->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblMaxIterations, 6, 0, 1, 1);

        chkEnableSegmentation = new QCheckBox(SegmentationOptionWidget);
        chkEnableSegmentation->setObjectName(QStringLiteral("chkEnableSegmentation"));
        chkEnableSegmentation->setFont(font);
        chkEnableSegmentation->setChecked(false);

        gridLayout->addWidget(chkEnableSegmentation, 0, 0, 1, 1);

        spnMaxIterations = new QSpinBox(SegmentationOptionWidget);
        spnMaxIterations->setObjectName(QStringLiteral("spnMaxIterations"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spnMaxIterations->sizePolicy().hasHeightForWidth());
        spnMaxIterations->setSizePolicy(sizePolicy1);
        spnMaxIterations->setMinimumSize(QSize(0, 50));
        spnMaxIterations->setFont(font);
        spnMaxIterations->setMaximum(20);
        spnMaxIterations->setValue(10);

        gridLayout->addWidget(spnMaxIterations, 6, 1, 1, 1);

        chkOptimazeCoef = new QCheckBox(SegmentationOptionWidget);
        chkOptimazeCoef->setObjectName(QStringLiteral("chkOptimazeCoef"));
        chkOptimazeCoef->setFont(font);
        chkOptimazeCoef->setChecked(true);

        gridLayout->addWidget(chkOptimazeCoef, 1, 0, 1, 2);

        lblMethodType = new QLabel(SegmentationOptionWidget);
        lblMethodType->setObjectName(QStringLiteral("lblMethodType"));
        lblMethodType->setFont(font);
        lblMethodType->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblMethodType, 4, 0, 1, 1);

        spnDistanceThreshold = new QDoubleSpinBox(SegmentationOptionWidget);
        spnDistanceThreshold->setObjectName(QStringLiteral("spnDistanceThreshold"));
        spnDistanceThreshold->setMinimumSize(QSize(0, 50));
        spnDistanceThreshold->setFont(font);
        spnDistanceThreshold->setDecimals(4);
        spnDistanceThreshold->setMinimum(0.001);
        spnDistanceThreshold->setSingleStep(0.001);
        spnDistanceThreshold->setValue(0.02);

        gridLayout->addWidget(spnDistanceThreshold, 7, 1, 1, 1);

        cmbModelType = new QComboBox(SegmentationOptionWidget);
        cmbModelType->setObjectName(QStringLiteral("cmbModelType"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cmbModelType->sizePolicy().hasHeightForWidth());
        cmbModelType->setSizePolicy(sizePolicy2);
        cmbModelType->setMinimumSize(QSize(250, 50));
        cmbModelType->setFont(font);
        cmbModelType->setEditable(false);

        gridLayout->addWidget(cmbModelType, 3, 0, 1, 3);

        lblDistanceThreshold = new QLabel(SegmentationOptionWidget);
        lblDistanceThreshold->setObjectName(QStringLiteral("lblDistanceThreshold"));
        lblDistanceThreshold->setFont(font);
        lblDistanceThreshold->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblDistanceThreshold, 7, 0, 1, 1);

        cmbMethodType = new QComboBox(SegmentationOptionWidget);
        cmbMethodType->setObjectName(QStringLiteral("cmbMethodType"));
        sizePolicy2.setHeightForWidth(cmbMethodType->sizePolicy().hasHeightForWidth());
        cmbMethodType->setSizePolicy(sizePolicy2);
        cmbMethodType->setMinimumSize(QSize(250, 50));
        cmbMethodType->setFont(font);

        gridLayout->addWidget(cmbMethodType, 5, 0, 1, 3);

        lblUDMmeters_3 = new QLabel(SegmentationOptionWidget);
        lblUDMmeters_3->setObjectName(QStringLiteral("lblUDMmeters_3"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(lblUDMmeters_3->sizePolicy().hasHeightForWidth());
        lblUDMmeters_3->setSizePolicy(sizePolicy3);
        lblUDMmeters_3->setFont(font);
        lblUDMmeters_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblUDMmeters_3, 7, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 8, 0, 1, 1);


        retranslateUi(SegmentationOptionWidget);

        QMetaObject::connectSlotsByName(SegmentationOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *SegmentationOptionWidget)
    {
        SegmentationOptionWidget->setWindowTitle(QApplication::translate("SegmentationOptionWidget", "Form", Q_NULLPTR));
        lblModelType->setText(QApplication::translate("SegmentationOptionWidget", "Modelo", Q_NULLPTR));
        lblMaxIterations->setText(QApplication::translate("SegmentationOptionWidget", "M\303\241ximo de itera\303\247\303\265es", Q_NULLPTR));
        chkEnableSegmentation->setText(QApplication::translate("SegmentationOptionWidget", "Ativar", Q_NULLPTR));
        chkOptimazeCoef->setText(QApplication::translate("SegmentationOptionWidget", "Optimizar coefficients", Q_NULLPTR));
        lblMethodType->setText(QApplication::translate("SegmentationOptionWidget", "M\303\251todo", Q_NULLPTR));
        lblDistanceThreshold->setText(QApplication::translate("SegmentationOptionWidget", "Limite de dist\303\242ncia", Q_NULLPTR));
        lblUDMmeters_3->setText(QApplication::translate("SegmentationOptionWidget", "m", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SegmentationOptionWidget: public Ui_SegmentationOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SEGMENTATIONOPTIONWIDGET_H
