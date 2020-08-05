#include "export.h"
#include <fstream>

using namespace std;
Export::Export()
{

}

bool Export::parseData(BoardPoint** board, int pointsPerPixel,int timeBase, string scanningType,int numberOfLayers, int n)
{
    int minVal = 48;
    int maxVal = 4096;
    int valueRange = maxVal - minVal;
    int m = n*pointsPerPixel;
    double step = valueRange/(m - 1);
    fstream file;
    file.open("data.txt",ios::out);
    int x;
    int y;
    int time;


    /*
     * przygotowanie planszy do skanowania poprzez jej przeskalowanie
     *
     */

    BoardPoint** boardPom;
    boardPom = new BoardPoint* [m];
    for (int i = 0; i < m ; i++)
    {
        boardPom[i] = new BoardPoint[m];
    }

    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            boardPom[i][j].setValue(i,j,0,0);
        }
    }

    int pom_i = 0;
    int pom_j = 0;

    for(int i = 0 ; i < n ; i++)
    {

        for(int j = 0 ; j < n ; j++)
        {

            if(board[i][j].timeFactor != 0)
            {
                for(int k = 0; k < pointsPerPixel; k++)
                {
                    for(int l = 0; l < pointsPerPixel ; l++)
                    {
                        boardPom[pom_i+k][pom_j+l].timeFactor = board[i][j].timeFactor;

                    }
                }
            }
            pom_j += pointsPerPixel;
        }
        pom_j = 0;
        pom_i += pointsPerPixel;
    }


    /* aby wyswietlic stan tabeli */
    //printBoard(boardPom, m);

    int numberOfDrowingElements = 0;
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
           if(boardPom[i][j].timeFactor != 0.0)
           {
              numberOfDrowingElements++;
           }
        }
    }


    cout << "Rysowanych jest " << numberOfDrowingElements << " elementow" <<endl;
    if (numberOfDrowingElements > maxElementAmount)
    {
        return false;
    }

    file << numberOfDrowingElements << endl;
    file << numberOfLayers;
    /*
     * strategie skanowania
     *
     */
    if(scanningType =="horizontal")
    {
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(boardPom[i][j].timeFactor != 0.0)
                {
                    //cout << "Element jest na pozycji " << i << "  " << j << endl;
                    x = minVal + j*step;
                    y = minVal + i*step;
                    time = boardPom[i][j].timeFactor * timeBase;        // obliczamy ile czasu ma stac w danym miejscu na podstawie bazy czasowej i mnoznika czyli odcienia szarosci
                    file << endl << x << " " << y << " " << (int)time;
                }
            }
        }
    }
    else if (scanningType =="vertical")
    {
        cout << "Skanowanie pionowe " << endl;
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                if(boardPom[j][i].timeFactor != 0.0)
                {
                    //cout << "Element jest na pozycji " << i << "  " << j << endl;
                    x = minVal + i*step;
                    y = minVal + j*step;
                    time = boardPom[j][i].timeFactor * timeBase;        // obliczamy ile czasu ma stac w danym miejscu na podstawie bazy czasowej i mnoznika czyli odcienia szarosci
                    file << endl << x << " " << y << " " << time;
                }
            }
        }
    }
    else if(scanningType == "optimal")
    {
        cout << "TO DO algorytmy genetyczne" << endl;
    }
    else
    {
        cout << "Niepoprawna opcja skanowania" << endl;
    }

    file.close();
    return true;



}

void Export::printBoard(BoardPoint** board, int m)
{
    for(int i = 0 ; i < m ; i++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            cout << board[i][j].timeFactor << " ";
        }
        cout << endl;
    }
}
