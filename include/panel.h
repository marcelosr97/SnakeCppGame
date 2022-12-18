#ifndef PANEL_H
#define PANEL_H

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace cv;
using namespace std;

class Panel
{
    public:
    /* Constructor */
    Panel();
    /* Main Task */
    void panelMainTask(void);

    private:
    Mat m_background;
    Rect m_square;
};

#endif /* PANEL_H */