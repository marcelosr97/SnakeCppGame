#include "panel.h"

using namespace cv;

Panel::Panel()
{
    Mat m_backgroundTmp = Mat(512, 512, CV_8UC3, Scalar(0, 0, 0));
    m_background = m_backgroundTmp;
    Rect m_squareTmp = Rect(20,20,32,32);
    m_square = m_squareTmp;
}

void Panel::panelMainTask(void)
{
    rectangle(m_background, m_square, Scalar(255,255,255), 2, 1);
    imshow("SnakeCppGame", m_background);
    waitKey(50);
}
