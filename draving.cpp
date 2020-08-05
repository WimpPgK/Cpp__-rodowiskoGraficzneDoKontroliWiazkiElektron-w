#include "draving.h"
#include <math.h>
#include <iostream>

using namespace std;



Draving::Draving(int n)
{
    this->n = n;
    board = new BoardPoint* [n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new BoardPoint[n];
    }

}
void Draving::drawPoint(int x, int y, int size, double value)
{

    for(int i = y ; i < y + size &&  i < n; i++)
    {
        for(int j = x ; j < x + size && j < n ; j++)
        {
            board[i][j].timeFactor = value;
        }
    }
}

void Draving::drawLine(int x1, int y1, int x2, int y2, int size, double value)
{
    //double length = sqrt(1.0*((x1-x2)^2 + (y1-y2)^2));
    //cout << "Dlugosc linii to" << length << endl;

    if(x1 < x2 && y1 < y2)
    {

    }


}

void Draving::drawRectangle(int x1, int y1, int x2, int y2, double value)
{
    for(int i = y1 ; i <= y2; i++)
    {
        for(int j = x1 ; j <= x2; j++)
        {
            board[i][j].timeFactor = value;
        }
    }
}



void Draving::clearSpace()
{
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            board[i][j].setValue(i,j,0,0);
        }
    }
}
