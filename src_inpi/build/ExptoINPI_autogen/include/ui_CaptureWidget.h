/********************************************************************************
** Form generated from reading UI file 'CaptureWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTUREWIDGET_H
#define UI_CAPTUREWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CaptureWidget
{
public:

    void setupUi(QWidget *CaptureWidget)
    {
        if (CaptureWidget->objectName().isEmpty())
            CaptureWidget->setObjectName(QStringLiteral("CaptureWidget"));
        CaptureWidget->resize(640, 480);

        retranslateUi(CaptureWidget);

        QMetaObject::connectSlotsByName(CaptureWidget);
    } // setupUi

    void retranslateUi(QWidget *CaptureWidget)
    {
        CaptureWidget->setWindowTitle(QApplication::translate("CaptureWidget", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CaptureWidget: public Ui_CaptureWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTUREWIDGET_H
