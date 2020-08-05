#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QMainWindow>
#include <iostream>
#include "draving.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString path_color000 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/000.jpg";
    QString path_color001 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/001.jpg";
    QString path_color002 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/002.jpg";
    QString path_color003 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/003.jpg";
    QString path_color004 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/004.jpg";
    QString path_color005 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/005.jpg";
    QString path_color006 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/006.jpg";
    QString path_color007 = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/007.jpg";

    QString path_firstPoint = "D:/Dropbox/000_PracaMagisterska/Programy/InterfejsUzytkownika/001/Images/firstPoint.jpg";





    int n; // wymiar planszy
    int iconSizeX;
    int iconSizeY;
    int pointNumber;
    int previousPoint_x;
    int previousPoint_y;
    QPushButton*** Field;
    Draving* d1;


private slots:
    void on_pushButton_createBoard_clicked();

    void on_pushButton_export_clicked();

private:

    void mapButtons(QString text);
    void clickAction(int pozycja_x, int pozycja_y);
    void createBoard();
    void refreshBoardView();
    void loadBMP();
    void saveBMP();
    void saveCodes();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
