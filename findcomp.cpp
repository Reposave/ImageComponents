#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>

int imageWidth = 0;
int imageHeight = 0;

int min_size = 0;
int max_size = 0;

int threshold = 0;

std::string filename;
std::string outfilename;

std::vector<std::string> arguments;
		
int main (int argc, char *argv[])
{
	bool print_component_data = false;
	bool write_to_PGM = false;
	
	for (int i = 1; i<argc; ++i){
		arguments.push_back(argv[i]);
	}
    
    for(std::vector<std::string>::size_type i = 0; i != arguments.size(); ++i) {
    	
    	if(arguments[i] == "-s"){
    		min_size = std::stoi(arguments[i+1]);
    		max_size = std::stoi(arguments[i+2]);
    		i=i+3;	
    	}else if(arguments[i] == "-t"){
    		threshold = std::stoi(arguments[i+1]);
    		i=i+2;
    	}else if(arguments[i] == "-p"){
    		print_component_data = true;
    	}else if(arguments[i] == "-w"){
    		write_to_PGM = true;
    		outfilename = arguments[i+1];
    		i = i+2;
    	}else if(i==(arguments.size()-1)){
    		filename = arguments[i];
    	}
	}
  	
  	
  	
}
