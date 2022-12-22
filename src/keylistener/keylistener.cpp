#include "keylistener.h"

KeyListener::KeyListener(Snake &t_snake) : m_snake(t_snake)
{
    ;
}

void KeyListener::keyListenerMainTask(void)
{
    m_getKeyInput();
    m_setDir();
}

void KeyListener::m_getKeyInput(void)
{
    if(m_checkKeyIsDown(VK_UP))    
    {
        m_key = VK_UP;
    }
    else if (m_checkKeyIsDown(VK_DOWN))
    {
        m_key = VK_DOWN;
    }
    else if (m_checkKeyIsDown(VK_RIGHT))
    {
        m_key = VK_RIGHT;
    }
    else if (m_checkKeyIsDown(VK_LEFT))
    {
        m_key = VK_LEFT;
    }
    else
    {
        m_key = NO_KEY;
    }
}

bool KeyListener::m_checkKeyIsDown(int32_t t_key)
{
    return GetKeyState(t_key) & 0x8000; // MSB indicates if the key is held down
}

void KeyListener::m_setDir(void)
{
    if(m_key != NO_KEY)
    {
        switch(m_key)
        {
            case VK_UP:
                if((m_snake.getDir() != DOWN_DIR) && (m_snake.getDir() != UP_DIR)) m_snake.setDir(UP_DIR);
                break;
            case VK_DOWN:
                if((m_snake.getDir() != UP_DIR) && (m_snake.getDir() != DOWN_DIR)) m_snake.setDir(DOWN_DIR);
                break;
            case VK_LEFT:
                if((m_snake.getDir() != RIGHT_DIR) && (m_snake.getDir() != LEFT_DIR)) m_snake.setDir(LEFT_DIR);
                break;
            case VK_RIGHT:
                if((m_snake.getDir() != LEFT_DIR) && (m_snake.getDir() != RIGHT_DIR)) m_snake.setDir(RIGHT_DIR);
                break;
            default:
                // Do nothing
                break;
        }
    }
}
