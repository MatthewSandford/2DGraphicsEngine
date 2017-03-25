#pragma once

#include "instruction.h"
#include "vector3.h"

//Class for Polygons 

class Poly : public Instruction {														
public:

	Poly() : Instruction(), colour(0.0f,0.0f,0.0f) {};							
	~Poly() {};																	

	void set_colour(const Vector3<GLfloat> new_colour);									
	void add_vertex(const Vector3<GLfloat> new_data) { verts.push_back(new_data); };	

	Vector3<GLfloat> get_colour() {return colour; };									
	std::vector<Vector3<GLfloat>> get_verts() {return verts; };							

	//Function that will draw the shape information to the screen
	void draw(void);																	

	//Take file and extract relevent shape information
	friend std::istream& operator >> (std::istream& file, Poly& Poly);			

protected:

	Vector3<GLfloat> colour;															
	std::vector<Vector3<GLfloat>> verts;												

private:

};
