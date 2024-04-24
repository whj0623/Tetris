#include "shop.h"


int itemPrise[4] = { 5,5,50,100 };

enum direction
{
    LEFT = 75,
    RIGHT = 77,
    UP = 72,
    DOWN = 80
};


void shop::buyItem(int index)
{
	gold -= itemPrise[index];
	inventory[index]++;
}

void shop::showItem(int index,int x, int y)
{
    switch (index)
	{
	case 0:
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::screen::gotoxy(x, y++);
        std::cout << "       "; screen::textColor(0, 15); std::cout << "  "; screen::textColor(0, 0); std::cout << "      ";
        screen::gotoxy(x, y++);
        std::cout << "      "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 6); std::cout << " "; screen::textColor(0, 4); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "     "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "      ";
        screen::gotoxy(x, y++);
        std::cout << "     "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "      ";
        screen::gotoxy(x, y++);
        std::cout << "    "; screen::textColor(0, 15); std::cout << "  "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 15); std::cout << "  "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "      "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "    ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "        "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "      "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "      "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "        "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "    "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "    ";
        screen::gotoxy(x, y++);
        std::cout << "    "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "    "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "     "; screen::textColor(0, 15); std::cout << "    "; screen::textColor(0, 0); std::cout << "      ";
        break;
	case 1:
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "      "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "      ";
        screen::gotoxy(x, y++);
        std::cout << "      "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "      ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 8); std::cout << "         "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "     "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 8); std::cout << "     "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "     "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 8); std::cout << "     "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "     "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 8); std::cout << "      "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "      "; screen::textColor(0, 0); std::cout << " ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 8); std::cout << "      "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << " ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 8); std::cout << "             "; screen::textColor(0, 0); std::cout << " ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 8); std::cout << "             "; screen::textColor(0, 0); std::cout << " ";
        break;
	}
    screen::textColor(15, 0);
}

void shop::showItemInformation(int index)
{
    showItem(index,86,6);
    int x = 86, y = 21;
    screen::gotoxy(x,y);
    switch (index)
    {
    case 0:
        screen::gotoxy(x, y++);
        std::cout << "��ź. ( 1 x 1 )";
        screen::gotoxy(x-3, ++y);
        std::cout << "�浹 �� �浹�� ������";
        screen::gotoxy(x - 3, ++y);
        std::cout << "�߽����� 5 x 5 ������";
        screen::gotoxy(x - 3, ++y);
        std::cout << "���ϵ��� �����մϴ�.";
        break;
    case 1:
        screen::gotoxy(x, y++);
        std::cout << "��. ( 1 x 1 )";
        screen::gotoxy(x-3 , ++y);
        std::cout << "�浹�� ���� ������";
        screen::gotoxy(x -3, ++y);
        std::cout << "���� �о� ���۴ϴ�.";
        screen::gotoxy(x - 3, ++y);
        std::cout << "          ";
        screen::gotoxy(x - 3, ++y);
        std::cout << "          ";
    }
    screen::gotoxy(83, 30);
    std::cout << "���� : �����̽� ��";
}

void shop::interaction()
{
    char input;
    int select = 0;
    while (true)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                input = _getch();
                switch (input)
                {
                case UP:
                    if (select == 3)
                        select = 0;
                    break;
                case DOWN:
                    if (select == 0)
                        select = 3;
                    break;
                case LEFT:
                    if (select == 0)
                        select = 3;
                    else
                        select--;
                    break;
                case RIGHT:
                    if (select == 3)
                        select = 0;
                    else
                        select++;
                    break;
                }
                drawSelect(select);
                showItemInformation(select);
            }
            else if (input == 32)
            {
                if (gold >= itemPrise[select])
                    buyItem(select);
                else
                    std::cout << "";
            }
        }
    }
}

void shop::drawSelect(int index)
{
    screen::shopScreen();
    if (index == 3)
    {
        int x = 7, y = 22;
        screen::gotoxy(x, y);
        screen::textColor(0, 14); std::cout << "                      ";
        for (int i = 0; i < 13; i++)
        {
            screen::gotoxy(x, ++y);
            std::cout << "  ";
            screen::gotoxy(x+20, y );
            std::cout << "  ";
        }
        screen::gotoxy(x, ++y);
        std::cout << "                      ";
    }
    else
    {
        int x = 7 + 24 * index, y = 6;
        screen::gotoxy(x, y);
        screen::textColor(0, 14); std::cout << "                      ";
        for (int i = 0; i < 13; i++)
        {
            screen::gotoxy(x, ++y);
            std::cout << "  ";
            screen::gotoxy(x+20, y);
            std::cout << "  ";
        }
        screen::gotoxy(x, ++y);
        std::cout << "                      ";
    }
    screen::textColor(15, 0);
}