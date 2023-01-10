#ifndef SNAKE_H
#define SNAKE_H

#include "common_defines.h"
#include "snake_defines.h"
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Snake
{
    public:
        // Constructor
        Snake();
        void snakeMainTask();
        int32_t getXPosition(uint8_t t_slot);
        void setXPosition(int32_t t_xPos);
        int32_t getYPosition(uint8_t t_slot);
        void setYPosition(int32_t t_yPos);
        uint8_t getDir();
        void setDir(uint8_t t_dir);
        uint8_t getLength();
        void increaseLength();
    private:
        void m_updateHead();
        void m_updateTale();
        void m_initTale();
        ArrayX2i m_pos = ArrayX2i::Zero(MAX_LENGTH,2);
        uint8_t m_dir;
        uint8_t m_length;
};

#endif // SNAKE_H