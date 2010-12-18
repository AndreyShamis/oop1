#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#define DEFAULT_DB_NAME "db.txt"	//	Default DB
#define PAS				' '			//	between string in DB
#define BUFFER_SIZE		1000		//	bufer size

#define ADMIN_NAME		"admin"
#define ADMIN_PASS		"1234"

#define DEFAULT_USER_PASSWORD	"1111"
#define TEMP_DB_NAME			"temp.txt"
//	struct User provide full information about one user
struct User
{
	string		_name;			//	user name
	string		_pass;			//	user pass
	bool		_locked;		//	if locked true=yes
	bool		_admin;			//	if admin true = yes
	short int	_invalid_login;	//	number of incorect trys to login

};

//	class UsersDB
class UsersDB
{
public:
	static UsersDB* getInstance();
//=============================================================================
//	function to validate user
//	get username and user Password
//	return	1	if saccess
//			0	not saccess
//			-1	some error
	int validateUser(const string userName,const string password);
	bool isLocked(const string userName);
	bool isAdmin(const string userName);
	int addUser(const string newUName,const string newPassword);

//=============================================================================
//	function to remove user from db
//	get username
//	return	1	if saccess
//			0	not saccess
//			-1	some error
	int removeUser(const string UserName);

//=============================================================================
//	function to lock User
//	get username
//	return	1	if saccess
//			0	not saccess
//			-1	some error
	int lockUser(const string UserName);

//=============================================================================
//	function to unlock
//	get username
//	return	1	if saccess
//			0	not saccess
//			-1	some error
	int unlockUser(const string UserName);

	int resetUserPassword(const string UserName);
	int getAllUsers(int &numOfUsers,string *&users);
	int getLockedUsers(int &numOfUsers,string *&users);
	
private:
	bool createDB();
	string sham(string input);
	static UsersDB* _instance;

	


	//	convert locked and admin to one number to save in DB
	short int getLokAdm(const short int locked,
										const short int admin);

	//	fill locked and admin from inp which was geted from DB
	void dbUsrTypToProg(const int inp,bool &locked,bool &admin);
	//	function which fill the stuct User from string which was
	//	returned from db. return struct User
	struct User dbStrToStruct(string db_string);

	string UserToString(const struct User &user);


protected:
	UsersDB();

//=============================================================================
//	function to unlock / unlock user status
//	get username and new value 
//	return	1	if saccess
//			0	not saccess
//			-1	some error
	short int ChangeLockStat(const string uName,const bool &Stat);
};
