#include "Player.h"
#include <stdio.h>
#include <string.h>

Player::Player() {
	this->incrementer = 0;
	this->decrementer = 0;
	this -> speed = 1;
	this->x = 0.0f;
	this->lifes = 5;
	this->itemsCollected = 0;
	this->radius = 0.5;

	MAX_INCREMENT = 0.25;
	MAX_DECREMENT = 0.25;
	INCREMENT_STEP = 0.02;
	DECREMENT_STEP = 0.03;
}

bool Player::isAlive() {
	return this->lifes > 0;
}

void Player::increaseSpeed() {
	if (incrementer + INCREMENT_STEP < MAX_INCREMENT) {
		incrementer += DECREMENT_STEP;
		speed = speed + speed * incrementer;		
	}
}

void Player::decreaseSpeed() {
	if (decrementer + DECREMENT_STEP < MAX_DECREMENT) {
		decrementer += DECREMENT_STEP;
		speed = speed - speed * decrementer;		
	}
}

void Player::toString() {
	printf("Lifes: %d\n", lifes);
	printf("Incrementer: %.2f\n", incrementer);	
	printf("Decrementer: %.2f\n", decrementer);
	printf("Speed: %.2f\n", speed);
	printf("Collected: %d\n\n\n", itemsCollected);
}