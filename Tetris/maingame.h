#pragma once
#include "screen.h"
#include "Block.h"
#include "shop.h"
#include <time.h>
#include <conio.h>
#include <iostream>

#ifndef PLAYER_H
#define PLAYER_H

extern short level;
extern short gold;
extern short earn_gold;
extern short choice;
extern bool continue_game;
extern short inventory[4];
extern short itemPrise[4];

#endif

class control
{
public: 
	static void gameStart();
	static void draw();
	static void eraseShadow();
	static void PrshortScore();
	static void MakeShadow(short color);
	static void Resetgame();
	static void eraseLine();
	static void drawnextblock(Block nextblock[]);
	static Block moveblock(char input, Block block);
	static void drawblock(short a);
	static void addblock(Block block, short board[20][10]);
	static bool crashcheck(short board[20][10]);
	static void useItem(short index);
	static void moveItem(char input, COORD* item);
	static void drawholdblock(Block holdblock, bool holdIsEmpty);
};

