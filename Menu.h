#pragma once

#include <cstdlib>
#include <stdio.h>
#include <GL/glut.h>


class Menu
{
public:

    static Menu* currentInstance;

    Menu();
    ~Menu();

    void displayMenu();


private:


    void CreateGLUTMenu();

    void processMenuEvents(int option);

};

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::CreateGLUTMenu()
{
    int menu;

    // glutCreateMenu paramenters are: void (*) (int menu)
    // adding (int option) doesn't help

   // menu = glutCreateMenu(processMenuEvents);

    glutAddMenuEntry("New Game", 1);
    glutAddMenuEntry("Pause", 2);
    glutAddMenuEntry("Exit", 3);

    glutAttachMenu(GLUT_RIGHT_BUTTON);


}

void Menu::processMenuEvents(int option)
{
    // Temp switch statements to make sure the menu works. Will replace with 
    // Game and window functions
    switch(option)
    {
        case 1:
            printf("Starting a new game");
            break;
        case 2:
            printf("Pausing");
            break;
        case 3:
            printf("Exiting");
            break;
    }
}