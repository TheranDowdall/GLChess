#include "Chess.h"

class ChessApp : public CG::Application{

};

//Declared in src/Chess/Application.h
CG::Application* CG::createApplication(){
    return new ChessApp();
}