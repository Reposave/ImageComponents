#ifndef __PGMIMAGEPROCESSOR__
#define __PGMIMAGEPROCESSOR__
#include <string>
namespace DLMARD001
	{
	class PGMimageProcessor{

	std::string filename;
	
	int min_size = 0;
	int max_size = 0;

	int threshold = 0;

	std::string filename;
	std::string outfilename;
	
	public:
		PGMimageProcessor(); 
		PGMimageProcessor(min_size, max_size, threshold, filename, outfilename, const std::string filename);
		
		~PGMimageProcessor();
		
		PGMimageProcessor(const PGMimageProcessor& p);
		PGMimageProcessor(PGMimageProcessor && p);
		
		PGMimageProcessor& operator=(const PGMimageProcessor& rhs);
		PGMimageProcessor& operator=(PGMimageProcessor&& rhs); 
		
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
