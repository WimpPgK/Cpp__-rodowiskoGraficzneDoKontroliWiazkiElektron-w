#ifndef BOARDPOINT_H
#define BOARDPOINT_H


class BoardPoint
{
public:
    BoardPoint();
    int x;
    int y;
    double timeFactor;
    int time;
    void setValue(int x, int y, int timeFactor, int time);

};

#endif // BOARDPOINT_H
