#include <GL/glut.h>

#include "Window.h"

Window mainWindow;

void drawBoard(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	
	int xChange = mainWindow.getWidth() / 8;
	int yChange = mainWindow.getHeight() / 8;


	for (int x = 0; x < mainWindow.width; x += xChange)
	{
		for (int y = 0; y < mainWindow.height; y+= yChange)
		{
 			if (((x + y) / xChange) & 1)
			{
				glColor3f(.6, .6, .6);
			}else{
				glColor3f(.2, .2, .2);
			}
			glRecti(x, y, (x + xChange), (y + yChange));
		}
	}

	glFlush();
}

int main(int argc, char ** argv)
{
	

	if (argc != 3)
	{
		printf("Error Initializing Chessboard\n");
		printf("The format is width, height\n");
	}

	glutInit(&argc, argv);
	

	mainWindow.width = atoi(argv[1]);
	mainWindow.height = atoi(argv[2]);

	int width = mainWindow.width;
	int height = mainWindow.height;

	mainWindow = Window(width, height);
	mainWindow.Initialize();

	glutDisplayFunc(drawBoard);


	glutMainLoop();

	return 0;
}
