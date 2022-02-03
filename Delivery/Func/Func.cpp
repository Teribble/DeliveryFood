#include "Func.h"


int Function::getRandomNumber( int min , int max )
{
    return min + rand() % ( max - min + 1 );
}

void Function::setCursorPosition(  short x , short y )
{
    HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
    COORD cursorPosition{ x,y };
    SetConsoleCursorPosition( console , cursorPosition );
}

void Function::deleteCursorInConsole()
{
    HANDLE console = GetStdHandle( STD_OUTPUT_HANDLE );
    CONSOLE_CURSOR_INFO info{ 100,false };
    SetConsoleCursorInfo( console , &info );
}

char* Function::getCurrentTime()
{
    time_t now = time( NULL );
    char* time = ctime( &now );
    return time;
}
