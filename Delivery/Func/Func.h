#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <conio.h>

#pragma warning (disable: 4996) // - ������ ��������

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
	// ������ ��������� ����� � ��������� ���������
	int getRandomNumber( int min , int max );

	// ��������� ������� � �������� �������
	void setCursorPosition( short x , short y );

	// ������� ������ � �������
	void deleteCursorInConsole();

	// ��������� ������ �� ������ ����� � ������� ��������
	char* getCurrentTime();
}