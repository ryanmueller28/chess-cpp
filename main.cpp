#include <cstdlib>
#include <GL/glut.h>

#include "Window.h"
//#include "Menu.h"

Window mainWindow;

/**
 * Draw function
 * For scalabilty, xChange and yChange are each height / 8
 * 
 * */
void drawBoard(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	
	// Create the window buffer
	int xBuff = mainWindow.getBufferWidth();
	int yBuff = mainWindow.getBufferHeight();

	// The difference in x and y for a tile
	int xChange = xBuff / 8;
	int yChange = yBuff / 8;


	for (int x = 0; x <= xBuff; x += xChange)
	{
		for (int y = 0; y <= yBuff; y+= yChange)
		{
			// Bit operator if x + y is odd or even to get white or black tiles
 			if (((x + y) / xChange) & 1)
			{
				glColor3f(.6, .6, .6);
			}else{
				glColor3f(.2, .2, .2);
			}
			glRecti(x, y, (x + xChange), (y + yChange)); // draw the tile
		}
	}

	glFlush();
}

/**
 * Wrapper function to type cast from Board.h to main
 * because GLUT functions are weird AF 
 * */

int main(int argc, char ** argv)
{
	int width, height;
	// Sanity check if we haven't passed in window size
	if (argc != 3)
	{
		printf("Error Initializing Chessboard\n");
		printf("The format is width, height\n");
		
		int temp_argc = 0;
		glutInit(&temp_argc, NULL);
		mainWindow = Window();
		height = mainWindow.height;
		width = mainWindow.width;
	}else{
		// Initialize GL
		glutInit(&argc, argv);
	
		// set Window Height and width
		mainWindow.width = atoi(argv[1]);
		mainWindow.height = atoi(argv[2]);

		width = mainWindow.width;
		height = mainWindow.height;
			// Reinitialize window with overloaded constructor
		mainWindow = Window(width, height);
	}


	mainWindow.Initialize();

	
	// Call the drawBoard function to draw the chessboard
	glutDisplayFunc(drawBoard);


	glutMainLoop();

	return EXIT_SUCCESS;
}
