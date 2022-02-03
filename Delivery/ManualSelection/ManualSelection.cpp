#include "ManualSelection.h"

Dish* ManualSelection::selectDishes(  ListFoodsAndDrinks* list )
{
    system("cls");
    list->printFoodList();
    std::cout << std::endl;
    int maxItemFood = list->getFoodCounter();
    int choice = 0;
    std::cout << TEXT_RED << "Выберите порядковый номер блюда: \n" << TEXT_RESET;
    std::cin >> choice;
    std::cout << "Вы выбрали: " << list->getFoodList()[ choice - 1 ] << std::endl;
    system("PAUSE");
    return new Dish( list->getFoodList()[ choice - 1 ] , Function::getRandomNumber( MIN_COLORIES , MAX_COLORIES ) , Function::getRandomNumber( MIN_PRICE , MAX_PRICE ) );
}

Drink* ManualSelection::selectDrinks(  ListFoodsAndDrinks* list )
{
    system( "cls" );
    list->printDrinkList();
    std::cout << std::endl;
    int maxItemFood = list->getFoodCounter();
    int choice = 0;
    std::cout <<TEXT_RED<< "Выберите порядковый номер напитка: \n"<<TEXT_RESET;
    std::cin >> choice;
    std::cout << "Вы выбрали: " << list->getDrinkList()[ choice - 1 ] << std::endl;
    system( "PAUSE" );
    return new Drink( list->getDrinkList()[ choice - 1 ] , Function::getRandomNumber( MIN_COLORIES , MAX_COLORIES ) , Function::getRandomNumber( MIN_PRICE , MAX_PRICE ) );
}
