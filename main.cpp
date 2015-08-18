// Grid World

#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include "Agent.h"
#include "Target.h"
#include "World.h"
#include "Test.h"
#include "Scoreboard.h"

using namespace std;

class Agent;	
class Target;
class World;

void print_grid(Agent* pA, Target* pT, World* pW);
void hard_code(Agent* pA, Target* pT);
int get_state(Agent* pA, World* pW);
int state_from_pos(Agent* pA, World* pW);
bool victory(Agent* pA, Target* pT, World* pW);
bool timesteps_reached(Agent* pA);

int state;

int main()
{
	// Set Objects
	World world_1;
	Agent agent_1;
	Target target_1;
	// Scoreboard scoreboard_1;
	// Test test_1;

	World* pW = &world_1;
	Agent* pA = &agent_1;
	Target* pT = &target_1;
	// Scoreboard* pSB = &scoreboard_1;
	// Test* pTEST = &test_1;

	// Set Grid
	world_1.setx_min(0);
	world_1.sety_min(0);
	world_1.setx_max(3);
	world_1.sety_max(3);

	// Set Target					// TODO TEST - make resolve bad target placement, ends program	
	target_1.setx_target(3);		
	target_1.sety_target(3);

	// Set Agent initial position	// TODO TEST - make resolve bad Agent placement, ends program	
	agent_1.setx_agent(0);			
	agent_1.sety_agent(0);

	// Set Qupdate
	agent_1.set_alpha(0.2);	
	agent_1.set_gamma(0.8);
	agent_1.set_epsilon(0.1);		// exploration
	 
	// Set number of Episodes		// TODO TEST - make incorrect episode value, ends program	
	agent_1.set_episodes(30);

	// Set number of Timesteps
	agent_1.set_timesteps(20);

	// Hard Code Main Function--------------------------------------------------------------------------------------------------
	//for (int e = 1; e < pA->get_episodes; e++){
		//while (!victory(pA, pT, pW)){
		//	print_grid(pA, pT, pW);
		//	get_state(pA, pW);
		//	hard_code(pA, pT);
		//	agent_1.move_agent(pW->getx_min(), pW->gety_min(), pW->getx_max(), pW->gety_max());
		//	agent_1.resolve(pW->getx_min(), pW->gety_min(), pW->getx_max(), pW->gety_max());

		//	// log_steps(); 
		//}
	//}
	// TODO 8/2 - Show Agent Statistics after episodes complete
	// ---------------------------------------------------------------------------------------------------------------
	
	agent_1.build_Qtable(pW->getx_max(), pW->gety_max());

	for (int e = 0; e < pA->get_episodes(); e++){
		// TODO- make reset agent function that includes all resets
		agent_1.setx_agent(0);
		agent_1.sety_agent(0);
		agent_1.set_steps(0);

		while (!victory(pA, pT, pW)){
			// sense()
			get_state(pA, pW);

			// decide()
			pA->decide();

			// act()
			pA->get_input(pA->get_action());
			pA->move_agent(pW->getx_min(), pW->gety_min(), pW->getx_max(), pW->gety_max());

			// react()			// TODO 8/10 - fix react() so duplicate of state doesn't happen
			int oldstate = pA->get_state();
			int newstate = state_from_pos(pA, pW);	// duplicate happens here
			double r = pA->compare(pT);
			pA->Qupdate(r, newstate, oldstate);

			// TODO - function that keeps log of steps taken until constant action or pattern develops.
		}
	}
}

// Print Grid function,
void print_grid(Agent* pA, Target* pT, World* pW){
	// Y-axis boundary
	for (int y = pW->gety_max(); y >= pW->gety_min(); y--)
	{
		// X-axis boundary
		for (int x = pW->getx_min(); x <= pW->getx_max(); x++)
		{
			if (x == pA->getx_agent() && y == pA->gety_agent()) 
			{
				cout << "A";
			}
			else if (x == pT->getx_target() && y == pT->gety_target()) 
			{
				cout << "T";
			}
			else
			{
				cout << 0;
			}
		}
		cout << endl;
	}
}

// Hard Coded Move Agent
void hard_code(Agent* pA, Target* pT){
	if (pA->getx_agent() < pT->getx_target()){
		pA->get_input(2);		// increases x_agent until equal to x_target
		cout << endl;
	}
	else if (pA->gety_agent() < pT->gety_target()){
		pA->get_input(0);		// increases y_agent until equal to y_target
		cout << endl;
	}
	else if (pA->getx_agent() > pT->getx_target()){
		pA->get_input(1);		// decreases x_agent until equal to x_target
		cout << endl;
	}
	else if (pA->gety_agent() > pT->gety_target()){
		pA->get_input(3);		// decreases y_agent until equal to x_target
		cout << endl;
	}
	else {
		cout << "must be on taget" << endl;
	}
}

// -------------------------------------------------------------------------------- // TODO- move into Agent Class
// State Function
int get_state(Agent* pA, World* pW){		// gets and updates state varaible
	int s = pA->getx_agent() + (pW->getx_max()+1)*(pA->gety_agent() );
	cout << s << endl;
	pA->set_state(s);
	return s;

	// TODO 7/31 - get agents position from state 
	// Idea- only make states from visited positions, doesn't need world information
}

// State from Position Function
int state_from_pos(Agent* pA, World* pW){		// State from position 
	int s = pA->getx_agent() + (pW->getx_max() + 1)*(pA->gety_agent());
	return s;
}
// -----------------------------------------------------------------------------------

// TODO- Implement Steptable from notes

// Victory Function
bool victory(Agent* pA, Target* pT, World* pW){ // Checks to see if Agent and Target coordinates are equal
	char e;
	if (pA->getx_agent() == pT->getx_target() && pA->gety_agent() == pT->gety_target())
	{
		// cout << "Last state was:" << get_state(pA, pW);
		cout << endl << "Victory Complete!" << endl << endl;
		cout << "steps = " << pA->get_steps() << endl;
		cout << "total steps = " << pA->get_total_steps() << endl;
		// TODO - show log of times visited grid
		cout << "press e and enter to continue" << endl;
		cin >> e;
		return true;
	}
	else if (pA->get_steps() >= pA->get_timesteps())
	{
		cout << endl << "Maxed Out timesteps..." << endl << endl;
		cout << "steps = " << pA->get_steps() << endl;
		cout << "total steps = " << pA->get_total_steps() << endl;
		cout << "press e and enter to continue" << endl;
		cin >> e;
		return true;
	}
	else
	{
		return false;
	}
}
	







