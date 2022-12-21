#ifndef PANEL_H
#define PANEL_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "panel_defines.h"
#include "common_defines.h"
#include "snake.h"

using namespace cv;
using namespace std;

class Panel
{
    public:
        // Constructor 
        Panel(Snake& t_snake);
        // Main Task 
        void panelMainTask(void);

    private:
        void m_showImage(void);
        void m_getKeyInput(void);
        void m_setDir(void);
        Mat m_background;
        Rect m_square;
        int32_t m_key;
        Snake& m_snake;
};

#endif // PANEL_H