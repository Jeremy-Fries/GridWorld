// Class World

#include <iostream>

using namespace std;

#ifndef WORLD_H
#define WORLD_H

class World{
	class Agent;		// intitilazes classes before headers
	class Target;
public:
	// Creating references to private variables
	int& x_minr = x_min;
	int& y_minr = y_min;
	int& x_maxr = x_max;
	int& y_maxr = y_max;


	// Default Constructor
	World();

	// Overload Constructor
	World(int, int, int, int);

	// Destructor
	~World();

	//Accessor Functions --------------------------------------------------
	int getx_min() const;
		// getx_min - returns min x-axis value
	int gety_min() const;
		// gety_min - returns min y-axis value
	int getx_max() const;
		// getx_min - returns max x-axis value
	int gety_max() const;
		// gety_max - returns max y-axis value

	// Mutator Functions ---------------------------------------------------
	void setx_min(int);
		// setx_min - sets x_min to desired range
	void sety_min(int);
		// sety_min - sets y_min to desired range
	void setx_max(int);
		// setx_max - sets x_max to desired range
	void sety_max(int);
		// sety_max - sets y_max to desired range

	// Function for Grid
	//void print_grid(Agent*, Target*);

private:	
	// Variables 
	int x_min, y_min, x_max, y_max;  

};

#endif // WORLD_H

