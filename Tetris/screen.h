#pragma once
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "control.h"


class screen

{
public:
    static void gameover();
    static void titlescreen();
    static void gamescreen();
    static void gotoxy(short x, short y);
    static void textcolor(int font, int background);
    static void drawtitle();
};

