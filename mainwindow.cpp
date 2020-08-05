#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "draving.h"
#include "fileoperators.h"
#include "export.h"
#include <QPushButton>
#include <QPixmap>
#include <iostream>
#include <QMessageBox>

using namespace std;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    /*
     *  Utworzenie tablicy 2d przyciskow i ich dolaczenie do grid layout.
     *  Po utworzeniu przyciskow polaczone zostaja one z funkcja obslugi klikniecia
     *  ktora przyjmuje jako argument QString. Musi byc taki typ aby dalo sie obslogiwac
     *  przesylanie argumentu. Aby program dzialal trzeba uzywac c++11. W pliku .pro dodano
     *  flage kompilatora ustawiajaca standard  c++11
     *
     */
    //n = 50;
    //createBoard();
}

void MainWindow::createBoard()
{

    iconSizeX = 1161/n;
    iconSizeY = 1761/n;
    pointNumber = 1;
    Field = new QPushButton**[n];
    for (int i = 0; i < n; i++)
    {
        Field[i] = new QPushButton*[n];
    }

    for(int i=0;i<n;i++)
    {

        for(int j=0;j<n;j++)
        {
            Field[i][j]=new QPushButton("", this);
            QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
            sizePolicy.setHeightForWidth(Field[i][j]->sizePolicy().hasHeightForWidth());
            Field[i][j]->setSizePolicy(sizePolicy);
            Field[i][j]->setFlat(false);
            ui->gridLayout->addWidget(Field[i][j], i, j);
            QString tekst = QString::number(i);
            tekst += " ";
            tekst += QString::number(j);
            Field[i][j]->setFlat(true);
            connect(Field[i][j],  &QPushButton::clicked,  [=](){ mapButtons(tekst); });
         }
    }
    d1 = new Draving(n);
    d1->clearSpace();
    refreshBoardView();
}

void MainWindow::refreshBoardView()
{
    QPixmap color000(path_color000);
    QPixmap color001(path_color001);
    QPixmap color002(path_color002);
    QPixmap color003(path_color003);
    QPixmap color004(path_color004);
    QPixmap color005(path_color005);
    QPixmap color006(path_color006);
    QPixmap color007(path_color007);




    QIcon color000Icon(color000);
    QIcon color001Icon(color001);
    QIcon color002Icon(color002);
    QIcon color003Icon(color003);
    QIcon color004Icon(color004);
    QIcon color005Icon(color005);
    QIcon color006Icon(color006);
    QIcon color007Icon(color007);



    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 0 ; j < n ; j++)
        {
            if(d1->board[i][j].timeFactor == 0)
            {
                Field[i][j]->setIcon(color000Icon);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor ==0.125)
            {
                Field[i][j]->setIcon(color001);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor == 0.25)
            {
                Field[i][j]->setIcon(color002);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor == 0.5)
            {
                Field[i][j]->setIcon(color003);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor == 1)
            {
                Field[i][j]->setIcon(color004);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor == 2)
            {
                Field[i][j]->setIcon(color005);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor == 4)
            {
                Field[i][j]->setIcon(color006);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
            else if(d1->board[i][j].timeFactor == 8)
            {
                Field[i][j]->setIcon(color007);
                Field[i][j]->setIconSize(QSize(iconSizeX,iconSizeY));
            }
        }
    }

}



void MainWindow::mapButtons(QString text)
{
    string zakodowanaPozycja =  text.toUtf8().constData();
    string delimiter = " ";
    int pozycja_x = stoi(zakodowanaPozycja.substr(0, zakodowanaPozycja.find(delimiter)));
    int pozycja_y = stoi(zakodowanaPozycja.substr(zakodowanaPozycja.find(delimiter)));
    clickAction(pozycja_x, pozycja_y);

}

void MainWindow::clickAction(int pozycja_y, int pozycja_x)
{
    cout << "Klikniecie na pozycji wiersz " << pozycja_y << "   kolumna " << pozycja_x << endl;

    QString QString_sizeOfElement = ui->comboBox_sizeOfElement->currentText();
    int size = QString_sizeOfElement.toInt();

    QString QString_timeFactor = ui->comboBox_timeFactor->currentText();
    double timeFactor = QString_timeFactor.toDouble();
    cout <<"time factory " <<  timeFactor << endl;



    if(d1->board[pozycja_y][pozycja_x].timeFactor != 0)
    {
        d1->board[pozycja_y][pozycja_x].timeFactor = 0;
        refreshBoardView();
    }
    else
    {
        if(ui->radioButton_point->isChecked())
        {
            //d1->board[pozycja_y][pozycja_x].color = 1;
            d1->drawPoint(pozycja_x,pozycja_y, size, timeFactor);
            refreshBoardView();
            cout << "Punkt" << endl;
        }
        else if (ui->radioButton_line->isChecked())
        {
            if(pointNumber == 1)
            {
                pointNumber = 2;
                previousPoint_x = pozycja_x;
                previousPoint_y = pozycja_y;

                QPixmap firstPoint(path_firstPoint);
                QIcon firstPointIcon(firstPoint);

                Field[pozycja_y][pozycja_x]->setIcon(firstPointIcon);
                Field[pozycja_y][pozycja_x]->setIconSize(QSize(iconSizeX,iconSizeY));


                //d1->board[pozycja_x][pozycja_y].color = 1;
            }
            else
            {
                pointNumber = 1;
                d1->drawLine(previousPoint_x, previousPoint_y, pozycja_x, pozycja_y, 1, timeFactor);
                refreshBoardView();
            }
            cout << "Linia " << endl;
        }
        else if(ui->radioButton_restangle->isChecked())
        {
           cout << "kwadrat " << endl;
           if(pointNumber == 1)
           {
               pointNumber = 2;
               previousPoint_x = pozycja_x;
               previousPoint_y = pozycja_y;

               QPixmap firstPoint(path_firstPoint);
               QIcon firstPointIcon(firstPoint);

               Field[pozycja_y][pozycja_x]->setIcon(firstPointIcon);
               Field[pozycja_y][pozycja_x]->setIconSize(QSize(iconSizeX,iconSizeY));


               //d1->board[pozycja_x][pozycja_y].color = 1;
           }
           else
           {
               pointNumber = 1;
               if(previousPoint_x > pozycja_x || previousPoint_y > pozycja_y)
               {
                   QMessageBox::StandardButton message = QMessageBox::information(this, "ERROR", "ERROR");
               }
               else
               {
                   d1->drawRectangle(previousPoint_x, previousPoint_y, pozycja_x, pozycja_y, timeFactor);
               }
               refreshBoardView();
           }
        }

    }



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_createBoard_clicked()
{
    n = ui->lineEdit_boardSize->text().toInt();
    ui->pushButton_export->setEnabled(true);

    cout << n << endl;

    createBoard();
}

void MainWindow::on_pushButton_export_clicked()
{
    cout << "Eksport klikniecie" << endl;

    QString QString_pointsPerPixel = ui->comboBox_pointsPerPixel->currentText();
    int pointsPerPixel = QString_pointsPerPixel.toInt();

    QString QString_scanningType = ui->comboBox_scanningType->currentText();
    string scanningType = QString_scanningType.toLocal8Bit().constData();

    int timeBase = ui->lineEdit_timeBase->text().toInt();
    int numberOfLayers = ui->lineEdit_numberOfLayers->text().toInt();


    //cout << "Pix" << pointsPerPixel << "   scannin  " << scanningType << endl;

    Export* e1 = new Export;
    bool flag = e1->parseData(d1->board, pointsPerPixel, timeBase, scanningType, numberOfLayers, n);
    if(flag == false)
    {
         QMessageBox::StandardButton message = QMessageBox::information(this, "ERROR", "Can't export! To many points.");
    }

    //e1->exportToFile();



}
