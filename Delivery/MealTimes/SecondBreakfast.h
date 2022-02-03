#pragma once

#define NULL 0

class Dish;
class Drink;

// Второй завтрак
template <const int preset>
class SecondBreakfast
{
public:

	// Конструктор
	SecondBreakfast();

	// Конструктор копирования
	SecondBreakfast( const SecondBreakfast& source );

	// Дестркутор
	virtual ~SecondBreakfast();

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
	SecondBreakfast& operator=( const SecondBreakfast& source );

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
inline SecondBreakfast<preset>::SecondBreakfast()
{
	dishes = new Dish[ preset ];
	drinks = new Drink[ preset ];
	dishesCounter = 0;
	drinksCounter = 0;
	capasity = preset;
}

template<int preset>
inline SecondBreakfast<preset>::SecondBreakfast( const SecondBreakfast& source )
{
	*this = source;
}

template<int preset>
inline SecondBreakfast<preset>::~SecondBreakfast()
{
	if(!isEmptyDishes())
		delete[] dishes;


	if(!isEmptyDrinks())
		delete[] drinks;
}

template<int preset>
inline void SecondBreakfast<preset>::addDish( const Dish* dish )
{
	if(!isFullDishes())
		dishes[ dishesCounter++ ] = *dish;
}

template<int preset>
inline void SecondBreakfast<preset>::addDrink( const Drink* drink )
{
	if(!isFullDrinks())
		drinks[ drinksCounter++ ] = *drink;
}

template<int preset>
inline Dish* SecondBreakfast<preset>::getDishes() const
{
	return dishes;
}

template<int preset>
inline Drink* SecondBreakfast<preset>::getDrinks() const
{
	return drinks;
}

template<int preset>
inline int SecondBreakfast<preset>::getDishesCounter() const
{
	return dishesCounter;
}

template<int preset>
inline int SecondBreakfast<preset>::getBeveragesCounter() const
{
	return drinksCounter;
}

template<int preset>
inline int SecondBreakfast<preset>::getCapasity() const
{
	return capasity;
}

template<int preset>
inline SecondBreakfast<preset>& SecondBreakfast<preset>::operator=( const SecondBreakfast& source )
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
inline bool SecondBreakfast<preset>::isEmptyDishes()
{
	return NULL == dishesCounter;
}

template<int preset>
inline bool SecondBreakfast<preset>::isFullDishes()
{
	return dishesCounter == capasity;
}

template<int preset>
inline bool SecondBreakfast<preset>::isEmptyDrinks()
{
	return NULL == drinksCounter;
}

template<int preset>
inline bool SecondBreakfast<preset>::isFullDrinks()
{
	return drinksCounter == capasity;
}