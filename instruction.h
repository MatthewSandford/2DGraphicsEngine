#pragma once

#include <GL/glew.h>
#include <GL/freeglut.h>
#include <GL/glut.h>
#include <GL/glu.h>

#include <iostream>
#include <sstream>
#include <vector>

//Bass class that will allow transformations and polygons to be stored in one container class

class Instruction 
{
public:

	Instruction() {};							
	virtual ~Instruction() {};	

	//Virtual function that will be used by transformations and polygons
	virtual void draw(void) = 0;				

protected:

private:

};
