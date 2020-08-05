#ifndef EXPORT_H
#define EXPORT_H
#include "boardpoint.h"
#include <iostream>
using namespace std;

class Export
{
    static const int maxElementAmount = 2500;
public:
    Export();
    bool parseData(BoardPoint** board, int pointsPerPixel, int timeBase, string scanningType, int numberOfLayers, int n);
    void printBoard(BoardPoint** board, int m);
    void exportToFile();
};

#endif // EXPORT_H
