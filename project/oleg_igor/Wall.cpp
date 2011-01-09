
#include "Wall.h"

Wall::Wall( double xPos, double yPos ): GameObject( xPos, yPos ) {	
	_sprites.push_back(WALL_PIC) ;
};

void Wall::draw()  {
	
	vector<Sprite>::iterator it ;

	it = _sprites.begin() ;
	it->draw(_xPos, _yPos) ;

};

Sprite Wall::getSprite() {
	vector<Sprite>::iterator it ;
	it = _sprites.begin() ;

	return (*it) ;
};