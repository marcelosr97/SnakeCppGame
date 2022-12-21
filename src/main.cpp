#include "panel.h"
#include "common_defines.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;
Snake snake;
Panel panel(snake);

static void mainThread(void);
static void goToSleep(system_clock::time_point t_initTime);
static void mainThread(void)
{
	
	while(true)
	{
		// Get initial task time
		auto initTime = system_clock::now();
		// Tasks
		panel.panelMainTask();
		snake.snakeMainTask();
		goToSleep(initTime);
	}

}

static void goToSleep(system_clock::time_point t_initTime)
{
		duration<float, milli> elapsedTime;
		while((int16_t) elapsedTime.count() < PERIOD)
		{
			auto finalTime = system_clock::now();
			elapsedTime = finalTime - t_initTime;
		}
		cout << (int16_t) elapsedTime.count() << endl;
}


int main(void)
{
    thread mainTh(mainThread);
    
	mainTh.join();

  	return(0);
}