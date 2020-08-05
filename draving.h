#ifndef DRAVING_H
#define DRAVING_H

#include "boardpoint.h"


class Draving
{
public:
    int n;
    BoardPoint **board;
    void clearSpace();  // funkcja ustawia na nowo wszystkie pola planszy i zeruje ich wartości, tworzy tzn. czysta plansze

    void drawPoint(int x, int y, int size, double value);
    void drawLine(int x1, int y1, int x2, int y2, int size, double value);
    void drawRectangle(int x1, int y1, int x2, int y2, double value);


    Draving(int n);
};

#endif // DRAVING_H
