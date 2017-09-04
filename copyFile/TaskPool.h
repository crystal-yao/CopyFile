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
	static Task* getTask( );   //��tasks��ȡ��һ�����񵽲���
	static void releaseTask();
private:
	QList<Task> tasks;
	int countThread;   //�����߳���
	long long fileSize;    //�ļ���С
	QString originalPath;   //�ļ�ԭ·��
	QString fileName;   //�ļ�����
	QString targetPath;  //Ŀ��·��
	QMutex mMutex;    //����tasks�Ļ�����
};

#endif