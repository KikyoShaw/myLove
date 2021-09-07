#include "MyLove.h"
#include "FireWidget.h"
#include <QtWidgets/QApplication>
#include <QMediaPlayer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

	QMediaPlayer *player = new QMediaPlayer();
	if (player) {
		player->setMedia(QMediaContent(QUrl("qrc:/music/qrc/music/bgm.mp3")));
		player->play();
		// µ¥ÇúÑ­»·
		QMediaObject::connect(player, &QMediaPlayer::stateChanged, player, &QMediaPlayer::play);
	}
	FireWidget w;
    w.show();
    return a.exec();
}
