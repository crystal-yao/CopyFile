#include "copymainwindow.h"
#include <QtGui/QApplication>
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
    QTextCodec::setCodecForTr(QTextCodec::codecForLocale());
    QTextCodec::setCodecForLocale(QTextCodec::codecForLocale());
    QTextCodec::setCodecForCStrings(QTextCodec::codecForLocale());
	QApplication a(argc, argv);
	CopyMainWindow w;
	w.show();
	return a.exec();
}
