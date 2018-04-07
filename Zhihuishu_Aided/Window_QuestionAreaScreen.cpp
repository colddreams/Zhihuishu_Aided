#include "Window_QuestionAreaScreen.h"

Window_QuestionAreaScreen::Window_QuestionAreaScreen(QPoint Start1_isd, QPoint End1_isd, QWidget *parent) : QWidget(parent)
{
	Start1 = Start1_isd, End1 = End1_isd;
	ui.setupUi(this);
	setWindowFlags(windowFlags()&~Qt::WindowMaximizeButtonHint);//��ֹ���
	setFixedSize(this->width(), this->height());//��ֹ�ı䴰�ڴ�С
	setWindowIcon(QIcon(":/Zhihuishu_Aided/main_ico.ico"));//������ͼ��
	setWindowTitle(QStringLiteral("�ǻ����������"));//����������
	Img = QImage(":/Zhihuishu_Aided/example2.png");

	connect(ui.pushButton_1, SIGNAL(clicked()), this, SLOT(begin()));//����
}

Window_QuestionAreaScreen::~Window_QuestionAreaScreen()
{

}

void Window_QuestionAreaScreen::paintEvent(QPaintEvent *event)//���������Ͻǿؼ�
{
	QPainter painter(this);
	painter.drawImage(QRect(30, 30, 384, 191), Img);
}

void Window_QuestionAreaScreen::begin(void)
{
	this->close();
	Sleep(1000);
	ShotWin = new ScreenShot2(Start1,End1);
	ShotWin->show();
}