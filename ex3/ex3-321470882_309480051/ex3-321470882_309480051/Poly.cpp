// A class that reprisent polynom.

//                               Include section
//=============================================================================
#include "Poly.h"

//                               Function section
//=============================================================================


// Poly class constractor
//=============================================================================
//Poly::Poly()

// Copy constractor
Poly::Poly(double coeffs[], unsigned int arrSize)
{
	for(unsigned int i = 0; i < arrSize; i++)
	{
		if(coeffs[i] != 0)	
		{
			Monom tempMonom;

			tempMonom.scalar = coeffs[i];
			tempMonom.power = arrSize - i - 1;

			polynom.push_back (tempMonom);
		}
	}	
}

// Copy constractor.
Poly::Poly(Poly *otherPoly)
{
	polynom = otherPoly->polynom;
}

// Scalar polynom constractor 
Poly::Poly(double &scal)
{
	Monom tempMonom;

	tempMonom.scalar = scal;
	tempMonom.power = 0;

	polynom.push_back(tempMonom);
}

//Poly::Poly(double X[], double Y[], int n)
//{
//	double f = 0;
//	int i,j;
//	for(i=0;i!=n;++i)
//	{
//		double L = 1.0;
//		for(j=0;j!=n;++j)
//	 
//			if(i!=j) 
//				L = L *(xx-x[j])/(x[i]-x[j]);
//
//		f = f + L*Y[i];
//	}


// Relouded of operator "+" for class poly.
Poly Poly::operator+(Poly *otherPoly)
{
	Poly sumPoly = Poly();

	int thisIndex = 0, otherIndex = 0;

	while(thisIndex < (int)polynom.size() && otherIndex < (int)otherPoly->polynom.size())
	{
		if(polynom[thisIndex].power > otherPoly->polynom[otherIndex].power)
		{
			sumPoly.polynom.push_back(polynom[thisIndex]);
			thisIndex ++;
		}
		else if(polynom[thisIndex].power < otherPoly->polynom[otherIndex].power)
		{
			sumPoly.polynom.push_back(otherPoly->polynom[otherIndex]);
			otherIndex ++;
		}
		else
		{
			Monom tempMonom;

			tempMonom.scalar = polynom[thisIndex].scalar + 
							   otherPoly->polynom[otherIndex].scalar;
			tempMonom.power = polynom[thisIndex].power;
			sumPoly.polynom.push_back(tempMonom );

			thisIndex ++;
			otherIndex ++;
		}
	}

	while(thisIndex < (int)polynom.size())
	{
		sumPoly.polynom.push_back(polynom[thisIndex]);

		thisIndex ++;
	}
	while(otherIndex < (int)otherPoly->polynom.size())
	{
		sumPoly.polynom.push_back(otherPoly->polynom[otherIndex]);

		otherIndex ++;
	}
	return (sumPoly);

}

// Relouded of operator "+=" for class poly.
Poly Poly::operator+=(Poly *otherPoly)
{
	return(this + *otherPoly);
}

// Relouded of operator "=" for class poly.
Poly Poly::operator=(Poly *otherPoly)
{
	polynom = otherPoly->polynom;

	return *this;
}

// Relouded of operator "*" for class poly.
Poly Poly::operator*(Poly *otherPoly)
{
	Poly sumPoly = Poly();
	Poly mulMonom = Poly();

	Monom tempMonom;

	for(int thisIndex = 0; thisIndex < (int)polynom.size(); thisIndex++)
	{
		for(int otherindex = 0; otherindex < (int)otherPoly->polynom.size(); 
			otherindex++)
		{
			tempMonom.power = polynom[thisIndex].power + 
							  otherPoly->polynom[otherindex].power;

			tempMonom.scalar = polynom[thisIndex].scalar *
							   otherPoly->polynom[otherindex].scalar;

			mulMonom.polynom.push_back(tempMonom);

			sumPoly += mulMonom;
		}
	}
	return (sumPoly);

}

// Relouded of operator "*=" for class poly.
Poly Poly::operator*=(Poly *otherPoly)
{
	return(this * *otherPoly);
}

//Poly Poly::operator<<(Poly *otherPoly)				//TODO