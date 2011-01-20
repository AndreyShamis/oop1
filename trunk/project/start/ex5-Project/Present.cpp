#include "Present.h"

//=============================================================================
//	Class constructor 
Present::Present()
{

	_present_type =	(rand()% 3) + 1	;			//	random the type of present
	switch(_present_type)
	{
	case PRESENT_BOMB:							//	present bomb
		_sprite.push_back(SURPRISE_BOMB);
		break;
	case PRESENT_TIME:							//	present time
		_sprite.push_back(SURPRISE_TIME);
		break;
	case PRESENT_LIGHT:							//	present lith
		_sprite.push_back(SURPRISE_LIHT);
		break;
	}
	_takable = true;							//	indication if the present is takable
	_movable = true;								//	if movable
	setSize();									//	set size

}

//=============================================================================
//	Function to draw object
void Present::Draw()
{
	vector <Sprite>::iterator it;		//	vector iterator
	it = _sprite.begin();				//	get the sprite 
	it->Draw(_cord);					//	draw
}

//=============================================================================
//	This function return the present type
short int Present::getPresentType()
{
	return (_present_type);
}