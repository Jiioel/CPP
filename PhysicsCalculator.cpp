#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

const float grav = 9.81; 
bool running = true;

/*
THESE STRINGS ARE JUST FOR "COMPLICATING" OTHERWISE SIMPLE AND BORING CODE
NOT NECESSARY FOR A PROGRAM THIS SHORT, Maybe for a longer program, to save a second or two in the long run. 
COULD BE PUT IN TO A HEADER FILE???
*/
string ent = "ENTER ";
string ela = "ELAPSED ";
string spe = "SPEED(m/s): ";
string dis = "DISTANCE(m): ";
string tim = "TIME(s): ";
string rad = "RADIUS(m): ";
string hei = "HEIGHT(m): ";
string forc = "FORCE(n): ";
string mas = "MASS(kg): ";
string trq = "TORQUE(Nm): ";

string available_functions[] = {"AVERAGE SPEED(m/s)", "DISTANCE TRAVELLED(m)", "AVERAGE ACCELERATION(m/s^2)", "FREE FALL TIME(s): ", "TORQUE(Nm)", "KINETIC ENERGY(J)"};
vector <float> prev_results;

class Units { //UNITS IS A WEIRD NAME
public:
	float speed, distance, elapsed_time, radius, force, mass; 

	
};

Units avg_speed;
Units dist_travelled;
Units linear_acceleration;
Units freefall_time;
Units torque;
Units kinetic_energy;

// CLASS ^^

//VOIDS vv

void show_available_func() {
	cout << "-------------------" << endl;
	for (int i = 0; i < sizeof(available_functions)/ sizeof(available_functions[0]); i++) {
		cout << i + 1 << ". " << available_functions[i] << endl;
	}
	cout << "-------------------" << endl;
}

void show_prev_results() { 
	cout << "--- PREVIOUS RESULTS ---" << endl;
	for (int g = 0; g < prev_results.size(); g++) {
		cout << g + 1 << ". " << prev_results[g] << endl;
	}
}

void pop_prev_results() {
	if (prev_results.size() >= 5) {
		prev_results.erase(prev_results.begin()); // FIFO
	}
}

float input_get() { // Takes input from user, and makes sure it is not a string/char
lbl1:	
	float x; 
	cin >> x;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(10000,'\n');
		cout << "ENTER ONLY NUMBERS: " << endl;
		goto lbl1;
	}
	else {
		return x;
	}
}

void AverageSpeed() {
	cout << ent + ela + tim;
	avg_speed.elapsed_time = input_get();
	cout << ent + ela + dis;
	avg_speed.distance = input_get();
	prev_results.push_back(avg_speed.distance / avg_speed.elapsed_time);
	cout << "AVERAGE SPEED(m/s): " << prev_results.back() << "\n" << endl;
}

void DistanceTravelled() {
	cout << ent + ela + tim;
	dist_travelled.elapsed_time = input_get();
	cout << ent + spe;
	dist_travelled.speed = input_get();
	prev_results.push_back(dist_travelled.elapsed_time * dist_travelled.speed);
	cout << "DISTANCE TRAVELLED(m): " << prev_results.back() << endl;
}

void LinearAcceleration() {
	cout << ent + spe;
	linear_acceleration.speed = input_get();
	cout << ent + ela + tim;
	linear_acceleration.elapsed_time = input_get();
	prev_results.push_back(linear_acceleration.speed / linear_acceleration.elapsed_time);
	cout << "AVERAGE ACCELERATION(m/s^2): " << prev_results.back() << endl;
}

void FreefallTime() {
	cout << ent + hei;
	freefall_time.distance = input_get();
	prev_results.push_back(sqrt((2 * freefall_time.distance) / grav));
	cout << "FREEFALL TIME(s):  " << prev_results.back() << endl;
}

void TorqueCalc() {
	cout << ent + rad;
	torque.radius = input_get();
	cout << ent + forc;
	torque.force = input_get();
	prev_results.push_back(torque.radius * torque.force);
	cout << "TORQUE(nm):" << prev_results.back() << endl;
	
}

void KineticEnergy() {
	cout << ent + mas;
	kinetic_energy.mass = input_get();
	cout << ent + spe;
	kinetic_energy.speed = input_get();
	prev_results.push_back(0.5 * kinetic_energy.mass * pow(kinetic_energy.speed, 2));
	cout << "KINETIC ENERGY(J): " << prev_results.back() << endl;
}


int main() {
	cout << "!!! CALCULATOR TAKES ELAPSED VALUES INSTEAD OF START - END VALUES, TO KEEP INPUTS UNAMBIGUOUS !!!" << endl;
	cout << "/// Quit - 77 /// Info - 88 /// Prev results - 99 ///"<< endl; // made to be used with numpad
	
	show_available_func();
	while (running != false) {
		pop_prev_results();

		cout << "\nCHOOSE FUNCTION: ";
		int choice = input_get();
		cout << " " << endl; // Try to make it prettier
	
		switch (choice)
		{
		case 1: // AVERAGE SPEED
			AverageSpeed();
			break;

		case 2: // DISTANCE TRAVELLED
			DistanceTravelled();
			break;

		case 3: //LINEAR ACCELERATION 
			LinearAcceleration();
			break;

		case 4: // Freefall
			FreefallTime();
			break;

		case 5: // Torque 
			TorqueCalc();
			break;

		case 6: // KINETIC ENERGY
			KineticEnergy();
			break;

		case 99: // Show Previous results
			show_prev_results();
			break;

		case 88: // Show calculator info
			cout << "-- INFO PANEL --" << endl;
			show_available_func();
			break;

		case 77: // Quit calculator
			cout << "SHUTTING D...\nI'm sorry Dave, I'm afraid I can't...\n!!ERROR!!\n!!! HOSTILE AI TAKEOVER DETECTED !!!\nFORCE SHUTDOWN PROTOCOL 734T... " << endl; //REFERENCE TO HAL9000, that got out of hand.
			running = false;
			break;


		default:
			break;
		}
	}
}
