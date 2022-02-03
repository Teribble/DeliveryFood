#pragma once

#define NULL 0


#include "../Dish/Dish.h"
#include "../Drink/Drink.h"

// Завтрак
template <const int preset> 
class Breakfast 
{
public:

	// Конструктор
	Breakfast();

	// Конструктор копирования
	Breakfast( const Breakfast& source );

	// Дестркутор
	virtual ~Breakfast();

	// Добавить блюдо
	void addDish( const Dish* dish );

	// Добавить напиток
	void addDrink( const Drink* drink );

	// Возращает указатель на массив блюд
	Dish* getDishes() const;

	// Возращает указатель на массив напитков
	Drink* getDrinks() const;

	// Возращает количество блюд в завтраке
	int getDishesCounter() const;

	// Возращает количество напитков в завтраке
	int getBeveragesCounter() const;

	// Возращает максимальное кол-во блюд и напитков
	int getCapasity() const;

	// Перегрузка оператора равно
	Breakfast& operator=( const Breakfast& source );


private:

	// Массив блюд
	Dish* dishes;

	// Массив напитков
	Drink* drinks;

	// Проверяет, есть ли блюда
	bool isEmptyDishes();

	// Проверяет, не полон ли список блюд
	bool isFullDishes();

	// Проверячет, есть ли напитки
	bool isEmptyDrinks();

	// Проверяет, не полон ли список напитков
	bool isFullDrinks();

	// Общее количество напитков и блюд
	int capasity;

	// Счетчик блюд
	int dishesCounter;

	// Счетчик напитков
	int drinksCounter;
};

template<int preset>
inline Breakfast<preset>::Breakfast()
{
	dishes = new Dish[preset];
	drinks = new Drink[preset];
	dishesCounter = 0;
	drinksCounter = 0;
	capasity = preset;
}

template<int preset>
inline Breakfast<preset>::Breakfast( const Breakfast& source )
{
	*this = source;
}

template<int preset>
inline Breakfast<preset>::~Breakfast()
{
	if(!isEmptyDishes())
		delete[] dishes;


	if(!isEmptyDrinks())
		delete[] drinks;
}

template<int preset>
inline void Breakfast<preset>::addDish( const Dish* dish )
{
	if(!isFullDishes())
		dishes[ dishesCounter++ ] = *dish;
}

template<int preset>
inline void Breakfast<preset>::addDrink( const Drink* drink )
{
	if(!isFullDrinks())
		drinks[ drinksCounter++ ] = *drink;
}

template<int preset>
inline Dish* Breakfast<preset>::getDishes() const
{
	return dishes;
}

template<int preset>
inline Drink* Breakfast<preset>::getDrinks() const
{
	return drinks;
}

template<int preset>
inline int Breakfast<preset>::getDishesCounter() const
{
	return dishesCounter;
}

template<int preset>
inline int Breakfast<preset>::getBeveragesCounter() const
{
	return drinksCounter;
}

template<int preset>
inline int Breakfast<preset>::getCapasity() const
{
	return capasity;
}

template<int preset>
inline Breakfast<preset>& Breakfast<preset>::operator=( const Breakfast& source )
{
	if(!isEmptyDishes())
	{
		delete[] dishes;
		dishes = new Dish[ preset ];
		dishes = source.getDishes();
		dishesCounter = source.getDishesCounter();
		capasity = source.getCapasity();
	}

	if(!isEmptyDrinks())
	{
		delete[] drinks;
		drinks = new Drink[ preset ];
		drinks = source.getDrinks();
		drinksCounter = source.getBeveragesCounter();
		capasity = source.getCapasity();
	}

	return *this;
}

template<int preset>
inline bool Breakfast<preset>::isEmptyDishes()
{
	return NULL == dishesCounter;
}

template<int preset>
inline bool Breakfast<preset>::isFullDishes()
{
	return dishesCounter == capasity;
}

template<int preset>
inline bool Breakfast<preset>::isEmptyDrinks()
{
	return NULL == drinksCounter;
}

template<int preset>
inline bool Breakfast<preset>::isFullDrinks()
{
	return drinksCounter == capasity;
}