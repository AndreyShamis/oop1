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
	A(int x) : _xPtr(new int(x)),mme() {
		cout <<"\tClass A builded\n";
		cout << "FROM A: X is " << x << "\n";
		cout << "FROM A: X-pointer is " << *_xPtr << "\n";
	}

	~A() {
		delete _xPtr;cout <<"\t~Class A Destroyed\n";
	}

private:					
	Me mme;
	int* _xPtr;

};
//====================================================================
class B {
public:
	B(int x) : _aPtr(new A(x)),mme() {
		cout <<"\tClass B builded\n"; 
		cout << "FROM B: X is " << x << "\n";
	}
	~B() {
		delete _aPtr;cout <<"\t~Class B Destroyed\n";
	};
	void print() const {
		cout << "B-print"<<endl;
	}
private:
	A* _aPtr;
	Me mme;
};
//====================================================================
class C : public B {
public:
	C(int x) : B(x) { 
		cout <<"\tClass C builded\n"; 
		cout << "FROM C: X is " << x << "\n";
	}
	void print() const {
		cout << "C-print"<<endl;
	}
	~C(){
		cout <<"\t~Class C Destroyed\n";
	}
};

int main() {
	C c1(7);
	//c1.print();
	//Me wasup;
	C c2(c1);
	//B* bPtr = &c1;
	//bPtr->print();
}