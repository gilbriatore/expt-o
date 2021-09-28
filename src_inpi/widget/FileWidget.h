#ifndef FILEWIDGET_H
#define FILEWIDGET_H

#include <QWidget>

namespace Ui {
  class FileWidget;
}

class FileWidget : public QWidget
{
    Q_OBJECT

  public:
    explicit FileWidget(QWidget *parent = 0);

    void setFileType(std::string fileType);
    void asFileSaver();
    void asFileOpener();
    void setSelectedFile(const std::string &s);
    const std::string getSelectedFile();

    ~FileWidget();

private slots:
    void on_btnChoose_clicked();

  private:
    Ui::FileWidget *ui;
    bool saver;
    std::string fileType;
};

#endif // FILEWIDGET_H
