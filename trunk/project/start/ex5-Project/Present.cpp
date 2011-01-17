#include "Present.h"

//=============================================================================
Present::Present()
{

	_present_type =	(rand()% 3) + 1	;
	switch(_present_type)
	{
	case PRESENT_BOMB:
		_sprite.push_back(SURPRISE_BOMB);
		break;
	case PRESENT_TIME:
		_sprite.push_back(SURPRISE_TIME);
		break;
	case PRESENT_LIGHT:
		_sprite.push_back(SURPRISE_LIHT);
		break;
	default:
		std::cout << "Error create surprise\n";
		exit(EXIT_FAILURE);
		break;
	}
	_takable = true;
	movable = 1;

}

//=============================================================================
void Present::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	it->Draw(_cord);
}


short int Present::getPresentType()
{
	return (_present_type);
}