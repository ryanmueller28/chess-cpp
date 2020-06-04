#pragma once

#include <GL/glut.h>
#include <string>

/**
 * Piece.h a base class from which all
 * Chess pieces will derive their legal moves
 * */

class Piece
{
public:


    Piece();
    ~Piece();
    
    int getXpos() { return xPos; }
    int getYpos() { return yPos; }

    std::string getColor() { return color; }

    virtual bool isValidMove(int x, int y, int* board[8][8]);

    virtual void drawPiece();

    virtual bool isCaptured();
    
    int bPosition[8][8];


protected:


    int xPos, yPos;
    bool killed;

    
    
    std::string color;

};

Piece::Piece()
{

    killed = false;
}

Piece::~Piece()
{

}

/**
 * Checks if a move is valid
 * returns false if it isn't
 * */
bool Piece::isValidMove(int x, int y, int* board[8][8])
{

}

bool Piece::isCaptured()
{

}


/**
 * draws the piece
 * */
void Piece::drawPiece()
{

}