#include "CollectorL.h"
#include "../Func/Func.h"

CollectorL::CollectorL()
{
	ration = new Ration<MAX_DD>();
	ration->setTypeRation( "Ration L" );
}

CollectorL::~CollectorL()
{
	if(!isEmpty()) delete ration;
}

void CollectorL::collectBreakfast( ListFoodsAndDrinks* list )
{
	Breakfast<MAX_DD>* breakfast = new Breakfast< MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_L; i++)
	{
		breakfast->addDish( getRandomDish( list ) );
		breakfast->addDrink( getRandomDrink( list ) );
	}
	ration->addBreakfast( breakfast );
}

void CollectorL::collectSecondBreakfast( ListFoodsAndDrinks* list )
{
	SecondBreakfast<MAX_DD>* secondBreakfast = new SecondBreakfast<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_L; i++)
	{
		secondBreakfast->addDish( getRandomDish( list ) );
		secondBreakfast->addDrink( getRandomDrink( list ) );
	}
	ration->addSecondBreakfast( secondBreakfast );
}

void CollectorL::collectLunch( ListFoodsAndDrinks* list )
{
	Lunch<MAX_DD>* lunch = new Lunch<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_L; i++)
	{
		lunch->addDish( getRandomDish( list ) );
		lunch->addDrink( getRandomDrink( list ) );
	}
	ration->addLunch( lunch );
}

void CollectorL::collectHighTea( ListFoodsAndDrinks* list )
{
	HighTea<MAX_DD>* hightea = new HighTea<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_L; i++)
	{
		hightea->addDish( getRandomDish( list ) );
		hightea->addDrink( getRandomDrink( list ) );
	}
	ration->addHighTea( hightea );
}

void CollectorL::collectDinner( ListFoodsAndDrinks* list )
{
	Dinner<MAX_DD>* dinner = new Dinner<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_L; i++)
	{
		dinner->addDish( getRandomDish( list ) );
		dinner->addDrink( getRandomDrink( list ) );
	}
	ration->addDinner( dinner );
}

Ration<MAX_DD>* CollectorL::getRation()
{
	return ration;
}

bool CollectorL::isEmpty()
{
	if(nullptr == ration)
		return true;
	else return false;
}

Dish* CollectorL::getRandomDish( ListFoodsAndDrinks* list ) const
{
	return new Dish( list->getFoodList()[ Function::getRandomNumber( 0 , list->getFoodCounter() - 1 ) ] , Function::getRandomNumber( MIN_COLORIES , MAX_COLORIES ) , Function::getRandomNumber( MIN_PRICE , MAX_PRICE ) );
}

Drink* CollectorL::getRandomDrink( ListFoodsAndDrinks* list ) const
{
	return new Drink( list->getDrinkList()[ Function::getRandomNumber( 0 , list->getDrinkCounter() - 1 ) ] , Function::getRandomNumber( MIN_COLORIES , MAX_COLORIES ) , Function::getRandomNumber( MIN_PRICE , MAX_PRICE ) );
}
