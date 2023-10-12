#pragma once

#include "CoreHeaders.h"
#include "Math/vec2.h"

namespace fw {

class ShaderProgram;

class Mesh
{
public:
    Mesh();
    Mesh(const Mesh& other) = delete;
    Mesh& operator=(const Mesh& other) = delete;
    virtual ~Mesh();

    void Create(std::vector<float>& verts, GLenum primitiveType);
    void Draw(ShaderProgram* pShader, vec2 offset);

protected:
    GLuint m_VBO = 0;
    int m_NumVerts = 0;
    GLenum m_PrimitiveType = GL_POINTS;
};

} // namespace fw
