#include"Header.h"

extern int FPS;
extern int mark;
extern int lv;

extern bool gameOver;
extern Map map;
extern Apple apple;

Snake::Snake() {
	Snake::dodai = 3;
	Snake::dir = RIGHT;
	Snake::changeDir = true;
	for (int i = 0; i < Snake::dodai; i++) {
		Snake::posX[i] = 5 - i;
		Snake::posY[i] = 10;
	}
}

Snake::~Snake() {}

void Snake::move() {
	for (int j = Snake::dodai - 1; j > 0; j--) {
		Snake::posX[j] = Snake::posX[j - 1];
		Snake::posY[j] = Snake::posY[j - 1];
	}
	if (Snake::dir == 1) {
		Snake::posY[0]--;
		Snake::changeDir = true;
	}
	else if (Snake::dir == -1) {
		Snake::posY[0]++;
		Snake::changeDir = true;
	}
	else if (Snake::dir == 2) {
		Snake::posX[0]++;
		Snake::changeDir = true;
	}
	else {
		Snake::posX[0]--;
		Snake::changeDir = true;
	}
}

void Snake::update() {
	if (Snake::posX[0] > map.getCol() - 1) Snake::posX[0] = 0;
	if (Snake::posX[0] < 0) Snake::posX[0] = map.getCol() - 1;

	if (Snake::posY[0] > (map.getRow() - 1)) Snake::posY[0] = 0;
	if (Snake::posY[0] < 0) Snake::posY[0] = map.getRow() - 1;

	if (Snake::posX[0] == apple.getAX() && Snake::posY[0] == apple.getAY()) {
		apple.setEaten(true);
		mark++;
		if (mark % 10 == 0) {
			lv++;
			FPS += 1;
		}
		Snake::dodai++;
	}
	for (int j = 1; j < Snake::dodai; j++) {
		if (Snake::posX[0] == Snake::posX[j] && Snake::posY[0] == Snake::posY[j])
			gameOver = true;
		if (apple.getAX() == Snake::posX[j] && apple.getAY() == Snake::posY[j])
			apple.random();
	}
	Snake::move();
}

void Snake::render() {
	glColor3f(0, 1, 0);
	for (int i = 1; i < Snake::dodai; i++) {
		glRectf(Snake::posX[i] + 0.05f, Snake::posY[i] + 0.05f, Snake::posX[i] + 0.95f, Snake::posY[i] + 0.95f);
	}
	glColor3f(0, 0, 1.0);
	glRectf(Snake::posX[0]+0.05f, Snake::posY[0]+0.05f, Snake::posX[0] + 0.95f, Snake::posY[0] + 0.95f);
}

void Snake::setDir(int d) {
	Snake::dir = d;
}

int Snake::getDir() {
	return Snake::dir;
}

void Snake::setChangeDir(bool c) {
	Snake::changeDir = c;
}

bool Snake::getChangeDir() {
	return Snake::changeDir;
}