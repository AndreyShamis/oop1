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
	//poly(); // Defaul constractor
	Poly(Poly *otherPoly); // Copy constractor.
	poly(double &scal);
	Poly(double X[], double Y[], int n);


private:

	Poly operator+(Poly *otherPoly);
	Poly operator+=(Poly *otherPoly);
	Poly operator=(Poly *otherPoly);
	Poly operator*(Poly *otherPoly);
	Poly operator*=(Poly *otherPoly);



//                              veribel section
//=============================================================================

	std::vector <Monom> polinom;	


};