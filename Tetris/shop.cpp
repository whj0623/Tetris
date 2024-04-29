#include "shop.h"


short itemPrise[4] = { 5,5,50,100 };

enum direction
{
    LEFT = 75,
    RIGHT = 77,
    UP = 72,
    DOWN = 80
};


void shop::buyItem(short select)
{
    if ((select == 3 || select == 2) && inventory[select] == 1)
    {
        screen::gotoxy(40, 20);
        std::cout << "��������������������������������";
        screen::gotoxy(40, 21);
        std::cout << "��  �̹� ������ ��";
        screen::gotoxy(40, 22);
        std::cout << "��������������������������������";
    }
    else if (gold >= itemPrise[select])
    {
        gold -= itemPrise[select];
        inventory[select]++;
        screen::gotoxy(40, 20);
        std::cout << "����������������������";
        screen::gotoxy(40, 21);
        std::cout << "�� ���ſϷᦢ";
        screen::gotoxy(40, 22);
        std::cout << "����������������������";
    }
    else
    {
        screen::gotoxy(40, 20);
        std::cout << "����������������������";
        screen::gotoxy(40, 21);
        std::cout << "�� �ܾ׺�����";
        screen::gotoxy(40, 22);
        std::cout << "����������������������";
    }
}

void shop::showItem(short index,short x, short y)
{
    short posy = 6;
    screen::gotoxy(80, posy);
    std::cout << "��������������������������������������������������";
    for (short i = 0; i < 25; i++)
    {
        screen::gotoxy(80, posy++);
        std::cout << "��                       ��";
    }
    screen::gotoxy(80, posy);
    std::cout << "��������������������������������������������������";
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
    case 2:
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "       "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "       "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "    "; screen::textColor(0, 15); std::cout << "  "; screen::textColor(0, 8); std::cout << "     "; screen::textColor(0, 0); std::cout << "    ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 6); std::cout << " "; screen::textColor(0, 4); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "    ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "     "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "    "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 14); std::cout << "  "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 14); std::cout << "  "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "  "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "  "; screen::textColor(0, 14); std::cout << "      "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << "  "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 15); std::cout << " "; screen::textColor(0, 14); std::cout << "      "; screen::textColor(0, 0); std::cout << "  ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 15); std::cout << "   "; screen::textColor(0, 0); std::cout << "   "; screen::textColor(0, 14); std::cout << "  "; screen::textColor(0, 0); std::cout << "    ";
        screen::gotoxy(x, y++);
        std::cout << "         "; screen::textColor(0, 14); std::cout << "  "; screen::textColor(0, 0); std::cout << "    ";
        screen::gotoxy(x, y++);
        std::cout << "               ";
        break;
    case 3:
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "       "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "       "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "     "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << "     ";
        screen::gotoxy(x, y++);
        std::cout << "     "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << "       ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << "   "; screen::textColor(0, 0); std::cout << " ";
        screen::gotoxy(x, y++);
        std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 0); std::cout << " ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 8); std::cout << " "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 8); std::cout << "  "; screen::textColor(0, 0); std::cout << " ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << " "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << " "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 0); std::cout << " "; screen::textColor(0, 5); std::cout << "   "; screen::textColor(0, 0); std::cout << "   ";
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "               ";
        screen::gotoxy(x, y++);
        std::cout << "               ";
        break;
    }
    screen::textColor(15, 0);
}

void shop::showItemInformation(short index)
{
    showItem(index,86,6);
    short x = 86, y = 21;
    screen::gotoxy(x,y);
    switch (index)
    {
    case 0:
        screen::gotoxy(x, y++);
        std::cout << "��ź. ( 1 x 1 )";
        screen::gotoxy(x - 3, ++y);
        std::cout << "�浹 �� �浹�� ������";
        screen::gotoxy(x - 3, ++y);
        std::cout << "�߽����� 5 x 5 ������";
        screen::gotoxy(x - 3, ++y);
        std::cout << "��ϵ��� �����մϴ�.";
        screen::gotoxy(x - 3, y + 2);
        std::cout << "���� ���� : " << inventory[index];
        break;
    case 1:
        screen::gotoxy(x, y++);
        std::cout << "��. ( 1 x 1 )";
        screen::gotoxy(x - 3 , ++y);
        std::cout << "�浹�� ���� ������";
        screen::gotoxy(x - 3, ++y);
        std::cout << "���� �о� ���۴ϴ�.";
        screen::gotoxy(x - 3, y + 2);
        std::cout << "���� ���� : " << inventory[index];
        break;
    case 2:
        screen::gotoxy(x - 2, y++);
        std::cout << "�Ⱦ� (�нú� ������)";
        screen::gotoxy(x - 3, ++y);
        std::cout << "���� 10�� ������ ";
        screen::gotoxy(x - 3, ++y);
        std::cout << "������ ������ ��� ";
        screen::gotoxy(x - 3, ++y);
        std::cout << "�������� ����ϴ�.";
        screen::gotoxy(x + 3, ++y);
        if (inventory[2] == 1)
            std::cout << "(������)";
        break;
    case 3:
        screen::gotoxy(x - 4, y++);
        std::cout << "�׸��� (�нú� ������)";
        screen::gotoxy(x - 3, ++y);
        std::cout << "����� ������ ������";
        screen::gotoxy(x - 3, ++y);
        std::cout << " �׸��ڸ� �����ݴϴ�.";
        screen::gotoxy(x + 3 , y + 2);
        if (inventory[3] == 1)
            std::cout << "(������)";
    }
    screen::gotoxy(83, 29);
    std::cout << "���� : " << itemPrise[index] << "G";
    screen::gotoxy(83, 30);
    std::cout << "���� : �����̽� ��";
    screen::gotoxy(85, 33);
    std::cout << "������ : " << gold << "G";
    screen::gotoxy(85, 35);
    std::cout << "������ : ESC";
}

void shop::interaction()
{
    char input;
    short select = 0;
    drawSelect(select,14);
    showItemInformation(select);
    while (true)
    {
        if (_kbhit())
        {
            input = _getch();
            if (input == -32)
            {
                drawSelect(select, 0);
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
                drawSelect(select,14);
                showItemInformation(select);
            }
            else if (input == 32)
            {
                buyItem(select);
  
                Sleep(1000);
                screen::shopScreen();
                drawSelect(select,14);
                showItemInformation(select);
            }
            else if (input == 27)
                break;
        }
    }
}

void shop::drawSelect(short index,short color)
{
    if (index == 3)
    {
        short x = 7, y = 22;
        screen::gotoxy(x, y);
        screen::textColor(0, color); std::cout << "                      ";
        for (short i = 0; i < 13; i++)
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
        short x = 7 + 24 * index, y = 6;
        screen::gotoxy(x, y);
        screen::textColor(0, color); std::cout << "                      ";
        for (short i = 0; i < 13; i++)
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
