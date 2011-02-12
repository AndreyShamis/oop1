#include <iostream>

using namespace std;

class Animals{

public:
	Animals(const int &x =0  , const int &y = 0)
	{
		_x =x;
		_y=y;
	}
	/*Animals[](const int &x , const int &y)
	{
		_x =x;
		_y=y;
	}*/
	virtual void Makesound(const Animals animMat[10][10]) {};

protected:
	int _x, _y;
};


class Cat : public Animals{

public:
	Cat(const int &x,const int &y):Animals(x,y){};

};
class Dog : public Animals{

public:
	Dog(const int &x,const int &y):Animals(x,y){};
	void Makesound(const Animals animMat[10][10]){
	
		if(typeid(animMat[_x][_y-1]) == typeid(Cat)		&&
			typeid(animMat[_x][_y+1]) == typeid(Cat)	&&
			typeid(animMat[_x-1][_y]) == typeid(Cat)	&&
			typeid(animMat[_x+1][_y]) == typeid(Cat))
		
			cout << "howww" << endl;
	}



	
};




class Whitecat : public Cat{
public:
	Whitecat(const int &x,const int &y):Cat(x,y){};

};

class Duk : public Animals{

public:
	Duk(const int &x,const int &y):Animals(x,y){};

};


int main()
{
	Animals Ani[10][10];

	Cat c(2,2);

	Ani[2][2] = c;

	for(int x=1;x<9;x++)
	{
		for(int y=1;y<9;y++)
		{
			Ani[x][y].Makesound(Ani);
		}
	}



	return (0);
}