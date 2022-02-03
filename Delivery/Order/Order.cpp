#include "Order.h"

int Order::countOrder = 0;

Order::Order( Ration<MAX_DD>* ration )
{
	this->ration = ration;
	deliveryDays = 0;
	orderPrice = 0;
	orderPriceDiscount = 0;
	countOrder++;
	discount = 0;
	timeOfDelivery = "";
	timeOrder = "";
}

Order::~Order()
{
	if(nullptr != ration)
		delete ration;
}

void Order::printOrder()
{
	system( "cls" );
	std::cout << "|=======================ЧЕК====================|" << std::endl;
	std::cout << "	Завтрак: " << std::endl;
	printBreakFast();
	std::cout << "	Второй завтрак: " << std::endl;
	printSecondsBreakfast();
	std::cout << "	Обед: " << std::endl;
	printLunch();
	std::cout << "	Полдник: " << std::endl;
	printHighTea();
	std::cout << "	Ужин: " << std::endl;
	printDinner();
	std::cout << "|==============================================|" << std::endl;
	std::cout << "   Тип рациона: " << ration->getTypeRation() << std::endl;
	std::cout << "   Количество дней доставки: " << deliveryDays << std::endl;
	std::cout << "   Время доставки: " << timeOfDelivery << std::endl;
	std::cout << "   Цена за 1 день: " << orderPrice << std::endl;
	std::cout << "   Цена за весь период: " << orderPrice * deliveryDays << std::endl;
	std::cout << "   Ваша скидка: " << discount<< "% : " << (((orderPrice*deliveryDays)/ONE_HUNDRED_PERCENT)*discount) <<" рублей" << std::endl;
	std::cout << "   Цена c учетом скидки: " << orderPriceDiscount << std::endl;
	std::cout << "   Дата и время оформления заказа:\n   " << timeOrder;
	std::cout << "|==============================================|" << std::endl;

}

void Order::discountCalculation()
{
	calcAllPrice();

	if(deliveryDays == 3)
	{
		orderPriceDiscount = orderPrice - ( ( orderPrice / ONE_HUNDRED_PERCENT ) * TWO_PERCENT );
		orderPriceDiscount *= deliveryDays;
		discount = TWO_PERCENT;
	}
	else if(deliveryDays >= 4 && deliveryDays <= 6)
	{
		orderPriceDiscount = orderPrice - ( ( orderPrice / ONE_HUNDRED_PERCENT ) * THREE_PERCENT );
		orderPriceDiscount *= deliveryDays;
		discount = THREE_PERCENT;
	}
	else if(deliveryDays >= 7 && deliveryDays <= 9)
	{
		orderPriceDiscount = orderPrice - ( ( orderPrice / ONE_HUNDRED_PERCENT ) * FOUR_PERCENT );
		orderPriceDiscount *= deliveryDays;
		discount = FOUR_PERCENT;
	}
	else if(deliveryDays >= 10)
	{
		orderPriceDiscount = orderPrice - ( ( orderPrice / ONE_HUNDRED_PERCENT ) * FIVE_PERCENT );
		orderPriceDiscount *= deliveryDays;
		discount = FIVE_PERCENT;
	}
	else
	{
		orderPriceDiscount = orderPrice;
	}
}

void Order::setDeliveryDay()
{
	std::cout << "Предложение скидок: 3 дня = 2% 6 дней = 3% 9 дней = 4% больше 10 = 5%" << std::endl;
	std::cout << "Введите кол-во дней доставки: ";
	std::cin >> deliveryDays;
	std::cout << "Введите время доставки: ";
	std::cin >> timeOfDelivery;
}

void Order::setTimeOfDelivery( const std::string time )
{
	timeOfDelivery = time;
}

std::string Order::getTimeOfDelivery() const
{
	return timeOfDelivery;
}

void Order::calcAllPrice()
{
	orderPrice += calcPriceBreakfast();
	orderPrice += calcPriceSecondBreakfast();
	orderPrice += calcPriceLunch();
	orderPrice += calcPriceHighTea();
	orderPrice += calcPriceDinner();
	timeOrder = Function::getCurrentTime();
}

double Order::calcPriceBreakfast()
{
	double price = 0;
	
	for(int i = 0; i < ration->getBreakfast()->getDishesCounter(); i++)
	{
		price += (double)ration->getBreakfast()->getDishes()[ i ].getPriceDish();
	}

	return price;
}

double Order::calcPriceSecondBreakfast()
{
	double price = 0;

	for(int i = 0; i < ration->getSecondBreakfast()->getDishesCounter(); i++)
	{
		price += (double)ration->getSecondBreakfast()->getDishes()[ i ].getPriceDish();
	}

	return price;
}

double Order::calcPriceLunch()
{
	double price = 0;

	for(int i = 0; i < ration->getLunch()->getDishesCounter(); i++)
	{
		price += ( double )ration->getLunch()->getDishes()[ i ].getPriceDish();
	}

	return price;
}

double Order::calcPriceHighTea()
{
	double price = 0;

	for(int i = 0; i < ration->getHighTea()->getDishesCounter(); i++)
	{
		price += ( double )ration->getHighTea()->getDishes()[ i ].getPriceDish();
	}

	return price;
}

double Order::calcPriceDinner()
{
	double price = 0;

	for(int i = 0; i < ration->getDinner()->getDishesCounter(); i++)
	{
		price += ( double )ration->getDinner()->getDishes()[ i ].getPriceDish();
	}

	return price;
}

void Order::printBreakFast()
{
	std::cout << "Блюда:\n";
	for(int i = 0; i < ration->getBreakfast()->getDishesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getBreakfast()->getDishes()[ i ].getNameDish()
			<< std::right << std::setw( 10 ) << ration->getBreakfast()->getDishes()[ i ].getPriceDish() << std::endl;
	}
	std::cout << "Напитки:\n";
	for(int i = 0; i < ration->getBreakfast()->getBeveragesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getBreakfast()->getDrinks()[ i ].getNameDrink()
			<< std::right << std::setw( 10 ) << ration->getBreakfast()->getDrinks()[ i ].getPriceDrink() << std::endl;
	}
}

void Order::printSecondsBreakfast()
{
	std::cout << "Блюда:\n";
	for(int i = 0; i < ration->getSecondBreakfast()->getDishesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getSecondBreakfast()->getDishes()[ i ].getNameDish()
			<< std::right << std::setw( 10 ) << ration->getSecondBreakfast()->getDishes()[ i ].getPriceDish() << std::endl;
	}
	std::cout << "Напитки:\n";
	for(int i = 0; i < ration->getSecondBreakfast()->getBeveragesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getSecondBreakfast()->getDrinks()[ i ].getNameDrink()
			<< std::right << std::setw( 10 ) << ration->getSecondBreakfast()->getDrinks()[ i ].getPriceDrink() << std::endl;
	}
}

void Order::printLunch()
{
	std::cout << "Блюда:\n";
	for(int i = 0; i < ration->getLunch()->getDishesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getLunch()->getDishes()[ i ].getNameDish()
			<< std::right << std::setw( 10 ) << ration->getLunch()->getDishes()[ i ].getPriceDish() << std::endl;
	}
	std::cout << "Напитки:\n";
	for(int i = 0; i < ration->getLunch()->getBeveragesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getLunch()->getDrinks()[ i ].getNameDrink()
			<< std::right << std::setw( 10 ) << ration->getLunch()->getDrinks()[ i ].getPriceDrink() << std::endl;
	}
}

void Order::printHighTea()
{
	std::cout << "Блюда:\n";
	for(int i = 0; i < ration->getHighTea()->getDishesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getHighTea()->getDishes()[ i ].getNameDish()
			<< std::right << std::setw( 10 ) << ration->getHighTea()->getDishes()[ i ].getPriceDish() << std::endl;
	}
	std::cout << "Напитки:\n";
	for(int i = 0; i < ration->getHighTea()->getBeveragesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getHighTea()->getDrinks()[ i ].getNameDrink()
			<< std::right << std::setw( 10 ) << ration->getHighTea()->getDrinks()[ i ].getPriceDrink() << std::endl;
	}
}

void Order::printDinner()
{
	std::cout << "Блюда:\n";
	for(int i = 0; i < ration->getDinner()->getDishesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getDinner()->getDishes()[ i ].getNameDish()
			<< std::right << std::setw( 10 ) << ration->getDinner()->getDishes()[ i ].getPriceDish() << std::endl;
	}
	std::cout << "Напитки:\n";
	for(int i = 0; i < ration->getDinner()->getBeveragesCounter(); i++)
	{
		std::cout << "   #: " << std::left << std::setw( 30 ) << ration->getDinner()->getDrinks()[ i ].getNameDrink()
			<< std::right << std::setw( 10 ) << ration->getDinner()->getDrinks()[ i ].getPriceDrink() << std::endl;
	}
}
