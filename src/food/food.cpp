#include "food.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Public functions
Food::Food()
{  
    generateFoodPosition();
}

void Food::foodMainTask()
{
    ;
}

void Food::generateFoodPosition()
{
    srand((uint32_t) time(NULL) * time(NULL)); // In order to not get the same seed as the snake
    m_xPos = rand()%(MAX_X/FOOD_SIZE - 1) * FOOD_SIZE;
    m_yPos = rand()%(MAX_Y/FOOD_SIZE - 1) * FOOD_SIZE;
}

uint8_t Food::getXPosition()
{
    return m_xPos;
}

uint8_t Food::getYPosition()
{
    return m_yPos;
}
