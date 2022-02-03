#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "../Func/Func.h"

// Лист еды и напитков
class ListFoodsAndDrinks
{
public:

	// Конструктор
	ListFoodsAndDrinks();
	
	// Конструктор копирования
	ListFoodsAndDrinks( const ListFoodsAndDrinks& source );

	// Деструктор
	virtual ~ListFoodsAndDrinks();

	// Инициализация из файла
	void init( std::string fileFood , std::string fileDrink );

	// Показать список еды
	void showFoods();

	// Показать список напитков
	void showDrinks();

	// Вернет список еды
	std::string* getFoodList() const;

	// Вернет список напитков
	std::string* getDrinkList() const;

	// Перегрузка оператора равно
	ListFoodsAndDrinks& operator=( const ListFoodsAndDrinks& source );

	// Возращает кол-во позиций еды
	int getFoodCounter() const;

	// Возращает кол-во позиций напитков
	int getDrinkCounter() const;

	// Выводит список еды, доступный для выбора
	void printFoodList();

	// Выводит список напитков, доступных для выбора
	void printDrinkList();


private:

	// Ссылка на массив названий еды
	std::string* foodList;

	// Ссылка на массив названий напитков
	std::string* drinkList;

	// Пустой ли список еды
	bool isEmptyFood();

	// Пустой ли список напитков
	bool isEmptyDrink();

	// Возращает кол-во строк в файле
	int getValueLineFile( std::string file );

	// Заполняет список еды из файла
	void initFood( std::string file );

	// Заполняет список напистков из файла
	void initDrink( std::string file );

	// Переменная, которая хванит кол-во еды в списке
	int foodCounter;

	// Переменная, которая хванит кол-во напитков в списке
	int drinkCounter;

};

