#include "screen.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>

enum direction
{
    LEFT = 75,
    RIGHT = 77,
    UP = 72,
    DOWN = 80,
};


void screen::gotoxy(short x, short y)
{
    COORD Pos = { (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void screen::textcolor(int font, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), font + background * 16);
}

int screen::titlescreen()
{
    system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; 
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    short select = 0;
    gotoxy(20, 10);
    std::cout << " tetris in c++ ";
    gotoxy(10, 25);
    std::cout << "   게임시작             상점               게임 종료";
    char input;
    while (true)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                gotoxy(10 + select * 4*5, 25);
                std::cout << "  ";
                input = _getch();
                switch (input)
                {
                case LEFT:
                    if (select != 0)
                        select--;
                    
                    
                    break;
                case RIGHT:
                    if (select != 2)
                        select++;
                    break;
                }
                gotoxy(10 + select * 20, 25);
                std::cout << "▶";
            }
            else if (input == 32)
            {
                switch (select)
                {
                case 0:
                    return 0;
                case 1:
                    break;
                case 2:
                    return -1;
                }
            }
        }
    }
}

void screen::gamescreen()
{
    system("cls");
    system("mode con cols=100 lines=30");
    for (int i = 0; i < 22; i++)
    {
        gotoxy(30, 5+i);
        if (i == 0 || i == 21)
            std::cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
        else
            std::cout << "▒                    ▒";

    }
    for (int i = 0; i < 6; i++)
    {
        gotoxy(5, 5 + i);
        if (i == 0 || i == 5)
            std::cout << "▒▒▒ NEXT▒▒▒";
        else
            std::cout << "▒         ▒";
    }

    for (int i = 0; i < 6; i++)
    {
        gotoxy(5, 13 + i);
        if (i == 0 || i == 5)
            std::cout << "▒▒▒▒▒▒ ITEMS▒▒▒▒▒▒";
        else
            std::cout << "▒                ▒";
    }
    
    gotoxy(55, 4);
    std::cout << "      조작키     ";
    gotoxy(55, 6);
    std::cout << "     ▲      : 블럭 회전 ";
    gotoxy(55, 7);
    std::cout << "   ◀▼▶    : 블럭 이동";
    gotoxy(55, 9);
    std::cout << "  SPACE BAR  : 바닥까지 블럭 이동   ";
    gotoxy(55, 11);
    std::cout << "  Z : 아이템 사용 ";

}