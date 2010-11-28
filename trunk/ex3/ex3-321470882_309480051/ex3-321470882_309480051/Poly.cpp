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

Poly::Poly(double X[], double Y[], int n)
{
	int i,j;
	Poly sumPoly = Poly();

	for(i=0;i<n;i++)
	{
		double temp_d[2];// = {0,1};
		//Poly yi = Poly(temp_d,2);

		temp_d[0] =0;
		temp_d[1] =Y[i];
		Poly ya = Poly(temp_d,2);

		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				double x1,x2 ;
				x1 =X[i]-X[j]; 
				if(x1)
					x1 = 1/x1;
				
				x2 =X[i]-X[j]; 

				if(x2)
					x2 = X[j] /x2;

				x2=x2*(-1);

				temp_d[0] = x1;
				temp_d[1] = x2;
				Poly temp =Poly(temp_d,2);
				ya*=temp;
			}
		}
		sumPoly+= ya;//*yi;
		//f = f + L*Y[i];
	}
	polynom=sumPoly.polynom;
	//*this = sumPoly;

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