#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include "PGMimageProcessor.h"

int imageWidth = 0;
int imageHeight = 0;

int min_size = 0;
int max_size = 0;

unsigned char threshold = 0;

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
    //std::cout <<"Finding parameters.";
    for(std::vector<std::string>::size_type i = 0; i != arguments.size(); ++i) {
    	
    	if(arguments[i] == "-s"){
    		min_size = std::stoi(arguments[i+1]);
    		max_size = std::stoi(arguments[i+2]);	
    	}else if(arguments[i] == "-t"){
    		threshold = (unsigned char) std::stoi(arguments[i+1]);
    	}else if(arguments[i] == "-p"){
    		print_component_data = true;
    	}else if(arguments[i] == "-w"){
    		write_to_PGM = true;
    		outfilename = arguments[i+1];
    	}else if(i==(arguments.size()-1)){
    		filename = arguments[i];
    	}
	}
	
  	DLMARD001::PGMimageProcessor a(outfilename, filename,min_size,max_size, threshold);
  	a.BuildArray();
  	
  	if(print_component_data){
  		std::cout << "Number of Components: ";
  		std::cout << a.getComponentCount() << std::endl;
  		std::cout << "Number of pixels in smallest component: ";
  		std::cout << a.getSmallestSize() << std::endl;
  		std::cout << "Number of pixels in Largest component: ";
  		std::cout << a.getLargestSize() << std::endl;
  		std::cout<<"Printing Components:"<<std::endl;
  		a.printAll();
  	}
  	
  	
}
