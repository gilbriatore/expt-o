/********************************************************************************
** Form generated from reading UI file 'FilterOptionWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILTEROPTIONWIDGET_H
#define UI_FILTEROPTIONWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FilterOptionWidget
{
public:
    QVBoxLayout *verticalLayout;
    QCheckBox *chkEnableFiltering;
    QHBoxLayout *horizontalLayout;
    QLabel *lblLeafSize;
    QDoubleSpinBox *spnLeafSize;
    QLabel *lblLeafSize_2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FilterOptionWidget)
    {
        if (FilterOptionWidget->objectName().isEmpty())
            FilterOptionWidget->setObjectName(QStringLiteral("FilterOptionWidget"));
        FilterOptionWidget->resize(359, 299);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FilterOptionWidget->sizePolicy().hasHeightForWidth());
        FilterOptionWidget->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(FilterOptionWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        chkEnableFiltering = new QCheckBox(FilterOptionWidget);
        chkEnableFiltering->setObjectName(QStringLiteral("chkEnableFiltering"));
        QFont font;
        font.setPointSize(10);
        chkEnableFiltering->setFont(font);
        chkEnableFiltering->setChecked(false);

        verticalLayout->addWidget(chkEnableFiltering);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lblLeafSize = new QLabel(FilterOptionWidget);
        lblLeafSize->setObjectName(QStringLiteral("lblLeafSize"));
        lblLeafSize->setFont(font);
        lblLeafSize->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblLeafSize);

        spnLeafSize = new QDoubleSpinBox(FilterOptionWidget);
        spnLeafSize->setObjectName(QStringLiteral("spnLeafSize"));
        spnLeafSize->setMinimumSize(QSize(0, 50));
        spnLeafSize->setFont(font);
        spnLeafSize->setDecimals(3);
        spnLeafSize->setMinimum(0.002);
        spnLeafSize->setSingleStep(0.001);

        horizontalLayout->addWidget(spnLeafSize);

        lblLeafSize_2 = new QLabel(FilterOptionWidget);
        lblLeafSize_2->setObjectName(QStringLiteral("lblLeafSize_2"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lblLeafSize_2->sizePolicy().hasHeightForWidth());
        lblLeafSize_2->setSizePolicy(sizePolicy1);
        lblLeafSize_2->setMinimumSize(QSize(0, 0));
        lblLeafSize_2->setFont(font);
        lblLeafSize_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout->addWidget(lblLeafSize_2);


        verticalLayout->addLayout(horizontalLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FilterOptionWidget);

        QMetaObject::connectSlotsByName(FilterOptionWidget);
    } // setupUi

    void retranslateUi(QWidget *FilterOptionWidget)
    {
        FilterOptionWidget->setWindowTitle(QApplication::translate("FilterOptionWidget", "Form", nullptr));
        chkEnableFiltering->setText(QApplication::translate("FilterOptionWidget", "Ativar", nullptr));
        lblLeafSize->setText(QApplication::translate("FilterOptionWidget", "Tamanho da folha", nullptr));
        lblLeafSize_2->setText(QApplication::translate("FilterOptionWidget", "m", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FilterOptionWidget: public Ui_FilterOptionWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILTEROPTIONWIDGET_H
