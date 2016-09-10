#include <gl/glut.h>

double DISTANCE = 0.45;
enum toDisplay{STAR, HEXAGON, SQUARE, FIGURE_10, ALL};
toDisplay current = ALL;
int MENU_STAR = 1, MENU_HEX = 2, MENU_FIG = 3, MENU_SQ = 4, MENU_ALL = 5, MENU_EXIT = 6;

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_QUADS);
	//Window vertex & Gradients
		glColor3f(1, 0, 0);
		glVertex2f(-0.5, -0.5);
		glColor3f(0.7, 0, 0.2);
		glVertex2f(-0.5, 0.5);
		glColor3f(0.4, 0.6, 0.3);
		glVertex2f(0.5, 0.5);
		glColor3f(1, 0.5, -0.3);
		glVertex2f(0.5, -0.5);
	glEnd();
	
	//star figure.
	if (current == STAR || current == ALL) {
		glBegin(GL_POLYGON);
		glColor3f(255, 0, 0);
		glVertex2f(0.0 + DISTANCE, 0.15 + DISTANCE);
		glVertex2f(-0.1 + DISTANCE, 0.0 + DISTANCE);
		glVertex2f(0.1 + DISTANCE, 0.0 + DISTANCE);
		glEnd();
		glBegin(GL_POLYGON);
		glColor3f(255, 0, 0);
		glVertex2f(-0.1 + DISTANCE, 0.09 + DISTANCE);
		glVertex2f(0.0 + DISTANCE, -0.09 + DISTANCE);
		glVertex2f(0.1 + DISTANCE, 0.09 + DISTANCE);
		glEnd();
	}
	
	
	//hexagon figure.
	if (current == HEXAGON || current == ALL) {
		glBegin(GL_POLYGON);
		glColor3f(0, 255, 0);
		glVertex2f(-0.1 - DISTANCE, 0.1 - DISTANCE);
		glVertex2f(-0.15 - DISTANCE, 0.0 - DISTANCE);
		glVertex2f(-0.1 - DISTANCE, -0.1 - DISTANCE);
		glVertex2f(0.1 - DISTANCE, -0.1 - DISTANCE);
		glVertex2f(0.15 - DISTANCE, 0.0 - DISTANCE);
		glVertex2f(0.1 - DISTANCE, 0.1 - DISTANCE);
		glEnd();
	}
	

	//Square figure
	if (current == SQUARE || current == ALL) {
		glBegin(GL_POLYGON);
		glColor3f(0, 0, 255);
		glVertex2f(-0.1 - DISTANCE, 0.1 + DISTANCE);
		glVertex2f(-0.1 - DISTANCE, -0.1 + DISTANCE);
		glVertex2f(0.1 - DISTANCE, -0.1 + DISTANCE);
		glVertex2f(0.1 - DISTANCE, 0.1 + DISTANCE);
		glEnd();
	}
	

	//10-sided figure
	if (current == FIGURE_10 || current == ALL) {
		glBegin(GL_POLYGON);
		glColor3f(255, 0, 255);
		glVertex2f(0.0 + DISTANCE, 0.1 - DISTANCE);
		glVertex2f(-0.0666 + DISTANCE, 0.0666 - DISTANCE);
		glVertex2f(-0.1 + DISTANCE, 0.0333 - DISTANCE);
		glVertex2f(-0.1 + DISTANCE, -0.0333 - DISTANCE);
		glVertex2f(-0.0666 + DISTANCE, -0.0666 - DISTANCE);
		glVertex2f(0.0 + DISTANCE, -0.1 - DISTANCE);
		glVertex2f(0.0666 + DISTANCE, -0.0666 - DISTANCE);
		glVertex2f(0.1 + DISTANCE, -0.0333 - DISTANCE);
		glVertex2f(0.1 + DISTANCE, 0.0333 - DISTANCE);
		glVertex2f(0.0666 + DISTANCE, 0.0666 - DISTANCE);
		glEnd();
	}
	

	glFlush();
	glutSwapBuffers();
}

void handleMouse(int button, int state, int x, int y) {
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
		exit(0);
	}
}



void handleMenu(int entryID) {

	switch (entryID) {
	case 1:
		current = STAR;
		break;
	case 2:
		current = HEXAGON;
		break;
	case 3:
		current = FIGURE_10;
		break;
	case 4:
		current = SQUARE;
		break;
	case 5:
		current = ALL;
		break;
	case 6:
		exit(0);
	}	

	glutPostRedisplay();
}

void createMenus() {
	glutCreateMenu(handleMenu);
	glutAddMenuEntry("Star", MENU_STAR);
	glutAddMenuEntry("Hexagon", MENU_HEX);
	glutAddMenuEntry("10-side figure", MENU_FIG);
	glutAddMenuEntry("Square", MENU_SQ);
	glutAddMenuEntry("Show all", MENU_ALL);
	glutAddMenuEntry("Exit", MENU_EXIT);
	glutAttachMenu(GLUT_LEFT_BUTTON);
}

void init() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glColor3f(1, 1, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1, 1, -1, 1);
}

//int main(int argc, char *argv[]) {
//	glutInitDisplayMode(GLUT_RED);
//	glutInitWindowSize(1000, 1000);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("Once upon a square...");
//	init();
//	createMenus();
//	glutDisplayFunc(display);
//	glutIdleFunc(display);
//	glutMainLoop();
//}