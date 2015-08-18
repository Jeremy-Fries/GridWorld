// Class World

#include "World.h"
#include <iostream>

using namespace std;

// Default Constructor
World::World(){ // Set default parameters
	x_min = 1;
	y_min = 1; 
	x_max = 5; 
	y_max = 5;
}

// Overload Constructor
World::World(int m, int n, int mm, int nn){ // Manually set parameters in main file; World( x_min, y_min, x_max, y_max)
	x_min = m;
	y_min = n;
	x_max = mm;
	y_max = nn;
}

// Destructor
World::~World(){

}

// Accessor Functions --------------
int World::getx_min() const{
	return x_min;
}

int World::gety_min() const{
	return y_min;
}

int World::getx_max() const{
	return x_max;
}

int World::gety_max() const{
	return y_max;
}

// Mutator Functions ----------------
void World::setx_min(int m){
	x_min = m;
}

void World::sety_min(int n){
	y_min = n;
}
void World::setx_max(int mm){
	x_max = mm;
}

void World::sety_max(int nn){
	y_max = nn;
}

// -------------------------Should this be implmented in main() so classes aren't associated inside a class?
//// Print Grid function,
//void World::print_grid(Agent* pA, Target* pT){
//	// Y-axis boundary
//	for (int y = y_max; y >= y_min; y--)
//	{
//		// X-axis boundary
//		for (int x = x_min; x <= x_max; x++)
//		{
//			if (x == pA->getx_agent() && y == pA->gety_agent()) // -------------will i need a pointer or reference to agent? 
//			{
//				cout << "A";
//			}
//			else if (x == pT->getx_target() && y == pT->gety_target()) // --------------will i need a pointer or reference to target? yes
//			{
//				cout << "T";
//			}
//			// Can be used at later time if multiple targets, need function to remove agent after found
//			/*else if (x_agent == x_target && y_agent == y_target)
//			{
//			cout << "V";
//			}*/
//			else
//			{
//				cout << 0;
//			}
//		}
//		cout << endl;
//	}
//}


