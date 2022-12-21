#include "panel.h"

using namespace cv;

Panel::Panel(Snake &t_snake) : m_snake(t_snake)
{
    ;
}

void Panel::panelMainTask(void)
{
    m_getKeyInput();
    m_showImage();
    m_setDir();
}

void Panel::m_showImage(void)
{
    m_background = Mat(512, 512, CV_8UC3, Scalar(0, 0, 0));
    m_square = Rect((int32_t) m_snake.getXPosition(), (int32_t) m_snake.getYPosition(), 32, 32);
    rectangle(m_background, m_square, Scalar(255,255,255), FILLED);
    imshow("SnakeCppGame", m_background);
    waitKeyEx(1);
}

void Panel::m_getKeyInput()
{
    m_key = NO_KEY;
}

void Panel::m_setDir()
{
    if(m_key != NO_KEY)
    {
        switch(m_key)
        {
            case UP_ARROW:
                if((m_snake.getDir() != DOWN_DIR) && (m_snake.getDir() != UP_DIR)) m_snake.setDir(UP_DIR);
                break;
            case DOWN_ARROW:
                if((m_snake.getDir() != UP_DIR) && (m_snake.getDir() != DOWN_DIR)) m_snake.setDir(DOWN_DIR);
                break;
            case LEFT_ARROW:
                if((m_snake.getDir() != RIGHT_DIR) && (m_snake.getDir() != LEFT_DIR)) m_snake.setDir(LEFT_DIR);
                break;
            case RIGHT_ARROW:
                if((m_snake.getDir() != LEFT_DIR) && (m_snake.getDir() != RIGHT_DIR)) m_snake.setDir(RIGHT_DIR);
                break;
            default:
                // Do nothing
                break;
        }
    }
}
