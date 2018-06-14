#ifndef PLAY_H
#define PLAY_H

#include <QDialog>
#include <QPushButton>
#include <QLabel>
#include <QString>
#include <QRadioButton>
#include <QMessageBox>
#include "choose_strategies.h"

#define PLAY2START 4

class DialogPlay : public QDialog
{
    Q_OBJECT

public:
    DialogPlay(QWidget *parent = 0);
    ~DialogPlay();
    void restart();

protected:
    // 声明需要的部件
    QPushButton *button_return;
    QPushButton *button_submit;
    QPushButton *button_choose_strategies;
    QRadioButton *button_go_to_bar;
    QRadioButton *button_stay_at_home;
    QButtonGroup *buttons_chioce;

    QMessageBox *alert_box;
    QLabel* play_label;
    QString play_welcome_message;

    DialogChooseStrategies *dlg_choose_strategies;
    bool set_strategies;

signals:
    void change_from_play(int);

    //声明处理按钮的槽函数
private slots:
    //按照ui文件默认命名规则
    void on_button_return_clicked();
    void on_button_submit_clicked();
    void on_button_choose_strategies_clicked();

};

#endif // PLAY_H
