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

void screen::textcolor(int font, int background)
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), font + background * 16);
}
void screen::drawtitle()
{
    gotoxy(18, 3);
    screen::textcolor(1, 0);
    std::cout << "����������������������������������������";
    for (int i = 0; i < 14; i++)
    {
        gotoxy(18, i + 4);
        std::cout << "��                                                                          ��";
    }
    gotoxy(18, 18);
    std::cout << "��������������                          ��������������";
    for (int i = 0; i < 14; i++)
    {
        gotoxy(42, i + 19);
        std::cout << "��                          ��";
        
    }
    gotoxy(42, 33);
    std::cout << "����������������";

    int title_x =  20, title_y =  5;
    gotoxy(title_x, title_y++);
    std::cout << "  "; screen::textcolor(0, 12 );std::cout << "          "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 9);std::cout << "           "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  14 );std::cout << "          "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 10);std::cout << "           "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,   11);std::cout << "    "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0, 13);std::cout << "               "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "  "; screen::textcolor(0, 12 );std::cout << "          "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 9 );std::cout << "           "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  14 );std::cout << "          "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 10);std::cout << "             "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0,   11);std::cout << "    "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  13 );std::cout << "               "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "  "; screen::textcolor(0, 12 );std::cout << "          "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 9);std::cout << "           "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 14  );std::cout << "          "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  10);std::cout << "              "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  11 );std::cout << "    "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0, 13  );std::cout << "              "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 9);std::cout << "    "; screen::textcolor(0,  0);std::cout << "           "; screen::textcolor(0, 14  );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  10);std::cout << "    "; screen::textcolor(0,  0);std::cout << "   "; screen::textcolor(0,  10);std::cout << "       "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  11 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0, 13  );std::cout << "       "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 9);std::cout << "         "; screen::textcolor(0,  0);std::cout << "      "; screen::textcolor(0,  14 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  10);std::cout << "    "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0,  10);std::cout << "       "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0, 11  );std::cout << "    "; screen::textcolor(0,  0);std::cout << "   "; screen::textcolor(0,13   );std::cout << "       "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 9);std::cout << "        "; screen::textcolor(0,  0);std::cout << "       "; screen::textcolor(0,  14 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  10);std::cout << "    "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  10);std::cout << "       "; screen::textcolor(0,  0);std::cout << "   "; screen::textcolor(0,  11 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  13 );std::cout << "       "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 9);std::cout << "       "; screen::textcolor(0,  0);std::cout << "        "; screen::textcolor(0,  14 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  10);std::cout << "    "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0,  10);std::cout << "       "; screen::textcolor(0,  0);std::cout << "  "; screen::textcolor(0, 11  );std::cout << "    "; screen::textcolor(0,  0);std::cout << "     "; screen::textcolor(0,  13 );std::cout << "       "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 9);std::cout << "    "; screen::textcolor(0,  0);std::cout << "           "; screen::textcolor(0,  14 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  10);std::cout << "    "; screen::textcolor(0,  0);std::cout << "   "; screen::textcolor(0,  10);std::cout << "       "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  11 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "      "; screen::textcolor(0,  13 );std::cout << "       "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 9);std::cout << "    "; screen::textcolor(0,  0);std::cout << "           "; screen::textcolor(0, 14  );std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0,  10);std::cout << "    "; screen::textcolor(0,  0);std::cout << "    "; screen::textcolor(0, 10);std::cout << "      "; screen::textcolor(0,  0);std::cout << " "; screen::textcolor(0,  11 );std::cout << "    "; screen::textcolor(0,  0);std::cout << "       "; screen::textcolor(0,  13 );std::cout << "       "; screen::textcolor(0,  0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12); std::cout << "    "; screen::textcolor(0, 0); std::cout << "    "; screen::textcolor(0, 9); std::cout << "            "; screen::textcolor(0, 0); std::cout << "   "; screen::textcolor(0, 14); std::cout << "    "; screen::textcolor(0, 0); std::cout << "    "; screen::textcolor(0, 10); std::cout << "    "; screen::textcolor(0, 0); std::cout << "     "; screen::textcolor(0, 10); std::cout << "     "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 11); std::cout << "    "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 13); std::cout << "              "; screen::textcolor(0, 0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12); std::cout << "    "; screen::textcolor(0, 0); std::cout << "     "; screen::textcolor(0, 9); std::cout << "            "; screen::textcolor(0, 0); std::cout << "  "; screen::textcolor(0, 14); std::cout << "    "; screen::textcolor(0, 0); std::cout << "    "; screen::textcolor(0, 10); std::cout << "    "; screen::textcolor(0, 0); std::cout << "      "; screen::textcolor(0, 10); std::cout << "    "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 11); std::cout << "    "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 13); std::cout << "               "; screen::textcolor(0, 0);
    gotoxy(title_x, title_y++);
    std::cout << "     "; screen::textcolor(0, 12); std::cout << "    "; screen::textcolor(0, 0); std::cout << "      "; screen::textcolor(0, 9); std::cout << "            "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 14); std::cout << "    "; screen::textcolor(0, 0); std::cout << "    "; screen::textcolor(0, 10); std::cout << "    "; screen::textcolor(0, 0); std::cout << "       "; screen::textcolor(0, 10); std::cout << "   "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 11); std::cout << "    "; screen::textcolor(0, 0); std::cout << " "; screen::textcolor(0, 13); std::cout << "              "; screen::textcolor(0, 0);
    
    
    gotoxy(10,38);
    screen::textcolor(15, 0);
    std::cout << "   ���ӽ���                                ����                                   ���� ����";
}

void screen::titlescreen()
{
    system("cls");
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
    short select = 0;
    drawtitle();
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
                std::cout << "��";
                
            }
            else if (input == 32)
            {
                choice = select;
                return;
            }
        }
    }
}

void screen::gameover()
{
    int x = 35, y = 15;
    gotoxy(x, y++);
    std::cout << "����������������������������������������������������������������������������";
    gotoxy(x, y++);
    std::cout << "��            ���� ����               ��";
    gotoxy(x, y++);
    std::cout << "��                                    ��";
    gotoxy(x, y++);
    std::cout << "��  ȹ���� ��� : " << earn_gold <<"G\t������ : "<< gold<< "G\t��";
    gotoxy(x, y++);
    std::cout << "��   ������ �ٽ� �����Ͻðڽ��ϱ�?    ��";
    gotoxy(x, y++);
    std::cout << "��        YES                 NO      ��";
    gotoxy(x, y++);
    std::cout << "����������������������������������������������������������������������������";
  
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
                std::cout << "��";
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

void screen::gamescreen()
{
    system("cls");
    system("mode con cols=100 lines=30");
    for (int i = 0; i < 22; i++)
    {
        gotoxy(30, 5+i);
        if (i == 0 || i == 21)
            std::cout << "�ƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢƢ�";
        else
            std::cout << "��                     ��";

    }
    for (int i = 0; i < 18; i++)
    {
        gotoxy(5, 5 + i);
        if (i == 0)
            std::cout << "�ƢƢ� NEXT�ƢƢ�";
        else if (i == 17)
            std::cout << "�ƢƢƢƢƢƢƢƢƢƢ�";
        else
            std::cout << "��         ��";
    }
    
    gotoxy(55, 4);
    std::cout << "      ����Ű     ";
    gotoxy(55, 6);
    std::cout << "     ��      : �� ȸ�� ";
    gotoxy(55, 7);
    std::cout << "   ���墺    : �� �̵�";
    gotoxy(55, 9);
    std::cout << "  SPACE BAR  : �ٴڱ��� �� �̵�   ";
    gotoxy(55, 11);
    std::cout << "  Z : ������ ��� ";

}