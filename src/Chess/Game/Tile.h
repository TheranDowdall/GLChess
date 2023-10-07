#pragma once

#include "Piece.h"

namespace CG{
    class Tile{
    public:
        Tile()
        :Occupant(new BlankPiece()){

        };

        ~Tile() = default;

        void setTileOccupant(Piece* m_piece){
            occupied = true;
            Occupant = m_piece;
        }

        void setTileLocation(int x, int y){
            occupied = false;
            xLocation = x;
            yLocation = y;
        }

        void OnClick(){
            Occupant->MoveOptions(xLocation, yLocation);
        }

        void OnMove(int x, int y){
            Occupant->updatePiecePos(x, y);
            Occupant = new BlankPiece();
            occupied = false;
        }

        void validMove() {movable = true; }
        void DisableMove() {movable = false; }
        PieceColour getPieceColour() {return Occupant->getColour(); }
        PieceType getPieceType() {return Occupant->getPieceType(); }
        void RemovePiece() { Occupant->DeletePiece(); }

        bool isOccupied() {return occupied; }
        bool isMovable() {return movable; }
    private:
        bool occupied, movable;
        int xLocation, yLocation;
        Piece* Occupant;
    };
}