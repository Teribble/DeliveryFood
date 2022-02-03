#pragma once
#include <iostream>

// Блюдо
class Dish
{
public:
	
	// Конструктор
	Dish();

	// Конструктор с параметрами
	Dish( std::string nameDish, int caloriesDish , double priceDish );

	// Конструктор копирования
	Dish( const Dish& d );

	// Вернет имя блюда
	std::string getNameDish() const;

	// Вернет кол-во каллорий блюда
	int getCaloriesDish() const;

	// Вернет цену блюда
	double getPriceDish() const;

	// Перегрузка оператора равно
	Dish& operator=( const Dish& d );

private:

	// Название блюда
	std::string nameDish;

	// Кол-во каллорий
	int caloriesDish;

	// Цена
	double priceDish;

};

