#ifndef __PGMIMAGEPROCESSOR__
#define __PGMIMAGEPROCESSOR__

namespace DLMARD001
	{
	class PGMimageProcessor{

	std::string filename;
	
	public:
		PGMimageProcessor(); 
		PGMimageProcessor(const std::string filename);
		
		~PGMimageProcessor();
		
		PGMimageProcessor(const PGMimageProcessor& p);
		PGMimageProcessor(PGMimageProcessor && p);
		
		PGMimageProcessor& operator=(const PGMimageProcessor& rhs);
		PGMimageProcessor& operator=(PGMimageProcessor&& rhs); 
		
	};
}
#endif
