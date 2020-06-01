#pragma once

#include "stdio.h"

#include <GL/glut.h>

class Window
{
public:
	Window();

	Window(int windowWidth, int windowHeight);

	void Initialize();	

	int xDiff = width / 64;
	int yDiff = height / 64;

	int getHeight() { return height; }
	int getWidth() { return width; }

	int width, height;

	~Window();

private:

	int bufferWidth, bufferHeight;

};

/**
 * Default constructor, window size of 800 x 600
 * */
Window::Window()
{
	width = 800;
	height = 600;

}

/**
* Overloaded constructor, creates a window size with command line parameters
*/
Window::Window(int windowWidth, int windowHeight)
{
	width = windowWidth;
	height = windowHeight;
}


void Window::Initialize()
{
	glutInitWindowSize(width, height);
	glutInitWindowPosition(100, 150);
	glutCreateWindow("Chess");
	
	
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(10);

	glutInitDisplayMode(GLUT_SINGLE | GL_RGB);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

Window::~Window()
{

}