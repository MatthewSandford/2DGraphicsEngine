#include "poly.h"

void Poly::set_colour(const Vector3<GLfloat> new_colour)
{																			
	std::vector<GLfloat> new_colour_2({ new_colour.x,new_colour.y,new_colour.z });

	//Loop through rgb values and do some error checking
	for (auto &item : new_colour_2)
	{
		if (item > 1)
		{
			std::cerr << "Colour component greater than 1! Component will be set to 1!";
			item = 1;
		}
		if (item < 0)
		{
			std::cerr << "Colour component less than 0! Component will be set to 0!";
			item = 0;
		}
	}

	colour = new_colour;
};

void Poly::draw()
{
	//Draw out our shape information
	glColor3f(colour.x, colour.y, colour.z);								
	glBegin(GL_LINE_LOOP);													
	
	for (Vector3<GLfloat> &vert : verts) 									
    {
        glVertex3f(vert.x, vert.y, vert.z);									
    }

    glEnd();																
};

std::istream& operator >> (std::istream& file, Poly& Poly)		
{
	std::string description;
	int num_of_verts;
	Vector3<GLfloat> temp_vector;

	file >> description;

	//Set colour
	if (description == "colour")											
	{																	
		file >> temp_vector.x;
		file >> temp_vector.y;
		file >> temp_vector.z;
		Poly.set_colour(temp_vector);									
	} 
	else 
	{
		throw std::exception("Error in file, was expecting colour first in Poly object"); 
	}

	file >> description;													
	
	//Set num_of_verts
	if (description == "num_vert")											
	{
		file >> num_of_verts;												
	} 
	else
	{
		throw std::exception("Error in file, was expecting number of vertices Poly object"); 
	}

	//Read vertices and add to verts vector
	for (int i =0; i < num_of_verts; i++) {									
		file >> temp_vector.x;
		file >> temp_vector.y;
		file >> temp_vector.z;
		Poly.add_vertex(temp_vector);
	}

	std::cout << "Polygon: " << std::endl;
	std::cout << "Colour: " << temp_vector.x << " " << temp_vector.y << " " << temp_vector.z << std::endl;
	std::cout << "Vertices: " << num_of_verts << "\n" << std::endl;

	return file;															
};
