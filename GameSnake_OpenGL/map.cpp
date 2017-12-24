#include"Header.h"

Map::Map() {
	Map::col = 40;
	Map::row = 40;
}

Map::~Map() {}

void Map::drawTile(int x,int y) {
	glLineWidth(0.1);
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(x, y);
	glVertex2f(x, y + 1);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x + 1, y);
	glEnd();
}

void Map::render() {
	for (int i = 0; i < Map::col; i++) {
		for (int j = 0; j < Map::row; j++) {
			Map::drawTile(i, j);
		}
	}
}

int Map::getCol() {
	return Map::col;
}

int Map::getRow() {
	return Map::row;
}