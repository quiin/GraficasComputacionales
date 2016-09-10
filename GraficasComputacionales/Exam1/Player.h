
#ifndef PLAYER_H 
#define PLAYER_H

class Player {	
	private:
		float MAX_INCREMENT;
		float MAX_DECREMENT;
		float INCREMENT_STEP;
		float DECREMENT_STEP;

	public:
		/*Instance variables*/		
		float incrementer;
		float decrementer;
		float speed;
		float x;
		float radius;
		int lifes;
		int itemsCollected;
		

		/*Functions*/
		Player();
		bool isAlive();
		void increaseSpeed();
		void decreaseSpeed();
		void toString();

};

#endif 

