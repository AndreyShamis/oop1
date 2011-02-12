#include <iostream>
#include <math.h>
using namespace std;


class A {
public:
	A( int x=0,int y=0,int z=0);
	void set( int x,int y,int z );
	int& getX();
private:
	int _x,_y,_z;
};

A::A( int x,int y,int z ) { set(x,y,z); }
void A::set( int x,int y,int z ){
	x = ( x>0 ? x : 1 ); 
y = ( y>0 ? y : 1 ); 
z = ( z>0 ? z : 1 );
}
int& A::getX() { return _x; }

class B {
public:
	B( int x=0,int y=0,int z=0 );
	A getA();
private:
	A _a;
};

B::B( int x,int y,int z ) : _a( x,y,z ) {} 
A B::getA() { return _a; }

class C {
public:
	C( A* aPtr );
	A* getAPtr();
private:
	A* _aPtr;
};

C::C( A* aPtr ) : _aPtr(aPtr) {} 
A* C::getAPtr() { return _aPtr; }


class Point {
public:
	Point( double x=0,double y=0 );
	double xVal()const;
	double yVal()const;
	void set( double x,double y );
	double norm();
private:
	double _x,_y;
};

Point::Point( double x,double y ) : _x(x),_y(y) {}
double Point::xVal()const { return _x; }
double Point::yVal()const { return _y; }
void Point::set( double x,double y ) { _x=x; _y=y; }
double Point::norm() { return sqrt(_x*_x+_y*_y); }

double dist( const Point& p1,const Point& p2 ) {



	const double xx = p1.xVal()-p2.xVal();
	const double yy = p1.yVal()-p2.yVal();

	const double x = xx*xx;
	const double y = yy*yy;
	return(sqrt( x+y) );
}

int main() {
	/*
תאריך:8.5.09
מרצה: מיכל אלחנתי
מתרגל: יצחק שמידמאיר
משך הבחינה: שלוש שעות.
המבחן בחומר סגור.

ענו על כל שלוש השאלות הבאות. הקפידו על כתיבה קצרה, ובהירה. הוסיפו תיעוד קצר (אפשר בעברית) בתשובות המכילות קטעי קוד:(33 נקודות) נתון הקוד הבא:
*/
	A array[10];
	for ( int i=0;i<10;i++ )
		array[i].getX() = i;

	//===============
	/*
א.	(8 נקודות) האם הקוד תקין? נמקו.

*/
	Point zero;
	zero.set(2,2); //*
	cout << zero.xVal() << "\n";
	Point p(3,4);
	cout << dist(p,zero) << endl; //**

}
