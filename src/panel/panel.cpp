#include "panel.h"

using namespace cv;

Panel::Panel(Snake& t_snake, Food& t_food) : m_snake(t_snake), m_food(t_food)
{
    m_commandNewFoodPosition();
}

void Panel::panelMainTask()
{
    m_checkSnakeBoundaries();
    m_checkFoodEaten();
    m_showImage();
}

void Panel::m_showImage()
{
    // Set black background
    m_background = Mat(MAX_X, MAX_Y, CV_8UC3, BLACK_COLOR);

    m_printSnake();

    m_printFood();
    // Show image
    imshow("SnakeCppGame", m_background);
    waitKeyEx(1);
}

void Panel::m_checkSnakeBoundaries()
{
    // Check x boundary
    if(m_snake.getXPosition(HEAD_SLOT) >= MAX_X)
    {
        m_snake.setXPosition(MIN_X);
    }
    else if ((m_snake.getXPosition(HEAD_SLOT) <= - SNAKE_SIZE) && (m_snake.getDir() == LEFT_DIR))
    {
        m_snake.setXPosition(MAX_X - SNAKE_SIZE);
    }

    // Check y boundary
    if(m_snake.getYPosition(HEAD_SLOT) >= MAX_Y)
    {
        m_snake.setYPosition(MIN_Y);
    }
    else if ((m_snake.getYPosition(HEAD_SLOT) <= - SNAKE_SIZE) && (m_snake.getDir() == UP_DIR))
    {
        m_snake.setYPosition(MAX_Y - SNAKE_SIZE);
    }
}

void Panel::m_printSnake()
{
    for(uint8_t index = 0; index <= m_snake.getLength(); index++)
    {
        m_square = Rect(m_snake.getXPosition(index), m_snake.getYPosition(index), SNAKE_SIZE, SNAKE_SIZE);
        rectangle(m_background, m_square, WHITE_COLOR, FILLED);
    }
}

void Panel::m_printFood()
{
    m_square = Rect(m_food.getXPosition(), m_food.getYPosition(), FOOD_SIZE, FOOD_SIZE);
    rectangle(m_background, m_square, RED_COLOR, FILLED);
}

void Panel::m_checkFoodEaten()
{
    // Check if position for snake head slot and food is the same
    if((m_snake.getXPosition(HEAD_SLOT) == m_food.getXPosition()) && (m_snake.getYPosition(HEAD_SLOT) == m_food.getYPosition()))
    {
        m_commandNewFoodPosition();
        m_snake.increaseLength();
    }
}

bool Panel::m_checkPositionConflict()
{
    bool ret = false;
    for(uint8_t index = 0; index <= m_snake.getLength(); index++)
    {
        if((m_snake.getXPosition(index) == m_food.getXPosition()) && (m_snake.getYPosition(index) == m_food.getYPosition()))
        {
            ret = true;
            cout << "Conflict" << endl;
            break;
        }
    }
    return ret;
}

void Panel::m_commandNewFoodPosition()
{
    uint8_t count = 1; // Counter to change the seed
    do
    {
        m_food.generateFoodPosition(count);
        count++;
    } while (m_checkPositionConflict() == true);
}
