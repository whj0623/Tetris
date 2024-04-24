#include "screen.h"



enum direction
{
    LEFT = 75,
    RIGHT = 77
};


void screen::gotoxy(short x, short y)
{
    COORD Pos = { (short)x, (short)y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void screen::textColor(int font, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), font + background * 16);
}
void screen::drawTitle()
{
    gotoxy(18, 3);
    screen::textColor(1, 0);
    std::cout << "■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■";
    for (int i = 0; i < 14; i++)
    {
        gotoxy(18, i + 4);
        std::cout << "■                                                                          ■";
    }
    gotoxy(18, 18);
    std::cout << "■■■■■■■■■■■■■                          ■■■■■■■■■■■■■";
    for (int i = 0; i < 14; i++)
    {
        gotoxy(42, i + 19);
        std::cout << "■                          ■";
        
    }
    gotoxy(42, 33);
    std::cout << "■■■■■■■■■■■■■■■";

    int title_x =  20, title_y =  5;
    gotoxy(title_x, title_y++);
    std::cout << "  "; screen::textColor(0, 12 );std::cout << "          "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 9);std::cout << "           "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  14 );std::cout << "          "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 10);std::cout << "           "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,   11);std::cout << "    "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0, 13);std::cout << "               "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "  "; screen::textColor(0, 12 );std::cout << "          "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 9 );std::cout << "           "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  14 );std::cout << "          "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 10);std::cout << "             "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0,   11);std::cout << "    "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  13 );std::cout << "               "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "  "; screen::textColor(0, 12 );std::cout << "          "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 9);std::cout << "           "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 14  );std::cout << "          "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  10);std::cout << "              "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  11 );std::cout << "    "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0, 13  );std::cout << "              "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 9);std::cout << "    "; screen::textColor(0,  0);std::cout << "           "; screen::textColor(0, 14  );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  10);std::cout << "    "; screen::textColor(0,  0);std::cout << "   "; screen::textColor(0,  10);std::cout << "       "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  11 );std::cout << "    "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0, 13  );std::cout << "       "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 9);std::cout << "         "; screen::textColor(0,  0);std::cout << "      "; screen::textColor(0,  14 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  10);std::cout << "    "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0,  10);std::cout << "       "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0, 11  );std::cout << "    "; screen::textColor(0,  0);std::cout << "   "; screen::textColor(0,13   );std::cout << "       "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 9);std::cout << "        "; screen::textColor(0,  0);std::cout << "       "; screen::textColor(0,  14 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  10);std::cout << "    "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  10);std::cout << "       "; screen::textColor(0,  0);std::cout << "   "; screen::textColor(0,  11 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  13 );std::cout << "       "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 9);std::cout << "       "; screen::textColor(0,  0);std::cout << "        "; screen::textColor(0,  14 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  10);std::cout << "    "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0,  10);std::cout << "       "; screen::textColor(0,  0);std::cout << "  "; screen::textColor(0, 11  );std::cout << "    "; screen::textColor(0,  0);std::cout << "     "; screen::textColor(0,  13 );std::cout << "       "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 9);std::cout << "    "; screen::textColor(0,  0);std::cout << "           "; screen::textColor(0,  14 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  10);std::cout << "    "; screen::textColor(0,  0);std::cout << "   "; screen::textColor(0,  10);std::cout << "       "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  11 );std::cout << "    "; screen::textColor(0,  0);std::cout << "      "; screen::textColor(0,  13 );std::cout << "       "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12 );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 9);std::cout << "    "; screen::textColor(0,  0);std::cout << "           "; screen::textColor(0, 14  );std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0,  10);std::cout << "    "; screen::textColor(0,  0);std::cout << "    "; screen::textColor(0, 10);std::cout << "      "; screen::textColor(0,  0);std::cout << " "; screen::textColor(0,  11 );std::cout << "    "; screen::textColor(0,  0);std::cout << "       "; screen::textColor(0,  13 );std::cout << "       "; screen::textColor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12); std::cout << "    "; screen::textColor(0, 0); std::cout << "    "; screen::textColor(0, 9); std::cout << "            "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 14); std::cout << "    "; screen::textColor(0, 0); std::cout << "    "; screen::textColor(0, 10); std::cout << "    "; screen::textColor(0, 0); std::cout << "     "; screen::textColor(0, 10); std::cout << "     "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 11); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 13); std::cout << "              "; screen::textColor(0, 0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12); std::cout << "    "; screen::textColor(0, 0); std::cout << "     "; screen::textColor(0, 9); std::cout << "            "; screen::textColor(0, 0); std::cout << "  "; screen::textColor(0, 14); std::cout << "    "; screen::textColor(0, 0); std::cout << "    "; screen::textColor(0, 10); std::cout << "    "; screen::textColor(0, 0); std::cout << "      "; screen::textColor(0, 10); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 11); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 13); std::cout << "               "; screen::textColor(0, 0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textColor(0, 12); std::cout << "    "; screen::textColor(0, 0); std::cout << "      "; screen::textColor(0, 9); std::cout << "            "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 14); std::cout << "    "; screen::textColor(0, 0); std::cout << "    "; screen::textColor(0, 10); std::cout << "    "; screen::textColor(0, 0); std::cout << "       "; screen::textColor(0, 10); std::cout << "   "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 11); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 13); std::cout << "              "; screen::textColor(0, 0);
    
    
    
}

int screen::gamePause()
{
    char input;
    int select = 0;
    int x = 35, y = 10;
    gotoxy(x, y++);
    std::cout << "┌─────────────────────────────────────┐";
    gotoxy(x, y++);
    std::cout << "│              일시 정지              │";
    gotoxy(x, y++);
    std::cout << "│                                     │";
    gotoxy(x, y++);
    std::cout << "│    게임 재개    새 게임     타이틀로│";
    gotoxy(x, y++);
    std::cout << "└─────────────────────────────────────┘";
    while (true)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                gotoxy(37 + select * 13, 13);
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
                gotoxy(37 + select * 13, 13);
                std::cout << "▶";
            }
            else if (input == 32)
                return select;
        }
    }
}

void screen::titleScreen()
{
    system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    short select = 0;
    drawTitle();
    gotoxy(10, 38);
    screen::textColor(15, 0);
    std::cout << "   게임시작                                상점                                   게임 종료";
    char input;
    while (true)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                gotoxy(10 + select * 40, 38);
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
                gotoxy(10 + select * 40, 38);
                std::cout << "▶";
                
            }
            else if (input == 32)
            {
                choice = select;
                return;
            }
        }
    }
}

void screen::gameOver()
{
    int x = 35, y = 15;
    gotoxy(x, y++);
    std::cout << "┌────────────────────────────────────┐";
    gotoxy(x, y++);
    std::cout << "│            게임 오버               │";
    gotoxy(x, y++);
    std::cout << "│                                    │";
    gotoxy(x, y++);
    std::cout << "│  획득한 골드 : " << earn_gold <<"G\t소지금 : "<< gold<< "G\t│";
    gotoxy(x, y++);
    std::cout << "│   게임을 다시 시작하시겠습니까?    │";
    gotoxy(x, y++);
    std::cout << "│        YES                 NO      │";
    gotoxy(x, y++);
    std::cout << "└────────────────────────────────────┘";
  
    int select = 0;
    while (true)
    {
        char input;
        
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                input = _getch();
                gotoxy(37 + select * 20, 20);
                std::cout << "  ";
                switch (input)
                {
                case LEFT:
                    select = 0;
                    break;
                case RIGHT:
                    select = 1;
                    break;
                }
                gotoxy(37 + select * 20, 20);
                std::cout << "▶";
            }          
            else if (input == 32)
            {
                if (select == 0)
                    continue_game = true;
                else
                    continue_game = false;
                return;
            }
           
        }
    }
}

void screen::gameScreen()
{
    system("cls");
    system("mode con cols=100 lines=30");
    for (int i = 0; i < 22; i++)
    {
        gotoxy(30, 5+i);
        if (i == 0 || i == 21)
            std::cout << "▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒";
        else
            std::cout << "▒                     ▒";

    }
    for (int i = 0; i < 18; i++)
    {
        gotoxy(5, 5 + i);
        if (i == 0)
            std::cout << "▒▒▒ NEXT▒▒▒";
        else if (i == 17)
            std::cout << "▒▒▒▒▒▒▒▒▒▒▒";
        else
            std::cout << "▒         ▒";
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


void screen::shopScreen()
{
    
    system("mode con cols=110 lines=40");
    
    int y = 5;
    gotoxy(5, y++);
    std::cout << "┌───────────────────────┬───────────────────────┬───────────────────────┐";
    for (int i = 0; i < 31; i++)
    {
        gotoxy(5, y++);
        if (i == 15)
            std::cout << "├───────────────────────┼───────────────────────┼───────────────────────┤";
        else
            std::cout << "│                       │                       │                       │";
    }
    gotoxy(5, y++);
    std::cout << "└───────────────────────┴───────────────────────┴───────────────────────┘";
    

    
    textColor(15, 0);
    
    y = 6;
    gotoxy(80, 5);
    std::cout << "┌───────────────────────┐";
    for (int i = 0; i < 25; i++)
    {
        gotoxy(80, y++);
        std::cout << "│                       │";
    }
    gotoxy(80, y);
    std::cout << "└───────────────────────┘";
    shop::showItem(0, 11, 6);
    shop::showItem(1, 35, 6);
}