#include "CollectorM.h"
#include "../Func/Func.h"

CollectorM::CollectorM()
{
	ration = new Ration<MAX_DD>();
	ration->setTypeRation( "Ration M" );
}

CollectorM::~CollectorM()
{
	if(!isEmpty()) delete ration;
}

void CollectorM::collectBreakfast( ListFoodsAndDrinks* list )
{
	Breakfast<MAX_DD>* breakfast = new Breakfast< MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_M; i++)
	{
		breakfast->addDish( getRandomDish( list ) );
		breakfast->addDrink( getRandomDrink( list ) );
	}
	ration->addBreakfast( breakfast );
}

void CollectorM::collectSecondBreakfast( ListFoodsAndDrinks* list )
{
	SecondBreakfast<MAX_DD>* secondBreakfast = new SecondBreakfast<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_M; i++)
	{
		secondBreakfast->addDish( getRandomDish( list ) );
		secondBreakfast->addDrink( getRandomDrink( list ) );
	}
	ration->addSecondBreakfast( secondBreakfast );
}

void CollectorM::collectLunch( ListFoodsAndDrinks* list )
{
	Lunch<MAX_DD>* lunch = new Lunch<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_M; i++)
	{
		lunch->addDish( getRandomDish( list ) );
		lunch->addDrink( getRandomDrink( list ) );
	}
	ration->addLunch( lunch );
}

void CollectorM::collectHighTea( ListFoodsAndDrinks* list )
{
	HighTea<MAX_DD>* hightea = new HighTea<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_M; i++)
	{
		hightea->addDish( getRandomDish( list ) );
		hightea->addDrink( getRandomDrink( list ) );
	}
	ration->addHighTea( hightea );
}

void CollectorM::collectDinner( ListFoodsAndDrinks* list )
{
	Dinner<MAX_DD>* dinner = new Dinner<MAX_DD>();
	for(int i = 0; i < MAX_COLLECTOR_M; i++)
	{
		dinner->addDish( getRandomDish( list ) );
		dinner->addDrink( getRandomDrink( list ) );
	}
	ration->addDinner( dinner );
}

Ration<MAX_DD>* CollectorM::getRation()
{
	return ration;
}

bool CollectorM::isEmpty()
{
	if(nullptr == ration)
		return true;
	else return false;
}

Dish* CollectorM::getRandomDish( ListFoodsAndDrinks* list ) const
{
	return new Dish( list->getFoodList()[ Function::getRandomNumber( 0 , list->getFoodCounter() - 1 ) ] , Function::getRandomNumber( MIN_COLORIES , MAX_COLORIES ) , Function::getRandomNumber( MIN_PRICE , MAX_PRICE ) );
}

Drink* CollectorM::getRandomDrink( ListFoodsAndDrinks* list ) const
{
	return new Drink( list->getDrinkList()[ Function::getRandomNumber( 0 , list->getDrinkCounter() - 1 ) ] , Function::getRandomNumber( MIN_COLORIES , MAX_COLORIES ) , Function::getRandomNumber( MIN_PRICE , MAX_PRICE ) );
}
