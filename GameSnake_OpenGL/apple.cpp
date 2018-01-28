#include"Header.h"

extern Map map;

Apple::Apple() {
	Apple::random();
	Apple::isEaten = false;
}

Apple::~Apple(){}

void Apple::update() {
	if (Apple::isEaten) {
		Apple::random();
		Apple::isEaten = false;
	}
}

void Apple::random() {
	srand(time(NULL));
	Apple::aX = rand() % (map.getCol() - 1) + 1;
	Apple::aY = rand() % (map.getRow() - 1) + 1;
}

void Apple::render() {
	glColor3f(1, 0, 0);
	glRectd(Apple::aX + 0.2, Apple::aY + 0.2, Apple::aX + 0.8, Apple::aY + 0.8);
}

void Apple::setEaten(bool a) {
	Apple::isEaten = a;
}

int Apple::getAX() {
	return Apple::aX;
}

void Apple::setAX(int x) {
	Apple::aX = x;
}

int Apple::getAY() {
	return Apple::aY;
}

void Apple::setAY(int y) {
	Apple::aY = y;
}
