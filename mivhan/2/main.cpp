#include <iostream>

using namespace std;

class A {


public:
	A(int x=0);
	~A();
	int getX()
	{
		return(_x);
	};
private:
	int _x;
};

A::A(int x) : _x(x) { cout << " A-ctor--- " << x << "\n"; }
A::~A() { cout << "A-dtor" << _x << "\n"; }

class B:public A {
public:
	B(int x);
	~B();
	int getX()
	{
		return(_a.getX());
	};
private:
	A _a;
};

B::B(int x) : _a(x) { cout << " B-ctor----- " << x << "\n"; }
B::~B() { cout << "B-dtor --- \t[" << _a.getX() << "]\n" ; }

class C {
public:
	C();
	C(int x);
	~C();
	C(const C &obj)
	{	
		cout << " C-ctor == Bulder " << obj._bPtr->getX() <<"\n";
		///////////C *new_obj = new C(obj._bPtr->getX());

		_bPtr = new B(obj._bPtr->getX()+ 12);
		
	}
	//C operator=(const C &obj)
	//{	
	//	cout << "Yes \t = " << obj._bPtr->getX() <<"\n";
	//	///////////C *new_obj = new C(obj._bPtr->getX());

	//	_bPtr = new B(obj._bPtr->getX()+ 12);
	//	
	//	return(*this);
	//}

private:
	B* _bPtr;
};

C::C() : _bPtr(NULL) { cout << " C-ctor\n"; }
C::C(int x) : _bPtr(new B(x)) { cout << " C-ctor--- " << x << "\n"; }
C::~C() { cout << "C-dtor\n"; delete _bPtr; }

int main() {
	C c1(5);
	cout << "\t - Load next\n";
	//C c2=c1;
	//cout << "\t - Load next\n\n\n";

	//C array[5];
}