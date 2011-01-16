#include "Present.h"

//=============================================================================
Present::Present()
{

	_present_type =	(rand()% 3) + 1	;
	switch(_present_type)
	{
	case 1:
		_sprite.push_back(SURPRISE_BOMB);
		break;
	case 2:
		_sprite.push_back(SURPRISE_TIME);
		break;
	case 3:
		_sprite.push_back(SURPRISE_LIHT);
		break;
	default:
		std::cout << "Error create surprise\n";
		exit(EXIT_FAILURE);
		break;
	}
	
	movable = 1;

}

//=============================================================================
void Present::Draw()
{
	vector <Sprite>::iterator it;
	it = _sprite.begin();
	it->Draw(_cord);
}