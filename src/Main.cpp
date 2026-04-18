#include "./graphic/Mesh.h"
#include "./graphic/Shader.h"
#include "./graphic/Renderer.h"
#include "./window/Window.h"

float vertices[] = {
     0.5f,  0.5f, 0.0f,   // 0
     0.5f, -0.5f, 0.0f,   // 1
    -0.5f, -0.5f, 0.0f,   // 2
    -0.5f,  0.5f, 0.0f    // 3
};

unsigned int indices[] = {
    0, 1, 2,
    2, 3, 0
};

int main() {
	Window window(800, 600, "Racist");
	
	Shader shader("C:/Kreeece/Projects/GLbasic/src/shaders/vertex.vert", "C:/Kreeece/Projects/GLbasic/src/shaders/fragment.frag");
	// buffers
	Mesh mesh(vertices, sizeof(vertices), 3, 3*sizeof(float), indices, sizeof(indices), 6);

	// main loop (it keeps the window open)
	while (!window.shouldClose())
	{
		window.processInput();

		glClear(GL_COLOR_BUFFER_BIT);

		Renderer::Draw(mesh, shader);

		window.swapBuffers();
		window.pollEvents();
	}

	return 0;
}