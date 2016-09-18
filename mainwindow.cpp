#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qpainter.h"
#include "qdatetime.h"
#include <QDebug>

#define CARD_WIDTH	76
#define CARD_HEIGHT	116

#define START_X		400
#define START_Y		500

#define CARD_COUNT	54

#define CARD_H_DISTANCE	18
#define CARD_V_DISTANCE	22

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
	ui->mainToolBar->hide();
	ui->menuBar->hide();


	m_CardsImage = QPixmap(":/new/Image/cards.png");
	QPixmap bk(":/new/Image/BK.png");
	resize(bk.size());
	//resize(1200,800);

	QPalette palette;
	palette.setBrush( QPalette::Window,QBrush(bk));
	setPalette(palette); 

	InitPlayers();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent( QPaintEvent * )
{
	//DrawCards();
	DrawPlayer1();
	DrawPlayer2();
	DrawPlayerMe();

	update();
}

void MainWindow::DrawBK()
{

}

void MainWindow::DrawCards()
{
	QPainter painter(this);

	for (int i=0;i<m_playerMe.m_cards.size();i++)
	{
		Card* pCard = m_playerMe.m_cards[i];
		//�˿˶�Ӧ��ͼƬλ��
		QRect rcSrc( 1+ (pCard->m_nNumber - 1)*(CARD_WIDTH+1), 1+pCard->m_type*(CARD_HEIGHT+1),CARD_WIDTH,CARD_HEIGHT);
		QRect rcTarget(START_X + i*30,START_Y,CARD_WIDTH,CARD_HEIGHT);
		painter.drawPixmap(rcTarget,m_CardsImage,rcSrc);
	}

}

void MainWindow::InitPlayers()
{
	//ϴ�Ʒ����㷨��54�����ִ���54���ƣ�����˳�����ȡ2�����ֽ���λ�ã���1000�Σ���Ȼ�����η���
	int numbers[54];
	for (int i=0; i<CARD_COUNT;i++)
	{
		numbers[i] = i;
	}
	//����54��
	int i,j,nTimes=1000,tmp;
	while(nTimes--)
	{
		qsrand(QTime::currentTime().msec());
		i=qrand()%CARD_COUNT;
		j=qrand()%CARD_COUNT;
		tmp=numbers[i];
		numbers[i]=numbers[j];
		numbers[j]=tmp;
	}
	//����
	for(i=0;i<CARD_COUNT-3;i++)
	{
		qDebug()<<"number["<<i<<"] "<< numbers[i];
		CARD_TYPE cardType = (CARD_TYPE)( numbers[i]/13 );	//��0~12�ڵ����ֳ���13=0,�Ǻ��ҵ�һ��
		int nNumber = numbers[i]%13+1;
		Card* pCard = new Card(cardType,nNumber);
		if (i%3 == 0)
		{
			m_player1.m_cards.push_back(pCard);
		}
		else if (i%3 == 1)
		{
			m_player2.m_cards.push_back(pCard);
		}
		else if (i%3 == 2)
		{
			m_playerMe.m_cards.push_back(pCard);
		}
	}
}

void MainWindow::DrawPlayer1()
{
	int x = 200;
	int y = 100;
	QPainter painter(this);

	for (int i=0;i<m_player1.m_cards.size();i++)
	{
		Card* pCard = m_player1.m_cards[i];

		//�˿˶�Ӧ��ͼƬλ��
		QRect rcSrc( 1+ (pCard->m_nNumber - 1)*(CARD_WIDTH+1), 1+pCard->m_type*(CARD_HEIGHT+1),CARD_WIDTH,CARD_HEIGHT);
		QRect rcTarget(x,y + i*CARD_V_DISTANCE,CARD_WIDTH,CARD_HEIGHT);
		painter.drawPixmap(rcTarget,m_CardsImage,rcSrc);
	}
}

void MainWindow::DrawPlayer2()
{
	int x = 900;
	int y = 100;
	QPainter painter(this);

	for (int i=0;i<m_player2.m_cards.size();i++)
	{
		Card* pCard = m_player2.m_cards[i];
		//�˿˶�Ӧ��ͼƬλ��
		QRect rcSrc( 1+ (pCard->m_nNumber - 1)*(CARD_WIDTH+1), 1+pCard->m_type*(CARD_HEIGHT+1),CARD_WIDTH,CARD_HEIGHT);
		QRect rcTarget(x,y + i*CARD_V_DISTANCE,CARD_WIDTH,CARD_HEIGHT);
		painter.drawPixmap(rcTarget,m_CardsImage,rcSrc);
	}
}

void MainWindow::DrawPlayerMe()
{
	QPainter painter(this);

	for (int i=0;i<m_playerMe.m_cards.size();i++)
	{
		Card* pCard = m_playerMe.m_cards[i];
		//�˿˶�Ӧ��ͼƬλ��
		QRect rcSrc( 1+ (pCard->m_nNumber - 1)*(CARD_WIDTH+1), 1+pCard->m_type*(CARD_HEIGHT+1),CARD_WIDTH,CARD_HEIGHT);
		QRect rcTarget(START_X + i*CARD_H_DISTANCE,START_Y,CARD_WIDTH,CARD_HEIGHT);
		painter.drawPixmap(rcTarget,m_CardsImage,rcSrc);
	}
}
