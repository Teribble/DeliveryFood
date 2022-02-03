#pragma once
#include "../Dish/Dish.h"
#include "../Drink/Drink.h"
#include "../ListFoodsAndDrinks/ListFoodsAndDrinks.h"

#define MIN_PRICE 100
#define MAX_PRICE 800

#define MIN_COLORIES 10
#define MAX_COLORIES 1600

#define MAX_DRINK_AND_DISHES 5

// Ручной выбор
class ManualSelection
{
public:

	// Возращает ссылку на выбранную еду из списка
	static Dish* selectDishes(  ListFoodsAndDrinks* list);

	// Возращает ссылку на выбранный напиток из списка
	static Drink* selectDrinks(  ListFoodsAndDrinks* list );

};

