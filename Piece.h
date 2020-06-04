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

    Piece(std::string pColor, std::string pName);

    ~Piece();
    
    int getXpos() { return xPos; }
    int getYpos() { return yPos; }

    std::string getColor();
    std::string getName() { return name; }

    virtual bool isCaptured();

 

    /**
     * A struct to store the position of x and y
     * To where the piece is.
     * */
    struct Position{
        int x;
        int y;
    }piecePos;

protected:

    bool isBlack;

    int xPos, yPos;
    bool killed;

    void deletePiece();

    std::string name;
    
    std::string color;

};

Piece::Piece()
{
    piecePos.x = xPos;
    piecePos.y = yPos;

    killed = false;
}

// Overloaded constructor to take the color and name
Piece::Piece(std::string pColor, std::string pName)
{
    killed = false;

    piecePos.x = xPos;
    piecePos.y = yPos;
    color = pColor;
    name = pName;
}

Piece::~Piece()
{
    deletePiece();
}


bool Piece::isCaptured()
{
    killed = true;

    return killed;
}

void Piece::deletePiece()
{
    if (killed)
    {
        delete this;
    }
}
 std::string Piece::getColor() { 
        if (isBlack)
        {
            color = "black";
        }else{
            color = "white";
        }
        return color; 
        }
