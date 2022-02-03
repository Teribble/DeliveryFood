#pragma once
#include <iostream>

// Напиток
class Drink
{
public:

	// Конструктор
	Drink();

	// Конструктор с параметрами
	Drink( std::string nameDrink , int caloriesDrink , double priceDrink );

	// Конструктор копирования
	Drink( const Drink& d );

	// Вернет имя напитка
	std::string getNameDrink() const;

	// Вернет кол-во каллорий напитка
	int getCaloriesDrink() const;

	// Вернет цену напитка
	double getPriceDrink() const;

	// Перегрузка оператора равно
	Drink& operator=( const Drink& d );

private:

	// Название напитка
	std::string nameDrink;

	// Кол-во каллорий
	int caloriesDrink;

	// Цена
	double priceDrink;

};

