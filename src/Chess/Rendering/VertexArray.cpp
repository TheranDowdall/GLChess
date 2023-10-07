#include "cgpch.h"

#include "VertexArray.h"

#include "GL/glew.h"

namespace CG{
    extern bool getGLInited();
    VertexArray::VertexArray(float* data, unsigned int size)
    :m_data(data), m_size(size) {
        if(!Init())
            delete this;
    }

    VertexArray::~VertexArray(){
        glDeleteVertexArrays(1, &vaoId);
    }

    void VertexArray::Bind(){
        glBindVertexArray(vaoId);
    }

    void VertexArray::Unbind(){
        glBindVertexArray(0);
    }

    bool VertexArray::Init(){
        if(!getGLInited)
            return false;

        glGenVertexArrays(1, &vaoId);
        glGenBuffers(1, &vboId);

        glBindVertexArray(vaoId);
        glBindBuffer(GL_ARRAY_BUFFER, vboId);
        glBufferData(GL_ARRAY_BUFFER, m_size * sizeof(float), m_data, GL_DYNAMIC_DRAW);

        glBindVertexArray(0);

        return true;
    }

    void VertexArray::addBufferAttrib(unsigned int id, unsigned int size, unsigned int stride, unsigned int offset){
        Bind();
        glEnableVertexAttribArray(id);
        glVertexAttribPointer(id, size, GL_FLOAT, GL_FALSE, stride * sizeof(float), (void*)(offset * sizeof(float)));
        Unbind();
    }

    void VertexArray::UpdateVertexInfo(float* data, unsigned int start, unsigned int size){
        Bind();
        glBufferSubData(GL_ARRAY_BUFFER, start * sizeof(float), size * sizeof(float), data);
        Unbind();
    }
}