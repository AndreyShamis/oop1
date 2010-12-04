// A class that reprisent polynom .

//                               Include section
//=============================================================================
#include "Poly.h"

//                               Function section
//=============================================================================


Poly::~Poly()
{
	polynom.clear();
}


// Poly class constractor
//=============================================================================
Poly::Poly()
{
	;
}

//=============================================================================
Poly::Poly(const struct Monom &value)
{
	polynom.push_back(value);
}


//=============================================================================
// constractor   
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

//=============================================================================
// Copy constractor.  TODO-- test
Poly::Poly(Poly &otherPoly)			
{
	polynom = otherPoly.polynom;
}

//=============================================================================
// Scalar polynom constractor 
Poly::Poly(double &scal)
{
	Monom tempMonom;

	tempMonom.scalar = scal;
	tempMonom.power = 0;

	polynom.push_back(tempMonom);
}

//=============================================================================
// Constractor Lagrange
// Using formula of lagrange:
// <math> f(x) = \frac{x-x_b}{x_a-x_b} y_a - \frac{x-x_a}{x_a-x_b} y_b </math>
Poly::Poly(double X[], double Y[], int n)
{
	int j, k; // Indexes of the formula.

	// Create new empty polynom object that summarize sub polynoms.
	Poly sumPoly = Poly();

	//	enter to first cycle of Y
	for(j = 0; j < n; j++)
	{
		double temp_d[2];			//	temorary variable used twice in Y cycle

		//	set array to plynom 0*x + Y[j]
		temp_d[0] =0;				
		temp_d[1] =Y[j];
		
		//	create polynom with previous data and size 2
		Poly multiplyPoly = Poly(temp_d,2);

		//	enter to second cycle of multiply
		for(k = 0; k < n; k++)
		{
			//	do this section where j != k
			if(j != k)
			{
				//	the precudure of multiply parse the sub-function to two parts
				double x1, x2 ;
				//	this is first part of sub-function
				x1 = X[j] - X[k]; 
				if(x1)				//	check if can devide 
					x1 = 1 / x1;	//	deviding
				
				//	second part of sub-function
				x2 = X[j]-X[k]; 

				if(x2)				//	check if can devide
					x2 = X[k] / x2;	//	deviding
				//	the sub-function looks like first part minus second part
				//	so here we convert the second part to minus
				x2 = x2 * (-1);
				
				//	create array with data which we geted previsously
				temp_d[0] = x1;	
				temp_d[1] = x2;
				//	create polynom whith array was created
				Poly temp = Poly(temp_d, 2);
				multiplyPoly *= temp;			//	multiply the result to Y[]
			}
		}
		//	sum the results of all multiplys
		sumPoly += multiplyPoly;
	
	}
	polynom = sumPoly.polynom;
}


//=============================================================================
// Relouded of operator "+" for class poly.
Poly Poly::operator+(const Poly &otherPoly)
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

			if(tempMonom.scalar)	//	if the power not zero
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

//=============================================================================
//// Relouded of operator "+=" for class poly.
Poly Poly::operator+=(const Poly &otherPoly)
{
	//Poly temp; 
	*this = *this + otherPoly;
	return (*this);
}

//=============================================================================
// Relouded of operator "=" for class poly.
Poly Poly::operator=(const Poly &otherPoly)
{
	polynom = otherPoly.polynom;

	return *this;
}

//=============================================================================
//// Relouded of operator "*" for class poly.
Poly Poly::operator*(const Poly &otherPoly)
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

			Poly mulMonom = Poly(tempMonom);
			sumPoly += mulMonom;
		}
	}
	return (sumPoly);

}

//=============================================================================
// Relouded of operator "*=" for class poly.
Poly Poly::operator*=(const Poly &otherPoly)
{
	*this = *this * otherPoly;
	return(*this);
}

//=============================================================================
std::ostream& operator<<(std::ostream& pout,const Poly &otherPoly)				//TODO const
{
	Monom tempMonom;
	int polySize = otherPoly.getSize();

	for(int index = 0; index < polySize; index++)
	{
		tempMonom = otherPoly.getMonom(index);

		if((int)tempMonom.scalar > 0 && index != 0)
		{
			pout << "+";
		}
		pout << tempMonom.scalar;

		if(tempMonom.power > 1)
		{
			pout << "*x^" << tempMonom.power;
		}

		if(tempMonom.power == 1)
		{
			pout << "*x";
		}
	}
	
	pout << endl;
	
	return pout;
}

//=============================================================================
double Poly::operator()(const double &x) const
{
	int polySize = getSize();

	if(!polySize)

		return (0);

	double fx = 0;

	for(int index = 0; index < polySize; index++)
	{
		fx += polynom[index].scalar * pow(x ,polynom[index].power);
	}

	return(fx);
}

//=============================================================================
bool Poly::operator==(const Poly &otherPoly)const
{
	if(comperPoly(otherPoly))

		return true;

	return false;
}

//=============================================================================
bool Poly::operator!=(const Poly &otherPoly)const
{
	if(!comperPoly(otherPoly))

		return true;

	return false;
}


//=============================================================================
bool Poly::comperPoly(const Poly &otherPoly) const
{
	Monom otherMonom;
	
	int polySize = getSize();
	if(otherPoly.getSize() == polySize)
	{
		for(int index = 0; index < polySize; index++)
		{
			otherMonom = getMonom(index);
			if(polynom[index].scalar != otherMonom.scalar ||
				polynom[index].power  != otherMonom.power)
			{
				return false;
			}	
		}
		return true;
	}
	return false;
}




//=============================================================================
//	fucntion which return Monom struct from vector by index
//	which is geyed in parameters to call function
Monom Poly::getMonom(const int &index) const
{
	return(polynom[index]);
}
//	END getMonom

//=============================================================================
//	function which return the size of vector
//	needed for compare the vector size in for cycles
//	between integr to value which fuction vector.size() return is unsigned
int Poly::getSize() const
{
	return((int)polynom.size());
}
//	END getSize