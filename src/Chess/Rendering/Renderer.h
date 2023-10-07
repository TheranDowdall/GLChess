#pragma once

#include "Shader.h"
#include "VertexArray.h"
#include "IndexBuffer.h"

namespace CG{
    class Renderer{
    public:
        Renderer();
        ~Renderer();

        void Draw(Shader* program, VertexArray* vao, IndexBuffer* ibo);

        static bool GLInited() {return s_GLInited; }
    private:
        bool Init();
    private:
        static bool s_GLInited;
    };
}