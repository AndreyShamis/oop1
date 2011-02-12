#include <iostream>

using namespace std;


class Me{
public:
	Me(): me(int(3)){cout <<"\tME CONSTR Me me=" << me << "\n";};
	~Me(){cout <<"\t~Me DESTROY\n";}
	int me;
};

class A {
public:
	A(){cout << "A- def const\n";}
	A(int x) : _xPtr(new int(x)) {
		cout <<"\tClass A builded\n";
		//cout << "FROM A: X is " << x << "\n";
		//cout << "FROM A: X-pointer is " << *_xPtr << "\n";
	}

	~A() {
		delete _xPtr;cout <<"\t~Class A Destroyed\n";
	}
	int getX()const
	{
		return(*_xPtr);
	}
private:					
	//Me mme;
	int* _xPtr;

};
//====================================================================
class B {
public:
	B(){cout <<"Banay Defultivi B\n";}
	B(int x) : _aPtr(new A(x)) {
		cout <<"\tClass B builded\n"; 
		//cout << "FROM B: X is " << x << "\n";
	}
	~B() {
		delete _aPtr;
		cout <<"\t~Class B Destroyed\n";
	};
	void print() const {
		cout << "B-print"<<endl;
	}
	B(const B &obj)
	{
		_aPtr = new A(obj._aPtr->getX());
	}
private:
	A* _aPtr;
	//Me mme;
};
//====================================================================
class C : public B {
public:
	C(){cout << "C - def const\n";}
	C(int x) : B(x) { 
		cout <<"\tClass C builded\n"; 
		//cout << "FROM C: X is " << x << "\n";
	}
	void print() const {
		cout << "C-print"<<endl;
	}
	void print1() const {
		cout << "C-print 1"<<endl;
	}
	~C(){
		cout <<"\t~Class C Destroyed\n";
	}

};

int main() {
	C c1=7;
	//c1.print();
	//Me wasup;
	//C c2(c1);
	//c2.print();
	B* bPtr = &c1;
	bPtr->print();
}