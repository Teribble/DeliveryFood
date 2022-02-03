#include "CollectorChooseYourself.h"
#include "../Func/Func.h"
#include "../ManualSelection/ManualSelection.h"

CollectorChooseYourself::CollectorChooseYourself()
{
	ration = new Ration<MAX_DD>();
	ration->setTypeRation( "Ration ChooseYouself" );
}

CollectorChooseYourself::~CollectorChooseYourself()
{
	if(!isEmpty()) delete ration;
}

void CollectorChooseYourself::collectBreakfast( ListFoodsAndDrinks* list )
{
	Breakfast<MAX_DD>* breakfast = new Breakfast< MAX_DD>();
	std::cout << "Выберите кол-во блюд и напитков на завтрак, максимум 5: ";
	int countFoodAndDrink = 0;
	std::cin >> countFoodAndDrink;
	for(int i = 0; i < countFoodAndDrink; i++)
	{
		breakfast->addDish( ManualSelection::selectDishes( list ) );
		breakfast->addDrink( ManualSelection::selectDrinks( list ) );
	}
	ration->addBreakfast( breakfast );
}

void CollectorChooseYourself::collectSecondBreakfast( ListFoodsAndDrinks* list )
{
	SecondBreakfast<MAX_DD>* secondBreakfast = new SecondBreakfast<MAX_DD>();
	std::cout << "Выберите кол-во блюд и напитков на завтрак, максимум 5: ";
	int countFoodAndDrink = 0;
	std::cin >> countFoodAndDrink;
	for(int i = 0; i < countFoodAndDrink; i++)
	{
		secondBreakfast->addDish( ManualSelection::selectDishes( list ) );
		secondBreakfast->addDrink( ManualSelection::selectDrinks( list ) );
	}
	ration->addSecondBreakfast( secondBreakfast );
}

void CollectorChooseYourself::collectLunch( ListFoodsAndDrinks* list )
{
	Lunch<MAX_DD>* lunch = new Lunch<MAX_DD>();
	std::cout << "Выберите кол-во блюд и напитков на завтрак, максимум 5: ";
	int countFoodAndDrink = 0;
	std::cin >> countFoodAndDrink;
	for(int i = 0; i < countFoodAndDrink; i++)
	{
		lunch->addDish( ManualSelection::selectDishes( list ) );
		lunch->addDrink( ManualSelection::selectDrinks( list ) );
	}
	ration->addLunch( lunch );
}

void CollectorChooseYourself::collectHighTea( ListFoodsAndDrinks* list )
{
	HighTea<MAX_DD>* hightea = new HighTea<MAX_DD>();
	std::cout << "Выберите кол-во блюд и напитков на завтрак, максимум 5: ";
	int countFoodAndDrink = 0;
	std::cin >> countFoodAndDrink;
	for(int i = 0; i < countFoodAndDrink; i++)
	{
		hightea->addDish( ManualSelection::selectDishes( list ) );
		hightea->addDrink( ManualSelection::selectDrinks( list ) );
	}
	ration->addHighTea( hightea );
}

void CollectorChooseYourself::collectDinner( ListFoodsAndDrinks* list )
{
	Dinner<MAX_DD>* dinner = new Dinner<MAX_DD>();
	std::cout << "Выберите кол-во блюд и напитков на завтрак, максимум 5: ";
	int countFoodAndDrink = 0;
	std::cin >> countFoodAndDrink;
	for(int i = 0; i < countFoodAndDrink; i++)
	{
		dinner->addDish( ManualSelection::selectDishes( list ) );
		dinner->addDrink( ManualSelection::selectDrinks( list ) );
	}
	ration->addDinner( dinner );
}

Ration<MAX_DD>* CollectorChooseYourself::getRation()
{
	return ration;
}

bool CollectorChooseYourself::isEmpty()
{
	if(nullptr == ration)
		return true;
	else return false;
}

Dish* CollectorChooseYourself::getRandomDish( ListFoodsAndDrinks* list ) const
{
	return new Dish( list->getFoodList()[ Function::getRandomNumber( 0 , list->getFoodCounter() - 1 ) ] , Function::getRandomNumber( 100 , 1000 ) , Function::getRandomNumber( 150 , 200 ) );
}

Drink* CollectorChooseYourself::getRandomDrink( ListFoodsAndDrinks* list ) const
{
	return new Drink( list->getDrinkList()[ Function::getRandomNumber( 0 , list->getDrinkCounter() - 1 ) ] , Function::getRandomNumber( 100 , 1000 ) , Function::getRandomNumber( 50 , 150 ) );
}
