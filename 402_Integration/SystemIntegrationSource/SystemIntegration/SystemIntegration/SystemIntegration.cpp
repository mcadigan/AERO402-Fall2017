/*************************************************************************
**********************(COPYRIGHT INFORMATION)*****************************
**************************************************************************/

/*************************************************************************
PURPOSE:
	(Initial implementation of the simulation structure for the AERO 402 
	 course, Fall 2017)
LANGUAGE:
	(C++)
LIBRARY DEPENDENCIES:
	(
	 ()
	)
REFERENCES:
	(
	 (None.)
	)
ASSUMPTIONS AND LIMITATIONS:
	(
	 (Currently a work in progress.)
	)
PROGRAMMERS:
	(
	 ((Robert Hogan) (AERO 402) (11/14/2017) (Initial implementation))
	)
**************************************************************************/

#include "stdafx.h"
#include <iostream>
#include "TAS_StateOfObject.h"



void SimUpdate(TAS_StateOfObject *Object, double timespan, double g) 
{
	Object->Update_State(timespan, g);
	return;
}

int main()
{
	double pos0 = 0;						/* *i m    Init position of component */
	double vel0 = 10;						/* *i m/s  Init velocity of component */
	double g = -9.81;						/* *i m/s2 Acceleration of Gravity*/
	TAS_StateOfObject Ball(pos0, vel0);		/* --	   Creating an instance of the sim object*/
	double timespan = 1.0 / 90.0;			/* -- 1/s  Frame rate of sim*/
	int framenum = 1;						/* --      Keeps track of which frame the sim is on */
	bool run = true;						/* --      Runs if true, stops if false*/
	while (run) {

		SimUpdate(&Ball, timespan, g);		/* --      Calls the update function for the ball*/
		std::cout << framenum << ", " << Ball.pos << ", " << Ball.vel << std::endl;
		framenum++;							/* --      Increases the frame number*/

		if (Ball.pos <= 0) {
			run = false;					/* --      Stops sim if the ball hits the ground*/
		}
	}

	return 0;
}




















//#include <chrono>
//#include <thread>


//using namespace std::chrono;
//using fseconds = duration<float>;
//using frame = duration<double, std::ratio<1, 90>>;

//void f(duration<double, std::milli> d) {
//	std::cout << d.count() << std::endl;
//	return;
//}




	/*
	milliseconds mils = 5ms;
	seconds secs = 3s;

	milliseconds combined = mils + secs;
	seconds combinedagain = duration_cast<seconds>(mils + secs);

	fseconds micros = 45ms + 63us;

	frame ticker = 45ms + 63us;
	double checked = ticker.count() / 90;

	std::cout << combined.count() << std::endl;
	std::cout << combinedagain.count() << std::endl;
	std::cout << micros.count() << std::endl;
	std::cout << ticker.count() << std::endl;
	std::cout << checked << std::endl;

	f(frame{ 17 });


	time_point<system_clock, duration<double, std::ratio<1, 90>>> init_time{ system_clock::now() };
	std::this_thread::sleep_for(seconds(1));
	time_point<system_clock, duration<double, std::ratio<1, 90>>> wait_time{ system_clock::now() };
	std::cout << duration_cast<nanoseconds>((wait_time - init_time)).count() << std::endl; // sleeps for 1 second
	std::cout << (wait_time - init_time).count() << std::endl; // sleeps for 90 frames





	*/


