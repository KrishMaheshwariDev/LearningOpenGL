#include "Renderer.h"

void Renderer::Draw(const Mesh& mesh, const Shader& shader){
    shader.use();

    // Texture goes here (V2 plans)

    mesh.Draw();
}