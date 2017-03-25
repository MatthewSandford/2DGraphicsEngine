#include "circle.h"
#include <math.h>

void Circle::set_radius(const double new_radius)
{
	//Check for valid values
	if (new_radius > 0) 
	{													
		radius = new_radius;											
	} 
	else 
	{
		throw std::exception("Invalid radius value entered, radius must be greater than 0"); 
	}
};

void Circle::set_segments(const int new_segments)
{
	//Check for valid values
	if (new_segments >= 2)
	{												
		segments = new_segments;										
	} 
	else 
	{
		throw std::exception("Invalid segments value entered, there must be 2 or more segments"); 
	}
};

Circle::Circle(const double new_radius, const int new_segments, const Vector3<GLfloat> new_colour)
{
	//Calls functions so that values may be checked
	set_radius(new_radius);													
	set_segments(new_segments);												
	set_colour(new_colour);												
	calculate_verts();													
};


void Circle::calculate_verts()
{
	//Check for valid values
	if (radius != 0 && segments > 2)
	{
		// calculates degrees of each segment
		GLfloat section = 360/(float)segments;												
		GLfloat x=0.0f, y=0.0f;													

		//Loop through the circle edge points
		for (GLfloat degrees = 0; degrees < 360; degrees += section) 				
		{	
			//Calculate coordinate
			x = radius * sin(degrees * PI / 180);								
			y = radius * cos(degrees * PI / 180);

			//Add vertex to object vector
			add_vertex({ x,y,0.0f });												
		}
	}
	else
	{
		std::cerr << "Incorrect values for radius or segments!";
	}
};

std::istream& operator >> (std::istream& file, Circle& circle)				
{
	std::string description;

	Vector3<GLfloat> temp_vector;
	int num_of_segments;
	double radius;
	
	file >> description;

	//Set colour
	if (description == "colour")
	{
		file >> temp_vector.x;
		file >> temp_vector.y;
		file >> temp_vector.z;

		circle.set_colour(temp_vector);
	} 
	else 
	{
		throw std::exception("Error in file, was expecting colour in Circle object"); // Error : Message
	}

	file >> description;

	//Set radius
	if (description == "radius")
	{
		file >> radius;
		circle.set_radius(radius);
	} 
	else 
	{
		throw std::exception("Error in file, was expecting radius in Circle object"); // Error : Message
	}

	file >> description;

	//Set segments
	if (description == "num_segments")
	{
		file >> num_of_segments;
		circle.set_segments(num_of_segments);
	} 
	else 
	{
		throw std::exception("Error in file, was expecting number of segments in Circle object"); // Error : Message
	}

	//Calculate vertices based on previously read values
	circle.calculate_verts();

	std::cout << "Circle: " << std::endl;
	std::cout << "Colour: " << temp_vector.x << " " << temp_vector.y << " " << temp_vector.z << std::endl;
	std::cout << "Radius: " << radius << std::endl;
	std::cout << "Segments: " << num_of_segments << "\n" << std::endl;

	//Return file with new position to read from
	return file;
};