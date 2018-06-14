#include "play.h"
#include <QGridLayout>

DialogPlay::DialogPlay(QWidget *parent)
    : QDialog(parent)
{
    play_welcome_message = "Enjoy El Farol Bar game!";
    play_label = new QLabel(play_welcome_message);

    set_strategies = false;

    button_return = new QPushButton("Return");
    button_submit = new QPushButton("Submit");
    button_choose_strategies = new QPushButton("Choose Strategies");

    button_go_to_bar = new QRadioButton("Search from the &cursor", this);
    button_stay_at_home = new QRadioButton("Search from the &cursor", this);
    buttons_chioce = new QButtonGroup(this);
    buttons_chioce->setExclusive(true);


    // 使用网格布局，还有水平和垂直布局
    QGridLayout *Grid = new QGridLayout;

    // 参数含义:widget部件指针,所在行,所在列,(行宽,列宽,)对齐方式
    Grid->addWidget(play_label,1,1,1,4,Qt::Alignment());
    Grid->addWidget(button_return,20,5,Qt::Alignment());
    Grid->addWidget(button_go_to_bar,10,5,Qt::Alignment());
    Grid->addWidget(button_stay_at_home,11,5,Qt::Alignment());
    Grid->addWidget(button_submit,15,5,Qt::Alignment());
    Grid->addWidget(button_choose_strategies,10,1,Qt::Alignment());

    // 把Grid布局设置给当前创建的对话框对象
    this->setLayout(Grid);

    // 实现连接函数  Connect函数参数 (pushbutton,signal,this指针,slot函数)
    connect(button_return,SIGNAL(clicked(bool)),this,SLOT(on_button_return_clicked()));
    connect(button_submit,SIGNAL(clicked(bool)),this,SLOT(on_button_submit_clicked()));
    connect(button_choose_strategies,SIGNAL(clicked(bool)),this,SLOT(on_button_choose_strategies_clicked()));

}

DialogPlay::~DialogPlay()
{

}

// 实现槽函数
void DialogPlay::on_button_return_clicked()
{
    emit change_from_play(PLAY2START);
}

void DialogPlay::on_button_submit_clicked()
{
    // Check是否设置了策略，且注意策略设置了就不能改变了，这个在点击设置策略的时候才有用
    if (set_strategies) {
        alert_box = QMessageBox::critical(0,
                                          "critical message",
                                          "You have not set strategies. Please set them first.",
                                          QMessageBox::Ok | QMessageBox::Default,
                                          QMessageBox::Cancel | QMessageBox::Escape,
                                          0);
        alert_box->exec();
    }

    else {
        // 得到单选框讯号
        // 并且发送给后台函数 用信号槽
        // 单选框归零
    }

}

void DialogPlay::on_button_choose_strategies_clicked() {

    if (set_strategies) {
        alert_box = QMessageBox::critical(0,
                                          "critical message",
                                          "You have set strategies already. They cannot be changed",
                                          QMessageBox::Ok | QMessageBox::Default,
                                          QMessageBox::Cancel | QMessageBox::Escape,
                                          0);
        alert_box->exec();
    }

    else {
        dlg_choose_strategies = new DialogChooseStrategies;
        int set = dlg_choose_strategies->exec();// 写到这里
    }
}

void DialogPlay::restart()
{
// 更新变量 并重新游戏(调用某函数开始)
}
