#pragma once
#include "Card.h"
#include "qvector.h"

class Player
{
public:
	Player(void);
	~Player(void);


	QVector<Card*> m_cards;
};

