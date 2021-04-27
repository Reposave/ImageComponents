#include "PGMimageProcessor.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

DLMARD001::PGMimageProcessor::PGMimageProcessor(): min_size(3), max_size(10000), threshold(128){}

DLMARD001::PGMimageProcessor::~PGMimageProcessor(){
	if(array!=nullptr){
		for(int i =0; i< imageHeight; ++i)
	  	{ delete [] array[i]; }
	  	
	  	delete [] array;
	}
}

DLMARD001::PGMimageProcessor::PGMimageProcessor(const int min_size, const int max_size, const int threshold, const std::string outfilename, const std::string filename): min_size(min_size), max_size(max_size), threshold(threshold), outfilename(outfilename), filename(filename){

}

int DLMARD001::PGMimageProcessor::getMinSize(){

	return min_size;
}
int DLMARD001::PGMimageProcessor::getImageHeight(){

	return imageHeight;
}
void DLMARD001::PGMimageProcessor::BuildArray(){
	
	int buffsize = 80;
	
	//Reading PGM Header info.
	std::string line;
	std::string previous; //Stores the previous line after an iteration.
	
   	std::ifstream infile("Images/"+filename,std::ios_base::binary);
	std::stringstream ss;
	
	char buff[buffsize];
	
	while(line.compare("255")!=0){ //Iterate through the non-binary data.	
		previous = line;
		getline(infile, line);
		
		//std::cout << line << std::endl;
	}
	
	getline(infile, line);//Go to next line with Binary data.

	//std::cout << previous << std::endl;
	
	ss.clear();
	ss << previous;
	
	ss >> imageWidth;
	ss >> imageHeight;
	
	//std::cout << imageWidth <<" "<< imageHeight << " " << "columns" << std::endl;
	
	if((array = new unsigned char*[imageHeight])!= nullptr){
		for(int i=0; i<imageHeight; ++i){
			if((array[i] = new unsigned char[imageWidth]) == nullptr)
				{std::cerr << "Allocation error!"; break;}
		}
	}
	
	//ss << infile.rdbuf();
	
	char b;
	
	//Populate the array with the whole image data.
	for(int row = 0; row < imageHeight; row++){
		for (int col = 0; col < imageWidth; col++){
				infile.get(b);
				//ss >> array[row][col];
				array[row][col] = b;
				}
			}
			
	infile.close();
}
