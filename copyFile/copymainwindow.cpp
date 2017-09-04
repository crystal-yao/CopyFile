#include "copymainwindow.h"
#include <qfiledialog.h>
#include <qmessagebox.h>

#include "TaskPool.h"
#include "copythread.h"

CopyMainWindow::CopyMainWindow(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	QObject::connect(ui.OriginButton, SIGNAL(clicked() ), this, SLOT(choosefile() ) );
	QObject::connect(ui.TargetButton, SIGNAL(clicked() ), this, SLOT(chooseDirectory() ) );
	QObject::connect(ui.copyButton, SIGNAL(clicked() ), this, SLOT(copyFile() ) );
	//��ʼ�����󣬸��Ƽ�ӦʧЧ
	QObject::connect(ui.copyButton, SIGNAL(clicked() ), this, SLOT(unableCopy() ) );
	//��������ı��߳�������̨��Ӧ��Ӧ�ı�
	QObject::connect(ui.spinBox, SIGNAL(valueChanged(int) ), this, SLOT(changeThreadCount(int) ) );
	//���ȡ������Ӧֹͣ����
	QObject::connect(ui.quitButton, SIGNAL(clicked() ), this, SLOT(cancel() ) );
	QObject::connect(ui.closeButton, SIGNAL(clicked() ), this, SLOT(close() ) );
	threadNum = 10;
	finished = 0;
}

CopyMainWindow::~CopyMainWindow()
{
	//while(!threads.isEmpty() ) {
	//			CopyThread* tmp = threads.front();
	//			threads.pop_front();
	//			delete tmp;
	//		}
}

void CopyMainWindow::choosefile() {
	originFileName = QFileDialog::getOpenFileName(this, QString::fromWCharArray(L"��ѡ���ļ�"),"","",0);
	if( !originFileName.isNull() ) {
		ui.OriginLine->setText( originFileName);
	}
}

void CopyMainWindow::chooseDirectory() {
	targetDirectory = QFileDialog::getExistingDirectory(this, tr("��ѡ��Ŀ¼"),
		"",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	if( !targetDirectory.isNull() ) {
		ui.TargetLine->setText( targetDirectory);
	}
}

//ʵ����һ��TaskPool����������߳���ɿ���
void CopyMainWindow::copyFile() {
	//QMessageBox::information(this,tr("Coping..."), QString::fromWCharArray(L"��ʼ����"),0,0);
	ui.quitButton->setText(tr("ȡ��") );
	ui.resultEdit->setText("");
	TaskPool* tasks= TaskPool::initTasks(this,originFileName, targetDirectory, threadNum);
	targetFileName=originFileName.section('/',-1);
	finished = 0;
	time.restart();
	for(int i=1;i<= threadNum; i++) {
		CopyThread * cThread = new CopyThread(this,i,originFileName,targetDirectory);
		connect(cThread,SIGNAL(updateValue(QString) ) ,this,SLOT(setText(QString)) );
		connect(cThread,SIGNAL(finished()), this, SLOT(quit()) );
		cThread->start();
		threads.append(cThread);
	}
	//QMessageBox::information(this,tr("Coping..."), QString::fromWCharArray(L"��������"),0,0);
}

//�ڽ����resultEdit�����������
void CopyMainWindow::setText( QString str) {
	ui.resultEdit->append(str);
}

//�߳����ı�ʱ���ú�̨�е��߳�������������߳������ĺϷ��Լ��
void CopyMainWindow::changeThreadCount(int count) { 
	if(count <1 ) {
		QMessageBox::information(this,tr("ERROR"), QString::fromWCharArray(L"�߳����������0"),0,0);
		ui.copyButton->setEnabled(false);
	}
	else {
		threadNum = count;
		if( !ui.copyButton->isEnabled() ) {
			ui.copyButton->setEnabled(true);
		}
	}
}

//��ʼ�����󣬽����Ƽ�ʧЧ
void CopyMainWindow::unableCopy() {
	if( ui.copyButton->isEnabled() ) {
			ui.copyButton->setEnabled(false);
		}
	if( ui.closeButton->isEnabled() ) {
		ui.closeButton->setEnabled(false);
	}
}

//�����߳���ɺ�ȡ������Ϊȷ����
void CopyMainWindow::quit() {
	finished++;
	if(finished == threadNum) {
		QString str = "�����ļ���ʱ " + QString::number( time.elapsed()/1000.0) + "�롣";
		ui.resultEdit->append(str);
		ui.quitButton->setText(tr("ȷ��") );
		ui.copyButton->setEnabled(true);
		ui.closeButton->setEnabled(true);
			TaskPool::releaseTask();
			while(!threads.isEmpty() ) {
				CopyThread* tmp = threads.front();
				threads.pop_front();
				delete tmp;
			}
	}
}

//ȡ�����ƺ�ɾ���õ����ļ�
void CopyMainWindow::cancel() {
	if( finished != threadNum ) {
		for(int i=0;i < threads.size(); i++ ) {
			CopyThread* tmp = threads.front();
			threads.pop_front();
			tmp->stop();
		}
		QString delpath = targetDirectory+'\\'+targetFileName;
		QFile::remove(delpath);
	}
}
