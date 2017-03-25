#pragma once

#include <sstream>
#include <algorithm>

#include "instruction.h"
#include "vector3.h"

//Transformation class that will be inhertied by scale and transform classes

class Transformation : public Instruction
{
public:

	Transformation() : Instruction(), data(0, 0, 0) {};											
	Transformation(const Vector3<GLfloat> new_data) : Instruction(), data(new_data) {};			
	~Transformation() {};																		

	void set_transformation_data(const Vector3<GLfloat> new_data) { data = new_data; };			

	Vector3<GLfloat> get_transformation_data() const { return data; };							

	//Take file and extract relevent transformation information
	friend std::istream& operator >> (std::istream& file, Transformation& trasnformation)		
	{
		std::cout << "Transformation:" << std::endl;

		file >> trasnformation.data.x;														
		file >> trasnformation.data.y;															
		file >> trasnformation.data.z;														

		std::cout << trasnformation.data.x << " " << trasnformation.data.y << " " << trasnformation.data.z << "\n" << std::endl;

		return file;
	};

protected:

	Vector3<GLfloat> data;																		

private:

};
