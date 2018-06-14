#ifndef SIMULATE_H
#define SIMULATE_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QString>

#define SIMULATE2START 3

class DialogSimulate : public QDialog
{
    Q_OBJECT

public:
    DialogSimulate(QWidget *parent = 0);
    ~DialogSimulate();
    void restart();

protected:
    // 声明需要的部件
    QPushButton *button_return;
    QLabel *simulate_label;
    QString simulate_welcome_message;

signals:
    void change_from_simulate(int);

    //声明处理按钮的槽函数
private slots:
    //按照ui文件默认命名规则
    void on_button_return_clicked();

};

#endif // SIMULATE_H
