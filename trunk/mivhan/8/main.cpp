#include <iostream>
#include <typeinfo>
using namespace std;


class Creature{
public:
	virtual void meets(const Creature &othCture){};
	
//	
};

class Dragon : public Creature{
public:
	bool isDragon(Creature &othCture){return(typeid(othCture)==typeid(Dragon));}
	void meets(Creature &othCture)
	{
		switch(isDragon(othCture))
		{
		case true:	
			cout << "Dragon meets Dragon and helps it\n";

			break;
		case false:
			cout << "Dragon meets Monster and hurts it\n";

			break;
		}
	};
};
			

class Monster : public Creature{
public:

	
	void meets(Creature &othCture)
	{
		switch(isMonster(othCture))
		{
		case false:	
			cout << "Monster meets Dragon and eats it\n";

			break;
		case true:
			cout << "Monster meets Monster and ignores it\n";

			break;
		}
	};
	bool isMonster(const Creature &othCture){return(typeid(othCture)==typeid(Monster));}
};


int main() {
	Monster momy;
	Dragon dragy;

	Creature* arr[10];
	// Initialize arr
	//:

	for (int i=0;i<10;i++) {
		if(i==0 || i == 1 || i==2)
			arr[i] = new Monster();
		else 
			arr[i] = new Dragon();
	}
	arr[2]->meets( arr[2] );
	for (int i=0;i<10;i++) {
		arr[i]->meets(momy);
		arr[i]->meets(dragy);
	}
}
