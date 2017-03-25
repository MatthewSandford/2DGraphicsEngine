#pragma once

#include "transformation.h"

//Class to represent scale transformations

class Scale : public Transformation
{
public:

	Scale() : Transformation() {};												
	Scale(const Vector3<GLfloat> new_data) : Transformation(new_data) {};		
	~Scale() {};	

	//Overwriting the virtual draw function within "Instruction" to call GlScale function
	void draw(void) { glScalef(data.x, data.y, data.z); };			

protected:

private:

};
