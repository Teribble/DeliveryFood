#include "Manager.h"

Manager::Manager( Collector* collector , ListFoodsAndDrinks* list )
{
	this->collector = collector;
	this->list = list;
}

Manager::~Manager()
{
	if(nullptr != collector)
	{
		delete collector;
		collector = nullptr;
	}
		

	if(nullptr != list)
	{
		delete list;
		list = nullptr;
	}
		
}

void Manager::setCollector( Collector* collector , ListFoodsAndDrinks* list )
{
	this->collector = collector;
	this->list = list;
}

Ration<MAX_DD>* Manager::getRation()
{
	collector->collectBreakfast( list );
	collector->collectSecondBreakfast( list );
	collector->collectLunch( list );
	collector->collectHighTea( list );
	collector->collectDinner( list );

	return collector->getRation();
}
