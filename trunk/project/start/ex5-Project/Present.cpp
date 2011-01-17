#include "Present.h"

//=============================================================================
//	Constructor
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
	movable = 1;								//	if movable
	setSize();									//	set size

}

//=============================================================================
//	Drow function
void Present::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	it->Draw(_cord);
}

//=============================================================================
//	This function return the present type
short int Present::getPresentType()
{
	return (_present_type);
}