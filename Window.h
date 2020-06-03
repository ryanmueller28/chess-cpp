#pragma once

#include "stdio.h"

#include <GL/glut.h>

/**
 * Window.h
 * A class that handles the general window drawing in the chess game
 * 
 * */

class Window
{
public:
	Window();

	// Overloaded constructor
	Window(int windowWidth, int windowHeight);

	void Initialize();	

	int getHeight() { return height; }
	int getWidth() { return width; }

	int getBufferWidth();
	int getBufferHeight();

	int width, height;

	~Window();

private:

	// Buffers are the play area, the generic height and width are is the full window size
	int bufferWidth, bufferHeight;

};

/**
 * Default constructor, window size of 800 x 600
 * */
Window::Window()
{
	width = 800;
	height = 800;

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
	
	// Name window
	glutCreateWindow("Chess");
	
	
	glClearColor(1, 1, 1, 0);
	glColor3f(0, 0, 0);
	glPointSize(10);

	glutInitDisplayMode(GLUT_SINGLE | GL_RGB);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, width, 0, height);
}

int Window::getBufferWidth()
{
	bufferWidth = width - 75;
	return bufferWidth;
}

int Window::getBufferHeight()
{
	bufferHeight = height - 75;
	return bufferHeight;
}

Window::~Window()
{
	
}