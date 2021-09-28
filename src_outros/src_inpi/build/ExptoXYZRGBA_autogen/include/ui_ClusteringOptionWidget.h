/********************************************************************************
** Form generated from reading UI file 'ClusteringOptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLUSTERINGOPTIONWIDGET_H
#define UI_CLUSTERINGOPTIONWIDGET_H

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

class Ui_ClusteringOptionWidget
{
public:
    QGridLayout *gridLayout;
    QLabel *lblDescriptorRadius;
    QCheckBox *chkEnableClustering;
    QLabel *lblModelSample;
    QLabel *lblClusterTolerance;
    QSpinBox *spnMinClusterSize;
    QSpinBox *spnMaxClusterSize;
    QLabel *lblUDMmeters_3;
    QDoubleSpinBox *spnClusterTolerance;
    QDoubleSpinBox *spnDescriptorRadius;
    QDoubleSpinBox *spnModelSample;
    QLabel *lblMinClusterSize;
    QLabel *lblMaxClusterSize;
    QCheckBox *chkShowUsedKeypoints;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *ClusteringOptionWidget)
    {
        if (ClusteringOptionWidget->objectName().isEmpty())
            ClusteringOptionWidget->setObjectName(QStringLiteral("ClusteringOptionWidget"));
        ClusteringOptionWidget->resize(389, 501);
        gridLayout = new QGridLayout(ClusteringOptionWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        lblDescriptorRadius = new QLabel(ClusteringOptionWidget);
        lblDescriptorRadius->setObjectName(QStringLiteral("lblDescriptorRadius"));
        QFont font;
        font.setPointSize(10);
        lblDescriptorRadius->setFont(font);
        lblDescriptorRadius->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblDescriptorRadius, 6, 0, 1, 1);

        chkEnableClustering = new QCheckBox(ClusteringOptionWidget);
        chkEnableClustering->setObjectName(QStringLiteral("chkEnableClustering"));
        chkEnableClustering->setFont(font);
        chkEnableClustering->setChecked(false);

        gridLayout->addWidget(chkEnableClustering, 0, 0, 1, 2);

        lblModelSample = new QLabel(ClusteringOptionWidget);
        lblModelSample->setObjectName(QStringLiteral("lblModelSample"));
        lblModelSample->setFont(font);
        lblModelSample->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblModelSample, 5, 0, 1, 1);

        lblClusterTolerance = new QLabel(ClusteringOptionWidget);
        lblClusterTolerance->setObjectName(QStringLiteral("lblClusterTolerance"));
        lblClusterTolerance->setFont(font);
        lblClusterTolerance->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblClusterTolerance, 1, 0, 1, 1);

        spnMinClusterSize = new QSpinBox(ClusteringOptionWidget);
        spnMinClusterSize->setObjectName(QStringLiteral("spnMinClusterSize"));
        spnMinClusterSize->setMinimumSize(QSize(0, 50));
        spnMinClusterSize->setFont(font);
        spnMinClusterSize->setMinimum(1);
        spnMinClusterSize->setMaximum(99999);
        spnMinClusterSize->setValue(100);

        gridLayout->addWidget(spnMinClusterSize, 2, 1, 1, 1);

        spnMaxClusterSize = new QSpinBox(ClusteringOptionWidget);
        spnMaxClusterSize->setObjectName(QStringLiteral("spnMaxClusterSize"));
        spnMaxClusterSize->setMinimumSize(QSize(0, 50));
        spnMaxClusterSize->setFont(font);
        spnMaxClusterSize->setMinimum(1);
        spnMaxClusterSize->setMaximum(99999);
        spnMaxClusterSize->setValue(25000);

        gridLayout->addWidget(spnMaxClusterSize, 3, 1, 1, 1);

        lblUDMmeters_3 = new QLabel(ClusteringOptionWidget);
        lblUDMmeters_3->setObjectName(QStringLiteral("lblUDMmeters_3"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lblUDMmeters_3->sizePolicy().hasHeightForWidth());
        lblUDMmeters_3->setSizePolicy(sizePolicy);
        lblUDMmeters_3->setFont(font);
        lblUDMmeters_3->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblUDMmeters_3, 1, 2, 1, 1);

        spnClusterTolerance = new QDoubleSpinBox(ClusteringOptionWidget);
        spnClusterTolerance->setObjectName(QStringLiteral("spnClusterTolerance"));
        spnClusterTolerance->setMinimumSize(QSize(0, 50));
        spnClusterTolerance->setFont(font);
        spnClusterTolerance->setDecimals(3);
        spnClusterTolerance->setMinimum(0);
        spnClusterTolerance->setMaximum(100);
        spnClusterTolerance->setSingleStep(0.001);
        spnClusterTolerance->setValue(0.02);

        gridLayout->addWidget(spnClusterTolerance, 1, 1, 1, 1);

        spnDescriptorRadius = new QDoubleSpinBox(ClusteringOptionWidget);
        spnDescriptorRadius->setObjectName(QStringLiteral("spnDescriptorRadius"));
        spnDescriptorRadius->setMinimumSize(QSize(0, 50));
        spnDescriptorRadius->setFont(font);
        spnDescriptorRadius->setMinimum(0.01);
        spnDescriptorRadius->setSingleStep(0.01);
        spnDescriptorRadius->setValue(0.02);

        gridLayout->addWidget(spnDescriptorRadius, 6, 1, 1, 1);

        spnModelSample = new QDoubleSpinBox(ClusteringOptionWidget);
        spnModelSample->setObjectName(QStringLiteral("spnModelSample"));
        spnModelSample->setMinimumSize(QSize(0, 50));
        spnModelSample->setFont(font);
        spnModelSample->setMinimum(0.01);
        spnModelSample->setSingleStep(0.01);
        spnModelSample->setValue(0.02);

        gridLayout->addWidget(spnModelSample, 5, 1, 1, 1);

        lblMinClusterSize = new QLabel(ClusteringOptionWidget);
        lblMinClusterSize->setObjectName(QStringLiteral("lblMinClusterSize"));
        lblMinClusterSize->setFont(font);
        lblMinClusterSize->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblMinClusterSize, 2, 0, 1, 1);

        lblMaxClusterSize = new QLabel(ClusteringOptionWidget);
        lblMaxClusterSize->setObjectName(QStringLiteral("lblMaxClusterSize"));
        lblMaxClusterSize->setFont(font);
        lblMaxClusterSize->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout->addWidget(lblMaxClusterSize, 3, 0, 1, 1);

        chkShowUsedKeypoints = new QCheckBox(ClusteringOptionWidget);
        chkShowUsedKeypoints->setObjectName(QStringLiteral("chkShowUsedKeypoints"));
        chkShowUsedKeypoints->setFont(font);
        chkShowUsedKeypoints->setChecked(true);

        gridLayout->addWidget(chkShowUsedKeypoints, 4, 0, 1, 2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 1);


        retranslateUi(ClusteringOptionWidget);

        QMetaObject::connectSlotsByName(ClusteringOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *ClusteringOptionWidget)
    {
        ClusteringOptionWidget->setWindowTitle(QApplication::translate("ClusteringOptionWidget", "Form", Q_NULLPTR));
        lblDescriptorRadius->setText(QApplication::translate("ClusteringOptionWidget", "Raio do descritor", Q_NULLPTR));
        chkEnableClustering->setText(QApplication::translate("ClusteringOptionWidget", "Ativar", Q_NULLPTR));
        lblModelSample->setText(QApplication::translate("ClusteringOptionWidget", "Amostra modelo", Q_NULLPTR));
        lblClusterTolerance->setText(QApplication::translate("ClusteringOptionWidget", "Toler\303\242ncia", Q_NULLPTR));
        lblUDMmeters_3->setText(QApplication::translate("ClusteringOptionWidget", "m", Q_NULLPTR));
        lblMinClusterSize->setText(QApplication::translate("ClusteringOptionWidget", "Tamanho m\303\255nimo", Q_NULLPTR));
        lblMaxClusterSize->setText(QApplication::translate("ClusteringOptionWidget", "Tamanho m\303\241ximo", Q_NULLPTR));
        chkShowUsedKeypoints->setText(QApplication::translate("ClusteringOptionWidget", "Mostrar pontos-chave", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClusteringOptionWidget: public Ui_ClusteringOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLUSTERINGOPTIONWIDGET_H
