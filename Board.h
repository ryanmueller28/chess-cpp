#pragma once

#include <vector>

#include "Tile.h"



class Board : public Tile
{
public:
    Board();
    ~Board();

    void DrawBoard();
private:
    GLint xDiff;
    GLint yDiff;

    std::vector<Tile*> tiles;
};

Board::Board()
{
    xDiff = 75;
    yDiff = 75;
}

Board::~Board()
{

}

void Board::DrawBoard()
{
    glClear(GL_COLOR_BUFFER_BIT);
    xDiff = getTileSizex();
    yDiff = getTileSizey();
    for (GLint x = 0; x <= retBufferWidth(); x += xDiff)
    {
        for (GLint y = 0; y <= retBufferHeight(); y += yDiff)
        {
            DrawTile(x, y + yDiff, x +xDiff, y + yDiff, x + xDiff, y, x, y);
        }
    }

    glFlush();
}