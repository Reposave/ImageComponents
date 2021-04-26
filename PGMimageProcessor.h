#ifndef __PGMIMAGEPROCESSOR__
#define __PGMIMAGEPROCESSOR__
#include <string>
namespace DLMARD001
	{
	class PGMimageProcessor{
	
	int min_size = 0;
	int max_size = 0;

	int threshold = 0;

	std::string filename;
	std::string outfilename;
	
	public:
		PGMimageProcessor(); 
		PGMimageProcessor(const int min_size, const int max_size, const int threshold, const std::string outfilename, const std::string filename);
		
		~PGMimageProcessor();
		
		PGMimageProcessor(const PGMimageProcessor& p);
		PGMimageProcessor(PGMimageProcessor && p);
		
		PGMimageProcessor& operator=(const PGMimageProcessor& rhs);
		PGMimageProcessor& operator=(PGMimageProcessor&& rhs); 
		
		int getMinSize();
		/*int extractComponents(unsigned char  threshold, int minValidSize);
		int  filterComponentsBySize(int minSize, int maxSize);
		bool writeComponents(const std::string & outFileName);
		int getComponentCount(void) const;
		int getLargestSize(void) const;
		int getSmallestSize(void) const;
		void printComponentData(const ConnectedComponent & theComponent) const;*/
	};
}
#endif
