
#include "Box.h"

Box::Box( double xPos, double yPos ) : GameObject( xPos, yPos ) {	
	_sprites.push_back( BOX_PIC ) ;
};

void Box::draw()  {
	
	vector<Sprite>::iterator it ;

	it = _sprites.begin() ;
	it->draw(_xPos, _yPos) ;

};

Sprite Box::getSprite() {
	vector<Sprite>::iterator it ;
	it = _sprites.begin() ;

	return (*it) ;
};