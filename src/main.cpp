#include "panel.h"
#include "keylistener.h"
#include "common_defines.h"
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono;

Snake snake;
KeyListener keylistener(snake);
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
		snake.snakeMainTask();
		panel.panelMainTask();
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
			keylistener.keyListenerMainTask();
		}
}


int main(void)
{
    thread mainTh(mainThread);
    
	mainTh.join();

  	return(0);
}