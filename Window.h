#pragma once

#include "stdio.h"

#include <GL/glut.h>

class Window
{
public:
	Window();

	Window(int windowWidth, int windowHeight);

	void Initialize();

	int getBufferWidth() { return bufferWidth; }
	int getBufferHeight() { return bufferHeight; }
	

	int xDiff = width / 64;
	int yDiff = height / 64;

	int width, height;

	~Window();

private:




	int bufferWidth, bufferHeight;

};


Window::Window()
{
	width = 800;
	height = 600;

}

Window::Window(int windowWidth, int windowHeight)
{
	width = windowWidth;
	height = windowHeight;
}


void Window::Initialize()
{
	glutInitWindowSize(width, height);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Chess");
	
	
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(10);

	glutInitDisplayMode(GLUT_SINGLE | GL_RGB);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(width, 0, height, 0);
}

Window::~Window()
{

}