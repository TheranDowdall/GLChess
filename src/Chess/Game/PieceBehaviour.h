#pragma once

#include "GameBoard.h"

namespace CG{
    class KingPiece : public Piece{
    public:
        KingPiece(PieceColour Colour, int xLocation, int yLocation, float* vertexData, Tile* tile)
        :boardTiles(tile), vertexLoc(vertexData), colour(Colour){
            updatePiecePos(xLocation, yLocation);
        }

        void updatePiecePos(int xLocation, int yLocation) override {
            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].RemovePiece();
            float vertices[] ={
                (float)xLocation, (float)yLocation, 0.9f, 0/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation, 0.9f, 1/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation+1.0f, 0.9f, 1/6.0f, (colour / 2.0f), 1.1f,
                (float)xLocation, (float)yLocation+1.0f, 0.9f, 0/6.0f, (colour / 2.0f), 1.1f
            };

            for(int i = 0; i < 24; i++)
                vertexLoc[i] = vertices[i];

            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].setTileOccupant(this);
        }

        void DeletePiece() override {
            for(int i = 0; i < 24; i++)
                vertexLoc[i] = -1.0f;

            delete this;
        }

        PIECE_TYPE(KING);

        void MoveOptions(int x, int y) const override {
            for(int i = x + 1; i>=x - 1 && i>=0; i--){
                if(i >=BOARD_LENGTH)
                    continue;

                for(int j = y + 1; j>=y-1 && j>=0; j--){
                    if((i == x && j == y) || j>=BOARD_LENGTH)
                        continue;

                    if(!boardTiles[i + (j*BOARD_LENGTH)].isOccupied() || boardTiles[i + (j*BOARD_LENGTH)].getPieceColour()!=colour)
                        boardTiles[i + (j*BOARD_LENGTH)].validMove();
                }
            }
        }

    private:
        Tile* boardTiles;
        float* vertexLoc;
        PieceColour colour;
    };

    class QueenPiece : public Piece{
    public:
        QueenPiece(PieceColour Colour, int xLocation, int yLocation, float* vertexData, Tile* tile)
        :boardTiles(tile), vertexLoc(vertexData), colour(Colour){
            updatePiecePos(xLocation, yLocation);
        }

        void updatePiecePos(int xLocation, int yLocation) override {
            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].RemovePiece();
            float vertices[] ={
                (float)xLocation, (float)yLocation, 0.9f, 1/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation, 0.9f, 2/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation+1.0f, 0.9f, 2/6.0f, (colour / 2.0f), 1.1f,
                (float)xLocation, (float)yLocation+1.0f, 0.9f, 1/6.0f, (colour / 2.0f), 1.1f
            };

            for(int i = 0; i < 24; i++)
                vertexLoc[i] = vertices[i];

            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].setTileOccupant(this);
        }

        void DeletePiece() override {
            for(int i = 0; i < 24; i++)
                vertexLoc[i] = -1.0f;

            delete this;
        }

        PIECE_TYPE(QUEEN);

        void MoveOptions(int x, int y) const override {
            for(int i = x + 1, j = y + 1; i<BOARD_LENGTH && j<BOARD_HEIGHT; i++, j++){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x + 1, j = y - 1; i<BOARD_LENGTH && j>=0; i++, j--){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x - 1, j = y - 1; i>=0 && j>=0; i--, j--){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x - 1, j = y + 1; i>=0 && j<BOARD_HEIGHT; i--, j++){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }
            
            for(int i = x + 1; i<BOARD_LENGTH; i++){
                boardTiles[i + (y*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (y*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (y*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (y*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x - 1; i>=0; i--){
                boardTiles[i + (y*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (y*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (y*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (y*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = y  + 1; i<BOARD_HEIGHT; i++){
                boardTiles[x + (i*BOARD_LENGTH)].validMove();

                if(boardTiles[x + (i*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[x + (i*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[x + (i*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = y  - 1; i>=0; i--){
                boardTiles[x + (i*BOARD_LENGTH)].validMove();

                if(boardTiles[x + (i*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[x + (i*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[x + (i*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }
        }

    private:
        Tile* boardTiles;
        float* vertexLoc;
        PieceColour colour;
    };

    class BishopPiece : public Piece{
    public:
        BishopPiece(PieceColour Colour, int xLocation, int yLocation, float* vertexData, Tile* tile)
        :boardTiles(tile), vertexLoc(vertexData), colour(Colour){
            updatePiecePos(xLocation, yLocation);
        }

        void updatePiecePos(int xLocation, int yLocation) override {
            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].RemovePiece();
            float vertices[] ={
                (float)xLocation, (float)yLocation, 0.9f, 2/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation, 0.9f, 3/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation+1.0f, 0.9f, 3/6.0f, (colour / 2.0f), 1.1f,
                (float)xLocation, (float)yLocation+1.0f, 0.9f, 2/6.0f, (colour / 2.0f), 1.1f
            };

            for(int i = 0; i < 24; i++)
                vertexLoc[i] = vertices[i];

            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].setTileOccupant(this);
        }

        void DeletePiece() override {
            for(int i = 0; i < 24; i++)
                vertexLoc[i] = -1.0f;

            delete this;
        }

        PIECE_TYPE(BISHOP);

        void MoveOptions(int x, int y) const override {
            for(int i = x + 1, j = y + 1; i<BOARD_LENGTH && j<BOARD_HEIGHT; i++, j++){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x + 1, j = y - 1; i<BOARD_LENGTH && j>=0; i++, j--){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x - 1, j = y - 1; i>=0 && j>=0; i--, j--){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x - 1, j = y + 1; i>=0 && j<BOARD_HEIGHT; i--, j++){
                boardTiles[i + (j*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (j*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (j*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (j*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }
        }

    private:
        Tile* boardTiles;
        float* vertexLoc;
        PieceColour colour;
    };

    class KnightPiece : public Piece{
    public:
        KnightPiece(PieceColour Colour, int xLocation, int yLocation, float* vertexData, Tile* tile)
        :boardTiles(tile), vertexLoc(vertexData), colour(Colour){
            updatePiecePos(xLocation, yLocation);
        }

        void updatePiecePos(int xLocation, int yLocation) override {
            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].RemovePiece();
            float vertices[] ={
                (float)xLocation, (float)yLocation, 0.9f, 3/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation, 0.9f, 4/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation+1.0f, 0.9f, 4/6.0f, (colour / 2.0f), 1.1f,
                (float)xLocation, (float)yLocation+1.0f, 0.9f, 3/6.0f, (colour / 2.0f), 1.1f
            };

            for(int i = 0; i < 24; i++)
                vertexLoc[i] = vertices[i];

            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].setTileOccupant(this);
        }

        void DeletePiece() override {
            for(int i = 0; i < 24; i++)
                vertexLoc[i] = -1.0f;

            delete this;
        }

        PIECE_TYPE(KNIGHT);

        void MoveOptions(int x, int y) const override {
            for(int i = x + 2; i>=x-2; i--){
                int yOffset = y;

                ((i - x) % 2 == 0) ? yOffset +=1 : yOffset += 2;

                if(i == x || i >= BOARD_LENGTH || i<0)
                    continue;
                
                if(yOffset < BOARD_HEIGHT){
                    if(!boardTiles[i + (yOffset*BOARD_LENGTH)].isOccupied() || boardTiles[i + (yOffset*BOARD_LENGTH)].getPieceColour()!=colour)
                        boardTiles[i + (yOffset*BOARD_LENGTH)].validMove();
                }
                
                yOffset -= (2*(yOffset - y));

                if(yOffset >= 0){
                    if(!boardTiles[i + (yOffset*BOARD_LENGTH)].isOccupied() || boardTiles[i + (yOffset*BOARD_LENGTH)].getPieceColour()!=colour)
                        boardTiles[i + (yOffset*BOARD_LENGTH)].validMove();
                }
            }
        }

    private:
        Tile* boardTiles;
        float* vertexLoc;
        PieceColour colour;
    };

    class RookPiece : public Piece{
    public:
        RookPiece(PieceColour Colour, int xLocation, int yLocation, float* vertexData, Tile* tile)
        :boardTiles(tile), vertexLoc(vertexData), colour(Colour){
            updatePiecePos(xLocation, yLocation);
        }

        void updatePiecePos(int xLocation, int yLocation) override {
            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].RemovePiece();
            float vertices[] ={
                (float)xLocation, (float)yLocation, 0.9f, 0.66f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation, 0.9f, 5/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation+1.0f, 0.9f, 5/6.0f, (colour / 2.0f), 1.1f,
                (float)xLocation, (float)yLocation+1.0f, 0.9f, 4/6.0f, (colour / 2.0f), 1.1f
            };

            for(int i = 0; i < 24; i++)
                vertexLoc[i] = vertices[i];

            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].setTileOccupant(this);
        }

        void DeletePiece() override {
            for(int i = 0; i < 24; i++)
                vertexLoc[i] = -1.0f;

            delete this;
        }

        PIECE_TYPE(ROOK);

        void MoveOptions(int x, int y) const override {
            for(int i = x + 1; i<BOARD_LENGTH; i++){
                boardTiles[i + (y*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (y*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (y*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (y*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = x - 1; i>=0; i--){
                boardTiles[i + (y*BOARD_LENGTH)].validMove();

                if(boardTiles[i + (y*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[i + (y*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[i + (y*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = y  + 1; i<BOARD_HEIGHT; i++){
                boardTiles[x + (i*BOARD_LENGTH)].validMove();

                if(boardTiles[x + (i*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[x + (i*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[x + (i*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }

            for(int i = y  - 1; i>=0; i--){
                boardTiles[x + (i*BOARD_LENGTH)].validMove();

                if(boardTiles[x + (i*BOARD_LENGTH)].isOccupied()){
                    if(boardTiles[x + (i*BOARD_LENGTH)].getPieceColour() == colour)
                        boardTiles[x + (i*BOARD_LENGTH)].DisableMove();

                    break;
                }
            }
        }

    private:
        Tile* boardTiles;
        float* vertexLoc;
        PieceColour colour;
    };

    class PawnPiece : public Piece{
    public:
        PawnPiece(PieceColour Colour, int xLocation, int yLocation, float* vertexData, Tile* tile)
        :boardTiles(tile), vertexLoc(vertexData), colour(Colour){
            updatePiecePos(xLocation, yLocation);
            neverMoved  = true;
        }

        void updatePiecePos(int xLocation, int yLocation) override {
            neverMoved  = false;
            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].RemovePiece();
            float vertices[] ={
                (float)xLocation, (float)yLocation, 0.9f, 5/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation, 0.9f, 6/6.0f, (colour / 2.0f) - 0.5f, 1.1f,
                (float)xLocation+1.0f, (float)yLocation+1.0f, 0.9f, 6/6.0f, (colour / 2.0f), 1.1f,
                (float)xLocation, (float)yLocation+1.0f, 0.9f, 5/6.0f, (colour / 2.0f), 1.1f
            };

            for(int i = 0; i < 24; i++)
                vertexLoc[i] = vertices[i];

            boardTiles[xLocation + (yLocation * BOARD_LENGTH)].setTileOccupant(this);
        }

        void DeletePiece() override {
            for(int i = 0; i < 24; i++)
                vertexLoc[i] = -1.0f;

            delete this;
        }

        PIECE_TYPE(PAWN);

        void MoveOptions(int x, int y) const override {
            if(colour == WHITE && x < BOARD_LENGTH - 1){
                if(!boardTiles[(x+1) + (y*BOARD_LENGTH)].isOccupied()){
                        boardTiles[(x+1) + (y*BOARD_LENGTH)].validMove();

                    if(neverMoved && !boardTiles[(x+2) + (y*BOARD_LENGTH)].isOccupied())
                        boardTiles[(x+2) + (y*BOARD_LENGTH)].validMove();
                }

                if(y+1 < BOARD_HEIGHT){
                    if(boardTiles[(x+1) + ((y+1)*BOARD_LENGTH)].isOccupied() && boardTiles[(x+1) + ((y+1)*BOARD_LENGTH)].getPieceColour() != colour)
                        boardTiles[(x+1) + ((y+1)*BOARD_LENGTH)].validMove();
                }

                if(y-1 >= 0){
                    if(boardTiles[(x+1) + ((y-1)*BOARD_LENGTH)].isOccupied() && boardTiles[(x+1) + ((y-1)*BOARD_LENGTH)].getPieceColour() != colour)
                        boardTiles[(x+1) + ((y-1)*BOARD_LENGTH)].validMove();
                }
            }
            else if (x > 0 && colour == BLACK){
                if(!boardTiles[(x-1) + (y*BOARD_LENGTH)].isOccupied()){
                        boardTiles[(x-1) + (y*BOARD_LENGTH)].validMove();

                    if(neverMoved && !boardTiles[(x-2) + (y*BOARD_LENGTH)].isOccupied())
                        boardTiles[(x-2) + (y*BOARD_LENGTH)].validMove();
                }

                if(y+1 < BOARD_HEIGHT){
                    if(boardTiles[(x-1) + ((y+1)*BOARD_LENGTH)].isOccupied() && boardTiles[(x-1) + ((y+1)*BOARD_LENGTH)].getPieceColour() != colour)
                        boardTiles[(x-1) + ((y+1)*BOARD_LENGTH)].validMove();
                }
                
                if(y-1 >= 0){
                    if(boardTiles[(x-1) + ((y-1)*BOARD_LENGTH)].isOccupied() && boardTiles[(x-1) + ((y-1)*BOARD_LENGTH)].getPieceColour() != colour)
                        boardTiles[(x-1) + ((y-1)*BOARD_LENGTH)].validMove();
                }
            }

        }

    private:
        Tile* boardTiles;
        float* vertexLoc;
        PieceColour colour;
        bool neverMoved;
    };
}