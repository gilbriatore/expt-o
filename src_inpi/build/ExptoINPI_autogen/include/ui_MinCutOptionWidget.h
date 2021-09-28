/********************************************************************************
** Form generated from reading UI file 'MinCutOptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MINCUTOPTIONWIDGET_H
#define UI_MINCUTOPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MinCutOptionWidget
{
public:
    QGridLayout *gridLayout_2;
    QLabel *lblUDMmeters_5;
    QGridLayout *gridLayout;
    QCheckBox *chkEnableMinCut;
    QLabel *lblxCenterPoint;
    QDoubleSpinBox *spnxCenterPoint;
    QLabel *lblUDMmeters;
    QLabel *lblyCenterPoint;
    QDoubleSpinBox *spnyCenterPoint;
    QLabel *lblUDMmeters_2;
    QLabel *lblzCenterPoint;
    QDoubleSpinBox *spnzCenterPoint;
    QLabel *lblUDMmeters_3;
    QLabel *lblSigma;
    QDoubleSpinBox *spnSigma;
    QLabel *lblRadius;
    QDoubleSpinBox *spnRadius;
    QLabel *lblUDMmeters_4;
    QLabel *lblNrNeighbours;
    QSpinBox *spnNrNeighbours;
    QLabel *lblSourceWeight;
    QDoubleSpinBox *spnSourceWeight;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *MinCutOptionWidget)
    {
        if (MinCutOptionWidget->objectName().isEmpty())
            MinCutOptionWidget->setObjectName(QStringLiteral("MinCutOptionWidget"));
        MinCutOptionWidget->resize(356, 735);
        gridLayout_2 = new QGridLayout(MinCutOptionWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lblUDMmeters_5 = new QLabel(MinCutOptionWidget);
        lblUDMmeters_5->setObjectName(QStringLiteral("lblUDMmeters_5"));
        QFont font;
        font.setPointSize(10);
        lblUDMmeters_5->setFont(font);
        lblUDMmeters_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(lblUDMmeters_5, 1, 1, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        chkEnableMinCut = new QCheckBox(MinCutOptionWidget);
        chkEnableMinCut->setObjectName(QStringLiteral("chkEnableMinCut"));
        chkEnableMinCut->setFont(font);
        chkEnableMinCut->setChecked(true);

        gridLayout->addWidget(chkEnableMinCut, 0, 0, 1, 1);

        lblxCenterPoint = new QLabel(MinCutOptionWidget);
        lblxCenterPoint->setObjectName(QStringLiteral("lblxCenterPoint"));
        lblxCenterPoint->setFont(font);
        lblxCenterPoint->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblxCenterPoint, 1, 0, 1, 1);

        spnxCenterPoint = new QDoubleSpinBox(MinCutOptionWidget);
        spnxCenterPoint->setObjectName(QStringLiteral("spnxCenterPoint"));
        spnxCenterPoint->setMinimumSize(QSize(0, 50));
        spnxCenterPoint->setFont(font);
        spnxCenterPoint->setDecimals(2);
        spnxCenterPoint->setMinimum(-99999);
        spnxCenterPoint->setMaximum(99999);
        spnxCenterPoint->setSingleStep(1);
        spnxCenterPoint->setValue(0);

        gridLayout->addWidget(spnxCenterPoint, 1, 1, 1, 1);

        lblUDMmeters = new QLabel(MinCutOptionWidget);
        lblUDMmeters->setObjectName(QStringLiteral("lblUDMmeters"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblUDMmeters->sizePolicy().hasHeightForWidth());
        lblUDMmeters->setSizePolicy(sizePolicy);
        lblUDMmeters->setFont(font);
        lblUDMmeters->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblUDMmeters, 1, 2, 1, 1);

        lblyCenterPoint = new QLabel(MinCutOptionWidget);
        lblyCenterPoint->setObjectName(QStringLiteral("lblyCenterPoint"));
        lblyCenterPoint->setFont(font);
        lblyCenterPoint->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblyCenterPoint, 2, 0, 1, 1);

        spnyCenterPoint = new QDoubleSpinBox(MinCutOptionWidget);
        spnyCenterPoint->setObjectName(QStringLiteral("spnyCenterPoint"));
        spnyCenterPoint->setMinimumSize(QSize(0, 50));
        spnyCenterPoint->setFont(font);
        spnyCenterPoint->setDecimals(2);
        spnyCenterPoint->setMinimum(-99999);
        spnyCenterPoint->setMaximum(99999);
        spnyCenterPoint->setSingleStep(1);
        spnyCenterPoint->setValue(0);

        gridLayout->addWidget(spnyCenterPoint, 2, 1, 1, 1);

        lblUDMmeters_2 = new QLabel(MinCutOptionWidget);
        lblUDMmeters_2->setObjectName(QStringLiteral("lblUDMmeters_2"));
        sizePolicy.setHeightForWidth(lblUDMmeters_2->sizePolicy().hasHeightForWidth());
        lblUDMmeters_2->setSizePolicy(sizePolicy);
        lblUDMmeters_2->setFont(font);
        lblUDMmeters_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblUDMmeters_2, 2, 2, 1, 1);

        lblzCenterPoint = new QLabel(MinCutOptionWidget);
        lblzCenterPoint->setObjectName(QStringLiteral("lblzCenterPoint"));
        lblzCenterPoint->setFont(font);
        lblzCenterPoint->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblzCenterPoint, 3, 0, 1, 1);

        spnzCenterPoint = new QDoubleSpinBox(MinCutOptionWidget);
        spnzCenterPoint->setObjectName(QStringLiteral("spnzCenterPoint"));
        spnzCenterPoint->setMinimumSize(QSize(0, 50));
        spnzCenterPoint->setFont(font);
        spnzCenterPoint->setDecimals(2);
        spnzCenterPoint->setMinimum(-99999);
        spnzCenterPoint->setMaximum(99999);
        spnzCenterPoint->setSingleStep(1);
        spnzCenterPoint->setValue(0);

        gridLayout->addWidget(spnzCenterPoint, 3, 1, 1, 1);

        lblUDMmeters_3 = new QLabel(MinCutOptionWidget);
        lblUDMmeters_3->setObjectName(QStringLiteral("lblUDMmeters_3"));
        sizePolicy.setHeightForWidth(lblUDMmeters_3->sizePolicy().hasHeightForWidth());
        lblUDMmeters_3->setSizePolicy(sizePolicy);
        lblUDMmeters_3->setFont(font);
        lblUDMmeters_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblUDMmeters_3, 3, 2, 1, 1);

        lblSigma = new QLabel(MinCutOptionWidget);
        lblSigma->setObjectName(QStringLiteral("lblSigma"));
        lblSigma->setFont(font);
        lblSigma->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblSigma, 4, 0, 1, 1);

        spnSigma = new QDoubleSpinBox(MinCutOptionWidget);
        spnSigma->setObjectName(QStringLiteral("spnSigma"));
        spnSigma->setMinimumSize(QSize(0, 50));
        spnSigma->setFont(font);
        spnSigma->setDecimals(3);
        spnSigma->setSingleStep(0.01);
        spnSigma->setValue(0.25);

        gridLayout->addWidget(spnSigma, 4, 1, 1, 1);

        lblRadius = new QLabel(MinCutOptionWidget);
        lblRadius->setObjectName(QStringLiteral("lblRadius"));
        lblRadius->setFont(font);
        lblRadius->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblRadius, 5, 0, 1, 1);

        spnRadius = new QDoubleSpinBox(MinCutOptionWidget);
        spnRadius->setObjectName(QStringLiteral("spnRadius"));
        spnRadius->setMinimumSize(QSize(0, 50));
        spnRadius->setFont(font);
        spnRadius->setDecimals(3);
        spnRadius->setSingleStep(0.01);
        spnRadius->setValue(3.043);

        gridLayout->addWidget(spnRadius, 5, 1, 1, 1);

        lblUDMmeters_4 = new QLabel(MinCutOptionWidget);
        lblUDMmeters_4->setObjectName(QStringLiteral("lblUDMmeters_4"));
        sizePolicy.setHeightForWidth(lblUDMmeters_4->sizePolicy().hasHeightForWidth());
        lblUDMmeters_4->setSizePolicy(sizePolicy);
        lblUDMmeters_4->setFont(font);
        lblUDMmeters_4->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblUDMmeters_4, 5, 2, 1, 1);

        lblNrNeighbours = new QLabel(MinCutOptionWidget);
        lblNrNeighbours->setObjectName(QStringLiteral("lblNrNeighbours"));
        lblNrNeighbours->setFont(font);
        lblNrNeighbours->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblNrNeighbours, 6, 0, 1, 1);

        spnNrNeighbours = new QSpinBox(MinCutOptionWidget);
        spnNrNeighbours->setObjectName(QStringLiteral("spnNrNeighbours"));
        spnNrNeighbours->setMinimumSize(QSize(0, 50));
        spnNrNeighbours->setFont(font);
        spnNrNeighbours->setMaximum(999);
        spnNrNeighbours->setValue(14);

        gridLayout->addWidget(spnNrNeighbours, 6, 1, 1, 1);

        lblSourceWeight = new QLabel(MinCutOptionWidget);
        lblSourceWeight->setObjectName(QStringLiteral("lblSourceWeight"));
        lblSourceWeight->setFont(font);
        lblSourceWeight->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblSourceWeight, 7, 0, 1, 1);

        spnSourceWeight = new QDoubleSpinBox(MinCutOptionWidget);
        spnSourceWeight->setObjectName(QStringLiteral("spnSourceWeight"));
        spnSourceWeight->setMinimumSize(QSize(0, 50));
        spnSourceWeight->setFont(font);
        spnSourceWeight->setDecimals(3);
        spnSourceWeight->setSingleStep(0.01);
        spnSourceWeight->setValue(0.8);

        gridLayout->addWidget(spnSourceWeight, 7, 1, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 2, 3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);


        retranslateUi(MinCutOptionWidget);

        QMetaObject::connectSlotsByName(MinCutOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *MinCutOptionWidget)
    {
        MinCutOptionWidget->setWindowTitle(QApplication::translate("MinCutOptionWidget", "Form", Q_NULLPTR));
        lblUDMmeters_5->setText(QString());
        chkEnableMinCut->setText(QApplication::translate("MinCutOptionWidget", "Ativar", Q_NULLPTR));
        lblxCenterPoint->setText(QApplication::translate("MinCutOptionWidget", "Ponto central X", Q_NULLPTR));
        lblUDMmeters->setText(QApplication::translate("MinCutOptionWidget", "m", Q_NULLPTR));
        lblyCenterPoint->setText(QApplication::translate("MinCutOptionWidget", "Ponto central Y", Q_NULLPTR));
        lblUDMmeters_2->setText(QApplication::translate("MinCutOptionWidget", "m", Q_NULLPTR));
        lblzCenterPoint->setText(QApplication::translate("MinCutOptionWidget", "Ponto central Z", Q_NULLPTR));
        lblUDMmeters_3->setText(QApplication::translate("MinCutOptionWidget", "m", Q_NULLPTR));
        lblSigma->setText(QApplication::translate("MinCutOptionWidget", "Sigma", Q_NULLPTR));
        lblRadius->setText(QApplication::translate("MinCutOptionWidget", "Raio", Q_NULLPTR));
        lblUDMmeters_4->setText(QApplication::translate("MinCutOptionWidget", "m", Q_NULLPTR));
        lblNrNeighbours->setText(QApplication::translate("MinCutOptionWidget", "Nr dos vizinhos", Q_NULLPTR));
        lblSourceWeight->setText(QApplication::translate("MinCutOptionWidget", "Peso da fonte", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MinCutOptionWidget: public Ui_MinCutOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MINCUTOPTIONWIDGET_H
