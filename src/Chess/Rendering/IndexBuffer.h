#pragma once

namespace CG{
    class IndexBuffer{
    public:
        IndexBuffer(unsigned int* data, unsigned int count);
        ~IndexBuffer();
        
        void Bind();
        void Unbind();

        unsigned int getCount() {return m_count; }
        void UpdateIndexInfo(unsigned int* data, unsigned int start, unsigned int size);
    private:
        bool Init();
    private:
        unsigned int* m_data;
        unsigned int iboId, m_count;
    };
}