#ifndef HEAERWIDGET_H
#define HEAERWIDGET_H

#include <QWidget>

class QPainter;
class QTimer;

class HeartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HeartWidget(QWidget *parent = Q_NULLPTR);
    ~HeartWidget();

private:
    void initWindow();
    void initTimer();

protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    const double PI = 3.1415926;
	QPainter *painter = Q_NULLPTR;
    QTimer *timer = Q_NULLPTR;
    int w, h;
    // 定义分辨率标识,适配多种分别率
    // 0 -> 1920 * 1080
    // 1 -> 1366 * 768
    int resolution;
};

#endif // HEAERWIDGET_H
