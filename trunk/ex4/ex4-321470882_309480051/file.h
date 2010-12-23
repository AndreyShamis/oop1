#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define DEFAULT_DB_NAME "db.txt"	//	Default DB
#define TEMP_DB_NAME			"temp.txt"

class file
{
public:
	// fanction that create data base.
	// return true if created, othewise retern faqlse.
	bool CheckDB();

	// fanction wichek if data base exist
	// if exist - return true, othewise retern faqlse.
	bool createDB();
protected:
};
