#include "../cgpch.h"

#include "Application.h"

#define BIND_EVENT_FN(x) std::bind(Application::x, this, std::placeholders::_1)

namespace CG{
    Application::Application(){ 
        Window::WinProps props = Window::WinProps(720, 720, "Chess");
        m_window = new Window(props);
        
        m_renderer = new Renderer();
        m_board = new ChessBoard();
        m_Pieces = new ChessPieces();

        m_window->setEventCallbackFunc(BIND_EVENT_FN(OnEvent));
        
        WindowCloseEvent::setCallback(BIND_EVENT_FN(closeWindow));
        MouseMoveEvent::setCallback(BIND_EVENT_FN(updateMosPos));
        MousePressEvent::setCallback(BIND_EVENT_FN(selectCell));
    }

    Application::~Application(){
        delete m_window;
    }

    void Application::OnEvent(Event& e){
        bool handled;

        handled = e.DispatchEvent(); 
    }

    void Application::run(){
        vao = new VertexArray(m_board->getBoardVertices(), BOARD_VERTEX_COUNT + BOARD_EXTRA_VERTICES + PIECE_VERTICES);
        vao->UpdateVertexInfo(m_Pieces->getExtraBoardVertices(), BOARD_VERTEX_COUNT, BOARD_EXTRA_VERTICES);
        vao->UpdateVertexInfo(m_Pieces->getPieceVertices(), BOARD_VERTEX_COUNT + BOARD_EXTRA_VERTICES, PIECE_VERTICES);

        vao->addBufferAttrib(0, 3, 6, 0);
        vao->addBufferAttrib(1, 2, 6, 3);
        vao->addBufferAttrib(2, 1, 6, 5);

        IndexBuffer* ibo = new IndexBuffer(m_board->getBoardIndices(), BOARD_INDEX_COUNT + BOARD_EXTRA_INDICES + PIECE_INDICES);
        ibo->UpdateIndexInfo(m_Pieces->getExtraBoardIndices(), BOARD_INDEX_COUNT, BOARD_EXTRA_INDICES);
        ibo->UpdateIndexInfo(m_Pieces->getPieceIndices(), BOARD_INDEX_COUNT + BOARD_EXTRA_INDICES, PIECE_INDICES);

        Shader* shader = new Shader();
        shader->setProjection(0, BOARD_LENGTH, 0, BOARD_HEIGHT);

        int textureId[] = {0, 1};
        shader->setUniform1iv("textures", 2, textureId);

        Texture* m_boardTex = new Texture("../res/Textures/BoardTiles.png", 0);
        Texture* m_pieceTex = new Texture("../res/Textures/Pieces.png", 1);

        m_boardTex->Bind(0);
        m_pieceTex->Bind(1);

        while(!windowClosed){
            m_window->setBackgroundColour(1,1,1,1);

            m_renderer->Draw(shader, vao, ibo);

            m_window->OnUpdate();
        }
    }

    bool Application::closeWindow(WindowCloseEvent e){
        windowClosed = true;
        return true;
    }

    bool Application::updateMosPos(MouseMoveEvent e){
        return true;
    }

    bool Application::selectCell(MousePressEvent e){
        mouseX = ((e.xPos() / m_window->getWidth()) * BOARD_LENGTH);
        mouseY = ((e.yPos() / m_window->getHeight())* BOARD_HEIGHT);

        if(m_Pieces->getTile(mouseX,mouseY).isMovable()){
            m_Pieces->moveHighlightedPiece(mouseX, mouseY);
            vao->UpdateVertexInfo(m_Pieces->getPieceVertices(), BOARD_VERTEX_COUNT + BOARD_EXTRA_VERTICES, PIECE_VERTICES); 
            
            m_Pieces->ResetExtraVertices();
            vao->UpdateVertexInfo(m_Pieces->getExtraBoardVertices(), BOARD_VERTEX_COUNT, BOARD_EXTRA_VERTICES);

            moveColour = (moveColour == PieceColour::WHITE) ? PieceColour::BLACK : PieceColour::WHITE;
            return true;
        }

        m_Pieces->ResetExtraVertices();
        vao->UpdateVertexInfo(m_Pieces->getExtraBoardVertices(), BOARD_VERTEX_COUNT, BOARD_EXTRA_VERTICES);

        if(!m_Pieces->getTile(mouseX,mouseY).isOccupied() || m_Pieces->getTile(mouseX,mouseY).getPieceColour() != moveColour)
            return true;

        m_Pieces->setHighlightedCell(mouseX, mouseY);
        m_Pieces->getTile(mouseX,mouseY).OnClick();
        m_Pieces->setMovementChips();

        vao->UpdateVertexInfo(m_Pieces->getExtraBoardVertices(), BOARD_VERTEX_COUNT, BOARD_EXTRA_VERTICES);
        return true;
    }
}