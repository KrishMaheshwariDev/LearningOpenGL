#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <math.h>
#include "./graphic/Shader.h"

using namespace std;
// shape data
float vertices[] = {
     0.0f,  0.5f, 0.0f, 1.0f, 0.0f, 0.0f,  // top right (x, y, z, r, g, b)
     0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // bottom right
    -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, // bottom left 
};

// unsigned int indicies[] = {
// 	0, 1, 3,
// 	1, 2, 3
// };

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
	unsigned int VAO; // vertex array object (id)
	unsigned int VBO; // vertex buffer object (id)
	// unsigned int EBO;

	glGenVertexArrays(1, &VAO);  	
	glGenBuffers(1, &VBO);
	// glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	// glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	// glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicies), indicies, GL_STATIC_DRAW);
	
	// telling openGL how to interpret the vertex data before stuffing it for rendering
	// position attributes
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// color attributes
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3*sizeof(float)));
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	// main loop (it keeps the window open)
	while (!glfwWindowShouldClose(window))
	{
		processInput(window);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.use();

		float angle = glfwGetTime();

		float cx = cos(angle);
		float sx = sin(angle);

		float cy = cos(angle);
		float sy = sin(angle);

		float cz = cos(angle);
		float sz = sin(angle);

		float transform[] = {
			cy * cz,                cz * sx * sy - cx * sz,   sx * sz + cx * cz * sy,   0.0f,
			cy * sz,                cx * cz + sx * sy * sz,   cx * sy * sz - cz * sx,   0.0f,
			-sy,                    cy * sx,                  cx * cy,                  0.0f,
			0.0f,                   0.0f,                     0.0f,                     1.0f
		};

		shader.setMat4("transform", transform);

		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// deleting the buffers and objects for the memory sake
	glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);

	// terminating the glfw
	glfwTerminate();
	return 0;
}


//static void key_callback()