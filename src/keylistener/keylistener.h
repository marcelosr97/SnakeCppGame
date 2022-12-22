#ifndef KEYLISTENER_H
#define KEYLISTENER_H

#include "keylistener_defines.h"
#include "snake.h"
#include <conio.h>
#include <windows.h>

class KeyListener
{
    public:
        // Constructor
        KeyListener(Snake& t_snake);
        // Main Task 
        void keyListenerMainTask(void);
    private:
        void m_getKeyInput(void);
        bool m_checkKeyIsDown(int32_t t_key);
        void m_setDir(void);
        int32_t m_key;
        Snake& m_snake;
};

#endif // KEYLISTENER_H