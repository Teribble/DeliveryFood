#include "Shop.h"

Shop::Shop()
{
	list = nullptr;
	manager = nullptr;
	orders = nullptr;
}

Shop::~Shop()
{	

	if(nullptr != manager)
	{
		delete manager;
		manager = nullptr;
	}

	if(nullptr != orders)
	{
		delete orders;
		orders = nullptr;
	}
}

void Shop::openShift()
{
	list = new ListFoodsAndDrinks();

	list->init( "foods.txt" , "drinks.txt" );

}

void Shop::checkout( Collector* collector )
{
	manager = new Manager( collector , list );
	orders = new Order( manager->getRation() );
	orders->setDeliveryDay();
	orders->discountCalculation();
}

void Shop::showOrder()
{
	orders->printOrder();
}

void Shop::choice()
{
	system( "PAUSE" );
	system( "cls" );
	Collector* collectorS = new CollectorS();
	Collector* collectorM = new CollectorM();
	Collector* collectorL = new CollectorL();
	Collector* collectorLK = new CollectorChooseYourself();
	std::cout << "1: Рацион S(3 блюда и 3 напитка)\n"
		<< "2: Рацион M( 4 блюда и 4 напитка )\n"
		<< "3: Рацион L(5 блюда и 5 напитка)\n"
		<< "4: Выбери сам ( до 5 блюд и до 5 напитков )\n";
	int choice_switch;
	std::cin >> choice_switch;
	if(choice_switch < 1 && choice_switch > 4)
	{
		choice();
	}
	else
	{
		switch(choice_switch)
		{
			case 1:
				checkout( collectorS );
				showOrder();
				break;
			case 2:
				checkout( collectorM );
				showOrder();
				break;
			case 3:
				checkout( collectorS );
				showOrder();
				break;
			case 4:
				checkout( collectorLK );
				showOrder();
				break;
		}
	}
}

