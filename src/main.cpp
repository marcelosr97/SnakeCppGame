#include "panel.h"
#include <thread>

using namespace std;

static Panel panel;

void mainThread(void)
{
	while(1)
	{
		panel.panelMainTask();	
	}
}

int main(void){

    thread th(mainThread);
    
    if(th.joinable())
	{
        th.join();
    }

  return(0);
}