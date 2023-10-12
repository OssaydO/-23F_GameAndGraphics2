#pragma once

#include "Math/vec2.h"

namespace fw {

class ShaderProgram
{
public:
    ShaderProgram();
    ShaderProgram(const char* vertFilename, const char* fragFilename);
    virtual ~ShaderProgram();

    GLuint GetProgram() { return m_Program; }

    void SetUniform1f(const char* uniformName, float value);
    void SetUniform2f(const char* uniformName, vec2 value);

protected:
    void Cleanup();

    void CompileShader(GLuint& shaderHandle, const char* shaderString);
    bool Init(const char* vertFilename, const char* fragFilename);
    bool Reload();

protected:
    char* m_VertShaderString = nullptr;
    char* m_FragShaderString = nullptr;

    GLuint m_VertShader = 0;
    GLuint m_FragShader = 0;
    GLuint m_Program = 0;
};

} // namespace fw
