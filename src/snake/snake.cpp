#include "snake.h"
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <conio.h>

// Public functions
Snake::Snake()
{
    m_dir = RIGHT_DIR;
    m_xPos = 32;
    m_yPos = 32;
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

uint8_t Snake::setXPosition()
{
    return 0;
}

uint8_t Snake::setYPosition()
{
    return 0;
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
            m_yPos -= 32;
            break;       
        case DOWN_DIR:
            m_yPos += 32;
            break;
        case LEFT_DIR:
            m_xPos -= 32;
            break;            
        case RIGHT_DIR:
            m_xPos += 32;
            break;
        default:
            // Do nothing
            break;        
    }
}
