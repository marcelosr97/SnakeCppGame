#include "panel.h"

using namespace cv;

Panel::Panel(Snake &t_snake) : m_snake(t_snake)
{
    ;
}

void Panel::panelMainTask()
{
    m_checkSnakeBoundaries();
    m_showImage();
}

void Panel::m_showImage()
{
    // Set black background
    m_background = Mat(MAX_X, MAX_Y, CV_8UC3, BLACK_COLOR);
    // Print snake
    m_square = Rect((int32_t) m_snake.getXPosition(), (int32_t) m_snake.getYPosition(), SNAKE_SIZE, SNAKE_SIZE);
    rectangle(m_background, m_square, WHITE_COLOR, FILLED);
    // Show image
    imshow("SnakeCppGame", m_background);
    waitKeyEx(1);
}

void Panel::m_checkSnakeBoundaries()
{
    // Check x boundary
    if(m_snake.getXPosition() >= MAX_X)
    {
        m_snake.setXPosition(0);
    }
    else if ((m_snake.getXPosition() <= 0) && (m_snake.getDir() == LEFT_DIR))
    {
        m_snake.setXPosition(MAX_X - SNAKE_SIZE);
    }

    // Check y boundary
    if(m_snake.getYPosition() >= MAX_Y)
    {
        m_snake.setYPosition(0);
    }
    else if ((m_snake.getYPosition() <= 0) && (m_snake.getDir() == UP_DIR))
    {
        m_snake.setYPosition(MAX_Y - SNAKE_SIZE);
    }
}
