#include "ConnectedComponent.h"
#include <utility>

int DLMARD001::ConnectedComponent::IDAssign = 0;

DLMARD001::ConnectedComponent::ConnectedComponent():pixels(0){
	DLMARD001::ConnectedComponent::AssignID();
}

DLMARD001::ConnectedComponent::ConnectedComponent(const DLMARD001::ConnectedComponent& p): pixels(p.pixels), coord(p.coord){
	this->AssignID();
}

DLMARD001::ConnectedComponent::ConnectedComponent(DLMARD001::ConnectedComponent && p): pixels(p.pixels), ID(p.ID),coord(p.coord){}

DLMARD001::ConnectedComponent& DLMARD001::ConnectedComponent::operator=(const DLMARD001::ConnectedComponent& rhs){
	if(this != &rhs) //Checks to make that we are not performing a self-assignment
		{
			this->pixels = rhs.pixels;
			this->coord = rhs.coord;
			this->AssignID();
		}
	
	return *this;
}
DLMARD001::ConnectedComponent& DLMARD001::ConnectedComponent::operator=(DLMARD001::ConnectedComponent&& rhs){
	if(this != &rhs) //Checks to make that we are not performing a self-assignment
		{
			this->pixels = rhs.pixels;
			this->coord = rhs.coord;
			this->ID = rhs.ID;
		}
	
	return *this;
}

void DLMARD001::ConnectedComponent::AssignID(){
	ID = IDAssign;
	++IDAssign;
		}
		
DLMARD001::ConnectedComponent::~ConnectedComponent(){} 

int DLMARD001::ConnectedComponent::getID()const{
	return ID;
}
void DLMARD001::ConnectedComponent::push(int x, int y){
	coord.push_back(std::pair<int,int>(x,y));
	++pixels;
}
int DLMARD001::ConnectedComponent::getNumOfPixels()const{
	return pixels;
}
const std::vector<std::pair<int, int>> & DLMARD001::ConnectedComponent::getVectorPairs(){
	return coord;
}
