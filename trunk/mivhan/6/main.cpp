#include <iostream>

using namespace std;


class Array1D
{
public:
	Array1D(){
		cout << "Array 1 D is loaded\n";
		//Array2D::_array
	}

	int& operator[](int i)
	{ 
	cout << "sdasds\n";
		if(i<0||i>=sizeof(*this)) 
			exit(1);
		
	return (*this)[i]; 
	}	
};
class Array2D :public Array1D{
public:
Array2D(int n,int m);
    	int*& operator[](int i);
private:
    	int **_array;
int _n,_m;
};

Array2D::Array2D(int n, int m) : _array(new int*[n]),_n(n),_m(m){
    	for(int i=0; i<n;i++)
      	_array[i] = new int[m];
}

int*& Array2D:: operator[](int i){ 
if(i<0||i>=_n) 
		exit(1);
return _array[i]; 
}


//int operator[](int *arr,const int &x)
//{
//	if(x >= sizeof(arr))
//		exit(1);
//	else
//		return(arr[x]);
//}

int main() {
Array2D ar(4,5);
    	ar[2][3] = 17;
    	cout << ar[2][3] << endl;
		ar[2][15] = 18; 
		delete [] ar[2];
		ar[2] = new int[3];
		ar[2][4] = 18;
    	cout << ar[2][3] << endl;
}
