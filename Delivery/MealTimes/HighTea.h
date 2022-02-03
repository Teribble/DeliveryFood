#pragma once

#define NULL 0

class Dish;
class Drink;

// Полдник
template <const int preset>
class HighTea
{
public:

	// Конструктор
	HighTea();

	// Конструктор копирования
	HighTea( const HighTea& source );

	// Дестркутор
	virtual ~HighTea();

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

	int getCapasity() const;

	HighTea& operator=( const HighTea& source );

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
inline HighTea<preset>::HighTea()
{
	dishes = new Dish[ preset ];
	drinks = new Drink[ preset ];
	dishesCounter = 0;
	drinksCounter = 0;
	capasity = preset;
}

template<int preset>
inline HighTea<preset>::HighTea( const HighTea& source )
{
	*this = source;
}

template<int preset>
inline HighTea<preset>::~HighTea()
{
	if(!isEmptyDishes())
		delete[] dishes;


	if(!isEmptyDrinks())
		delete[] drinks;
}

template<int preset>
inline void HighTea<preset>::addDish( const Dish* dish )
{
	if(!isFullDishes())
		dishes[ dishesCounter++ ] = *dish;
}

template<int preset>
inline void HighTea<preset>::addDrink( const Drink* drink )
{
	if(!isFullDrinks())
		drinks[ drinksCounter++ ] = *drink;
}

template<int preset>
inline Dish* HighTea<preset>::getDishes() const
{
	return dishes;
}

template<int preset>
inline Drink* HighTea<preset>::getDrinks() const
{
	return drinks;
}

template<int preset>
inline int HighTea<preset>::getDishesCounter() const
{
	return dishesCounter;
}

template<int preset>
inline int HighTea<preset>::getBeveragesCounter() const
{
	return drinksCounter;
}

template<int preset>
inline int HighTea<preset>::getCapasity() const
{
	return capasity;
}

template<int preset>
inline HighTea<preset>& HighTea<preset>::operator=( const HighTea& source )
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
inline bool HighTea<preset>::isEmptyDishes()
{
	return NULL == dishesCounter;
}

template<int preset>
inline bool HighTea<preset>::isFullDishes()
{
	return dishesCounter == capasity;
}

template<int preset>
inline bool HighTea<preset>::isEmptyDrinks()
{
	return NULL == drinksCounter;
}

template<int preset>
inline bool HighTea<preset>::isFullDrinks()
{
	return drinksCounter == capasity;
}