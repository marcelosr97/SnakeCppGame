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
    m_initTale();
    m_dir = RIGHT_DIR;
    m_length = MIN_LENGTH;
}

void Snake::snakeMainTask()
{
    m_updateTale();
    m_updateHead();
}

int32_t Snake::getXPosition(uint8_t t_slot)
{
    return m_pos(t_slot, X_INDEX);
}

int32_t Snake::getYPosition(uint8_t t_slot)
{
    return m_pos(t_slot, Y_INDEX);
}

void Snake::setXPosition(int32_t t_xPos)
{
    m_pos(HEAD_SLOT, X_INDEX) = t_xPos;
}

void Snake::setYPosition(int32_t t_yPos)
{
    m_pos(HEAD_SLOT, Y_INDEX) = t_yPos;
}

uint8_t Snake::getDir()
{
    return m_dir;
}

void Snake::setDir(uint8_t t_dir)
{
    m_dir = t_dir;
}

uint8_t Snake::getLength()
{
    return m_length;
}

void Snake::increaseLength()
{
    m_length++;
}

// Private functions
void Snake::m_updateHead()
{   
    switch(m_dir)
    {
        case UP_DIR:
            m_pos(HEAD_SLOT, Y_INDEX) -= SNAKE_SIZE;
            break;       
        case DOWN_DIR:
            m_pos(HEAD_SLOT, Y_INDEX) += SNAKE_SIZE;
            break;
        case LEFT_DIR:
            m_pos(HEAD_SLOT, X_INDEX) -= SNAKE_SIZE;
            break;            
        case RIGHT_DIR:
            m_pos(HEAD_SLOT, X_INDEX) += SNAKE_SIZE;
            break;
        default:
            // Do nothing
            break;        
    }
}

void Snake::m_updateTale()
{
    for(uint8_t index = m_length; index > 0; index--)
    {
        m_pos(index, X_INDEX) = m_pos(index-1, X_INDEX);
        m_pos(index, Y_INDEX) = m_pos(index-1, Y_INDEX);
    }
}

void Snake::m_initTale()
{
    srand((uint32_t) time(NULL));
    m_pos(0, X_INDEX) = rand()%(MAX_X/SNAKE_SIZE - 1)*SNAKE_SIZE;
    m_pos(0, Y_INDEX) = rand()%(MAX_Y/SNAKE_SIZE - 1)*SNAKE_SIZE;
    m_pos(1, X_INDEX) = m_pos(0, X_INDEX) - SNAKE_SIZE;
    m_pos(1, Y_INDEX) = m_pos(0, Y_INDEX);
    m_pos(2, X_INDEX) = m_pos(1, X_INDEX) - SNAKE_SIZE;
    m_pos(2, Y_INDEX) = m_pos(1, Y_INDEX);
}
