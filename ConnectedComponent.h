#ifndef __CONNECTEDComponent__
#define __CONNECTEDComponent__
#include <vector>
#include <utility>

namespace DLMARD001
	{
	class ConnectedComponent{
	private:
		static int IDAssign;
		int pixels;
		int ID;
		
		std::vector<std::pair<int, int>> coord;
	public: 
		ConnectedComponent(); 
		
		~ConnectedComponent(); 
		
		
		ConnectedComponent(const ConnectedComponent& p); 
		ConnectedComponent(ConnectedComponent && p); 
		
		ConnectedComponent& operator=(const ConnectedComponent& rhs);
		ConnectedComponent& operator=(ConnectedComponent&& rhs); 
		
		void push(int x, int y);
		void AssignID();
		int getID();
		int getNumOfPixels();
	};
}
#endif
