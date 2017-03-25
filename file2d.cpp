#include "file2d.h"

void File2d::createInstructionVector() {

	std::cout << "Reading file: " << selected_file << "\n" << std::endl;

	std::ifstream openFile(selected_file.c_str());		
	std::string line;

	//Loop through each line in input file
	while (getline(openFile, line)) 
	{
		try
		{
			std::stringstream stream(line);
			std::string first_word;
			std::string second_word;
			stream >> first_word;
			stream >> second_word;

			if (second_word == "[")
			{
				//Switch on first_word and create the relevant object and call its file read overloaded function
				if (first_word == "translate")
				{
					Translate* next_translation = new Translate;
					openFile >> *next_translation;
					instruction_vector.push_back(next_translation);
				}
				else if (first_word == "scale")
				{
					Scale* next_scale = new Scale;
					openFile >> *next_scale;
					instruction_vector.push_back(next_scale);
				}
				else if (first_word == "circle")
				{
					Circle* next_circle = new Circle;
					openFile >> *next_circle;
					instruction_vector.push_back(next_circle);
				}
				else if (first_word == "polygon")
				{
					Poly* next_Poly = new Poly;
					openFile >> *next_Poly;
					instruction_vector.push_back(next_Poly);
				}
#
				//Read the crap at bottom of instruction
				getline(openFile, line);
				getline(openFile, line);
				std::stringstream stream(line);
				stream >> first_word;

				if (first_word == "]")
				{
					getline(openFile, line);
				}
				else
				{
					throw std::exception("Missing ] at end of instruction!");
				}

			}
			else
			{
				throw std::exception("SMissing [ at start of instruction!");
			}
		}
		catch (std::exception& error)
		{
			//Catch all exceptions and print error
			std::cerr << "Syntax error: " << error.what() << std::endl;
			return;
		}
	}
	openFile.close();
}

std::vector<Instruction*> File2d::getInstructionVector() const
{
	return instruction_vector;
}
