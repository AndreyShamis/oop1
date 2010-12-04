// A class that reprisent Polynom.

#pragma once

//                               Include section
//=============================================================================
//#include "macros.h"
#include <vector>
#include <iostream>
#include <cmath> //

using namespace std;
//                               Structur section
//=============================================================================
// Difine bomb stractur.
struct Monom
{
	double	scalar;
	int		power;

};

class Poly
{

//                               Function section
//=============================================================================
public:
	friend std::ostream& operator<<(std::ostream& pout,const Poly &otherPoly);			//TODO const

	Poly(double coeffs[], unsigned int arrSize);
	Poly(); // Defaul constractor
	Poly(Poly &otherPoly); // Copy constractor.
	Poly(double &scal);
	~Poly();
	Poly(double X[], double Y[], int n);
	Poly(const struct Monom &value);
	
	Poly operator+(const Poly &otherPoly);
	Poly operator+=(const Poly &otherPoly);
	Poly operator=(const Poly &otherPoly);
	Poly operator*(const Poly &otherPoly);
	Poly operator*=(const Poly &otherPoly);
	double operator()(const double &x)const ;
	bool operator==(const Poly &otherPoly)const;
	bool operator!=(const Poly &otherPoly)const;

private:
	bool comperPoly(const Poly &otherPoly)const;
	int Poly::getSize() const;
	Monom getMonom(const int &index) const;
//                              veribel section
//=============================================================================

	std::vector <Monom> polynom;	


};

//bool readDataFromUser()
//{
//	int index;
//	char chr;
//	numPoints = 0;
//
//	cout << "Please enter X values for interpulation" << endl  
//		 << "(Each value separated with space)" << endl << endl
//		 << "For example: x1 x2 x3 x4 'Enter'" << endl
//		 << "             y1 y2 y3 y4 'Enter'" << endl 
//		 << "(REMEBER! Number of Y points must be equal to the number of X points)" << endl << endl;
//
//	for(index = 0; index < MAX_INPUT; index++)
//	{
//		chr = cin.get();
//
//		if(!checkDouble(chr))
//			break;
//
//		cin.putback(chr);
//		cin >> X[index];
//		numPoints++; 
//	}
//
//	cout << "Please enter X values for interpulation" << endl  
//		 << "(Each value separated with space)" << endl << endl
//		 << "For example: y1 y2 y3 y4 'Enter'" << endl
//		 << "(REMEBER! Number of Y points must be equal to the number of X points)" << endl << endl;
//
//	for(index = 0; index < numPoints; index++)
//	{
//		chr = cin.get();
//
//		if(!checkDouble(chr))
//			break;
//
//		cin.putback(chr);
//		cin >> Y[index];
//	}
//	return 1;
//}
