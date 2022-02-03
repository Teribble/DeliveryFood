#pragma once
#include "../MealTimes/Breakfast.h"
#include "../MealTimes/Dinner.h"
#include "../MealTimes/HighTea.h"
#include "../MealTimes/Lunch.h"
#include "../MealTimes/SecondBreakfast.h"

// Рацион
template <const int preset>
class Ration
{
public:

	// Конструктор по умолчанию
	Ration();

	// Конструктор копирования
	Ration( const Ration& source );

	// Дестркутор
	virtual ~Ration();

	// Добавить завтрак
	void addBreakfast( Breakfast<preset> * breakfast);

	// Добавить второй завтрак
	void addSecondBreakfast( SecondBreakfast<preset>* secondBreakfast );

	// Добавить обед
	void addLunch( Lunch<preset>* lunch );

	// Добавить полдник
	void addHighTea( HighTea<preset>* highTea );

	// Добавить ужин
	void addDinner( Dinner<preset>* dinner );

	// Перегрузка оператора равно
	Ration& operator=( const Ration& source );

	// Возращает ссылку на завтрак
	Breakfast<preset>* getBreakfast() const;

	// Возращает ссылку на второй завтрак
	SecondBreakfast<preset>* getSecondBreakfast() const;

	// Возращает ссылку на обед
	Lunch<preset>* getLunch() const;

	// Возращает ссылку на полдник
	HighTea<preset>* getHighTea() const;

	// Возращает ссылку на ужин
	Dinner<preset>* getDinner() const;

	// Везращает тип рациона
	std::string getTypeRation() const;

	// Задать тип рациона
	void setTypeRation(std::string rationType);

private:
	
	// Завтрак
	Breakfast<preset>* breakfast;

	// Второй завтрак
	SecondBreakfast<preset>* secondBreakfast;

	// Обед
	Lunch<preset>* lunch;

	// Полдник
	HighTea<preset>* highTea;

	// Ужин
	Dinner<preset>* dinner;

	// Тип рациона
	std::string rationType;

	// Проверка, не пустой ли завтрак
	bool isEmptyBreakfast();

	// Проверка, не пустой ли второй завтрак
	bool isEmptySecondBreakFast();

	// Проверка, не пустой ли обед
	bool isEmptyLunch();

	// Проверка, не пустой ли полдник
	bool isEmptyHighTea();

	// Проверка, не пустой ли ужин
	bool isEmptyDinner();

	// Отчистить объект
	void clearObj();

};

template<int preset>
inline Ration<preset>::Ration()
{
	breakfast = new Breakfast<preset>();
	secondBreakfast = new SecondBreakfast<preset>();
	lunch = new Lunch<preset>();
	highTea = new HighTea<preset>();
	dinner = new Dinner<preset>();
	rationType = "";
}

template<int preset>
inline Ration<preset>::Ration( const Ration& source )
{
	*this = source;
}

template<int preset>
inline Ration<preset>::~Ration()
{
	if(isEmptyBreakfast()) delete breakfast;
	if(isEmptySecondBreakFast()) delete secondBreakfast;
	if(isEmptyLunch()) delete lunch;
	if(isEmptyHighTea()) delete highTea;
	if(isEmptyDinner()) delete dinner;
}

template<int preset>
inline void Ration<preset>::addBreakfast( Breakfast<preset>* breakfast )
{
	this->breakfast = breakfast;
}

template<int preset>
inline void Ration<preset>::addSecondBreakfast( SecondBreakfast<preset>* secondBreakfast )
{
	this->secondBreakfast = secondBreakfast;
}

template<int preset>
inline void Ration<preset>::addLunch( Lunch<preset>* lunch )
{
	this->lunch = lunch;
}

template<int preset>
inline void Ration<preset>::addHighTea( HighTea<preset>* highTea )
{
	this->highTea = highTea;
}

template<int preset>
inline void Ration<preset>::addDinner( Dinner<preset>* dinner )
{
	this->dinner = dinner;
}

template<int preset>
inline Ration<preset>& Ration<preset>::operator=( const Ration& source )
{
	clearObj();
	this->breakfast = source.breakfast;
	this->dinner = source.dinner;
	this->highTea = source.highTea;
	this->lunch = source.lunch;
	this->secondBreakfast = source.secondBreakfast;
	this->rationType = source.rationType;
}

template<int preset>
inline Breakfast<preset>* Ration<preset>::getBreakfast() const
{
	return breakfast;
}

template<int preset>
inline SecondBreakfast<preset>* Ration<preset>::getSecondBreakfast() const
{
	return secondBreakfast;
}

template<int preset>
inline Lunch<preset>* Ration<preset>::getLunch() const
{
	return lunch;
}

template<int preset>
inline HighTea<preset>* Ration<preset>::getHighTea() const
{
	return highTea;
}

template<int preset>
inline Dinner<preset>* Ration<preset>::getDinner() const
{
	return dinner;
}

template<int preset>
inline std::string Ration<preset>::getTypeRation() const
{
	return rationType;
}

template<int preset>
inline void Ration<preset>::setTypeRation( std::string rationType )
{
	this->rationType = rationType;
}

template<int preset>
inline bool Ration<preset>::isEmptyBreakfast()
{
	if(nullptr == breakfast)
		return true;
	else return false;
}

template<int preset>
inline bool Ration<preset>::isEmptySecondBreakFast()
{
	if(nullptr == secondBreakfast)
		return true;
	else return false;
}

template<int preset>
inline bool Ration<preset>::isEmptyLunch()
{
	if(nullptr == lunch)
		return true;
	else return false;
}

template<int preset>
inline bool Ration<preset>::isEmptyHighTea()
{
	if(nullptr == highTea)
		return true;
	else return false;
}

template<int preset>
inline bool Ration<preset>::isEmptyDinner()
{
	if(nullptr == dinner)
		return true;
	else return false;
}

template<int preset>
inline void Ration<preset>::clearObj()
{
	if(isEmptyBreakfast())
	{
		delete breakfast;
		breakfast = nullptr;
	}

	if(isEmptyDinner())
	{
		delete dinner;
		dinner = nullptr;
	}

	if(isEmptyHighTea())
	{
		delete highTea;
		highTea = nullptr;
	}

	if(isEmptyLunch())
	{
		delete lunch;
		lunch = nullptr;
	}

	if(isEmptySecondBreakFast())
	{
		delete secondBreakfast;
		secondBreakfast = nullptr;
	}
}
