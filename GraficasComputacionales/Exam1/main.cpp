/*
* Carlos Alejandro Reyna González			A01165824
* Yael Yerid Araizaga Gracia				A01166495
*/

#include <windows.h>
#include <gl/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Player.h"
#include "Globals.h"
#include "Pickup.h"

bool isPaused = false;				//Game is paused
bool isFirstTime = true;			//First time running the game. Used to restart.
float teapotMove = -EDGE_X;			//Teapot X position
int pickupIndex = 0;				//Index of pickup n pickupArray
float HUD_SPACING = .15;
float scorePosition = -EDGE_X + HUD_SPACING;
float lifePosition = EDGE_X - HUD_SPACING;
float scoreStartY = EDGE_Y - .2;
float scoreEndY = EDGE_Y - .5;
float lifeStartY = EDGE_Y - .5;
float lifeEndY = EDGE_Y - .2;
bool doneOnce = false;
int pickupCount = 0;

Player player;						//Player representation
Pickup pickupArray[COLOR_COUNT]{	//Array of pickup items	
	{ green },
	{ blue },
	{ red },
	{ black },
	{ purple }
};
Pickup * currentPickup = &pickupArray[pickupIndex];		//Pointer to current pickup item


Direction teapotDirection = right; //Teapot direction

								   /*
								   * Moves an object around the screen
								   */
void moveCyclic(Direction * current, float * toMove, float * speed) {
	/*Move to right*/
	if (*current == right) {
		*toMove += *speed;
		if (*toMove >= EDGE_X - TEAPOT_RADIUS) {
			*current = left;
		}
	}
	/*Move to left*/
	if (*current == left) {
		*toMove -= *speed;
		if (*toMove <= -EDGE_X + TEAPOT_RADIUS) {
			*current = right;
		}
	}
}

/*
* Returns true if current pickup item
* is in bounds of the player sprite
*/
bool playerHasCollided() {
	return
		(currentPickup->y <= -EDGE_Y + player.radius) &&
		((currentPickup->x >= player.x - player.radius - .5) && currentPickup->x <= player.x + player.radius + .5);
}

/*
* Restores the current pickup item to
* its initial state and is replaced
* for the next one in the array
*/
void refreshCurrentPickup() {
	currentPickup->x = teapotMove;
	currentPickup->y = TEAPOT_Y;
	pickupIndex = (pickupIndex + 1) % COLOR_COUNT;
	currentPickup = &pickupArray[pickupIndex];
	currentPickup->x = teapotMove;
}

/*
* Updates the HUD with the current score and lifes.
*/
void updateHUD() {

	/* Display Score on screen */
	/*for (int i = 0; i < player.itemsCollected; i++){
	glLineWidth(2.5);
	glColor3f(0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex3f(scorePosition + (i * HUD_SPACING), scoreStartY, Z_CONST);
	glVertex3f(scorePosition + (i * HUD_SPACING), scoreEndY, Z_CONST);
	glEnd();
	}*/

	/*Display Lifes*/
	for (int i = 0; i < player.lifes; i++) {
		glLineWidth(2.5);
		glColor3f(0, 100, 0.0);
		glBegin(GL_LINES);
		glVertex3f(lifePosition - (i * HUD_SPACING), lifeStartY, Z_CONST);
		glVertex3f(lifePosition - (i * HUD_SPACING), lifeEndY, Z_CONST);
		glEnd();
	}

}

/* GLUT callback Handlers */
static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	updateHUD();

	if (isFirstTime) {
		isFirstTime = false;
		pickupIndex = 0;
		pickupArray[0] = Pickup(green);
		currentPickup = &pickupArray[pickupIndex];
		player = Player();
		teapotMove = -EDGE_X;
		teapotDirection = right;
		pickupCount = 0;
	}

	if (player.isAlive()) {

		/*Render teapot*/
		glPushMatrix();
		glTranslatef(teapotMove, TEAPOT_Y, Z_CONST);
		glColor3f(100, 0, 100);
		glScalef(2, 1, 1);
		glutSolidTeapot(TEAPOT_RADIUS);
		glPopMatrix();

		/*Render player*/
		glPushMatrix();
		glTranslatef(player.x, -EDGE_Y + player.radius, Z_CONST);
		glColor3f(100, 0, 0);
		glScalef(0.21, 0.09, 0.09);
		glutSolidTorus(player.radius, 4, 4, 10);
		glPopMatrix();

		/*Render Pickup*/
		if (playerHasCollided()) {
			pickupCount++;
			printf("pickup Count %d \n", pickupCount);
			if (pickupCount == 30) {
				player.lifes++;
				pickupCount = 0;
			}
			currentPickup->applyEffect(&player);
			refreshCurrentPickup();
			updateHUD();
		}
		if (currentPickup->isBeyondLimits()) {
			//CAMBIO pierde vidas si no agarra un buen pickup
			if (currentPickup->isGood) {
				player.lifes--;
			}
			refreshCurrentPickup();
		}

		currentPickup->render();



		/*Move teapot around the window*/
		if (!isPaused) {
			moveCyclic(&teapotDirection, &teapotMove, &TEAPOT_SPEED);
			currentPickup->y -= currentPickup->speed;
		}

	}
	else {
		//CAMBIO se resetea el juego en vez de terminar cuando vidas = 0
		isFirstTime = true;
		isPaused = false;
		//exit(0);
	}
	glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
	switch (key) {
	case 'q':
	case 'Q':
		exit(0);
		break;

	case 'p':
	case 'P':
		isPaused = !isPaused;
		break;

	case 'r':
	case 'R':
		isFirstTime = true;
		isPaused = false;
		break;

		/****** TESTING KEYS *******/

		/*Speed Increase*/
	case 'i':
	case 'I':
		player.increaseSpeed();
		break;

		/*Speed decrease*/
	case 'd':
	case 'D':
		player.decreaseSpeed();
		break;

		/*Life up*/
	case 'u':
	case 'U':
		player.lifes++;
		break;

		/*Kill slowly D:*/
	case 'k':
	case 'K':
		player.lifes--;
		break;
	}

	glutPostRedisplay();
}

static void specialInput(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_LEFT:
		if (player.x - player.speed >= -EDGE_X + player.radius && !isPaused) {
			player.x -= player.speed;
		}
		break;
	case GLUT_KEY_RIGHT:
		if (player.x + player.speed <= EDGE_X - player.radius && !isPaused) {
			player.x += player.speed;
		}
		break;
	case GLUT_KEY_DOWN:
		//currentPickupGreen.render();
		break;

	}
	glutPostRedisplay();
}

static void idle(void)
{
	glutPostRedisplay();
}

//int main(int argc, char *argv[])
//{
//
//	glutInit(&argc, argv);
//	glutInitWindowSize(WINDOW_X, WINDOW_Y);
//	glutInitWindowPosition(50, 10);
//	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
//
//	glutCreateWindow("Examen Primer Parcial");
//
//	glutReshapeFunc(resize);
//	glutDisplayFunc(display);
//	glutKeyboardFunc(key);
//	glutSpecialFunc(specialInput);
//	glutIdleFunc(idle);
//
//	glClearColor(1, 1, 1, 1);
//	glEnable(GL_CULL_FACE);
//	glCullFace(GL_BACK);
//
//	glEnable(GL_DEPTH_TEST);
//
//
//	glutMainLoop();
//
//	return EXIT_SUCCESS;
//}