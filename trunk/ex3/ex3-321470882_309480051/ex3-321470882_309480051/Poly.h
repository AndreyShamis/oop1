// A class that reprisent Polynom.

#pragma once

//                               Include section
//=============================================================================
//#include "macros.h"
#include <vector>
#include <iostream>

//                               Structur section
//=============================================================================
// Difine bomb stractur.
struct Monom
{
	double scalar;
	int	power;

};

class Poly
{
//                               Function section
//=============================================================================
public:

	Poly(double coeffs[], unsigned int arrSize);
	Poly(); // Defaul constractor
	Poly(Poly *otherPoly); // Copy constractor.
	Poly(double &scal);
	//Poly(double X[], double Y[], int n);
	Poly(const struct Monom &value);

	Poly operator+(Poly &otherPoly);
	Poly operator+=(Poly &otherPoly);
	Poly operator=(Poly &otherPoly);
	Poly operator*(Poly &otherPoly);
	Poly operator*=(Poly &otherPoly);

	void print();

private:

	





//                              veribel section
//=============================================================================

	std::vector <Monom> polynom;	


};