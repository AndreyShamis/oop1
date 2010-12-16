#include "UsersDB.h"

UsersDB* UsersDB::_instance = NULL;

UsersDB* UsersDB::getInstance()
{
	if(_instance == NULL)
	{
		_instance = new UsersDB;
	}

	return _instance;
}
UsersDB::UsersDB()
{
	cout << "Lol\n";
}
//=============================================================================
int UsersDB::lockUser(string newUserName)
{
	return(1);
}

//=============================================================================
short int UsersDB::getUserTypebyLockedAdmin(const short int locked,
											const short int admin)
{
/*
	locked  admin	result
		0   0		0
		0   1		1
		1   0		2
		1   1		3
*/
	if(!locked && !admin)
		return(0);
	else if(!locked && admin)
		return(1);
	else if(locked && !admin)
		return(2);
	else if(locked && admin)
		return(3);

	return(0);
}

struct User UsersDB::Select(string userName)
{
	ifstream myReadFile;
	
	myReadFile.open(DEFAULT_DB_NAME);
	string line_data;
	string name_data;


	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile >> line_data;

			if(myReadFile.fail())
				break;

			if(line_data.find(name_data+PAS))
			{
				dbStrToStruct(line_data);
			}

		}
	}

	myReadFile.close();
	struct User user;
	return(user);
}

struct User UsersDB::dbStrToStruct(string db_string)
{
	int start=0;
	int counter = 0;
	string data[4];
	struct User user;

	for(unsigned int i=0;i<db_string.length();i++)
	{
		if(db_string[i] == PAS)
		{
			data[counter] = db_string.substr(start,i-start);
			//if(!counter)
			//	cout << "-----"<<data[counter] << "\n";
			
			start=i+1;
			counter++;
		}
	}

	user._name = data[0];
	user._pass = "******";
	user._invalid_login = (int)data[2][0]-48;
	dbUsrTypToProg((int)data[3][0] - 48,user._locked,user._admin);
	return(user);
}

//=============================================================================
int UsersDB::addUser(string newUserName,string newPass)
{
	
	struct User newUser;
	newUser._admin			=	0;
	newUser._invalid_login	=	0;
	newUser._locked			=	0;
	newUser._name			=	newUserName;
	newUser._pass			=	sham(newPass);

	if(Insert(newUser))
		return(1);
	else
		return(0);
}
void dbUsrTypToProg(const int inp,short int &locked,short int &admin)
{
/*
	locked  admin	result
		0   0		0
		0   1		1
		1   0		2
		1   1		3
*/
	switch(inp)
	{
	case 0:
		locked	=	0;
		admin	=	0;
		break;
	case 1:
		locked	=	0;
		admin	=	1;
		break;
	case 2:
		locked	=	1;
		admin	=	0;
		break;
	case 3:
		locked	=	1;
		admin	=	1;
		break;
	}
}

//=============================================================================
bool UsersDB::Insert(const struct User &user)
{
	string save_str;
	string h_pass = sham(user._pass);
	char invalid_login = (char)(user._invalid_login+48);
	short int accss_t = getUserTypebyLockedAdmin(user._locked,user._admin);

	save_str=user._name+PAS+h_pass+PAS+"0"+PAS+(char)(accss_t+48);

	ofstream myfile;
	myfile.open(DEFAULT_DB_NAME,ios::app);               
	myfile << save_str << "\n";
	myfile.close();

	return true;
}
//=============================================================================
int UsersDB::validateUser(string userName,string password)
{
	return(1);
}
//=============================================================================
int UsersDB::isLocked(string userName)
{
	Select(userName);
	return(0);
}
//=============================================================================
int UsersDB::isAdmin(string userName)
{
	return(1);
}
//=============================================================================
int UsersDB::removeUser(string newUserName)
{
	return(1);
}
//=============================================================================
int UsersDB::unlockUser(string newUserName)
{
	return(1);
}
//=============================================================================
int UsersDB::resetUserPassword(string newUserName)
{
	return(1);
}
//=============================================================================
int UsersDB::getAllUsers(int &numOfUsers,string *users)
{
	return(1);
}
//=============================================================================
int UsersDB::getLockedUsers(int &numOfUsers,string *users)
{
	return(1);
}
//=============================================================================
bool UsersDB::createDB()
{

 
 
  ofstream myfile;
  myfile.open (DEFAULT_DB_NAME,ios::app);               
  myfile << "Writing this to a file.\n";
  myfile << "000";            
  myfile.close();
  return true;
}

//=============================================================================
string UsersDB::sham(string input)
{
	int input_size = input.length();

	for(int i=0;i<input_size;i++)
	{
		int val = (int)input[i];
		if(val%2==0)
			val=val*val;
		else if(val%3==0)	
			val=val/2;
		else if(val%5==0)	
			val=val*input_size;
		else if(val%7==0)	
			val=val+(input_size*input_size);
		else if(val%11==0)	
			val=1;
		else
			val=(val+7)/2;


		val = val%256;

		if(val <34)
			val+=34;

		//		cout << " " << val;
		input[i] = (char)val;
	}
	//cout << "\n" << input << "\n";
	//cout << "\nIn :" << input_size  << "\n";

	return(input);
}
//=============================================================================
//=============================================================================
//=============================================================================