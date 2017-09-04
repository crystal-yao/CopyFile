#pragma once

#ifndef TASKPOOL_H
#define TASKPOOL_H

#include <qlist.h>
#include <qstring.h>
#include <qmutex.h>
#include <QObject>

#include <Task.h>

class TaskPool:public QObject
{
	Q_OBJECT
		
private:
	static TaskPool* instance;
private:
	TaskPool(QObject *parent);
	TaskPool(QObject *parent,QString filename,QString targetpath, int countOfThread);
	TaskPool(QObject *parent,QString filename, QString targetpath);
	~TaskPool(void);

public:
	static TaskPool* initTasks(QObject *parent,QString filename,QString targetpath, int countOfThread = 1);
	static Task* getTask( );   //从tasks中取出一个任务到参数
	static void releaseTask();
private:
	QList<Task> tasks;
	int countThread;   //开启线程数
	long long fileSize;    //文件大小
	QString originalPath;   //文件原路径
	QString fileName;   //文件名称
	QString targetPath;  //目标路径
	QMutex mMutex;    //管理tasks的互斥量
};

#endif