#include <cstdlib>
#include <GL/glut.h>

#include "Window.h"
#include "Board.h"
//#include "Menu.h"

Window mainWindow;
Board* Board::currentInstance;

int main(int argc, char ** argv)
{
	int width, height;

	// Sanity check if we haven't passed in window size
	// And use the default constructor
	if (argc != 3)
	{		
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
		// Window with overloaded constructor
		mainWindow = Window(width, height);
	}



	mainWindow.Initialize();

	
	// Call the drawBoard function to draw the chessboard

	/**
 	* Wrapper function from Board.h to main
 	* because GLUT functions are weird AF 
 	* */
	Board::currentInstance->display();


	glutMainLoop();

	return EXIT_SUCCESS;
}
