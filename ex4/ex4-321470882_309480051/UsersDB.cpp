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
//	function to lock
//	get username
//	return	1	if saccess
//			0	not saccess
//			-1	some error
int UsersDB::lockUser(const string UserName)
{
	//	call ti function which know to change lock unlock status
	return(ChangeLockStat(UserName,true));
}

//=============================================================================
short int UsersDB::getLokAdm(const short int locked,
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

struct User UsersDB::Select(const string userName)
{
	ifstream myReadFile;
	
	myReadFile.open(DEFAULT_DB_NAME);
	string line_data;
	struct User user;
	char buf[BUFFER_SIZE];

	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile.getline(buf,BUFFER_SIZE);	//	TODO
		
			line_data = buf;
			if(myReadFile.fail())
				break;
			size_t found = line_data.find(userName+PAS);
			if(found!=string::npos)
			{
				user = dbStrToStruct(line_data);
				break;
			}

		}
	}

	myReadFile.close();
	
	return(user);
}

struct User UsersDB::dbStrToStruct(const string db_string)
{
	int start=0;
	int counter = 0;
	string data[4];
	struct User user;
	unsigned int str_len = db_string.length();
	for(unsigned int i=0;i<str_len;i++)
	{
		if(db_string[i] == PAS)
		{
			data[counter] = db_string.substr(start,i-start);
			start=i+1;
			counter++;
		}
	}

	user._name = data[0];
	user._pass = data[1];
	user._invalid_login = (int)data[2][0]-48;
	dbUsrTypToProg((int)((char)data[3][0])- 48,user._locked,user._admin);
	return(user);
}

//=============================================================================
int UsersDB::addUser(const string newUName,const string newPass)
{
	
	struct User newUser;
	newUser._admin			=	0;
	newUser._invalid_login	=	0;
	newUser._locked			=	0;
	newUser._name			=	newUName;
	newUser._pass			=	sham(newPass);
	
	if(newUName.length()<4 || newPass.length()<4 || newUName == "admin")
		return(0);

	struct User user_exist = Select(newUName);
	
	if(user_exist._name == "" && Insert(newUser))
		return(1);
	else
		return(0);

	return(-1);
}
void UsersDB::dbUsrTypToProg(const int inp,bool &locked,bool &admin)
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
		locked	=	false;
		admin	=	false;
		break;
	case 1:
		locked	=	false;
		admin	=	true;
		break;
	case 2:
		locked	=	true;
		admin	=	false;
		break;
	case 3:
		locked	=	true;
		admin	=	true;
		break;
	}
}

string UsersDB::UserToString(const struct User &user)
{
	string					save_str;
	char inLog			=	(char)(user._invalid_login+48);
	short int accss_t	=	getLokAdm(user._locked,user._admin);
	
	save_str=user._name+PAS+user._pass+PAS+inLog+PAS+(char)(accss_t+48)+PAS;
	
	return(save_str);
}
//=============================================================================
bool UsersDB::Insert(const struct User &user)
{

	ofstream myfile;
	myfile.open(DEFAULT_DB_NAME,ios::app);               
	myfile << UserToString(user) << "\n";
	myfile.close();

	return true;
}
//=============================================================================
//	Function wich deleteing user from db by user name
//	get username will be delete
//	return true if saccess and false if not
bool UsersDB::Delete(const string usrName)
{
	ifstream	input;				//	input stream	
	ofstream	output;				//	output stream
	char		buf[BUFFER_SIZE];	//	bufer for reading

	struct User	user			=	Select(usrName);	//	get user to struct

	if(user._name == "")
		return(false);

	string		userToDelete	=	UserToString(user);	//	covert to string
	

	input.open(DEFAULT_DB_NAME);		//	open file for reading
	output.open(TEMP_DB_NAME,ios.app);	//	open file for output

	//	check if saccess to open both files
	if (input.is_open() && output.is_open()) 
	{
		while (!input.eof())				//	while not end of file		
		{
			input.getline(buf,BUFFER_SIZE);	//	read line to bufer
			string readed = buf;			//	convert char* to string
			//	if this not who we want delete and it`s not empty line
			if(userToDelete != readed && readed != "")
				output << readed << "\n";	//	write to output file
		}
	}
	else
		return(false);						//	can not open files
	
	//	close both files
	input.close();
	output.close();
	//	delete old db file
	remove(DEFAULT_DB_NAME);
	//	rename old db to correct db name
	rename(TEMP_DB_NAME,DEFAULT_DB_NAME);

	//	return true
	return(true);
	
}
//=============================================================================
//	function to validate user
//	get username and user Password
//	return	1	if saccess
//			0	not saccess
//			-1	some error
int UsersDB::validateUser(const string userName,const string password)
{
	//	get User struct by name
	struct User user = Select(userName);
	short int	return_flag = false;

	//	compare between Name and Password
	if(userName == ADMIN_NAME && password == ADMIN_PASS)
		return(1);
	else if(userName == user._name && userName != ADMIN_NAME)
	{
		if(sham(password) == user._pass)
		{
			user._invalid_login = 0;
			return_flag=1;		//	if good compare return true
		}
		else
		{
			user._invalid_login+=1;
			if(user._invalid_login>=3)
				user._locked = true;

			return_flag=0;
		}
		Delete(userName); 
		Insert(user);

		return(return_flag);
	}
	else
		return(0);

	return(-1);			//	another

}
//=============================================================================
bool UsersDB::isLocked(const string userName)
{
	struct User user = Select(userName);

	if(user._locked && userName != ADMIN_NAME)
		return(true);
	
	return(false);

}
//=============================================================================
bool UsersDB::isAdmin(const string userName)
{
	struct User user = Select(userName);

	if(user._admin || userName == ADMIN_NAME)
		return(true);

	return(false);

}

//=============================================================================
//	function to remove user from db
//	get username
//	return	1	if saccess
//			0	not saccess
//			-1	some error
int UsersDB::removeUser(const string UserName)
{
	if(Delete(UserName))
		return(1);
	else
		return(0);

	return(-1);
}

//=============================================================================
//	function to unlock / unlock user status
//	get username and new value 
//	return	1	if saccess
//			0	not saccess
//			-1	some error
short int UsersDB::ChangeLockStat(const string uName,const bool &Stat)
{
	struct User user = Select(uName);	//	get user struct

	if(user._name != "")			//	check if user exits
	{
		user._locked	=	Stat;	//	set new value
		if(Delete(uName) && Insert(user))	//	delete old user instance
			return(1);						//	and insert new instance
	}
	else if(user._name == "")		//	if user not exist
		return(0);

	return(-1);						//	other 

}

//=============================================================================
//	function to unlock
//	get username
//	return	1	if saccess
//			0	not saccess
//			-1	some error
int UsersDB::unlockUser(const string UserName)
{
	//	call to function which know change lock/unlock status
	return(ChangeLockStat(UserName,false));

}
//=============================================================================
int UsersDB::resetUserPassword(const string UserName)
{	
	struct User user = Select(UserName);

	if(user._name != "")
	{
		user._pass = sham(DEFAULT_USER_PASSWORD);
		if(Delete(UserName) && Insert(user))
			return(1);
	}
	else if(user._name == "")
		return(0);

	return(-1);

}
//=============================================================================
int UsersDB::getAllUsers(int &numOfUsers,string *&users)
{
	ifstream myReadFile;		

	myReadFile.open(DEFAULT_DB_NAME);
	string line_data;
	struct User user;
	string *temp = NULL;
	char buf[BUFFER_SIZE];

	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile.getline(buf,BUFFER_SIZE);	
		
			line_data = buf;

			if(myReadFile.fail())
				break;

			numOfUsers++;
			user = dbStrToStruct(line_data);
			
			temp = new  string[numOfUsers];
			if(temp == NULL)
				return(-1);
			for(int i=0;i<numOfUsers-1;i++)
			{
				temp[i] = users[i];
				
			}
			temp[numOfUsers-1] = user._name;
			
			delete [] users;
			users = temp;
			temp = NULL;
		

		}
	}
	else
		return(0);

	myReadFile.close();
	
	return(1);
}
//=============================================================================
int UsersDB::getLockedUsers(int &numOfUsers,string *&users)
{
	ifstream myReadFile;		

	myReadFile.open(DEFAULT_DB_NAME);
	string line_data;
	struct User user;
	string *temp = NULL;
	char buf[BUFFER_SIZE];

	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile.getline(buf,BUFFER_SIZE);	
		
			line_data = buf;

			if(myReadFile.fail())
				break;

			user = dbStrToStruct(line_data);
			if(user._locked)
			{
				numOfUsers++;
				temp = new  string[numOfUsers];
				if(temp == NULL)
					return(-1);

				for(int i=0;i<numOfUsers-1;i++)
					temp[i] = users[i];
				
				temp[numOfUsers-1] = user._name;
				
				delete [] users;
				users = temp;
				temp = NULL;
			}			

		}
	}

	myReadFile.close();
	
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
		
		val=(val*2)+1;
		val = val%(127-34);
		if(val <34)
			val+=34;
		input[i] = (char)val;
	}

	return(input);
}
//=============================================================================
//=============================================================================
//=============================================================================