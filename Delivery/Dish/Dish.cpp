#include "Dish.h"

Dish::Dish()
{
	nameDish = "";
	caloriesDish = 0;
	priceDish = 0;
}

Dish::Dish( std::string nameDish , int caloriesDish , double priceDish )
{
	this->nameDish = nameDish;
	this->caloriesDish = caloriesDish;
	this->priceDish = priceDish;
}

Dish::Dish( const Dish& d )
{
	*this = d;
}

std::string Dish::getNameDish() const
{
	return nameDish;
}

int Dish::getCaloriesDish() const
{
	return caloriesDish;
}

double Dish::getPriceDish() const
{
	return priceDish;
}

Dish& Dish::operator=( const Dish& d )
{
	nameDish = d.nameDish;
	caloriesDish = d.caloriesDish;
	priceDish = d.priceDish;
	
	return *this;
}

