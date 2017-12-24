#include"Header.h"

int FPS = 10;
bool gameOver = false;
int mark = 0;
int lv = 1;

Snake snake;
Apple apple;
Map map;

string point, level;

int main(int argc, char** argv) {
	//glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);

	glutInitWindowSize(400, 400);
	glutInitWindowPosition(300, 200);
	glutCreateWindow("Snake");

	init();

	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutTimerFunc(0, timer, 0);
	glutSpecialFunc(input);
	glutKeyboardFunc(input2);

	glutMainLoop();
	return 0;
}

void init() {
	glClearColor(0, 0, 0, 1);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);

	//map.render();

	apple.update();
	apple.render();

	snake.update();
	snake.render();

	drawText();

	if (gameOver == true) {
		MessageBox(NULL, "Try agian", "Game Over", MB_OK);
		exit(0);
	}
	glutSwapBuffers();
}

void reshape(int w, int h) {
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	glOrtho(0, 40, 40, 0, 10, 0);
}

void timer(int) {
	glutPostRedisplay();
	glutTimerFunc(1000 / FPS, timer, 0);
}

void input(int key, int, int) {
	switch (key)
	{
	case GLUT_KEY_UP:
		if (snake.getDir() != DOWN && snake.getChangeDir()) {
			snake.setDir(UP);
			snake.setChangeDir(false);
		}
		break;
	case GLUT_KEY_DOWN:
		if (snake.getDir() != UP && snake.getChangeDir()) {
			snake.setDir(DOWN);
			snake.setChangeDir(false);
		}
		break;
	case GLUT_KEY_RIGHT:
		if (snake.getDir() != LEFT && snake.getChangeDir()) {
			snake.setDir(RIGHT);
			snake.setChangeDir(false);
		}
		break;
	case GLUT_KEY_LEFT:
		if (snake.getDir() != RIGHT && snake.getChangeDir()) {
			snake.setDir(LEFT);
			snake.setChangeDir(false);
		}
		break;
	default:
		break;
	}
}

void input2(unsigned char key, int, int) {
	switch (key)
	{
	case 'w':
	case 'W':
		if (snake.getDir() != DOWN && snake.getChangeDir()) {
			snake.setDir(UP);
			snake.setChangeDir(false);
		}
		break;
	case 's':
	case 'S':
		if (snake.getDir() != UP && snake.getChangeDir()) {
			snake.setDir(DOWN);
			snake.setChangeDir(false);
		}
		break;
	case 'd':
	case 'D':
		if (snake.getDir() != LEFT && snake.getChangeDir()) {
			snake.setDir(RIGHT);
			snake.setChangeDir(false);
		}
		break;
	case 'a':
	case 'A':
		if (snake.getDir() != RIGHT && snake.getChangeDir()) {
			snake.setDir(LEFT);
			snake.setChangeDir(false);
		}
		break;
	default:
		break;
	}
}

void drawText() {
	glColor3f(1, 1, 1);
	point = "Mark: ";
	point += to_string(mark);
	glRasterPos2i(1, 1);
	for (size_t k1 = 0; k1 < point.size(); k1++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, point[k1]);
	level = "Level: ";
	level += to_string(lv);
	glRasterPos2i(30, 1);
	for (size_t k2 = 0; k2 < level.size(); k2++)
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, level[k2]);
}