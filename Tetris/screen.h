#pragma once

class screen

{
public:
    static bool gameover();
    static int titlescreen();
    static void gamescreen();
    static void gotoxy(short x, short y);
    static void textcolor(int font, int background);
};

