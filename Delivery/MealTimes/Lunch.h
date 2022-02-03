#pragma once

#define NULL 0

class Dish;
class Drink;

// Обед
template <const int preset>
class Lunch
{
public:

	// Конструктор
	Lunch();

	// Конструктор копирования
	Lunch( const Lunch& source );

	// Дестркутор
	virtual ~Lunch();

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
	Lunch& operator=( const Lunch& source );

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
inline Lunch<preset>::Lunch()
{
	dishes = new Dish[ preset ];
	drinks = new Drink[ preset ];
	dishesCounter = 0;
	drinksCounter = 0;
	capasity = preset;
}

template<int preset>
inline Lunch<preset>::Lunch( const Lunch& source )
{
	*this = source;
}

template<int preset>
inline Lunch<preset>::~Lunch()
{
	if(!isEmptyDishes())
		delete[] dishes;


	if(!isEmptyDrinks())
		delete[] drinks;
}

template<int preset>
inline void Lunch<preset>::addDish( const Dish* dish )
{
	if(!isFullDishes())
		dishes[ dishesCounter++ ] = *dish;
}

template<int preset>
inline void Lunch<preset>::addDrink( const Drink* drink )
{
	if(!isFullDrinks())
		drinks[ drinksCounter++ ] = *drink;
}

template<int preset>
inline Dish* Lunch<preset>::getDishes() const
{
	return dishes;
}

template<int preset>
inline Drink* Lunch<preset>::getDrinks() const
{
	return drinks;
}

template<int preset>
inline int Lunch<preset>::getDishesCounter() const
{
	return dishesCounter;
}

template<int preset>
inline int Lunch<preset>::getBeveragesCounter() const
{
	return drinksCounter;
}

template<int preset>
inline int Lunch<preset>::getCapasity() const
{
	return capasity;
}

template<int preset>
inline Lunch<preset>& Lunch<preset>::operator=( const Lunch& source )
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
inline bool Lunch<preset>::isEmptyDishes()
{
	return NULL == dishesCounter;
}

template<int preset>
inline bool Lunch<preset>::isFullDishes()
{
	return dishesCounter == capasity;
}

template<int preset>
inline bool Lunch<preset>::isEmptyDrinks()
{
	return NULL == drinksCounter;
}

template<int preset>
inline bool Lunch<preset>::isFullDrinks()
{
	return drinksCounter == capasity;
}