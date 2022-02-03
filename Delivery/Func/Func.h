#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

#pragma warning (disable: 4996) // - решает проблему

enum Number
{
	ZERO , ONE , TWO , THREE , FOUR , FIVE , SIX , SEVEN , EIGHT , NINE , TEN
};

#pragma region Text_color

#define TEXT_RESET   "\033[0m"
#define TEXT_BLACK   "\033[30m"
#define TEXT_RED     "\033[31m"
#define TEXT_GREEN   "\033[32m"
#define TEXT_YELLOW  "\033[33m"
#define TEXT_BLUE    "\033[34m"
#define TEXT_MAGENTA "\033[35m"
#define TEXT_CYAN    "\033[36m"
#define TEXT_WHITE   "\033[37m"

#pragma endregion Text_color

namespace Function
{
	// ¬ыдает рандомное число в указанном диапазоне
	int getRandomNumber( int min , int max );

	// ”становка курсора в заданные позиции
	void setCursorPosition( short x , short y );

	// ”дал€ет курсор в консоли
	void deleteCursorInConsole();

	// ¬озращает ссылку на массив чаров с текущим временем
	char* getCurrentTime();
}