#include "Menu\Shop.h"
// 2890 строк

#pragma warning(disable : 4996)
#include <stdio.h>

#define PRESS_KEY 49

int main()
{
	setlocale( LC_ALL , "rus" );
	srand(time(NULL));

	Collector* collector = new CollectorL();

	Shop shop;
	shop.openShift();
	//shop.checkout( collector );
	//shop.showOrder();
	while(true)
	{
		shop.choice();
	}

	return 0;
 }