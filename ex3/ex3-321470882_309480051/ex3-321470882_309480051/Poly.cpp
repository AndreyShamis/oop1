// A class that reprisent polynom.

//                               Include section
//=============================================================================
#include "Poly.h"

//                               Function section
//=============================================================================

using namespace std;


// Poly class constractor
//=============================================================================
Poly::Poly()
{
	;
}


Poly::Poly(const struct Monom &value)
{
	polynom.push_back(value);
}




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


// Constractor Lagrange
// Using formula of lagrange:
// <math> f(x) = \frac{x-x_b}{x_a-x_b} y_a - \frac{x-x_a}{x_a-x_b} y_b </math>
Poly::Poly(double X[], double Y[], int n)
{
	int j, k; // Indexes of the formula.

	// Create new empty polynom object that summarize sub polynoms.
	Poly sumPoly = Poly();


	for(j = 0; j < n; j++)
	{
		double temp_d[2];


		temp_d[0] =0;
		temp_d[1] =Y[j];
		Poly ya = Poly(temp_d,2);

		for(k = 0; k < n; k++)
		{
			if(j != k)
			{
				double x1, x2 ;
				x1 = X[j] - X[k]; 
				if(x1)
					x1 = 1 / x1;
				
				x2 = X[j]-X[k]; 

				if(x2)
					x2 = X[k] / x2;

				x2 = x2 * (-1);

				temp_d[0] = x1;
				temp_d[1] = x2;
				Poly temp = Poly(temp_d, 2);
				ya *= temp;
			}
		}
		sumPoly += ya;
	
	}
	polynom = sumPoly.polynom;
}

// Relouded of operator "+" for class poly.
Poly Poly::operator+(Poly &otherPoly)
{
	Poly sumPoly = Poly();

	int thisIndex = 0, otherIndex = 0;

	while(thisIndex < (int)polynom.size() && otherIndex < (int)otherPoly.polynom.size())
	{
		if(polynom[thisIndex].power > otherPoly.polynom[otherIndex].power)
		{
			sumPoly.polynom.push_back(polynom[thisIndex]);
			thisIndex ++;
		}
		else if(polynom[thisIndex].power < otherPoly.polynom[otherIndex].power)
		{
			sumPoly.polynom.push_back(otherPoly.polynom[otherIndex]);
			otherIndex ++;
		}
		else
		{
			Monom tempMonom;

			tempMonom.scalar = polynom[thisIndex].scalar + 
							   otherPoly.polynom[otherIndex].scalar;
			tempMonom.power = polynom[thisIndex].power;
			if(tempMonom.scalar)
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
	while(otherIndex < (int)otherPoly.polynom.size())
	{
		sumPoly.polynom.push_back(otherPoly.polynom[otherIndex]);

		otherIndex ++;
	}
	return (sumPoly);

}
//
//// Relouded of operator "+=" for class poly.
Poly Poly::operator+=(Poly &otherPoly)
{
	//Poly temp; 
	*this = *this + otherPoly;
	return (*this);
}

// Relouded of operator "=" for class poly.
Poly Poly::operator=(Poly &otherPoly)
{
	polynom = otherPoly.polynom;

	return *this;
}
//
//// Relouded of operator "*" for class poly.
Poly Poly::operator*(Poly &otherPoly)
{
	Poly sumPoly = Poly();
	

	Monom tempMonom;

	for(int thisIndex = 0; thisIndex < (int)polynom.size(); thisIndex++)
	{
		for(int otherindex = 0; otherindex < (int)otherPoly.polynom.size(); 
			otherindex++)
		{
			tempMonom.power = polynom[thisIndex].power + 
							  otherPoly.polynom[otherindex].power;

			tempMonom.scalar = polynom[thisIndex].scalar *
							   otherPoly.polynom[otherindex].scalar;

			//double *arr = new double[tempMonom.power+1];
			//memset(arr,0,(tempMonom.power+1) * sizeof(double));
			//arr[0] = tempMonom.scalar;
			//Poly mulMonom = Poly(arr,tempMonom.power+1);
			Poly mulMonom = Poly(tempMonom);
			//delete arr;
			sumPoly += mulMonom;
		}
	}
	return (sumPoly);

}

// Relouded of operator "*=" for class poly.
Poly Poly::operator*=(Poly &otherPoly)
{
	*this = *this * otherPoly;
	return(*this);
}

////Poly Poly::operator<<(Poly *otherPoly)				//TODO



void Poly::print()
{
	for(int i=0; i < (int)polynom.size(); i++)
	{
		std::cout << polynom[i].scalar<< "^" << polynom[i].power <<" ";
	}

	if(! (int)polynom.size())
		cout << "0";
	cout << endl;
}