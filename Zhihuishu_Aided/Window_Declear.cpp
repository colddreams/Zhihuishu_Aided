#include "Window_Declear.h"

Window_Declear::Window_Declear(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);//��ֹ���
	setFixedSize(this->width(), this->height());//��ֹ�ı䴰�ڴ�С
	setWindowIcon(QIcon(":/Zhihuishu_Aided/main_ico.ico"));//������ͼ��
	setWindowTitle(QStringLiteral("�ǻ����������"));//����������
	iconImg = QImage(":/Zhihuishu_Aided/main_ico.png");
	ui.pushButton_1->setDisabled(1);

	connect(ui.checkBox, SIGNAL(clicked()), this, SLOT(EnabledNext()));//����
	connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(NextWindow()));//����
	connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(close()));//����
}

Window_Declear::~Window_Declear()
{

}

void Window_Declear::paintEvent(QPaintEvent *event)//���������Ͻǿؼ�
{
	QPainter painter(this);
	painter.drawImage(QRect(10, 30, 100, 100), iconImg);
}

void Window_Declear::EnabledNext(void)
{
	if (ui.checkBox->isChecked())
	{
		ui.pushButton_1->setEnabled(1);
	}
	else
	{
		ui.pushButton_1->setDisabled(1);
	}
}

void Window_Declear::NextWindow(void)
{
	this->close();
	NextWin = new Window_VideoAreaScreen;
	NextWin->show();
}