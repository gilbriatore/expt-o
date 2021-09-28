#include "FileWidget.h"
#include "ui_FileWidget.h"

#include <QFileDialog>

FileWidget::FileWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileWidget),
    fileType("PCD files (*.pcd)")
{
    ui->setupUi(this);
}

void FileWidget::setFileType(std::string fileType)
{
    this->fileType = fileType;
}

void FileWidget::asFileSaver()
{
    saver=true;
}

void FileWidget::asFileOpener()
{
    saver=false;
}

const std::string FileWidget::getSelectedFile()
{
    return ui->txtPath->text().toStdString();
}

void FileWidget::setSelectedFile(const std::string &s)
{
    ui->txtPath->setText(QString::fromStdString(s));
}

FileWidget::~FileWidget()
{
    delete ui;
}

void FileWidget::on_btnChoose_clicked()
{
    QString filename;
    if(saver)
        filename= QFileDialog::getSaveFileName(
                this,
                "Salvar arquivo",
                "",
                QString::fromStdString(fileType)
                );
    else
        filename= QFileDialog::getOpenFileName(
                this,
                "Abrir arquivo",
                "",
                QString::fromStdString(fileType)
                );
    ui->txtPath->setText(filename);
}