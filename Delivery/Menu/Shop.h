#pragma once
#pragma region includes
#include <iostream>
#include <iomanip>
#include <string>
#include "../Ration/Ration.h"
#include "../ListFoodsAndDrinks\ListFoodsAndDrinks.h"
#include "../Order\Order.h"
#include "../Manager\Manager.h"
#pragma endregion includes

class Shop
{
public:

	// Конструктор
	Shop();

	// Деструктор
	virtual ~Shop();

	// Открыть смену
	void openShift();

	// Оформить заказ
	void checkout(Collector* collector);

	// Вывести заказ
	void showOrder();

	// Выбор
	void choice();

private:

	// Ссылка на список напитоков и еды
	ListFoodsAndDrinks* list;

	// Ссылка на менеджера
	Manager* manager;

	// Ссылка на заказ
	Order* orders;

};

