#ifndef PANEL_H
#define PANEL_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "panel_defines.h"
#include "common_defines.h"
#include "snake.h"
#include "food.h"

using namespace std;

class Panel
{
    public:
        // Constructor 
        Panel(Snake& t_snake, Food& t_food);
        // Main Task 
        void panelMainTask();

    private:
        void m_showImage();
        void m_checkSnakeBoundaries();
        void m_printSnake();
        void m_printFood();
        void m_checkFoodEaten();
        cv::Mat m_background;
        cv::Rect m_square;
        Snake& m_snake;
        Food& m_food;
};

#endif // PANEL_H