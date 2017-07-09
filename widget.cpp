#include "widget.h"
#include "rightpanel.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    //rightPanel *panel=new rightPanel;
    b=new  board;
    QHBoxLayout* layout=new QHBoxLayout;
    layout->addWidget(b);
    //layout->addWidget(panel);
    setLayout(layout);
    QPalette p;
    p.setBrush(this->backgroundRole(),QBrush(QColor(255,255,255)));
    this->setPalette(p);
    this->setAutoFillBackground(true);
    this->setMinimumSize(1200,762);
    this->setMaximumSize(1200,762);
}

Widget::~Widget()
{

}
