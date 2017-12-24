#pragma once

#include<iostream>
#include<stdlib.h>
#include<string>
#include<Windows.h>
#include<ctime>
#include<cstdlib>

#include<gl/glut.h>
#include<gl/GL.h>

using namespace std;


#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

//game
void init();
void display();
void reshape(int, int);
void timer(int);
void input(int, int, int);
void drawText();
void input2(unsigned char, int, int);

//map
class Map {
private:
	int row, col;
public:
	Map();
	~Map();
	void drawTile(int, int);
	void render();
	int getCol();
	int getRow();
};

//snake
class Snake {
private:
	int dodai;

	int posX[200];
	int posY[200];

	int dir;
	bool changeDir;
public:
	Snake();
	~Snake();
	void update();
	void render();
	void move();
	int getDir();
	void setDir(int);
	bool getChangeDir();
	void setChangeDir(bool);
};

//apple
class Apple
{
private:
	int aX, aY;
	bool isEaten;
public:
	Apple();
	~Apple();
	void random();
	void update();
	void render();
	void setEaten(bool);
	void setAX(int);
	void setAY(int);
	int getAX();
	int getAY();
};
