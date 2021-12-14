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
    QString text = QStringLiteral("��\n��\nĳ\n��\n��\n��\n��\n��\nһ\n��\n��\nŮ\n��");
    int i = 1;
    int w, h;
    // ����ֱ��ʱ�ʶ,������ֱַ���
    // 0 -> 1920 * 1080
    // 1 -> 1366 * 768
    int resolution;
};

#endif // FIREWIDGET_H
