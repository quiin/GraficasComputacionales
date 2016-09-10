#include "Globals.h"
#include "Player.h"

#ifndef PICKUP_H
#define PICKUP_H

class Pickup {	
	public:	
		float x;
		float y;
		float z;
		float speed;
		float radius;
		Color color;
		bool isGood;


		/*Functions*/
		Pickup(Color col);
		void render();
		void applyEffect(Player * player);
		bool isBeyondLimits();

};


#endif
