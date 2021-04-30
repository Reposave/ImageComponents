#include "PGMimageProcessor.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>


DLMARD001::PGMimageProcessor::PGMimageProcessor(): min_size(3), max_size(10000), threshold((unsigned char)128){}

DLMARD001::PGMimageProcessor::~PGMimageProcessor(){
	if(array!=nullptr){
		for(int i =0; i< imageHeight; ++i)
	  	{ delete [] array[i]; }
	  	
	  	delete [] array;
	}
}

DLMARD001::PGMimageProcessor::PGMimageProcessor(const std::string outfilename, const std::string filename,const int max_size,const int min_size,const unsigned char threshold): min_size(min_size), max_size(max_size), threshold(threshold), outfilename(outfilename), filename(filename){

}

int DLMARD001::PGMimageProcessor::getMinSize(){

	return min_size;
}
int DLMARD001::PGMimageProcessor::getImageHeight(){

	return imageHeight;
}
void DLMARD001::PGMimageProcessor::BuildArray(){
	
	//int buffsize = 80;
	
	//Reading PGM Header info.
	std::string line;
	std::string previous; //Stores the previous line after an iteration.
	
   	std::ifstream infile("Images/"+filename,std::ios_base::binary);
	std::stringstream ss;
	//char buff[buffsize];
	
	while(line.compare("255")!=0){ //Iterate through the non-binary data.	
		previous = line;
		getline(infile, line);
		
		//std::cout << line << std::endl;
	}
	
	//getline(infile, line);//Go to next line with Binary data.

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
	
	//std::cout << "Beginning Component Extraction";
	std::cout << extractComponents((unsigned char)threshold, min_size) << std::endl; //*removable*
	//std::cout << filterComponentsBySize(3, 5); //*removable*
	std::cout << writeComponents(outfilename) << std::endl; //*removable*
}
int DLMARD001::PGMimageProcessor::extractComponents(unsigned char threshold, int minValidSize){
	//find pixel above threshold.
	//Is there ever a need to check north.
	int components = 0;
	for(int row = 0; row < imageHeight; row++){
		for (int col = 0; col < imageWidth; col++){
					if(array[row][col] > threshold){
						DLMARD001::ConnectedComponent* c = new DLMARD001::ConnectedComponent();
						BuildComponent(row, col, c); //*removable*
						if(c->getNumOfPixels()>=minValidSize){
							cc.push_back(std::make_unique<DLMARD001::ConnectedComponent*>(c));
							++components;
						}
					}
				}
			}
	
	return components;
	
}
void DLMARD001::PGMimageProcessor::BuildComponent(int row, int col, DLMARD001::ConnectedComponent * c){
	c->push(row, col);
	array[row][col] = (unsigned char)0;
	
	if(row-1>=0){
		if(array[row-1][col] > threshold){
			//Check North, don't go below 0 boundary.
			//std::cout << "North";
			BuildComponent(row-1,col, c);
		}
	}
	if(col+1 <= imageWidth-1){
		if(array[row][col+1] > threshold){
			//std::cout << "East";
			BuildComponent(row,col+1, c);
		}
	}
	if(row+1<= imageHeight-1){
		if(array[row+1][col] > threshold){
			//std::cout << "South";
			BuildComponent(row+1,col, c);
		}
	}
	if(col-1>=0){
		if(array[row][col-1] > threshold){
			//std::cout << "West";
			BuildComponent(row,col-1, c);
		}
	}
}

int DLMARD001::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){
	for(std::list<std::unique_ptr<DLMARD001::ConnectedComponent*>>::iterator i = cc.begin(); i != cc.end(); ++i) {
		if((**i)->getNumOfPixels() < minSize || (**i)->getNumOfPixels() > maxSize){
			i = cc.erase(i);
		}
	}
	return cc.size();
}

bool DLMARD001::PGMimageProcessor::writeComponents(const std::string & outFileName){
	int numprinted = 0;
	int componentsizes = 0;
	for(int row = 0; row < imageHeight; row++){
		for (int col = 0; col < imageWidth; col++){
				//ss >> array[row][col];
				array[row][col] =(unsigned char) 0;
				}
			}
			
	for(std::list<std::unique_ptr<DLMARD001::ConnectedComponent*>>::iterator i = cc.begin(); i != cc.end(); ++i) {
		componentsizes+=(**i)->getNumOfPixels();
		
		std::vector<std::pair<int,int>> a;
		a = (**i)->getVectorPairs();
		for(std::vector<std::pair<int, int>>::iterator j = a.begin(); j != a.end(); ++j) {
			++numprinted;
			array[j->first][j->second] = (unsigned char)255;
		}
	}
	
	ExportImage(outFileName);
	
	if(numprinted == componentsizes){
		return true;
	}
	return false;
}

void DLMARD001::PGMimageProcessor::ExportImage(const std::string & filename){
	FILE* outfile;
    
    std::string out = "Output/"+filename;
    outfile = fopen(out.c_str(), "wb");
    
    fprintf(outfile, "P5\n"); 
    fprintf(outfile,"# Created using PGMimageProcessor program.\n");
    fprintf(outfile, "%d %d\n", imageWidth, imageHeight); 
    fprintf(outfile, "255\n"); 

    
  for(int row = 0; row < imageHeight; row++) {
    for(int col = 0; col < imageWidth; col++) {
    		fwrite(&array[row][col], 1,1,outfile);
      }
    }

}
int DLMARD001::PGMimageProcessor::getComponentCount(void) const{
	return cc.size();
}

/*int DLMARD001::PGMimageProcessor::filterComponentsBySize(int minSize, int maxSize){
	for(auto const & i: cc) {
		if((*i)->getNumOfPixels() < minSize || (*i)->getNumOfPixels() > maxSize){
			cc.erase(i);
		}
	}
	return cc.size();
}*/
