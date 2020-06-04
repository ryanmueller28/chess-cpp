#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#pragma once

#include <GL/gl.h>
#include <GL/glut.h>
#include <string>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

/**
 * Piece.h a base class from which all
 * Chess pieces will derive their legal moves
 * */

class Piece
{
public:

    int turnCounter;

    Piece();

    Piece(std::string pColor, std::string pName);

    ~Piece();
    
    int getXpos() { return xPos; }
    int getYpos() { return yPos; }

    std::string getColor();
    std::string getName() { return name; }

    virtual bool isCaptured();

    const char* getFileName(std::string fileName);
 
    GLuint rawImageLoad(const char* fileName, int width, int height);

    void Render();

    void init();

    /**
     * A struct to store the position of x and y
     * To where the piece is.
     * */
    struct Position{
        int x;
        int y;
    }piecePos;

protected:

    bool isBlack;

    int xPos, yPos;
    bool killed;

    void deletePiece();

    std::string name;
    
    std::string color;

    int imageWidth, imageHeight, nrChannels;

    static GLuint texture;

};

Piece::Piece()
{
    piecePos.x = xPos;
    piecePos.y = yPos;
    turnCounter = 0;

    killed = false;
}

// Overloaded constructor to take the color and name
Piece::Piece(std::string pColor, std::string pName)
{
    killed = false;
    turnCounter = 0;

    piecePos.x = xPos;
    piecePos.y = yPos;
    color = pColor;
    name = pName;
}

const char* Piece::getFileName(std::string fileName)
{
    fileName += "-";
    fileName += getColor();

    const char* cFileName = fileName.c_str();

    return cFileName;    
}

Piece::~Piece()
{
    deletePiece();
}


bool Piece::isCaptured()
{
    killed = true;

    return killed;
}

void Piece::deletePiece()
{
    if (killed)
    {
        delete this;
    }
}
 std::string Piece::getColor() { 
        if (isBlack)
        {
            color = "black";
        }else{
            color = "white";
        }
        return color; 
}

GLuint Piece::rawImageLoad(const char* fileName, int width, int height)
{
    GLuint texture;
     unsigned char *data;
     FILE *file;

    std::string temp(fileName);
    fileName = getFileName(fileName);
     
     // open texture data
     file = fopen(fileName, "rb");
     if (file == NULL) return 0;
     
     // allocate buffer
     data = (unsigned char*) malloc(width * height * 4);
     
     // read texture data
     fread(data, width * height * 4, 1, file);
     fclose(file);
     
     // allocate a texture name
     glGenTextures(1, &texture);
     
     // select our current texture
     glBindTexture(GL_TEXTURE_2D, texture);
     
     // select modulate to mix texture with color for shading
     glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
     
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_DECAL);
     glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_DECAL);
     
     // when texture area is small, bilinear filter the closest mipmap
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_NEAREST);
     // when texture area is large, bilinear filter the first mipmap
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
     
     // texture should tile
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
     glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
     
     // build our texture mipmaps
     gluBuild2DMipmaps(GL_TEXTURE_2D, 4, width, height, GL_RGBA, GL_UNSIGNED_BYTE, data);
     
     // free buffer
     free(data);
     
     return texture;
}

void Piece::Render()
{
    glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     /* fov, aspect, near, far */
     gluPerspective(60, 1, 1, 10);
     gluLookAt(0, 0, -2, /* eye */
               0, 0, 2, /* center */
               0, 1, 0); /* up */
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glPushAttrib(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
         glEnable(GL_TEXTURE_2D);
         
         /* create a square on the XY
            note that OpenGL origin is at the lower left
            but texture origin is at upper left
            => it has to be mirrored
            (gasman knows why i have to mirror X as well) */
         glBegin(GL_QUADS);
         glNormal3f(0.0, 0.0, 1.0);
         glTexCoord2d(1, 1); glVertex3f(0.0, 0.0, 0.0);
         glTexCoord2d(1, 0); glVertex3f(0.0, 1.0, 0.0);
         glTexCoord2d(0, 0); glVertex3f(1.0, 1.0, 0.0);
         glTexCoord2d(0, 1); glVertex3f(1.0, 0.0, 0.0);
         glEnd();
         
         glDisable(GL_TEXTURE_2D);
     glPopAttrib();
     
     glFlush();
     
     glutSwapBuffers();
 }