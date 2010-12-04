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
	double	scalar;
	int		power;

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
	
	friend std::ostream& operator<<(std::ostream& pout,const Poly &otherPoly);			//TODO const
	Poly operator+(const Poly &otherPoly);
	Poly operator+=(const Poly &otherPoly);
	Poly operator=(const Poly &otherPoly);
	Poly operator*(const Poly &otherPoly);
	Poly operator*=(const Poly &otherPoly);
	double operator()(const double &x)const ;
	bool operator==(const Poly &otherPoly)const;
	bool operator!=(const Poly &otherPoly)const;

	void print();

	


private:
	bool comperPoly(const Poly &otherPoly)const;
	int Poly::getSize() const;
	Monom getMonom(const int &index) const;
//                              veribel section
//=============================================================================

	std::vector <Monom> polynom;	


};


//void updateGlobals(const Poly &lPoly)
//{
//	int i = 0;
//	//minX =0;
//	//minY =0;
//	//maxY=0;
//	//minY=0;
//	for(i = 0 ;i < 20; i++)
//	{
//		//X[counter] = counter;
//		graphX[i] = (i-10);
//		graphY[i] = lPoly(i - 10);
//		X[i] = (i-10);
//		Y[i] = lPoly(i - 10);
//
//		cout << graphX[i] << "       "  << graphY[i] << endl; 
//
//		//Y[counter] = counter * counter;
//
//		//minX = min(minX,graphX[i]);
//		//maxX = max(maxX,graphX[i]);
//
//		//minY = min(minY,graphY[i]);
//		//maxY = max(maxY,graphY[i]);
//
//
//
//
//
//	}
//	minX = 15;
//	maxX = 15; 
//
//	minY = -15;
//	maxY = -15;
//
//	numPoints = 30;
//	
//}

//
//bool readDataFromUser()
//{
//	//double input;
//	int counter = 0;
//	bool FLAG = false;
//
//	
//	for(counter =0;counter<MAX_INPUT;counter++)	{
//		//cin >> input;
//		X[counter] = counter;
//		//counter++;
//	}
//
//	numPoints = counter;
//	return 0;
//}