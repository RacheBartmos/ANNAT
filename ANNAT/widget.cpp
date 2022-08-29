#include "widget.h"
#include "ui_widget.h"
#include <QBoxLayout>
#include "rolllabel.h"
#include "card.h"
#include <QStyle>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QString text = "四川疾控健康提示（2022年8月28日21时）【点击查看详情】";
    QWidget* title = new QWidget;
    title->setStyleSheet("background-color: white;border-radius: 10px;");

    QHBoxLayout* titleHB = new QHBoxLayout;
    ScrollLabel* titleLabel = new ScrollLabel();
    titleLabel->setText(text);
    titleHB->addWidget(titleLabel);
    title->setLayout(titleHB);

    QVBoxLayout* vb = new QVBoxLayout;
    QIcon icon = QApplication::style()->standardIcon(QStyle::SP_DriveNetIcon);
    vb->addWidget(title);
    Card* card = new Card;
    vb->addSpacing(10);
    vb->addWidget(card);
    this->setLayout(vb);
}

Widget::~Widget()
{
    delete ui;
}

