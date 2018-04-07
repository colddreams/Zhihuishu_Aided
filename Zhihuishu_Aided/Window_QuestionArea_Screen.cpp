#include "Window_QuestionArea_Screen.h"

ScreenShot2::ScreenShot2(QPoint Start1_isd, QPoint End1_isd, QWidget *parent) : QDialog(parent)//����������ⴰ��
{
	Start1 = Start1_isd, End1 = End1_isd;
	fullScreenPix = QPixmap::grabWindow(QApplication::desktop()->winId());
	fullTempPix = fullScreenPix;
}

void ScreenShot2::showEvent(QShowEvent *event)//��ʾȫ������
{
	showFullScreen();
	setCursor(Qt::CrossCursor);
}

void ScreenShot2::paintEvent(QPaintEvent *event)//��ʾȫ����ͼͼƬ
{
	QPainter painter(this);
	painter.drawPixmap(0, 0, fullTempPix);
	QDialog::paintEvent(event);
}

void ScreenShot2::mousePressEvent(QMouseEvent *event)//��갴��
{
	if (event->button() == Qt::LeftButton)
	{
		startPoint = event->pos();
	}
}

void ScreenShot2::mouseMoveEvent(QMouseEvent *event)//����ƶ�
{
	fullTempPix = fullScreenPix;
	endPonit = event->pos();
	paint(fullTempPix);
}

void ScreenShot2::mouseReleaseEvent(QMouseEvent *event)//���ſ�
{
	if (event->button() == Qt::LeftButton)
	{
		endPonit = event->pos();
		NextWindow();
	}
}

void ScreenShot2::paint(QPixmap &pixmap)//��ͼ���λ���
{
	QPoint startPoint_temp = startPoint;
	QPoint endPonit_temp = endPonit;
	QPainter painter(&pixmap);
	for (int i = 0; i < 3; i++)
	{
		painter.drawRect(QRect(startPoint_temp, endPonit_temp));
		startPoint_temp.setX(startPoint_temp.x() + 1); endPonit_temp.setX(endPonit_temp.x() - 1);
		startPoint_temp.setY(startPoint_temp.y() + 1); endPonit_temp.setY(endPonit_temp.y() - 1);
	}
	update();
}

void ScreenShot2::NextWindow(void)
{
	this->close();
	NextWin = new Window_BrowserWindowAreaScreen(Start1,End1,startPoint, endPonit);
	NextWin->show();
}