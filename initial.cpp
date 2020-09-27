//This program computes pendulum data and loads it into a .txt file
//Inspired by Computational Physics Konstantinos N. Anagnostopoulos

#include <iostream>  
#include <fstream>  
#include <cstdlib>  
#include <string>  
#include <cmath>  
using namespace std;



int main() {

	//Variables and file initialization
	//---------------------------------------------
	double l, theta, theta0, t0, tf, dt, omega, g, t, x, y, vx, vy, dtheta;

	g = 9.81998;

	ofstream myfile("pendulum.txt");




	//Inputs 
	//---------------------------------------------------------------
	cout << "Please enter the length of the pendulum" << endl;
	cin >> l;
	if (l <= 0) {
		cout << "please enter a length greater than zero" << endl;
		cin >> l;
	}

	cout << "Please enter the initial angle in radians" << endl;
	cin >> theta0;

	cout << "Please enter the initial time" << endl;
	cin >> t0;
	if (l <= 0) {
		cout << "please enter a time greater than zero" << endl;
		cin >> t0;
	}

	cout << "Please enter the final time" << endl;
	cin >> tf;
	if (tf <= t0) {
		cout << "please enter a time greater than zero" << endl;
		cin >> tf;
	}


	cout << "Please enter dt" << endl;
	cin >> dt;
	if (dt <= 0) {
		cout << "please enter a dt greater than zero" << endl;
		cin >> dt;
	}

	//Equations 
	//---------------------------------------------

	omega = sqrt(g / l);
	t = t0;

	while (t <= tf) {
		theta = theta0 * cos(omega * (t - t0));
		dtheta = -theta *omega * sin(omega * (t - t0));
		x = l * sin(theta);
		y = -l * cos(theta);
		vx = l * dtheta * cos(theta);
		vy = l * dtheta * sin(theta);

		myfile << t << " " << x << " " << y << " " << vx << " " << vy << " " << theta << dtheta << endl;

t = t + dt;
	}




		

	 
}
