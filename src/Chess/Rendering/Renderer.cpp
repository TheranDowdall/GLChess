#include "cgpch.h"

#include "Renderer.h"

#include <GL/glew.h>
namespace CG{
    extern bool getGLFWInit();

    bool Renderer::s_GLInited = false;

    Renderer::Renderer()
    {
        if (!Init())
            delete this;
    }

    Renderer::~Renderer()
    {

    }

    bool Renderer::Init()
    {
        if (s_GLInited == false)
        {
            if (!getGLFWInit()){
                printf("ERROR: failed to initialize renderer, must create a window first!");
                return false;
            }
            else if (glewInit() != GLEW_OK){
                printf("ERROR: failed to initialize renderer!");
                return false;
            }
            
            s_GLInited = true;
        }

        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

        glEnable(GL_DEPTH_TEST);
        glDepthFunc(GL_LESS);
        return true;
    }

    void Renderer::Draw(Shader* program, VertexArray* vao, IndexBuffer* ibo){
        
        glClearDepth(1.0f);
        glClear(GL_DEPTH_BUFFER_BIT);
        glClear(GL_COLOR_BUFFER_BIT);

        program->Bind();
        vao->Bind();
        ibo->Bind();

        glDrawElements(GL_TRIANGLES, ibo->getCount(), GL_UNSIGNED_INT, NULL);
        
        program->Unbind();
        vao->Unbind();
        ibo->Unbind();
    }

    bool getGLInited(){return Renderer::GLInited(); }
}