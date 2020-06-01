#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Window.h"

class Tile : Window
{
public:
    Tile();
    ~Tile();

    // Draws an individual tile
     void DrawTile(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4);
    
    // returns the value of the size of a tile in x and y, so the window is scalable
    GLint getTileSizex();
    GLint getTileSizey();

    // Return buffer size so Board class can inherit the buffer size
    GLint retBufferWidth();
    GLint retBufferHeight();
private:
    int color = 0;

    GLint tileSizeX;
    GLint tileSizeY;
    
   
};

// Render a simple chess tile

void Tile::DrawTile(GLint x1, GLint y1, GLint x2, GLint y2, GLint x3, GLint y3, GLint x4, GLint y4)
{
    // If color is 0, draw white box and change value of color

    if (color == 0)
    {
        glColor3f(1, 1, 1);
        color = 1;
    }else{
        glColor3f(0, 0, 0);
        color = 0;
    }
    
    glBegin(GL_QUADS);
    glVertex2i(x1, y1);
    glVertex2i(x2, y2);
    glVertex2i(x3, y3);
    glVertex2i(x4, y4);

    glEnd();

}

GLint Tile::getTileSizex()
{
    return (getBufferWidth() / 64);
}

GLint Tile::getTileSizey()
{
    return (getBufferHeight() / 64);
}

GLint Tile::retBufferHeight()
{
    return getBufferHeight();
}

GLint Tile::retBufferWidth()
{
    return getBufferWidth();
}

Tile::Tile()
{
    tileSizeX = 75;
    tileSizeY = 75;
}

Tile::~Tile()
{

}