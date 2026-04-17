#pragma once

#include <glad/glad.h>
#include "Shader.h"
#include "Mesh.h"

class Renderer{
    public:
        static void Draw(const Mesh& mesh, const Shader& shader);
};