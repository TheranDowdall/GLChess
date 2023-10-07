#include "cgpch.h"

#include "Shader.h"

#include <GL/glew.h>

namespace CG{
    extern bool getGLInited();

    Shader::Shader(const std::string& fileDir)
    :shaderProps(fileDir, ParseShaders("../" + fileDir)) {
        if(!Init())
            delete this;

        Bind();

        proj = glm::ortho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
        setUniformMat4("u_proj", proj);

        Unbind();
    }

    Shader::~Shader(){
        glDeleteProgram(ProgramId);
    }

    void Shader::Bind(){
        glUseProgram(ProgramId);
    }

    void Shader::Unbind(){
        glUseProgram(0);
    }

    void Shader::setProjection(float left, float right, float bottom, float top){
        proj = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        setUniformMat4("u_proj", proj);
    }

    void Shader::setUniform1iv(const char* name, int count, int* value){
        Bind();
        glUniform1iv(glGetUniformLocation(ProgramId, name), count, value);
        Unbind();
    }

    void Shader::setUniform4f(const char* name, float f1, float f2, float f3, float f4){
        Bind();
        glUniform4f(glGetUniformLocation(ProgramId, name), f1, f2, f3, f4);
        Unbind();
    }

    void Shader::setUniformMat4(const char* name, glm::mat4 mat){
        Bind();
        glUniformMatrix4fv(glGetUniformLocation(ProgramId, name), 1, GL_FALSE, &mat[0][0]);
        Unbind();
    }
    
    Shader::ShaderSrc Shader::ParseShaders(const std::string& filePath){
        std::fstream File(filePath);

        std::stringstream ss[2];
        std::string line;

        enum ShaderType{
            NONE = -1, VERTEX = 0, FRAGMENT = 1
        };
        ShaderType type = ShaderType::NONE;

        while(std::getline(File, line)){
            if(line.find("#Shader") != std::string::npos){
                if(line.find("vertex") != std::string::npos)
                    type = ShaderType::VERTEX;
                else if(line.find("fragment") != std::string::npos)
                    type = ShaderType::FRAGMENT;
                else
                    printf("ERROR: attempted to parse non-existant shader type");
            }
            else
                ss[type] << line << "\n";
        }
        
       return {ss[0].str(), ss[1].str()};
    }

    unsigned int Shader::CompileShader(std::string src, unsigned int type){
        unsigned int shader = glCreateShader(type);
        const char* c_src = src.c_str();
        glShaderSource(shader, 1, &c_src, NULL);
        glCompileShader(shader);
        
        int compiled;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

        if(compiled == GL_FALSE){
            int length;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

            char* message = (char*)malloc(length * sizeof(char));
            glGetShaderInfoLog(shader, length, &length, &message[0]);

            std::cout << "OpenGL ERROR: " << message;
            std::cout << src;

            glDeleteShader(shader);
            free(message);
            return -1;
        }
        
        return shader;
    }

    bool Shader::Init(){
        if(!getGLInited())
            return false;

        ProgramId = glCreateProgram();

        unsigned int vs = CompileShader(shaderProps.src.vertex, GL_VERTEX_SHADER);
        unsigned int fs = CompileShader(shaderProps.src.fragment, GL_FRAGMENT_SHADER);

        if(vs == -1 || fs == -1)
            return false;

        glAttachShader(ProgramId, vs);
        glAttachShader(ProgramId, fs);
        glLinkProgram(ProgramId);
        glValidateProgram(ProgramId);

        glDeleteShader(vs);
        glDeleteShader(fs);

        return true;
    }
}