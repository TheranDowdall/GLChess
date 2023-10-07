#pragma once

namespace CG{
    class Texture{
    public:
        Texture(const std::string& filePath, unsigned int slot);   
        ~Texture();

        void Bind(unsigned int slot = 0);
        void Unbind(unsigned int slot = 0);
    private:
        bool Init(unsigned int slot);
    private:
        std::string path;
        int m_width, m_height, m_BPP;
        unsigned int textureId;
        unsigned char* textureSrc;
    };
}