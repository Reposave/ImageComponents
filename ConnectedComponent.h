#ifndef __CONNECTEDComponent__
#define __CONNECTEDComponent__
#include <vector>
#include <pair>
namespace DLMARD001
	{
	class ConnectedComponent{
	private:
		int pixels;
		int ID;
		
		std::vector<std::pair<int, int>>
	public: 
		ConnectedComponent(); 
		ConnectedComponent(const int pixels, const int ID); 
		
		~ConnectedComponent(); 
		
		
		ConnectedComponent(const ConnectedComponent& p); 
		ConnectedComponent(ConnectedComponent && p); 
		
		ConnectedComponent& operator=(const ConnectedComponent& rhs);
		ConnectedComponent& operator=(ConnectedComponent&& rhs); 
		
	};
}
#endif
