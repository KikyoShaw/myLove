#pragma once

#include <QtWidgets/QWidget>
#include "ui_MyLove.h"

class MyLove : public QWidget
{
    Q_OBJECT

public:
    MyLove(QWidget *parent = Q_NULLPTR);

private:
    Ui::MyLoveClass ui;
};
