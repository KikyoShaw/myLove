#include "FireWidget.h"
#include <QPalette>
#include <QLabel>
#include <QMovie>
#include <QColor>
#include <QDebug>
#include <QTimer>
#include <QMediaPlayer>
#include <QPixmap>
#include <QPainter>
#include <QFont>
#include <QString>
#include <cstring>
#include <QApplication>
#include <QDesktopWidget>
#include <QRect>
#include <QScreen>
#include <QGuiApplication>
#include "HeartWidget.h"

FireWidget::FireWidget(QWidget *parent) : QWidget(parent)
{
    // 设置程序不在任务栏显示且窗体无边框
    this->setWindowFlags(Qt::Tool | Qt::FramelessWindowHint);

	auto desktop = QApplication::desktop();
	int index = 0;
	//获取是否有第二个显示屏
	if (2 == desktop->screenCount())
		index = 1;
	setGeometry(desktop->screenGeometry(index));
    // 全屏显示
    QRect screenRect = desktop->screenGeometry(index);
    w = screenRect.width();
    h = screenRect.height();
    // 设置分别率
    if (w == 1920)
        resolution = 0;
    else if (w <= 1400 && w >= 1280)
        resolution = 1;
    else
        resolution = 1;
    resize(w, h);

    // 设置背景全黑
    QPalette palette;
    palette.setColor(QPalette::Background, QColor(5, 4, 3));
    setAutoFillBackground(true);
    setPalette(palette);

	//初始化烟花
	initFireWorks();

    QTimer *timer = new QTimer(this);
    timer->start(7000);
    connect(timer, &QTimer::timeout, [=]{
        timer->stop();
        this->close();
        HeartWidget *w = new HeartWidget();
        w->show();
    });

    // 文字
	initText();
}

QSize FireWidget::getFireWorkSize()
{
	QSize size = QSize();
	QPixmap pixmap = QPixmap();
	switch (resolution)
	{
	case 0: {
		pixmap.load(":/gif/qrc/gif/fire.gif");
		break;
	}
	case 1: {
		pixmap.load(":/gif/qrc/gif/fire1.gif");
		break;
	}
	default: {
		pixmap.load(":/gif/qrc/gif/fire1.gif");
		break;
	}
	}
	if (!pixmap.isNull()) {
		size = pixmap.size();
	}
	return size;
}

void FireWidget::initFireWorks()
{
	auto size = getFireWorkSize();
	int mw = size.width();
	int mh = size.height();
	QLabel *label1 = new QLabel(this);
	label1->move(w / 2 - mw / 2, h / 2 - mh / 2);
	playMovie(label1);

	QLabel *label2 = new QLabel(this);
	label2->move(w / 2 - mw * 1.5, h / 2 - mh);
	playMovie(label2);

	QLabel *label3 = new QLabel(this);
	label3->move(w / 2 + mw / 2, h / 2 - mh);
	playMovie(label3);

	QLabel *label4 = new QLabel(this);
	label4->move(w / 2 - mw * 1.5, h / 2);
	playMovie(label4);

	QLabel *label5 = new QLabel(this);
	label5->move(w / 2 + mw / 2, h / 2);
	playMovie(label5);
}

void FireWidget::playMovie(QLabel *label)
{
    QMovie *movie = new QMovie(this);
	if (Q_NULLPTR == movie)
		return;
    switch (resolution)
    {
	case 0: {
		movie->setFileName(":/gif/qrc/gif/fire.gif");
		break;
	}
	case 1: {
		movie->setFileName(":/gif/qrc/gif/fire1.gif");
		break;
	}
	default: {
		movie->setFileName(":/gif/qrc/gif/fire1.gif");
		break;
	}
    }
    // 动画
    label->setMovie(movie);
    movie->start();
}

void FireWidget::initText()
{
	QLabel *textLabel = new QLabel(this);
	textLabel->move(80, 100);
	QFont ft;
	switch (resolution)
	{
	case 0:
		ft.setPointSize(28);
		break;
	case 1:
		ft.setPointSize(22);
		break;
	default:
		ft.setPointSize(22);
	}

	textLabel->setFont(ft);
	QPalette pa;
	pa.setColor(QPalette::WindowText, Qt::white);
	textLabel->setPalette(pa);
	textLabel->setWordWrap(true);
	textLabel->setAlignment(Qt::AlignTop);
	textLabel->setText(text);
}

