#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "./graphic/Mesh.h"
#include "./graphic/Shader.h"
#include "./graphic/Renderer.h"

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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);
}

int main() {
	// initializing the glfw to use its features
	if (!glfwInit()) {
		return -1;
	}
	// Telling GLFW about the context
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(800, 600, "Basic", NULL, NULL);
	if (window == NULL) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return -1;
	}

	glViewport(0, 0, 800, 600);
	
	Shader shader("C:/Kreeece/Projects/GLbasic/src/shaders/vertex.vert", "C:/Kreeece/Projects/GLbasic/src/shaders/fragment.frag");
	// buffers
	Mesh mesh(vertices, sizeof(vertices), 3, 3*sizeof(float), indices, sizeof(indices), 6);

	// main loop (it keeps the window open)
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClear(GL_COLOR_BUFFER_BIT);

		Renderer::Draw(mesh, shader);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// terminating the glfw
	glfwTerminate();
	return 0;
}


//static void key_callback()