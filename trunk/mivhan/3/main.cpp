#include <iostream>
#include <vector>

using namespace std;

class kelim
{
public:
	virtual void print(){};
private:


};
class Mavreg:public kelim
{
public:
		void print()
		{
			cout << "Mavreg";
		}
private:


};


class Patish:public kelim
{

public:
			void print()
		{
			cout << "Patish";
		}
private:


};
class Argaz :public kelim
{
public:
	Argaz(int MAX_SLOTS)
	{
		_MAX_TOOLS=MAX_SLOTS;
	}

	void print()
	{
		cout << "(Argaz: ";
		for(int x=0;x<(int)_kelim.size();x++)
		{
			_kelim[x]->print();
			cout << "|";
		}
		cout << ")";
	}

	void insert(kelim &obj)
	{

		if((int)_kelim.size() < _MAX_TOOLS && typeid(obj) != typeid(Argaz)  )
				//&& (&obj) != this )                              // VERY IMPORTANT
			_kelim.push_back(&obj) ;		
		else
			cout << "Try to insert to self\n";
	}

private :
	int _MAX_TOOLS;
	vector <kelim*> _kelim;

};



int main() {
	Argaz argaz1(7),argaz2(5),argaz3(1);
//  'argaz' can contain up to 7/5/1 tools  
	
Patish patish1, patish2; 
	Mavreg mavregim[4];

	for (int i=0;i<2;i++) {
		argaz1.insert(mavregim[i]); 
		argaz2.insert(mavregim[i+2]);
	}
	argaz2.insert(patish1);
	argaz2.insert(patish2);
 	argaz2.insert(argaz3);
	
	argaz3.insert(argaz3);	
// output: "Try to insert the 'Argaz' to itself (action aborted)"
	
	argaz1.print();			
// output: "(Argaz: Mavreg|Mavreg|)"

	cout << endl;
	argaz2.print();			
// output: "(Argaz: Mavreg|Mavreg|Patish| (Argaz: ) |)"

	cout << endl;
	argaz3.print();	
// output: "(Argaz: )"

	cout << "\n";
}
