#pragma once

#include <GL/glut.h>

#include "Window.h"

class Board
{
public:

    static Board* currentInstance;

    // Default constructor
    Board();

    Board(int rows, int cols, int tiles[8][8]);


    // The display function that finally gets called in main
    void display()
    {
        setUpDrawCallback();
    }

    ~Board();

private:
    // Create the draw callback function
    void setUpDrawCallback()
    {
        currentInstance = this;
        ::glutDisplayFunc(Board::drawCallback);
    }


    void drawBoard();

    // Call the draw function
    static void drawCallback()
    {
        currentInstance->drawBoard();
    }

    int boardTiles[8][8];
};

Board::Board()
{
    drawBoard();
}

Board::Board(int rows, int cols, int tiles[8][8])
{
    for (rows = 0; rows < 8; rows++)
    {
        for (cols = 0; cols < 8; cols++)
        {
            currentInstance->boardTiles[rows][cols] = tiles[rows][cols];
        }
    }
}

/**
 * Draw function
 * For scalabilty, xChange and yChange are each height / 8
 * 
 * */

void Board::drawBoard()
{
    Window mainWindow;
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	
	// Create the window buffer
	int xBuff = mainWindow.getBufferWidth();
	int yBuff = mainWindow.getBufferHeight();

	// The difference in x and y for a tile
	int xChange = xBuff / 8;
	int yChange = yBuff / 8;


	for (int x = 0; x <= xBuff; x += xChange)
	{
		for (int y = 0; y <= yBuff; y+= yChange)
		{
			// Bit operator if x + y is odd or even to get white or black tiles
 			if (((x + y) / xChange) & 1)
			{
				glColor3f(1, 1, 1);
			}else{
				glColor3f(0, 0, 0);
			}
			glRecti(x, y, (x + xChange), (y + yChange)); // draw the tile
		}
	}

	glFlush();
}

Board::~Board()
{

}