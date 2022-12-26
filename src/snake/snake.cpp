#include "snake.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

// Public functions
Snake::Snake()
{
    srand((uint32_t) time(NULL));
    m_dir = RIGHT_DIR;
    m_xPos = rand()%(MAX_X - SNAKE_SIZE);
    m_yPos = rand()%(MAX_Y - SNAKE_SIZE);
}

void Snake::snakeMainTask()
{
    m_updatePosition();
}

uint16_t Snake::getXPosition()
{
    return m_xPos;
}

uint16_t Snake::getYPosition()
{
    return m_yPos;
}

void Snake::setXPosition(uint16_t t_xPos)
{
    m_xPos = t_xPos;
}

void Snake::setYPosition(uint16_t t_yPos)
{
    m_yPos = t_yPos;
}

uint8_t Snake::getDir()
{
    return m_dir;
}

void Snake::setDir(uint8_t t_dir)
{
    m_dir = t_dir;
}

// Private functions
void Snake::m_updatePosition()
{   
    switch(m_dir)
    {
        case UP_DIR:
            m_yPos -= SNAKE_SIZE;
            break;       
        case DOWN_DIR:
            m_yPos += SNAKE_SIZE;
            break;
        case LEFT_DIR:
            m_xPos -= SNAKE_SIZE;
            break;            
        case RIGHT_DIR:
            m_xPos += SNAKE_SIZE;
            break;
        default:
            // Do nothing
            break;        
    }
}
