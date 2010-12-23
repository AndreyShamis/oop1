#include "file.h"

//=============================================================================
// fanction that create data base.
// return true if created, othewise retern faqlse.
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
// fanction wichek if data base exist
// if exist - return true, othewise retern faqlse.
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

