#ifndef FIREWIDGET_H
#define FIREWIDGET_H

#include <QWidget>

class QLabel;

class FireWidget : public QWidget
{
    Q_OBJECT
public:
    explicit FireWidget(QWidget *parent = Q_NULLPTR);

private:
	QSize getFireWorkSize();
	void initFireWorks();
    void playMovie(QLabel *label);
	void initText();

private:
    QString text = QStringLiteral("送\n给\n我\n大\n学\n唯\n一\n的\n一\n个\n喜\n欢\n的\n女\n生");
    int i = 1;
    int w, h;
    // 定义分辨率标识,适配多种分别率
    // 0 -> 1920 * 1080
    // 1 -> 1366 * 768
    int resolution;
};

#endif // FIREWIDGET_H
