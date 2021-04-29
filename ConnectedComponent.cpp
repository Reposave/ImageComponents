#include "ConnectedComponent.h"

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
