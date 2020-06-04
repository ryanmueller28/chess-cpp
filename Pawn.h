#pragma once

#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn();

    ~Pawn();

    void drawPiece(std::string color);

private:
    std::string name = "pawn";
    std::string color = Piece::getColor();

    Position piecePosition;
};

Pawn::Pawn() : Piece(color, name)
{

}