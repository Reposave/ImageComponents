#include "PGMimageProcessor.h"

DLMARD001::PGMimageProcessor::PGMimageProcessor(): min_size(3), max_size(10000), threshold(128){}
DLMARD001::PGMimageProcessor::~PGMimageProcessor(){}
int DLMARD001::PGMimageProcessor::getMinSize(){

	return min_size;
}
