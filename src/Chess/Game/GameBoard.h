#pragma once

#include "Tile.h"

#define BOARD_LENGTH 8
#define BOARD_HEIGHT 8

#define BOARD_VERTEX_COUNT (BOARD_LENGTH) * (BOARD_HEIGHT) * 24
#define BOARD_INDEX_COUNT BOARD_LENGTH  * BOARD_HEIGHT * 6

//Vertices aand indices to be modified at runtime
#define BOARD_EXTRA_VERTICES 24 * 32
#define BOARD_EXTRA_INDICES 6 * 32

namespace CG{
    class ChessBoard{
    public:
        ChessBoard() {
            float tex_x = 0.0f, tex_y = 0.0f;

            for(int i = 0, a = 0; i <= BOARD_HEIGHT; i++, tex_y += 0.5f){
                for(int j = 0; j <= BOARD_LENGTH; j++, tex_x += 0.2f){
                    boardVertices[a] = j; 
                    boardVertices[a + 1] = i;
                    boardVertices[a + 2] = 0.0f; 
                    boardVertices[a + 3] = tex_x; 
                    boardVertices[a + 4] = tex_y;
                    boardVertices[a + 5] = 0.0f;

                    a += 6;

                    if(tex_x == 0.4f){
                        tex_x = -0.2f;

                        if(j != BOARD_LENGTH)
                            j--;
                    }
                }
                tex_x = 0.0f;
                
                if(tex_y == 1.0f){
                    tex_y = -0.5f;
                    
                    if(i != BOARD_LENGTH)
                        i--;
                }
            }

            for(int i = 0, a = 0; i < (BOARD_HEIGHT+3)*(BOARD_LENGTH+3); i+=(BOARD_HEIGHT+4)){
                if((i + 12) % 36 == 0)
                    i += 12;

                for(int j = i; j<(BOARD_LENGTH+3) + i; j++){
                    if((j + 1) % 3 == 0)
                        j++;

                    boardIndices[a] = j; 
                    boardIndices[a + 1] = j + 1;
                    boardIndices[a + 2] = j + 12;

                    boardIndices[a + 3] = j + 13;
                    boardIndices[a + 4] = j + 12;
                    boardIndices[a + 5] = j + 1;

                    a += 6;
                }
            }
        }
        ~ChessBoard();

        float* getBoardVertices() {return boardVertices; }
        unsigned int* getBoardIndices() {return boardIndices; }
    private:
        float boardVertices[BOARD_VERTEX_COUNT];
        unsigned int boardIndices[BOARD_INDEX_COUNT];
    };
}