#include "Window_VideoAreaScreen.h"

Window_VideoAreaScreen::Window_VideoAreaScreen(QWidget *parent) : QWidget(parent)
{
	ui.setupUi(this);
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);//��ֹ���
	setFixedSize(this->width(), this->height());//��ֹ�ı䴰�ڴ�С
	setWindowIcon(QIcon(":/Zhihuishu_Aided/main_ico.ico"));//������ͼ��
	setWindowTitle(QStringLiteral("�ǻ����������"));//����������
	Img = QImage(":/Zhihuishu_Aided/example.png");

	connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(begin()));//����
}

Window_VideoAreaScreen::~Window_VideoAreaScreen()
{

}

void Window_VideoAreaScreen::paintEvent(QPaintEvent *event)//���������Ͻǿؼ�
{
	QPainter painter(this);
	painter.drawImage(QRect(30, 30, 384,191), Img);
}

void Window_VideoAreaScreen::begin(void)
{
	this->close();
	Sleep(1000);
	ShotWin = new ScreenShot1;
	ShotWin->show();
}