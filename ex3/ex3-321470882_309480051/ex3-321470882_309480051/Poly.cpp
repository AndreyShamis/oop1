// A class that reprisent polynom.
// This class rialize operators that will be usefull at work with polynoms.
// Also that class have 6 different constractors wihc allow to creat the
// polynom in many differente ways.

//                               Include section
//=============================================================================
#include "Poly.h"

//                               Function section
//=============================================================================

//                                 Distractor:
//#############################################################################

// Distractor that clear the polynom vector and distract Poly objetc.
//=============================================================================
Poly::~Poly()
{
	polynom.clear();
}


//                                Constractors:
//#############################################################################

// Default constractor. Also used as Constractor of Zero polynom.
// Zero polyno it is vector with no cells. in other words: if vector size equal
// to zero - it is mean that it is Zero polynom.
//=============================================================================
Poly::Poly()
{
	;
}

// Constractor that create monom (polynom with one monom).
//=============================================================================
// Input: single monom (struct monom type).
Poly::Poly(const struct Monom &value)
{
	polynom.push_back(value);
}


// Constractor that create polynom through coeffs and polynom degree.
//=============================================================================
// Input: Array of coeffs and dgree of the polynom.
Poly::Poly(double coeffs[], unsigned int arrSize)
{
	// Loop through array cells to fill vector with coeffs and powers.
	for(unsigned int i = 0; i < arrSize; i++)
	{
		// Ignor scalas that equal to zero - don't save them at vector.
		if(coeffs[i] != 0)	
		{
			
			Monom tempMonom;					// Difine temp monom.
			tempMonom.scalar = coeffs[i];		// difine curent scalar.
			tempMonom.power = arrSize - i - 1;	// difine curent power.
			polynom.push_back (tempMonom);		// push temp monom to his 									
		}										// corect place at vector.
	}	
}

// Copy constractor.
//=============================================================================
// Input: get other polynom.
Poly::Poly(Poly &otherPoly)                     
{
        polynom = otherPoly.polynom;
}

// Scalar polynom constractor. Creat polynom wich is singl scalar.
//=============================================================================
// Input: Scalar. 
Poly::Poly(double &scal)
{
	Monom tempMonom;				// Difine temp monom.
	tempMonom.scalar = scal;		// put scalar to monom.
	tempMonom.power = 0;			// put power zero to power monom.
	polynom.push_back(tempMonom);	// push temp monom to his 									
									// corect place at vector.	
}

// Lagrange Constractor. Create polynom through interpolation method.
//=============================================================================
// Input: Interpulation points (to arrays of points x and y) and get degree + 1
// of polynom. (actialy it is number of points that user give).
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
				//the precudure of multiply parse the sub-function to two parts
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
	
	} // Update current polynom.
	polynom = sumPoly.polynom;
}



//                                Operators:
//#############################################################################

// Operator "+" overloading. Suming polinoms.
//=============================================================================
// Input: Other polynom.
// Output: Sum of curent polynom and other polynom.
Poly Poly::operator+(const Poly &otherPoly)
{
	// Creat polynom obje that will save temp sum of temp calculation.
	Poly sumPoly = Poly();	

	int thisIndex = 0, otherIndex = 0;	// Difine loops indexs of both polynoms
	
	// Loop thruogh both polynoms. And orgonaze monoms by power to sum polynom.
	while(thisIndex < (int)polynom.size() && otherIndex < 
		 (int)otherPoly.polynom.size())
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
		//sum monoms that have equal powers.
		else
		{
			Monom tempMonom;	// Difine temp monom.
			tempMonom.scalar = polynom[thisIndex].scalar +		// Sum scalars.
							   otherPoly.polynom[otherIndex].scalar;
			tempMonom.power = polynom[thisIndex].power;

			if(tempMonom.scalar)	//	if the power not zero
				sumPoly.polynom.push_back(tempMonom );

			thisIndex ++;
			otherIndex ++;
		}
	}
	// When one of the polynom ends (polynom was shortly that ater polynom).
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
	// Rrturn Polynom that contain sum of polynoms that was sumed.
	return (sumPoly);

}

// Operator "+=" overloading. Suming polinoms.
//=============================================================================
// Input: Oter polynom.
// Output: Curent update polynom.
Poly Poly::operator+=(const Poly &otherPoly)
{
	*this = *this + otherPoly;	// using "+" operator.
	return (*this);
}

// Operator "=" overloading. Surface polynoms.
//=============================================================================
// Input: Other polynom.
Poly Poly::operator=(const Poly &otherPoly)
{
	polynom = otherPoly.polynom;	// Copy other polynom to curent polynom.

	return *this;
}

// Operator "*" overloading. Multiply polinoms.
//=============================================================================
// Input: Other polynom.
// Output: Multiple of curent polynom and other polynom.
Poly Poly::operator*(const Poly &otherPoly)
{
	// Creat polynom obje that will save temp sum of temp calculation.
	Poly sumPoly = Poly();

	// Difine temp monom.
	Monom tempMonom;

	// Loop through curent polynom.
	for(int thisIndex = 0; thisIndex < (int)polynom.size(); thisIndex++)
	{	
		// Loop through other polynom.
		for(int otherindex = 0; otherindex < (int)otherPoly.polynom.size(); 
			otherindex++)
		{	
			// Multiple tow monoms from both  polynoms. (multiple scalars and
			// sum powers.
			tempMonom.power = polynom[thisIndex].power + 
							  otherPoly.polynom[otherindex].power;

			tempMonom.scalar = polynom[thisIndex].scalar *
							   otherPoly.polynom[otherindex].scalar;
	
			// Create polynom object that will save multiple calculation.
			Poly mulMonom = Poly(tempMonom);

			// Sum temp multiple.
			sumPoly += mulMonom;
		}
	}
	// Rrturn Polynom that contain sum of multiples of monoms from polynoms.
	return (sumPoly);

}

// Operator "*=" overloading. Multiply polinoms.
//=============================================================================
// Input: Oter polynom.
// Output: Curent update polynom.
Poly Poly::operator*=(const Poly &otherPoly)
{
	*this = *this * otherPoly; //usung "*" and "=" operators. 
	return(*this);
}

// Operator "<<" overloading. Allows to print polynoms to STD.
//=============================================================================
// Input: ostream obj and other polynom obj.
// Uotput: Ostream obj to chaining.
std::ostream& operator<<(std::ostream& pout,const Poly &otherPoly)
{
	Monom tempMonom;	// Difine temp monom.

	int polySize = otherPoly.getSize(); // Difine polynom size.

	if(!polySize)						// if it is Zero polynom - Print "0".

		pout << "0";

	// Otherwise, Loop throug polynom monoms and print each monom.
	for(int index = 0; index < polySize; index++)
	{
		tempMonom = otherPoly.getMonom(index);

		if(tempMonom.scalar > 0 && index != 0)
		{
			pout << "+";		
		}
		pout << tempMonom.scalar;		// Print scalar.

		if(tempMonom.power > 1)
		{
			pout << "*x^" << tempMonom.power; // Print power.
		}

		if(tempMonom.power == 1)
		{
			pout << "*x"; 
		}
	}
	pout << "\n";
	
	// Retur ostream obj.
	return pout;
}

// Operator "()" overloading. Operator that get x value and resive f(x) value.
//=============================================================================
double Poly::operator()(const double &x) const
{
	int polySize = getSize();	// Difine polynom size.

	if(!polySize)				// if it is Zero polynom - Print "0".

		return (0);				// retur "0" because f(x) = 0.

	double fx = 0;

	// Otherwise, Loop throug polynom monoms and "put x value instead x"
	for(int index = 0; index < polySize; index++)
	{
		fx += polynom[index].scalar * pow(x ,polynom[index].power);
	}
	return(fx);		// Return f(x) value.
}

// Operator "==" (comperation) overloading. Comper to polynoms.
//=============================================================================
// Input: Other polynom.
bool Poly::operator==(const Poly &otherPoly)const
{
	if(comperPoly(otherPoly))	// if the polynoms equal - return true.

		return true;

	return false;				// Otherwise return false.
}

// Operator "!=" (comperation) overloading. Comper to polynoms.
//=============================================================================
// Input: Other polynom.
bool Poly::operator!=(const Poly &otherPoly)const
{
	if(!comperPoly(otherPoly))	// if the polynoms NOT equal - return true.

		return true;

	return false;				// Otherwise return false.
}


//                            Maintenence.
//#############################################################################

//=============================================================================
bool Poly::comperPoly(const Poly &otherPoly) const
{
	Monom otherMonom;	// Difine temp monom.
	
	int polySize = getSize();	// Difine polynom size.

	// if the polynoms have the same sizes. if not return false.
	if(otherPoly.getSize() == polySize)	
	{
		// Loop through polynoms and comper each pare of monoms.
		for(int index = 0; index < polySize; index++)
		{
			otherMonom = getMonom(index); // Get next monom from other polynom.

			// If the sequential monoms not equal - return false. 
			if(polynom[index].scalar != otherMonom.scalar ||
				polynom[index].power  != otherMonom.power)
			
				return false;
		}
		// Otherwise return true. (mean that all monoms is equal).
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
//	END getSiz