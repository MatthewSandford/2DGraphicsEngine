#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "instruction.h"
#include "translate.h"
#include "scale.h"
#include "circle.h"
#include "poly.h"

//Class the produces and instruction vector to be drawn 

class File2d 
{

public:

	//Constructor taking in filename
	File2d(std::string fileName) : selected_file(fileName) {};
	~File2d() {};
	
	//Function to read input file and produce an intruction vector
	void createInstructionVector();

	std::vector<Instruction*> getInstructionVector() const;

protected:

private:

	//Default constructor can not be called
    File2d(){};

	std::string selected_file;
	std::vector<Instruction*> instruction_vector;
};
