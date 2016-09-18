#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPaintEvent>
#include "Player.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

	void InitPlayers();
protected:
    void paintEvent(QPaintEvent *);

private:
	void DrawBK();
	void DrawCards();

	void DrawPlayer1();
	void DrawPlayer2();
	void DrawPlayerMe();

private:
    Ui::MainWindow *ui;

	Player m_player1;
	Player m_player2;
	Player m_playerMe;

	QPixmap m_CardsImage;
};

#endif // MAINWINDOW_H
