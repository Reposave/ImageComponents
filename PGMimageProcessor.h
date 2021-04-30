#ifndef __PGMIMAGEPROCESSOR__
#define __PGMIMAGEPROCESSOR__
#include <string>
#include "ConnectedComponent.h"
#include <list>

namespace DLMARD001
	{
	class PGMimageProcessor{
	
	int imageWidth;
	int imageHeight;
	
	int min_size = 0;
	int max_size = 0;

	unsigned char threshold;

	std::string filename;
	std::string outfilename;
	
	unsigned char ** array = nullptr;
	
	std::list<ConnectedComponent*> cc;
	
	public:
		PGMimageProcessor(); 
		PGMimageProcessor(const std::string outfilename, const std::string filename, const int max_size, const int min_size = 3, const unsigned char threshold=128);
		
		~PGMimageProcessor();
		
		PGMimageProcessor(const PGMimageProcessor& p);
		PGMimageProcessor(PGMimageProcessor && p);
		
		PGMimageProcessor& operator=(const PGMimageProcessor& rhs);
		PGMimageProcessor& operator=(PGMimageProcessor&& rhs); 
		
		int getMinSize();
		void BuildArray();
		int getImageHeight();
		int extractComponents(unsigned char  threshold, int minValidSize);
		void BuildComponent(int row, int col, DLMARD001::ConnectedComponent * c);
		/*int  filterComponentsBySize(int minSize, int maxSize);
		bool writeComponents(const std::string & outFileName);
		int getComponentCount(void) const;
		int getLargestSize(void) const;
		int getSmallestSize(void) const;
		void printComponentData(const ConnectedComponent & theComponent) const;*/
	};
}
#endif
