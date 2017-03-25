#include "instruction.h"
#include "file2d.h"
#include "window.h"

//Global vector of instances to be drawn
std::vector<Instruction*> instructions;		

//Function to draw the scene
void draw()										
{
	//For each loop to iterate over the instruction retrieved from the txt file
	for (auto &object : instructions)					
	{
		//Call each objects draw function
		object->draw();									
	}
}

int main(int argc, char** argv)
{

	//Check for correct number of arguments
	if(argc!=2)
	{
		std::cerr << "Incorrect number of argument.\nPlease try again!!!" << std::endl;
	}
	else
	{
		// Call the File2d class to read the text file and setup the instruction vector
		File2d file(argv[1]);							
		file.createInstructionVector();					
		instructions = file.getInstructionVector();		

		//Create and run a window
		Window window(argc, argv);						
	}
}
