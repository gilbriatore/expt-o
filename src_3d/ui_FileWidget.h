/********************************************************************************
** Form generated from reading UI file 'FileWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.10.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FILEWIDGET_H
#define UI_FILEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FileWidget
{
public:
    QGridLayout *gridLayout;
    QLineEdit *txtPath;
    QPushButton *btnChoose;

    void setupUi(QWidget *FileWidget)
    {
        if (FileWidget->objectName().isEmpty())
            FileWidget->setObjectName(QStringLiteral("FileWidget"));
        FileWidget->resize(329, 108);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FileWidget->sizePolicy().hasHeightForWidth());
        FileWidget->setSizePolicy(sizePolicy);
        FileWidget->setMinimumSize(QSize(250, 50));
        gridLayout = new QGridLayout(FileWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 5, 0, 5);
        txtPath = new QLineEdit(FileWidget);
        txtPath->setObjectName(QStringLiteral("txtPath"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtPath->sizePolicy().hasHeightForWidth());
        txtPath->setSizePolicy(sizePolicy1);
        txtPath->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setPointSize(12);
        txtPath->setFont(font);

        gridLayout->addWidget(txtPath, 0, 0, 1, 1);

        btnChoose = new QPushButton(FileWidget);
        btnChoose->setObjectName(QStringLiteral("btnChoose"));
        sizePolicy.setHeightForWidth(btnChoose->sizePolicy().hasHeightForWidth());
        btnChoose->setSizePolicy(sizePolicy);
        btnChoose->setMinimumSize(QSize(50, 50));

        gridLayout->addWidget(btnChoose, 0, 1, 1, 1);


        retranslateUi(FileWidget);

        QMetaObject::connectSlotsByName(FileWidget);
    } // setupUi

    void retranslateUi(QWidget *FileWidget)
    {
        FileWidget->setWindowTitle(QApplication::translate("FileWidget", "Form", nullptr));
        txtPath->setText(QString());
        btnChoose->setText(QApplication::translate("FileWidget", "...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FileWidget: public Ui_FileWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FILEWIDGET_H
