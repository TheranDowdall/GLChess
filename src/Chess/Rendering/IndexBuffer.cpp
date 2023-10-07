#include "cgpch.h"

#include "IndexBuffer.h"

#include "GL/glew.h"

namespace CG{
    extern bool getGLInited();

    IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count)
    :m_data(data), m_count(count) {
        if(!Init())
            delete this;
    }

    IndexBuffer::~IndexBuffer(){
        glDeleteBuffers(1, &iboId);
    }

    void IndexBuffer::Bind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
    }

    void IndexBuffer::Unbind(){
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    bool IndexBuffer::Init(){
        if(!getGLInited())
            return false;
            
        glGenBuffers(1, &iboId);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, iboId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_count * sizeof(unsigned int), m_data, GL_DYNAMIC_DRAW);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

        return true;
    }

    void IndexBuffer::UpdateIndexInfo(unsigned int* data, unsigned int start, unsigned int size){
        Bind();
        glBufferSubData(GL_ELEMENT_ARRAY_BUFFER, start * sizeof(unsigned int), size * sizeof(unsigned int), data);
        Unbind();
    }
}