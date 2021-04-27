#include "PGMimageProcessor.h"

DLMARD001::PGMimageProcessor::PGMimageProcessor(): min_size(3), max_size(10000), threshold(128){}
DLMARD001::PGMimageProcessor::~PGMimageProcessor(){}

DLMARD001::PGMimageProcessor::PGMimageProcessor(const int min_size, const int max_size, const int threshold, const std::string outfilename, const std::string filename): min_size(min_size), max_size(max_size), threshold(threshold), outfilename(outfilename), filename(filename){
	
	
}

int DLMARD001::PGMimageProcessor::getMinSize(){

	return min_size;
}
