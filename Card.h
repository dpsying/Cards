#pragma once

//enum CARD_TYPE{
//	CARD_spade = 0,	//����
//	CARD_heart,		//����
//	CARD_club,		//÷��
//	CARD_diamond,		//����
//	CARD_king,		//��
//	CARD_MAX,
//};

enum CARD_TYPE{
	CARD_HeiTao = 0,	//����
	CARD_HongTao,		//����
	CARD_MeiHua,		//÷��
	CARD_FangKuai,	//����
	CARD_Wang,		//��
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

