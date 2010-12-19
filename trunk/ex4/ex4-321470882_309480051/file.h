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
	file();
	bool CheckDB();
	bool createDB();
protected:
};
