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
    QString text = QStringLiteral("送\n给\n某\n个\n会\n陪\n伴\n我\n一\n生\n的\n女\n孩");
    int i = 1;
    int w, h;
    // 定义分辨率标识,适配多种分别率
    // 0 -> 1920 * 1080
    // 1 -> 1366 * 768
    int resolution;
};

#endif // FIREWIDGET_H
