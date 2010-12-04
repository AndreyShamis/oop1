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

