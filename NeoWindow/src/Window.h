#pragma once
#include <GL/glew.h> // it has to be included first
#include <GLFW/glfw3.h>
#include <iostream>
#include "glm/glm.hpp"
#include "Shape.h"
#include "glm/gtc/matrix_transform.hpp"
#include "Shader.h"
#include <vector>
#include "Camera.h"
class Window
{
public:
	Window();
	~Window();
	int Init();
	void Draw(std::vector<Shape*>& shapes);
	int WindowClosed() { return glfwWindowShouldClose(m_GLFWWindow); }
private:
	GLFWwindow* m_GLFWWindow;
	std::unique_ptr <Shader> m_ModelShader;
	static glm::mat4 m_Proj;
	static int entered_flag;
	static int right_mouse_flag;
	static int left_mouse_flag;
	static double lastx, lasty;
	static bool firstMouse;
	static Camera camera;
	static void window_size_callback(GLFWwindow* window, int width, int height);
	static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
	static void cursor_enter_callback(GLFWwindow* window, int entered);
	static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
	static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
	static void DoMovement();
	static void KeyCallback(GLFWwindow* window, int key, int scancode, int action, int mode);



};