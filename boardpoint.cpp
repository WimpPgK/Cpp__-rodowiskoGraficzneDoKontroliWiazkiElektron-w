#include "boardpoint.h"
#include <iostream>

using namespace std;


BoardPoint::BoardPoint()
{
    x = -1;
    y = -1;
    timeFactor = -1;
    time = -1;
    //cout << "Tworze punkt" << endl;
}

void BoardPoint::setValue(int x, int y, int color, int time)
{
    this->x = x;
    this->y = y;
    this->timeFactor = color;
    this->time = time;
}
