#include "Drink.h"

Drink::Drink()
{
	nameDrink = "";
	caloriesDrink = 0;
	priceDrink = 0;
}

Drink::Drink( std::string nameDrink , int caloriesDrink , double priceDrink )
{
	this->nameDrink = nameDrink;
	this->caloriesDrink = caloriesDrink;
	this->priceDrink = priceDrink;
}

Drink::Drink( const Drink& d )
{
	*this = d;
}

std::string Drink::getNameDrink() const
{
	return nameDrink;
}

int Drink::getCaloriesDrink() const
{
	return caloriesDrink;
}

double Drink::getPriceDrink() const
{
	return priceDrink;
}

Drink& Drink::operator=( const Drink& d )
{
	nameDrink = d.nameDrink;
	caloriesDrink = d.caloriesDrink;
	priceDrink = d.priceDrink;
	return *this;
}
