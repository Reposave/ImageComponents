#ifndef __CONNECTEDComponent__
#define __CONNECTEDComponent__
#include <vector>
//#include <pair>
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
		ConnectedComponent(const int x, const int y); 
		
		~ConnectedComponent(); 
		
		
		ConnectedComponent(const ConnectedComponent& p); 
		ConnectedComponent(ConnectedComponent && p); 
		
		ConnectedComponent& operator=(const ConnectedComponent& rhs);
		ConnectedComponent& operator=(ConnectedComponent&& rhs); 
		
		void AssignID();
		int getID();
	};
}
#endif
