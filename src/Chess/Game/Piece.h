#pragma once

namespace CG{
    enum PieceColour{
        NONE = 0, BLACK = 1, WHITE = 2
    };

    enum PieceType{
        NOTHING = 0, KING = 1, QUEEN = 2, 
        BISHOP = 3, KNIGHT = 4, ROOK = 5, 
        PAWN = 6
    };

#define PIECE_TYPE(type) PieceType getPieceType() const override { return PieceType::type; }\
                         PieceColour getColour() const override {return colour; }

    class Piece{
    public:
        Piece() = default;
        virtual PieceType getPieceType() const = 0;
        virtual PieceColour getColour() const = 0;
        virtual void DeletePiece() = 0;

        virtual void updatePiecePos(int xLocation, int yLocation) = 0;
        virtual void MoveOptions(int x, int y)const = 0;
    private:
        bool clicked = false;
    };

    //Dummy class in order to init tiles
    class BlankPiece : public Piece{
    public:
        BlankPiece() {}
        ~BlankPiece() {}

        void DeletePiece() override{};
        PIECE_TYPE(NOTHING)

        void updatePiecePos(int xLocation, int yLocation) override {}
        void MoveOptions(int x, int y) const override {}
    private:
        PieceColour colour = PieceColour::WHITE;
    };
}