#pragma once

namespace CG{
    class VertexArray{
    public:
        VertexArray(float* data, unsigned int size);
        ~VertexArray();

        void Bind();
        void Unbind();

        void addBufferAttrib(unsigned int id, unsigned int size, unsigned int stride, unsigned int offset = 0);
        void UpdateVertexInfo(float* data, unsigned int start, unsigned int size);

        unsigned int getArraySize() {return m_size; }
    private:
        bool Init();
    private:
        float* m_data;
        unsigned int vaoId, vboId, m_size;
    };
}