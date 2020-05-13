#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	//glewExperimental = true;
	if(!glfwInit()) {
		printf("[ERROR] Failed to initialize GLEW");
		return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow *win;
	win = glfwCreateWindow(400,400, "HydroSimulator", NULL, NULL);
	if(win == NULL) {
		printf("[ERROR] Could not create a glfw window");
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(win);
	glewExperimental=true;
	if(glewInit() != GLEW_OK) {
		printf("[ERROR] Failed to initialize GLEW");
		return -1;
	}

	glfwSetInputMode(win, GLFW_STICKY_KEYS, GL_TRUE);
	do {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(win);
		glfwPollEvents();
	} while(glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(win) == 0);
}
