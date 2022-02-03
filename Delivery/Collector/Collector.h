#pragma once
#include "../Ration/Ration.h"
#include "../ListFoodsAndDrinks/ListFoodsAndDrinks.h"

#define MAX_DD 5 // максильманое кол-во напитков и блюд
#define MAX_COLLECTOR_S 3
#define MAX_COLLECTOR_M 4
#define MAX_COLLECTOR_L 5

// Сборщик
class Collector
{
public:

	// Собрать завтрак
	virtual void collectBreakfast(ListFoodsAndDrinks* list) = 0;

	// Собрать второй завтак
	virtual void collectSecondBreakfast( ListFoodsAndDrinks* list ) = 0;

	// Собрать обед
	virtual void collectLunch( ListFoodsAndDrinks* list ) = 0;

	// Собрать полдник
	virtual void collectHighTea( ListFoodsAndDrinks* list ) = 0;

	// Собрать ужин
	virtual void collectDinner( ListFoodsAndDrinks* list ) = 0;

	// Вернуть рацион
	virtual Ration<MAX_DD>* getRation() = 0;
};

