#ifndef COPYTHREAD_H
#define COPYTHREAD_H

#include <QThread>
#include <qmutex.h>
#include <TaskPool.h>

#define MAX_BUFFER (1024*1024*2)

class CopyThread : public QThread
{
	Q_OBJECT

public:
	CopyThread(QObject *parent,int id,QString filename, QString targetpath);
	~CopyThread();
	void stop();

protected:
	virtual void run();

private:
	QString originalFile;
	QString originalPath;
	QString targetFile;
	QString targetPath;
	int id;
	Task* task;
	char* inStr;

	static int test;
	static QMutex mMutex;
	bool stopped;
	QMutex stopMutex;

signals:
	void updateValue( QString value);
};

#endif // COPYTHREAD_H
