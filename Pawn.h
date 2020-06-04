#pragma once

#include "Piece.h"

class Pawn : public Piece{
public:
    Pawn();

    ~Pawn();

    void drawPiece(std::string color);

private:
    std::string name = "Pawn";
    std::string color = Piece::getColor();

    std::string unicodeText;
};

Pawn::Pawn() : Piece(color, name)
{
    if (Piece::isBlack)
    {
        unicodeText = "U+265F";
    }else if (!Piece::isBlack)
    {
        unicodeText = "U+2659";
    }
}