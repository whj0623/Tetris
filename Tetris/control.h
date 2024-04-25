#pragma once
#include "screen.h"
#include "Block.h"
#include "shop.h"
#include <time.h>
#include <conio.h>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

extern int gold;
extern int earn_gold;
extern int choice;
extern bool continue_game;
extern int inventory[4];
extern int itemPrise[4];

#endif

class control
{
public: 
	static void gameStart();
	static void draw();
	static void eraseShadow();
	static void PrintScore();
	static void MakeShadow(int color);
	static void Resetgame();
	static void eraseLine();
	static void drawnextblock(Block nextblock[]);
	static Block moveblock(char input, Block block);
	static void drawblock(int a);
	static void addblock(Block block, int board[20][10]);
	static bool crashcheck(int board[20][10]);
	static void itemInfo();
	static void useItem(int index);
	static void moveItem(char input, COORD* item);
};

