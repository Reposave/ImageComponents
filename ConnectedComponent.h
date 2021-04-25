#ifndef __CONNECTEDComponent__
#define __CONNECTEDComponent__

namespace DLMARD001
	{
	class ConnectedComponent{
	private:
		int pixels;
		int ID;
		
	
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
