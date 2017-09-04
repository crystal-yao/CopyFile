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
	//开始拷贝后，复制键应失效
	QObject::connect(ui.copyButton, SIGNAL(clicked() ), this, SLOT(unableCopy() ) );
	//点击按键改变线程数，后台中应相应改变
	QObject::connect(ui.spinBox, SIGNAL(valueChanged(int) ), this, SLOT(changeThreadCount(int) ) );
	//点击取消键后，应停止程序
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
	originFileName = QFileDialog::getOpenFileName(this, QString::fromWCharArray(L"请选择文件"),"","",0);
	if( !originFileName.isNull() ) {
		ui.OriginLine->setText( originFileName);
	}
}

void CopyMainWindow::chooseDirectory() {
	targetDirectory = QFileDialog::getExistingDirectory(this, tr("请选择目录"),
		"",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);
	if( !targetDirectory.isNull() ) {
		ui.TargetLine->setText( targetDirectory);
	}
}

//实例化一个TaskPool，创建多个线程完成拷贝
void CopyMainWindow::copyFile() {
	//QMessageBox::information(this,tr("Coping..."), QString::fromWCharArray(L"开始拷贝"),0,0);
	ui.quitButton->setText(tr("取消") );
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
	//QMessageBox::information(this,tr("Coping..."), QString::fromWCharArray(L"拷贝结束"),0,0);
}

//在界面的resultEdit框内输出内容
void CopyMainWindow::setText( QString str) {
	ui.resultEdit->append(str);
}

//线程数改变时重置后台中的线程数量，并完成线程数量的合法性检测
void CopyMainWindow::changeThreadCount(int count) { 
	if(count <1 ) {
		QMessageBox::information(this,tr("ERROR"), QString::fromWCharArray(L"线程数必须大于0"),0,0);
		ui.copyButton->setEnabled(false);
	}
	else {
		threadNum = count;
		if( !ui.copyButton->isEnabled() ) {
			ui.copyButton->setEnabled(true);
		}
	}
}

//开始拷贝后，将复制键失效
void CopyMainWindow::unableCopy() {
	if( ui.copyButton->isEnabled() ) {
			ui.copyButton->setEnabled(false);
		}
	if( ui.closeButton->isEnabled() ) {
		ui.closeButton->setEnabled(false);
	}
}

//所有线程完成后，取消键变为确定键
void CopyMainWindow::quit() {
	finished++;
	if(finished == threadNum) {
		QString str = "复制文件耗时 " + QString::number( time.elapsed()/1000.0) + "秒。";
		ui.resultEdit->append(str);
		ui.quitButton->setText(tr("确定") );
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

//取消复制后删除得到的文件
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
