#pragma once
#include "Collector.h"


class CollectorChooseYourself :
	public Collector
{
public:
	// Конструктор
	CollectorChooseYourself();

	// Деструктор
	virtual ~CollectorChooseYourself();

	// Собрать завтрак
	void collectBreakfast( ListFoodsAndDrinks* list ) override;

	// Собрать второй завтак
	void collectSecondBreakfast( ListFoodsAndDrinks* list ) override;

	// Собрать обед
	void collectLunch( ListFoodsAndDrinks* list ) override;

	// Собрать полдник
	void collectHighTea( ListFoodsAndDrinks* list ) override;

	// Собрать ужин
	void collectDinner( ListFoodsAndDrinks* list ) override;

	// Вернуть ссылку на рацион
	Ration<MAX_DD>* getRation() override;

private:

	Ration<MAX_DD>* ration;

	// Проверка, есть ли рацион
	bool isEmpty();

#pragma region Утилитарные функции
	// Выдать случайное блюдо
	Dish* getRandomDish( ListFoodsAndDrinks* list ) const;

	// Выдать случайный напиток
	Drink* getRandomDrink( ListFoodsAndDrinks* list ) const;
#pragma endregion Утилитарные функции

};

