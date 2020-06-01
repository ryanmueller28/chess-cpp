#include <GL/glut.h>

#include "Window.h"

Window mainWindow;

void drawBoard(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);


	for (int x = 0; x < mainWindow.width; x += mainWindow.xDiff)
	{
		for (int y = 0; y < mainWindow.height; y+= mainWindow.yDiff)
		{
			if (((x + y) / 15) & 1)
			{
				glColor3f(.6, .6, .6);
			}else{
				glColor3f(.2, .2, .2);
			}
			glRecti(x, y, (x + mainWindow.xDiff), (y + mainWindow.yDiff));
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
	

	int width = atoi(argv[1]);
	int height = atoi(argv[2]);


	mainWindow = Window(width, height);
	mainWindow.Initialize();
	glutDisplayFunc(drawBoard);


	glutMainLoop();

	return 0;
}
