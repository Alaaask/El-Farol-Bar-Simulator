#include "simulate.h"
#include <QGridLayout>

DialogSimulate::DialogSimulate(QWidget *parent)
    : QDialog(parent)
{
    // 初始化变量
    simulate_welcome_message = "This is El Farol Bar Simulator!";

    // 初始化部件对象指针
    button_return = new QPushButton("Return");

    // Welcome message
    simulate_label = new QLabel(simulate_welcome_message);

    // 使用网格布局，还有水平和垂直布局
    QGridLayout *Grid = new QGridLayout;

    // 参数含义:widget部件指针,所在行,所在列,(行宽,列宽,)对齐方式
    Grid->addWidget(simulate_label,1,1,1,4,Qt::Alignment());
    Grid->addWidget(button_return,9,2,Qt::Alignment());

    // 把Grid布局设置给当前创建的对话框对象
    this->setLayout(Grid);

    // 实现连接函数  Connect函数参数 (pushbutton,signal,this指针,slot函数)
    connect(button_return,SIGNAL(clicked(bool)),this,SLOT(on_button_return_clicked()));

}

DialogSimulate::~DialogSimulate()
{

}

// 实现槽函数
void DialogSimulate::on_button_return_clicked()
{
    emit change_from_simulate(SIMULATE2START);
}

void DialogSimulate::restart()
{
// 更新变量 并重新游戏(调用某函数开始)
}

