#pragma once
#include "../Collector/Collector.h"
#include "../Collector/CollectorChooseYourself.h"
#include "../Collector/CollectorL.h"
#include "../Collector/CollectorM.h"
#include "../Collector/CollectorS.h"
#include "../ListFoodsAndDrinks/ListFoodsAndDrinks.h"
#include "../Ration/Ration.h"

// �������� ��������
class Manager
{

public:

	// ����������� � �����������
	Manager( Collector* collector, ListFoodsAndDrinks* list );

	// ����������
	virtual ~Manager();

	// ������ ��������
	void setCollector( Collector* collector ,ListFoodsAndDrinks* list );

	// ������ ������
	Ration<MAX_DD>* getRation();


private:

	// ������ �� ��������
	Collector* collector;

	// ������ �� ���� ��� � ��������
	ListFoodsAndDrinks* list;
};

