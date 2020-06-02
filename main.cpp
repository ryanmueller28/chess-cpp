#include <cstdlib>
#include <GL/glut.h>

#include "Window.h"

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
	
	// The difference in x and y for a tile
	int xChange = mainWindow.getWidth() / 8;
	int yChange = mainWindow.getHeight() / 8;


	for (int x = 0; x < mainWindow.width; x += xChange)
	{
		for (int y = 0; y < mainWindow.height; y+= yChange)
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

int main(int argc, char ** argv)
{
	int width, height;
	// Sanity check if we haven't passed in window size
	if (argc != 3)
	{
		printf("Error Initializing Chessboard\n");
		printf("The format is width, height\n");
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
