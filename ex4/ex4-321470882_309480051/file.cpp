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

void file::CloseFile(ifstream &myReadFile)
{
	myReadFile.close();
}
file::file(void)
{
	;
}

file::~file(void)
{
	;
}

