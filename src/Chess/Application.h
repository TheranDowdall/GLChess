#pragma once 

#include "Rendering/Renderer.h"
#include "Window.h"

#include "Rendering/Texture.h"

#include "Game/GamePieces.h"

//CG - Chess Game
namespace CG{
    class Application{
    public:
        Application();
        ~Application();

        void OnEvent(Event& e);
        void run();

        bool closeWindow(const WindowCloseEvent e);
        bool updateMosPos(MouseMoveEvent e);
        bool selectCell(MousePressEvent e);
    private:
        Window* m_window;
        Renderer* m_renderer;
        VertexArray* vao;

        ChessBoard* m_board;
        ChessPieces* m_Pieces;
        
        PieceColour moveColour = PieceColour::WHITE;
        bool windowClosed;
        int mouseX, mouseY;
    };
    
    //Defined in app.cpp
    Application* createApplication();
}