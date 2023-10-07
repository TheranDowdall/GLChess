#include "cgpch.h"

#include "Texture.h"

#include "GL/glew.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

namespace CG{
    extern bool getGLInited();

    Texture::Texture(const std::string& filePath, unsigned int slot)
    : path(filePath){
        if(!Init(slot)){
            delete this;
            std::cout << "Failed";
        }
    }

    Texture::~Texture(){
        glDeleteTextures(1, &textureId);
    }

    void Texture::Bind(unsigned int slot){
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, textureId);
    }

    void Texture::Unbind(unsigned int slot){
        glActiveTexture(GL_TEXTURE0 + slot);
        glBindTexture(GL_TEXTURE_2D, 0);
    }

    bool Texture::Init(unsigned int slot){
        if(!getGLInited())
            return false;

        stbi_set_flip_vertically_on_load(1);
        textureSrc = stbi_load(path.c_str(), &m_width, &m_height, &m_BPP, 0);

        glGenTextures(1, &textureId);
        Bind(slot);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, textureSrc);
        Unbind(0);

        return true;
    }
}