#pragma once

#include "PieceBehaviour.h"

#define NUM_PIECES 32
#define VERTICES_PER_PIECE 4 * 6
#define INDICES_PER_PIECE 6

#define PIECE_VERTICES (VERTICES_PER_PIECE * NUM_PIECES) + 24
#define PIECE_INDICES (INDICES_PER_PIECE * NUM_PIECES) + 6

namespace CG{
    class ChessPieces{
    public:
        ChessPieces(){
            tiles[0] = *new Tile();
            for(int i = 0, a = BOARD_VERTEX_COUNT / 6; i<BOARD_EXTRA_INDICES; i+=6, a+=4){
                extraIndices[i] = a;
                extraIndices[i + 1] = a + 1;
                extraIndices[i + 2] = a + 3;

                extraIndices[i + 3] = a + 3;
                extraIndices[i + 4] = a + 2;
                extraIndices[i + 5] = a + 1;
            }
            
            for(int i = 0; i<BOARD_LENGTH; i++){
                for(int j = 0; j<BOARD_HEIGHT; j++)
                    tiles[(i*BOARD_HEIGHT) + j].setTileLocation(j, i);
            }

            float vertex[] = {
                0.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                -1.0f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f,
                0.0f, -1.0f, 1.0f, 0.0f, 0.0f, 1.0f
            };

            for(int i = 0; i < 24; i++)
                pieceVertices[i] = vertex[i];

            RookPiece* test = new RookPiece(WHITE, 0, 0, &pieceVertices[24], tiles);
            KnightPiece* test2 = new KnightPiece(WHITE, 0, 1, &pieceVertices[48], tiles);
            BishopPiece* test3 = new BishopPiece(WHITE, 0, 2, &pieceVertices[72], tiles);
            QueenPiece* test4 = new QueenPiece(WHITE, 0, 4, &pieceVertices[96], tiles);
            KingPiece* test5 = new KingPiece(WHITE, 0, 3, &pieceVertices[120], tiles);
            BishopPiece* test6 = new BishopPiece(WHITE, 0, 5, &pieceVertices[144], tiles);
            KnightPiece* test7 = new KnightPiece(WHITE, 0, 6, &pieceVertices[168], tiles);
            RookPiece* test8 = new RookPiece(WHITE, 0, 7, &pieceVertices[192], tiles);
            RookPiece* test9 = new RookPiece(BLACK, 7, 0, &pieceVertices[216], tiles);
            KnightPiece* test10 = new KnightPiece(BLACK, 7, 1, &pieceVertices[240], tiles);
            BishopPiece* test11 = new BishopPiece(BLACK, 7, 2, &pieceVertices[264], tiles);
            QueenPiece* test12 = new QueenPiece(BLACK, 7, 4, &pieceVertices[288], tiles);
            KingPiece* test13 = new KingPiece(BLACK, 7, 3, &pieceVertices[312], tiles);
            BishopPiece* test14 = new BishopPiece(BLACK, 7, 5, &pieceVertices[336], tiles);
            KnightPiece* test15 = new KnightPiece(BLACK, 7, 6, &pieceVertices[360], tiles);
            RookPiece* test16 = new RookPiece(BLACK, 7, 7, &pieceVertices[384], tiles);

            PawnPiece* test17 = new PawnPiece(WHITE, 1, 0, &pieceVertices[408], tiles);
            PawnPiece* test18 = new PawnPiece(WHITE, 1, 1, &pieceVertices[432], tiles);
            PawnPiece* test19 = new PawnPiece(WHITE, 1, 2, &pieceVertices[456], tiles);
            PawnPiece* test20 = new PawnPiece(WHITE, 1, 3, &pieceVertices[480], tiles);
            PawnPiece* test21 = new PawnPiece(WHITE, 1, 4, &pieceVertices[504], tiles);
            PawnPiece* test22 = new PawnPiece(WHITE, 1, 5, &pieceVertices[528], tiles);
            PawnPiece* test23 = new PawnPiece(WHITE, 1, 6, &pieceVertices[552], tiles);
            PawnPiece* test24 = new PawnPiece(WHITE, 1, 7, &pieceVertices[576], tiles);
            PawnPiece* test25 = new PawnPiece(BLACK, 6, 0, &pieceVertices[600], tiles);
            PawnPiece* test26 = new PawnPiece(BLACK, 6, 1, &pieceVertices[624], tiles);
            PawnPiece* test27 = new PawnPiece(BLACK, 6, 2, &pieceVertices[648], tiles);
            PawnPiece* test28 = new PawnPiece(BLACK, 6, 3, &pieceVertices[672], tiles);
            PawnPiece* test29 = new PawnPiece(BLACK, 6, 4, &pieceVertices[696], tiles);
            PawnPiece* test30 = new PawnPiece(BLACK, 6, 5, &pieceVertices[720], tiles);
            PawnPiece* test31 = new PawnPiece(BLACK, 6, 6, &pieceVertices[744], tiles);
            PawnPiece* test32 = new PawnPiece(BLACK, 6, 7, &pieceVertices[768], tiles);
            
            for(int i = 0, a = (BOARD_VERTEX_COUNT / 6) + (BOARD_EXTRA_VERTICES / 6); i<PIECE_INDICES; i+=6, a+=4){
                pieceIndices[i] = a;
                pieceIndices[i + 1] = a + 1;
                pieceIndices[i + 2] = a + 3;

                pieceIndices[i + 3] = a + 2;
                pieceIndices[i + 4] = a + 3;
                pieceIndices[i + 5] = a + 1;
            }
        }

        void moveHighlightedPiece(int new_x, int new_y){
            tiles[(int)extraVertices[0] + (int)(extraVertices[1] *BOARD_LENGTH)].OnMove(new_x, new_y);
        }

        void setHighlightedCell(int xPos, int yPos) {
            for(int i = 0; i<24;i+=6){
                int x = xPos, y = yPos;

                if((i + 6) / 12 == 1)
                   x++;  
                if(i / 12 == 1)
                    y++;

                extraVertices[i] = x; 
                extraVertices[i + 1] = y; 
                extraVertices[i + 2] = 0.2f; 
                extraVertices[i + 3] = 0.5f; 
                extraVertices[i + 4] = 0.25f; 
                extraVertices[i + 5] = 0.0f; 
            }
        }

        void setCellInCheck(int xPos, int yPos) {
            for(int i = 24; i<48;i+=6){
                int x = xPos, y = yPos;

                if((i + 6) / 12 == 3)
                   x++;  
                if(i / 12 == 3)
                    y++;

                extraVertices[i] = x; 
                extraVertices[i + 1] = y; 
                extraVertices[i + 2] = 0.5f; 
                extraVertices[i + 3] = 0.5f; 
                extraVertices[i + 4] = 0.75f; 
                extraVertices[i + 5] = 0.0f; 
            }
        }

        void setMovementChips(){
            int vertexNum = 48;

            for(int i = 0; i<BOARD_HEIGHT; i++){
                for(int j = 0; j<BOARD_LENGTH; j++){
                    if(!tiles[j + (i * BOARD_LENGTH)].isMovable())
                        continue;
                    else if(tiles[j + (i * BOARD_LENGTH)].getPieceType() == PieceType::KING)
                        setCellInCheck(j, i);

                    for(int k = vertexNum; k<vertexNum + 24;k+=6){
                        int x = j, y = i;
                        float TexX = 0.0f, TexY = 0.0f;

                        if((k + 6) / 12 == 3+((vertexNum - 24) / 12)){
                            x++; TexX = 0.2f;
                        }
                        if(k / 12 == 3+((vertexNum - 24) / 12)){
                            y++; TexY = 0.5f;
                        }
                        if(tiles[j + (i * BOARD_LENGTH)].isOccupied()) 
                            extraVertices[k + 4] = 0.5f;

                        extraVertices[k] = x; 
                        extraVertices[k + 1] = y; 
                        extraVertices[k + 2] = 0.5f; 
                        extraVertices[k + 3] = 0.8f + TexX; 
                        extraVertices[k + 4] += 0.0f + TexY;
                        extraVertices[k + 5] = 0.0f; 
                    }
                    vertexNum += 24;
                }
            }
        }
        
        void ResetExtraVertices(){
            for(int i = 0; i<BOARD_EXTRA_VERTICES; i++)
                extraVertices[i] = 0.0f;
            for(int i = 0; i<BOARD_LENGTH * BOARD_HEIGHT; i++)
                tiles[i].DisableMove();
        }

        Tile getTile(int x, int y) {return tiles[x + (y * BOARD_LENGTH)]; }

        float* getPieceVertices() {return pieceVertices; }
        float* getExtraBoardVertices() {return extraVertices; }

        unsigned int* getPieceIndices() {return pieceIndices; }
        unsigned int* getExtraBoardIndices() {return extraIndices; }

    private:
        Tile tiles[BOARD_LENGTH * BOARD_HEIGHT];

        float pieceVertices[PIECE_VERTICES];
        unsigned int pieceIndices[PIECE_INDICES];

        float extraVertices[BOARD_EXTRA_VERTICES];
        unsigned int extraIndices[BOARD_EXTRA_INDICES];
    };
}