#pragma once

#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn();

    ~Pawn();

       Position piecePosition;

    void drawPiece(std::string color);

private:
    std::string name = "pawn";
    std::string color = Piece::getColor();

 
    GLuint imageID;
};

Pawn::Pawn() : Piece(color, name)
{
    color = Piece::getColor();
    name = "pawn";
}

Pawn::~Pawn()
{

}

void Pawn::drawPiece(std::string color)
{
    if (color == "black")
    {
        name = "black-pawn.png";
    }

    if (color == "white")
    {
        name = "white-pawn.png";
    }

    imageID = Piece::rawImageLoad(name.c_str(), Piece::imageWidth, Piece::imageHeight);

    Piece::Render();
}
