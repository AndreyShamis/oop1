// A class that reprisent polynom .
// This class rialize operators that will be usefull at work with polynoms.
// Also that class have 6 different constractors wihc allow to creat the
// polynom in many differente ways.



//                               Include section
//=============================================================================
#include <vector>
#include <iostream>
#include <cmath> 
#pragma once

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

	Poly(double coeffs[], unsigned int arrSize); // By coeffs constractor 
	Poly();										// Defaul constractor/polynom 0
	Poly(Poly &otherPoly);						// Copy constractor.
	Poly(double &scal);							// Scalar constractor
	Poly(double X[], double Y[], int n);		// Lagrange Constractor
	Poly(const struct Monom &value);			// Monom constractor 
	~Poly();									// Distractor.
	
	// Polynoms operator <<
	friend std::ostream& operator<<(std::ostream& pout,const Poly &otherPoly);
	Poly operator+(const Poly &otherPoly);		// Polynoms operator +
	Poly operator+=(const Poly &otherPoly);		// Polynoms operator +=
	Poly operator=(const Poly &otherPoly);		// Polynoms operator =
	Poly operator*(const Poly &otherPoly);		// Polynoms operator *
	Poly operator*=(const Poly &otherPoly);		// Polynoms operator =*
	double operator()(const double &x)const ;	// Polynoms operator ()
	bool operator==(const Poly &otherPoly)const;// Polynoms operator ==
	bool operator!=(const Poly &otherPoly)const;// Polynoms operator !=

private:

	bool comperPoly(const Poly &otherPoly)const;	// Comper to polynoms.
	int Poly::getSize() const;						// Get number of monoms
	Monom getMonom(const int &index) const;			// Get i monom from Polynom

//                              veribel section
//=============================================================================
	
	// Difine Polynom vector. Each "box" contain monom.
	std::vector <Monom> polynom;	
};


