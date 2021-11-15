#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QParallelAnimationGroup>
namespace Ui {
class Dialog;
}

class Dialog : public QDialog {
    Q_OBJECT

  public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    QParallelAnimationGroup *  m_group;

//    void show();
    int exec();
  private slots:


  private:
    Ui::Dialog *ui;

};

#endif // DIALOG_H
