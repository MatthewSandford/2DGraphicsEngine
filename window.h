#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glu.h>

void draw();

class Window
{
public:

	Window(int argc, char** argv);								

	static void reshape(int w, int h);							
	static void keyboard(unsigned char key, int x, int y);		
	static void display();										

protected:

private:

	Window() {};

};
