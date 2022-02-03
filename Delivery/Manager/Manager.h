#pragma once
#include "../Collector/Collector.h"
#include "../Collector/CollectorChooseYourself.h"
#include "../Collector/CollectorL.h"
#include "../Collector/CollectorM.h"
#include "../Collector/CollectorS.h"
#include "../ListFoodsAndDrinks/ListFoodsAndDrinks.h"
#include "../Ration/Ration.h"

// Менеджер магазина
class Manager
{

public:

	// Конструктор с параметрами
	Manager( Collector* collector, ListFoodsAndDrinks* list );

	// Деструктор
	virtual ~Manager();

	// Задать сборищка
	void setCollector( Collector* collector ,ListFoodsAndDrinks* list );

	// Выдать рацион
	Ration<MAX_DD>* getRation();


private:

	// Ссылка на сборщика
	Collector* collector;

	// Ссылка на лист еды и напитков
	ListFoodsAndDrinks* list;
};

