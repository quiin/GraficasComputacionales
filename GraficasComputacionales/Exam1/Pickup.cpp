#include <gl/glut.h>
#include "Pickup.h"
#include "Globals.h"
#include <stdio.h>


Pickup::Pickup(Color  col) {	
	this->radius = 0.5;
	this->color = col;
	this->x = 0;
	this->y = EDGE_Y - radius -1.5;
	this->z = Z_CONST;	
	this->speed = 0.01;
	switch (col) {
		case green:
			this->isGood = true;
			break;
		case blue:
			this->isGood = true;
			break;
		case red:
			this->isGood = false;
			break;
		case black:
			this->isGood = false;
			break;
		case purple:
			this->isGood = true;
			break;
	}
}

void Pickup::render() {
	glPushMatrix();
		glTranslatef(this -> x, this -> y, this->z);
		switch (color) {
			case green:
				glColor3f(0, 255, 0);
				break;
			case blue:
				glColor3f(0, 0, 255);
				break;
			case red:
				glColor3f(255, 0, 0);
				break;
			case black:
				glColor3f(0, 0, 0);
				break;
			case purple:
				glColor3f(255, 0, 255);
				break;

		}		
		glScalef(0.21, 0.09, 0.09);
		glutSolidSphere(radius, 50, 50);		
	glPopMatrix();
}

void Pickup::applyEffect(Player * player) {
	if (this->isGood) {		
		player->itemsCollected++;
		if (player->itemsCollected == 30) {
			player->lifes++;
		}
	}	
	
	switch (color){	
	case green:		
		printf("Green Item...\n");
		break;
	case blue:
		player->increaseSpeed();
		printf("Blue Item. Percentage is %.2f; Speed = %.2f\n", player->incrementer * 100, player->speed);
		break;
	case red:
		player->decreaseSpeed();
		printf("Red Item. Percentage is %.2f; Speed = %.2f\n", player ->decrementer * 100, player->speed);
		break;
	case black:
		player->lifes--;
		printf("Black Item. Lifes decreased!\n");
		break;
	case purple:
		player->lifes++;
		printf("Purple Item. Life +1!\n");
		break;
	default:
		break;
	}
}

/*
 * Returns true if the pickup object is
 * beyond the screen vertical edge*/
bool Pickup::isBeyondLimits() {
	return y < - EDGE_Y + radius;
}