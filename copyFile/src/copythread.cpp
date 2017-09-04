#include "copythread.h"

#include <qdebug.h>
#include <qfile.h>
#include <qtextcodec.h>

int CopyThread::test = 5000;
QMutex CopyThread::mMutex;
CopyThread::CopyThread(QObject *parent,int idn,QString filename, QString targetpath)
	: QThread(parent),stopped(false)
{
	originalFile = filename.section('/',-1);
	originalPath = filename.section('/',0,-2);
	targetFile = originalFile;
	targetPath = targetpath;
	id = idn;
	task = nullptr;
	inStr =new char[MAX_BUFFER];
}

CopyThread::~CopyThread()
{
	if(task != nullptr)
		delete task;
	task = nullptr;
	if( inStr != nullptr)
		delete [] inStr;
	inStr = nullptr;
}

void CopyThread::run() {
	QString str = "Thread " + QString::number(id) + " begin to copy file";
	emit updateValue(str);
	/*str = "Thread " + QString::number(id) + " information: copy file from \"" + originalPath + "/" + originalFile + "\" to \"" + targetPath + "\".";
	emit updateValue(str);*/
	task = TaskPool::getTask();
	if(task == nullptr) {
		str = "Thread " + QString::number(id) + " get no task.";
		emit updateValue(str);
		return;
	}
	else{
		str = "Thread " + QString::number(id) + " information: offset is \"" + QString::number(task->getOffset()) + "\" ,length is \"" + QString::number(task->getLength()) + "\".";
		emit updateValue(str);
		QFile in(originalPath + '/' + originalFile);
		if(!in.open(QIODevice::ReadOnly) ) {
			qDebug() << "Thread " << QString::number(id) << ": cannot open file " << originalPath << "/" << originalFile << ".";
			return;
		}
		QFile out(targetPath + '\\' + targetFile);
		if(!out.open(QIODevice::ReadWrite) ) {
			qDebug() << "Thread " << QString::number(id) << ": cannot open file " << targetPath << "/" << targetFile << ".";
			return;
		}
		if(in.seek(task->getOffset()) && out.seek(task->getOffset()) ) {
			long long written=0;
			while(written < task->getLength() ) {
				stopMutex.lock();
				if( stopped) {
					delete []inStr;
					break;
				}
				stopMutex.unlock();
				int result = in.read(inStr,MAX_BUFFER);
				if(result) {
					out.write(inStr, result );
					written += result;
				}
			}
			str =  "Thread " + QString::number(id) + ": successfully copied file.";
		    emit updateValue(str);
		}
		else {
			qDebug() << "Thread " << QString::number(id) << ": fail to call seek().";
		}
		in.close();
		out.close();
		
		//delete[] inStr;
	}
	/*while(test > 0) {
	mMutex.lock();
	test--;
	qDebug() << "Thread " << QString::number(id) << " : get value " << QString::number(test) << "." ;
	mMutex.unlock();
	}*/
}

void CopyThread::stop() {
	stopMutex.lock();
	stopped = true;
	stopMutex.unlock();
}