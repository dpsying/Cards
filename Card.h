#pragma once

//enum CARD_TYPE{
//	CARD_spade = 0,	//黑桃
//	CARD_heart,		//红桃
//	CARD_club,		//梅花
//	CARD_diamond,		//方块
//	CARD_king,		//王
//	CARD_MAX,
//};

enum CARD_TYPE{
	CARD_HeiTao = 0,	//黑桃
	CARD_HongTao,		//红桃
	CARD_MeiHua,		//梅花
	CARD_FangKuai,	//方块
	CARD_Wang,		//王
	CARD_MAX,
};

class Card
{
public:
	Card(void);
	Card(CARD_TYPE t,int n);
	~Card(void);

public:
	CARD_TYPE m_type;
	int m_nNumber;

};

