#include "file.h"

//=============================================================================
bool file::createDB()
{ 
	ofstream myfile;
	myfile.open (DEFAULT_DB_NAME,ios::app);
	if(myfile.is_open())
	{
		myfile.close();
		return(true);
	}	
	return (false);

}

bool file::CheckDB()
{
	ifstream myfile;
	myfile.open (DEFAULT_DB_NAME);
	if(myfile.is_open())
	{
		myfile.close();
		return(true);
	}	
	return (false);

}

file::file(void)
{
	;
}
