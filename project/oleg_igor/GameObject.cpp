
#include "GameObject.h"

GameObject::GameObject( double xPos, double yPos ) {

	_xPos = xPos ;
	_yPos = yPos ;

};

double GameObject::getxPos() {
	return (_xPos) ;
};

double GameObject::getyPos() {
	return (_yPos) ;
};

Sprite GameObject::getSprite() {
	return (_sprites[0]) ;
};