#ifndef COPYMAINWINDOW_H
#define COPYMAINWINDOW_H

#include <QtGui/QMainWindow>
#include "ui_copymainwindow.h"
#include <QTime>
#include "copythread.h"

class CopyMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	CopyMainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
	~CopyMainWindow();


private:
	Ui::CopyMainWindowClass ui;
	QString originFileName;
	QString targetDirectory;
	QString targetFileName;
	int threadNum;
	int finished;
	QTime time;
	QList<CopyThread*> threads;

	private slots:
		void choosefile();
		void chooseDirectory();
		void copyFile();
		void changeThreadCount(int);
		void setText(const QString);
		void unableCopy();
		void quit();
		void cancel();
};

#endif // COPYMAINWINDOW_H
