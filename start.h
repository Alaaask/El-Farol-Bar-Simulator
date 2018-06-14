#ifndef START_H
#define START_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QString>

#define EXIT 0
#define START2SIMULATE 1
#define START2PLAY 2

class DialogStart : public QDialog
{
    Q_OBJECT

public:
    DialogStart(QWidget *parent = 0);
    ~DialogStart();

protected:
    // 声明需要的部件
    QPushButton *button_simulate;
    QPushButton *button_play;
    QPushButton *button_exit;

    QLabel *welcome_label;

    // 声明需要的变量
    QString welcome_message; // 用于显示在welcome_label里面的字符串

signals:
    void change_from_start(int);

    // 声明处理按钮的槽函数
private slots:
    // 按照ui文件默认命名规则
    void on_button_simulate_clicked();
    void on_button_play_clicked();
    void on_button_exit_clicked();

};

#endif // START_H
