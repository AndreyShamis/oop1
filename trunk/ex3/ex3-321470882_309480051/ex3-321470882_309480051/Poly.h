// A class that reprisent Polynom.

#pragma once

//                               Include section
//=============================================================================
//#include "macros.h"
#include <vector>
#include <iostream>
#include <cmath> //

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
	//friend std::ostream& operator<<(std::ostream& pout, Poly &otherPoly);			//TODO const


//                               Function section
//=============================================================================
public:

	Poly(double coeffs[], unsigned int arrSize);
	Poly(); // Defaul constractor
	Poly(Poly *otherPoly); // Copy constractor.
	Poly(double &scal);
	Poly(double X[], double Y[], int n);
	Poly(const struct Monom &value);
	
	friend std::ostream& operator<<(std::ostream& pout, Poly &otherPoly);			//TODO const
	Poly operator+(Poly &otherPoly);
	Poly operator+=(Poly &otherPoly);
	Poly operator=(Poly &otherPoly);
	Poly operator*(Poly &otherPoly);
	Poly operator*=(Poly &otherPoly);
	double operator()(double x);
	bool operator==(Poly &otherPoly);
	bool operator!=(Poly &otherPoly);

	void print();
	Monom getMonom(int index);
	int Poly::getSize();
	bool comperPoly(Poly &otherPoly);


private:


//                              veribel section
//=============================================================================

	std::vector <Monom> polynom;	


};