#pragma once

#define NULL 0

class Dish;
class Drink;

// Ужин
template <const int preset>
class Dinner
{
public:

	// Конструктор
	Dinner();

	// Конструктор копирования
	Dinner( const Dinner& source );

	// Дестркутор
	virtual ~Dinner();

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
	int getCapacity() const;

	// Перегрузка оператора равно
	Dinner& operator=( const Dinner& source );

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
inline Dinner<preset>::Dinner()
{
	dishes = new Dish[ preset ];
	drinks = new Drink[ preset ];
	dishesCounter = 0;
	drinksCounter = 0;
	capasity = preset;
}

template<int preset>
inline Dinner<preset>::Dinner( const Dinner& source )
{
	*this = source;
}

template<int preset>
inline Dinner<preset>::~Dinner()
{
	if(!isEmptyDishes())
		delete[] dishes;


	if(!isEmptyDrinks())
		delete[] drinks;
}

template<int preset>
inline void Dinner<preset>::addDish( const Dish* dish )
{
	if(!isFullDishes())
		dishes[ dishesCounter++ ] = *dish;
}

template<int preset>
inline void Dinner<preset>::addDrink( const Drink* drink )
{
	if(!isFullDrinks())
		drinks[ drinksCounter++ ] = *drink;
}

template<int preset>
inline Dish* Dinner<preset>::getDishes() const
{
	return dishes;
}

template<int preset>
inline Drink* Dinner<preset>::getDrinks() const
{
	return drinks;
}

template<int preset>
inline int Dinner<preset>::getDishesCounter() const
{
	return dishesCounter;
}

template<int preset>
inline int Dinner<preset>::getBeveragesCounter() const
{
	return drinksCounter;
}

template<int preset>
inline int Dinner<preset>::getCapacity() const
{
	return capasity;
}

template<int preset>
inline Dinner<preset>& Dinner<preset>::operator=( const Dinner& source )
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
inline bool Dinner<preset>::isEmptyDishes()
{
	return NULL == dishesCounter;
}

template<int preset>
inline bool Dinner<preset>::isFullDishes()
{
	return dishesCounter == capasity;
}

template<int preset>
inline bool Dinner<preset>::isEmptyDrinks()
{
	return NULL == drinksCounter;
}

template<int preset>
inline bool Dinner<preset>::isFullDrinks()
{
	return drinksCounter == capasity;
}