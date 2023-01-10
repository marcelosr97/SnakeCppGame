#ifndef FOOD_H
#define FOOD_H

#include "common_defines.h"
#include "food_defines.h"
#include <iostream>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

class Food
{
    public:
        // Constructor
        Food();
        void foodMainTask();
        void generateFoodPosition(uint8_t t_factor);
        uint8_t getXPosition();
        uint8_t getYPosition();
    private:
        uint8_t m_xPos;
        uint8_t m_yPos;
};

#endif // FOOD_H