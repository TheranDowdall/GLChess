#pragma once

namespace CG{
    class Shader{
        struct ShaderSrc{
            std::string vertex;
            std::string fragment;

            ShaderSrc(std::string vert = "NULL", std::string frag = "NULL")
            : vertex(vert), fragment(frag){}
        };
    public: 
        Shader(const std::string& fileDir = "res/Shaders/Main.glsl");
        ~Shader();

        void Bind();
        void Unbind();

        const std::string& getVertexSrc() {return shaderProps.src.vertex; }
        const std::string& getFragmentSrc() {return shaderProps.src.fragment; }

        void setProjection(float left, float right, float bottom, float top);
        
        void setUniform1iv(const char* name, int count, int* value);
        void setUniform4f(const char* name, float f1, float f2, float f3, float f4);
        void setUniformMat4(const char* name, glm::mat4 mat);
    private:
        ShaderSrc ParseShaders(const std::string& filePath);
        unsigned int CompileShader(std::string src, unsigned int type);
        bool Init();
    private:
        struct ShaderProps{
            ShaderSrc src;

            const std::string& filePath;

            ShaderProps(const std::string& path, ShaderSrc m_src)
            : filePath(path), src(m_src.vertex, m_src.fragment){}
        };

        ShaderProps shaderProps;

        unsigned int ProgramId;

        glm::mat4 proj;
    };
}