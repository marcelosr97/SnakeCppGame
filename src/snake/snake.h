#ifndef SNAKE_H
#define SNAKE_H

#include "common_defines.h"
#include <iostream>

using namespace std;

class Snake
{
    public:
        // Constructor
        Snake();
        void snakeMainTask();
        uint16_t getXPosition();
        uint8_t setXPosition();
        uint16_t getYPosition();
        uint8_t setYPosition();
        uint8_t getDir();
        void setDir(uint8_t t_dir);
    private:
        void m_updatePosition();
        uint16_t m_xPos;
        uint16_t m_yPos;
        uint8_t m_dir;
};

#endif /* SNAKE_H */