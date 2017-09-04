#include "TaskPool.h"

#include <qfile.h>
#include <qiterator.h>
#include <qdebug.h>
#include <qmessagebox.h>

TaskPool* TaskPool::instance = nullptr;
TaskPool::TaskPool(QObject *parent)
	: QObject(parent)
{
	countThread = 0;
}


TaskPool::~TaskPool(void)
{
}

TaskPool::TaskPool(QObject *parent,QString filename, QString targetpath, int countOfThread) : QObject(parent)
{
	fileName = filename.section('/',-1);
	originalPath = filename.section('/',0,-2);
	targetPath = targetpath;
	countThread = countOfThread;
}

TaskPool::TaskPool(QObject *parent,QString filename, QString targetpath) : QObject(parent)
{
	fileName = filename.section('/',-1);
	originalPath = filename.section('/',0,-2);
	targetPath = targetpath;
	countThread = 1;
}

TaskPool* TaskPool::initTasks(QObject *parent,QString filename, QString targetpath, int countOfThread) {

	/*instance.fileName = filename.section('/',-1);
	instance.originalPath = filename.section('/',0,-2);
	instance.targetPath = targetpath;
	instance.countThread = countOfThread;*/

	if( instance == nullptr) {
		instance = new TaskPool(parent, filename,  targetpath,  countOfThread);
	}

	QFile in(instance->originalPath + '/' +instance->fileName);
	if(!in.open(QIODevice::ReadOnly)) {
		qDebug() << "Fail to open file: " << instance->fileName << ".\n";
		return nullptr;
	}
	instance->fileSize = in.size();
	QFile out(instance->targetPath + '/' + instance->fileName);
	if(!out.open(QIODevice::ReadWrite) ) {
		return nullptr;
	}
	if(!out.resize(instance->fileSize) ) {
		qDebug() << "Fail to resize target file.\n";
		return nullptr;
	}
	out.close();
	in.close();
	long long step = (instance->fileSize) /(instance->countThread);
	long long tail = (instance->fileSize) % (instance->countThread);
	int i;
	instance->mMutex.lock();
	for(i=0;i < (instance->countThread)-1; i++) {
		Task tmp(i*step,step);
		instance->tasks.append(tmp);
	}
	Task tmp(i*step,step+tail);
	instance->tasks.push_front(tmp);
	instance->mMutex.unlock();
	return instance;

	//饿汉模式的代码
	/*QFile in(instance.originalPath + '/' +instance.fileName);
	if(!in.open(QIODevice::ReadOnly)) {
		qDebug() << "Fail to open file: " << instance.fileName << ".\n";
		return nullptr;
	}
	instance.fileSize = in.size();
	QFile out(instance.targetPath + '/' + instance.fileName);
	if(!out.open(QIODevice::ReadWrite) ) {
		return nullptr;
	}
	if(!out.resize(instance.fileSize) ) {
		qDebug() << "Fail to resize target file.\n";
		return nullptr;
	}
	out.close();
	in.close();
	int step = (instance.fileSize) /(instance.countThread);
	int tail = (instance.fileSize) % (instance.countThread);
	int i;
	instance.mMutex.lock();
	for(i=0;i < (instance.countThread)-1; i++) {
		Task tmp(i*step,step);
		instance.tasks.append(tmp);
	}
	Task tmp(i*step,step+tail);
	instance.tasks.push_front(tmp);
	instance.mMutex.unlock();
	return &instance;*/
}

Task* TaskPool::getTask( ) {
	if( instance->tasks.isEmpty() )
		return nullptr;
	(instance->mMutex).lock();
	Task* ans =new Task( (instance->tasks).front() );
	instance->tasks.pop_front();
	instance->mMutex.unlock();
	return ans;

	/*if( instance.tasks.isEmpty() )
		return nullptr;
	(instance.mMutex).lock();
	Task* ans = new Task( (instance.tasks).front() );
	instance.tasks.pop_front();
	instance.mMutex.unlock();
	return ans;*/
}

void TaskPool::releaseTask() {
	if(instance != nullptr)
	delete instance;
	instance = nullptr;
}