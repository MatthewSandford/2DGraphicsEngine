#pragma once

#define PI 3.14159265359

#include "poly.h"

//Class for Circle object inheriting from the Polygon Class

class Circle : public Poly {														
public:

	Circle() : Poly() {};														
	Circle(const double new_radius, const int new_segments, const Vector3<GLfloat> new_colour);	
	~Circle() {};														

	void set_radius(const double new_radius);									
	void set_segments(const int new_segments);									

	const double get_radius() { return radius; };							
	const int get_segments() { return segments; };								

	//Calculate the vertices and add them to the inherited verts vector
	void calculate_verts();

	//Take file and extract relevent shape information
	friend std::istream& operator >> (std::istream& file, Circle& circle);		

protected:

private:

	double radius;															
	int segments;															

};
