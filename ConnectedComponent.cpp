#include "ConnectedComponent.h"
#include <utility>

int DLMARD001::ConnectedComponent::IDAssign = 0;

DLMARD001::ConnectedComponent::ConnectedComponent():pixels(0){
	DLMARD001::ConnectedComponent::AssignID();
}
void DLMARD001::ConnectedComponent::AssignID(){
	ID = IDAssign;
	++IDAssign;
		}
		
DLMARD001::ConnectedComponent::~ConnectedComponent(){}

int DLMARD001::ConnectedComponent::getID(){
	return ID;
}
void DLMARD001::ConnectedComponent::push(int x, int y){
	coord.push_back(std::pair<int,int>(x,y));
	++pixels;
}
int DLMARD001::ConnectedComponent::getNumOfPixels(){
	return pixels;
}
