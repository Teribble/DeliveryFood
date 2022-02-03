#pragma once
#include <iomanip>
#include "../Ration/Ration.h"
#include "../Func/Func.h"

#define MAX_DD 5 // Кол-во напитков и блюд

// Скидка
enum Discount
{
	TWO_PERCENT = 2 ,
	THREE_PERCENT ,
	FOUR_PERCENT ,
	FIVE_PERCENT = 5,
	ONE_HUNDRED_PERCENT = 100
};

// Заказ
class Order
{
public:

	// Конструктор с параметром
	Order(Ration<MAX_DD>* ration);

	// Деструктор
	virtual ~Order();

	// Распечатать заказ
	void printOrder();

	// Подсчитать скидку
	void discountCalculation();

	// Задать кол-во дней доставки
	void setDeliveryDay();

	// Задать время доставки
	void setTimeOfDelivery(const std::string time);

	// Возращает стрингу с временем доставки
	std::string getTimeOfDelivery() const;

private:

	// Ссылка на рацион
	Ration<MAX_DD>* ration;

	// Подсчитать все цены
	void calcAllPrice();

	// Считает цену завтрак
	double calcPriceBreakfast();

	// Считает цену второго завтрака
	double calcPriceSecondBreakfast();

	// Считает цену обеда
	double calcPriceLunch();

	// Считает цену полдника
	double calcPriceHighTea();

	// Считает цену ужина
	double calcPriceDinner();

	// Вывести на экран завтрак
	void printBreakFast();

	// Вывести на экран второй завтрак
	void printSecondsBreakfast();

	// Вывести на экран Обед
	void printLunch();

	// Вывести на экран полдник
	void printHighTea();

	// Вывести на экран ужин
	void printDinner();

	// Время доставки
	std::string timeOfDelivery;

	// Кол-во дней доставки
	int deliveryDays;

	// Цена заказ, без учета скидки
	double orderPrice;

	// Цена заказа с учетом скидки
	double orderPriceDiscount;

	// Кол-во заказов
	static int countOrder;

	// Скидка
	int discount;

	// Время и дата оформления заказа
	std::string timeOrder;
};

