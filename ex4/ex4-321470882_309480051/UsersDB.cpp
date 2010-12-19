#include "UsersDB.h"

UsersDB* UsersDB::_instance = NULL;

//=============================================================================
//	singleton :: getInsatnce of sigleton
//	if object not created create him
UsersDB* UsersDB::getInstance()
{
	if(_instance == NULL)
		_instance = new UsersDB;

	return _instance;

}

//=============================================================================
//	function to lock
//	geting username
//	return	1	if saccess / 0	not saccess /-1	some error
int UsersDB::lockUser(const string UserName)
{
	//	call ti function which know to change lock unlock status
	return(ChangeLockStat(UserName,true));

}
//=============================================================================
//	function to unlock
//	geting username
//	return	1	if saccess / 0	not saccess /-1	some error
int UsersDB::unlockUser(const string UserName)
{
	//	call to function which know change lock/unlock status
	return(ChangeLockStat(UserName,false));

}

//=============================================================================
//	Default constractor:	Loading database from txt file
UsersDB::UsersDB()
{
	LoadList();				//	load data from db to main mem
}

//=============================================================================
//	Add user to DB. Geting strings NewUserName And Password
//	return	1	if saccess
//			0	not saccess
//			-1	some error	
int UsersDB::addUser(const string newUName,const string newPass)
{

	User newUser(newUName);			//	create object User
	newUser.setPass(sham(newPass));	//	set pass for him	
	
	//	check if user name or pass size smaller than 4 or user name eq to admin
	if(newUName.length()<4 || newPass.length()<4 || newUName == "admin")
		return(0);
	
	//	fin user by name
	User *user_exist = Select(newUName);
	//	if wasnt found return NULL,check and insert
	if(user_exist == NULL && Insert(newUser))
	{
		if(SaveDB())			//	save changes
			return(1);			//	if changes saccess
		else
			return(-1);			//	if fail to write changes
	}
	else
		return(0);				//	if user exest return 0

	
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
	User *user = Select(userName);
	
	short int	return_flag = false;

	//	compare between Name and Password
	if(userName == ADMIN_NAME && password == ADMIN_PASS)
		return(1);
	else if(user == NULL)
		return(0);		//	if user not found
	//	compare between input data to what was found
	else if(userName == user->getName()&& userName != ADMIN_NAME)
	{	//	compare password
		if(sham(password) == user->getPass())
		{
			user->Login();		//	udpate number of incorect logins to 0
			return_flag=1;		//	if good compare return true
		}
		else
		{
			//	increase incorect login counter
			user->setIncreaseInvalidLogin();
			//	check if the counter more than 2 and lock user
			if(user->getNumberInvalidLogin()>=3)
				user->setLocked();

			return_flag=0;		//	incorect password
		}
		if(SaveDB())			//	try save changes
			return(return_flag);//	return result of validate
		else
			return(-1);			//	if write error
	}

	return(-1);
}

//=============================================================================
//	function which check if the user locked
//	function get user name
//	return true if locked and return false if not
bool UsersDB::isLocked(const string userName)
{
	//	try find user by name
	User *user = Select(userName);
	
	//	check if found and Lock Status
	if(user != NULL && user->getLockStatus()) 	
		return(true);					//	return locked
	
	return(false);						//	return not locked

}

//=============================================================================
//	function which check if the user is admin
//	function get user name
//	return true if admin and return false if not
bool UsersDB::isAdmin(const string userName)
{
	//	try to find user in data base
	User *user = Select(userName);
	
	//	check if the user is admin(by name) or if found and have admin stat
	if((user==NULL && userName == ADMIN_NAME) 
		|| (user!=NULL && user->getAdmin())	)
		return(true);						//	return admin

	return(false);							//	return not admin
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
	{
		if(SaveDB())	//	if saccess write changes return 1
			return(1);

		return(-1);		//	if fail to write return -1
	}
	
	return(0);			//	if user not exist return 0

}

//=============================================================================
//	function to unlock / unlock user status
//	get username and new value 
//	return	1	if saccess
//			0	not saccess
//			-1	some error
short int UsersDB::ChangeLockStat(const string uName,const bool &Stat)
{

	//	try to find user by name
	User *user = Select(uName);	

	if(user != NULL)			//	check if user exits
	{
		if(Stat)				//	if need to lock
			user->setLocked();	//	lock
		else
			user->setUnLocked();//	unlock
		
		if(SaveDB())			//	try to save changes
			return(1);
			
		return(-1);				//	fail write changes
	}
		
	return(0);					//	user not exist

}


//=============================================================================
//	function which reset user password to default password
//	return	1	if saccess
//			0	not saccess
//			-1	some error
int UsersDB::resetUserPassword(const string UserName)
{	
	//	try to find user by name
	User *user = Select(UserName);
	
	if(user!= NULL)
	{
		//	reset password to default
		user->setPass(sham(DEFAULT_USER_PASSWORD));
		if(SaveDB())			//	try to write changes
			return(1);			//	return true if saccess to wtite

		return(-1);				//	error ocured in write
	}
		
	return(0);					//	user not exist


}
//=============================================================================
//	function which return in pointer reference all users 
//	also update the counter
int UsersDB::getAllUsers(int &numOfUsers,string *&users)
{
	//	get size of db
	numOfUsers = getUsersCount();
	
	//	if size  == 0 return 0 - users not found
	if(numOfUsers == 0)
		return(0);

	//	try allocate memory
	users = new(nothrow)string[numOfUsers];
	
	//	if fail allocate memory
	if(users == NULL)
		return(-1);	   //	return error

	list <User>::iterator it;				//	set iterator for for
	int i = 0;								//	counter for aaray
	for(it=_users.begin();it!=_users.end();it++)
	{
		users[i] = (*it).getName();			//	copy name
		i++;								//	increase counter
	}
	return(1);								// returnb if users was found

}
//=============================================================================
//	 TODO MEMORY
int UsersDB::getLockedUsers(int &numOfUsers,string *&users)
{
	numOfUsers = getUsersCount();
	
	if(numOfUsers == 0)
		return(0);

	users = new(nothrow)string[numOfUsers];
	
	if(users == NULL)
		return(-1);

	list <User>::iterator it;
	int i = 0;
	for(it=_users.begin();it!=_users.end();it++)
	{
		if((*it).getLockStatus())
		{
			users[i] = (*it).getName();
			i++;
		}
	}
	numOfUsers = i;
	return(1);
}


//=============================================================================
//	function to crypt passwords	get password
//	return crypted password
string UsersDB::sham(string input)
{
	//	get input string size
	int input_size = input.length();

	for(int i=0;i<input_size;i++)
	{
		int val = (int)input[i];	//	convert char to int
		
		//	mathematical manipulations whith char
		val=(val*2)+1;
		val = val%(127-34);
		if(val <34)
			val+=34;
		//	convert int back to char
		input[i] = (char)val;
	}

	return(input);						//	return value
}

//=============================================================================
//	function which know insert new user into database
bool UsersDB::Insert(User user)
{
	_users.push_back(user);			//	insert into list

	return true;					//	every time return true but for future
}

//=============================================================================
int	UsersDB::getUsersCount()
{
	return((int)_users.size());
}
//=============================================================================
//	Function wich deleteing user from db by user name
//	get username will be delete
//	return true if saccess and false if not
bool UsersDB::Delete(const string usrName)
{
	User *user = Select(usrName);
	if(user == NULL)
		return(false);

	list <User>::iterator it;
	for(it=_users.begin();it!=_users.end();it++)
	{
		if((*it) == *user)
		{
			_users.remove((*it));
			return(true);
		}
	}	
	
	return(false);
	
}

bool UsersDB::SaveDB()
{
	
	ofstream	output;				//	output stream
	output.open(TEMP_DB_NAME,ios.app);	//	open file for output

	//	check if saccess to open file
	if (output.is_open()) 
	{
		list <User>::iterator it;

		for(it=_users.begin();it!=_users.end();it++)
		{
			string write = UserToString(*it);
			output << write << "\n";	//	write to output file;
		}
	
	}
	else
		return(false);						//	can not open files
	
	//	close file
	output.close();
	//	delete old db file
	remove(DEFAULT_DB_NAME);
	//	rename old db to correct db name
	rename(TEMP_DB_NAME,DEFAULT_DB_NAME);

	//	return true
	return(true);
	
}
bool UsersDB::LoadList()
{
	file filedb;
	if(!filedb.CheckDB())
	{
		filedb.createDB();
		if(!filedb.CheckDB())
			return(false);
	}
	ifstream myReadFile;		
	myReadFile.open(DEFAULT_DB_NAME);

	
	string line_data;
	User user;
	string *temp = NULL;
	char buf[BUFFER_SIZE];
	int numOfUsers = 0;
	
	if (myReadFile.is_open()) 
	{
		while (!myReadFile.eof()) 
		{
			myReadFile.getline(buf,BUFFER_SIZE);	
			line_data = buf;
			if(myReadFile.fail())
				break;
			numOfUsers++;
			//struct UserStruct user_str = ; 
			user = dbStrToStruct(line_data);
			_users.push_back(user);
		}
	}
	else
		return(false);

	myReadFile.close();
	
	return(true);

}
string UsersDB::UserToString(User &user)
{
	string					save_str;
	char inlog			=	(char)(user.getNumberInvalidLogin()+48);
	short int accss_t	=	getLokAdm(user.getLockStatus(),user.getAdmin());
	
	save_str=user.getName()+PAS+
		user.getPass()+PAS+
		inlog+PAS+
		(char)(accss_t+48)+PAS;
	
	return(save_str);
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


User *UsersDB::Select(const string userName)
{
	User *user = NULL;
	list <User>::iterator it;
	for(it=_users.begin();it!=_users.end();it++)
	{
		if((*it).getName() == userName)
		{
			user = &(*it);
			break;
		}
	}
	
	return(user);
}

User UsersDB::dbStrToStruct(const string db_string)
{
	int start=0;
	int counter = 0;
	string data[4];
	
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


	//user.setName();
	//user.setPass(data[1]);
	//user.set = ;
	bool LockStat;
	bool AdminStat;
	dbUsrTypToProg((int)((char)data[3][0])- 48,LockStat,AdminStat);

	User user(data[0],data[1],(int)data[2][0]-48,LockStat,AdminStat);
	return(user);
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
//=============================================================================
//=============================================================================
//=============================================================================
