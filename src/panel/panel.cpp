#include "panel.h"

using namespace cv;

Panel::Panel(Snake &t_snake) : m_snake(t_snake)
{
    ;
}

void Panel::panelMainTask(void)
{
    m_showImage();
}

void Panel::m_showImage(void)
{
    m_background = Mat(512, 512, CV_8UC3, Scalar(0, 0, 0));
    m_square = Rect((int32_t) m_snake.getXPosition(), (int32_t) m_snake.getYPosition(), 32, 32);
    rectangle(m_background, m_square, Scalar(255,255,255), FILLED);
    imshow("SnakeCppGame", m_background);
    waitKeyEx(1);
}