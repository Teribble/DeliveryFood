#include "ListFoodsAndDrinks.h"

ListFoodsAndDrinks::ListFoodsAndDrinks()
{
	foodList = nullptr;
	drinkList = nullptr;
	foodCounter = 0;
	drinkCounter = 0;
}

ListFoodsAndDrinks::ListFoodsAndDrinks( const ListFoodsAndDrinks& source )
{
	*this = source;
}

ListFoodsAndDrinks::~ListFoodsAndDrinks()
{
	if(!isEmptyFood())
	{
		delete[] foodList;
		foodList = nullptr;
	}
	if(!isEmptyDrink())
	{
		delete[] drinkList;
		drinkList = nullptr;
	}
}

void ListFoodsAndDrinks::init( std::string fileFood, std::string fileDrink )
{
	initFood(fileFood);
	initDrink(fileDrink);
}

void ListFoodsAndDrinks::showFoods()
{
	for(int i = 0; i < foodCounter; i++)
	{
		std::cout << foodList[ i ] << std::endl;
	}
}

void ListFoodsAndDrinks::showDrinks()
{
	for(int i = 0; i < drinkCounter; i++)
	{
		std::cout << drinkList[ i ] << std::endl;
	}
}

std::string* ListFoodsAndDrinks::getFoodList() const
{
	return foodList;
}

std::string* ListFoodsAndDrinks::getDrinkList() const
{
	return drinkList;
}

ListFoodsAndDrinks& ListFoodsAndDrinks::operator=( const ListFoodsAndDrinks& source )
{
	if(!isEmptyFood())
	{
		delete[] foodList;
		foodList = source.foodList;
		foodCounter = source.foodCounter;
	}

	if(!isEmptyDrink())
	{
		delete[] drinkList;
		drinkList = source.drinkList;
		drinkCounter = source.drinkCounter;
	}

	return *this;
}

int ListFoodsAndDrinks::getFoodCounter() const
{
	return foodCounter;
}

int ListFoodsAndDrinks::getDrinkCounter() const
{
	return drinkCounter;
}

void ListFoodsAndDrinks::printFoodList()
{
	for(int i = 0; i < foodCounter; i++)
	{
		if(i % 3 == 0)
			std::cout << std::endl;

		std::cout << std::right << std::setw( 3 ) << i + 1<<" - " << std::left << std::setw(25) << foodList[i];
	}
}

void ListFoodsAndDrinks::printDrinkList()
{
	for(int i = 0; i < drinkCounter; i++)
	{
		if(i % 3 == 0)
			std::cout << std::endl;

		std::cout << std::right << std::setw( 3 ) << i + 1 <<" - "<< std::left << std::setw(25) << drinkList[i];
	}
}

bool ListFoodsAndDrinks::isEmptyFood()
{
	if(nullptr == foodList)
		return true;
	else return false;
}

bool ListFoodsAndDrinks::isEmptyDrink()
{
	if(nullptr == drinkList)
		return true;
	else return false;;
}

int ListFoodsAndDrinks::getValueLineFile( std::string file )
{
	int counter = 0;

	std::ifstream ot;
	ot.open( file );
	std::string buffer;
	if(ot.is_open())
	{
		while(std::getline(ot, buffer))
		{
			ot >> buffer;
			counter++;
		}
		ot.close();
		return counter;
	}
	else
	{
		return counter;
	}
}

void ListFoodsAndDrinks::initFood( std::string file )
{
	int lengthFile = getValueLineFile( file );
	int count = 0;
	foodList = new std::string[ lengthFile ];

	std::ifstream ot;
	ot.open( file );
	std::string buffer;
	if(ot.is_open())
	{
		while(std::getline( ot , buffer ))
		{
			foodList[ count++ ] = buffer;
			foodCounter = lengthFile;
		}
		ot.close();
	}
}

void ListFoodsAndDrinks::initDrink( std::string file )
{
	int lengthFile = getValueLineFile( file );
	int count = 0;
	drinkList = new std::string[ lengthFile ];

	std::ifstream ot;
	ot.open( file );
	std::string buffer;
	if(ot.is_open())
	{
		while(std::getline( ot , buffer ))
		{
			drinkList[ count++ ] = buffer;
			drinkCounter = lengthFile;
		}
		ot.close();
	}
}
