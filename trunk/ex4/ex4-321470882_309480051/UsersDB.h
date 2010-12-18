#pragma once
#include <list>
#include <string>
#include "file.h"
#include "user.h"

using namespace std;




#define ADMIN_NAME		"admin"
#define ADMIN_PASS		"1234"
#define PAS				' '			//	between string in DB
#define BUFFER_SIZE		1000		//	bufer size
#define DEFAULT_USER_PASSWORD	"1111"



//	class UsersDB
class UsersDB
{
public:
	static UsersDB* getInstance();
//=============================================================================
//	function to validate user
//	get username and user Password
//	return	1	if saccess	/0	not saccess	/-1	some error
	int validateUser(const string userName,const string password);
	bool isLocked(const string userName);
	bool isAdmin(const string userName);
//=============================================================================
//	Add user to DB. Geting strings NewUserName And Password
//	return	1	if saccess	/0	not saccess	/-1	some error
	int addUser(const string newUName,const string newPassword);

//=============================================================================
//	function to remove user from db
//	get username
//	return	1	if saccess	/0	not saccess	/-1	some error
	int removeUser(const string UserName);

//=============================================================================
//	function to lock User
//	get username
//	return	1	if saccess	/0	not saccess	/-1	some error
	int lockUser(const string UserName);

//=============================================================================
//	function to unlock
//	get username
//	return	1	if saccess	/0	not saccess	/-1	some error
	int unlockUser(const string UserName);

	int resetUserPassword(const string UserName);
	int getAllUsers(int &numOfUsers,string *&users);
	int getLockedUsers(int &numOfUsers,string *&users);

private:
	//bool createDB();
	string sham(string input);
	static UsersDB* _instance;

protected:
	list <User> _users;
	User *Select(const string userName);
	bool	LoadList();
	bool	Insert(User user);
//=============================================================================
//	Function wich deleteing user from db by user name
//	get username will be delete
//	return true if saccess and false if not
	bool	Delete(const string usrName);

	int		getUsersCount();
	UsersDB();
	//	fill locked and admin from inp which was geted from DB
	void dbUsrTypToProg(const int inp,bool &locked,bool &admin);
	//	function which fill the stuct User from string which was
	//	returned from db. return struct User
	struct UserStruct dbStrToStruct(string db_string);
	//	convert locked and admin to one number to save in DB
	short int getLokAdm(const short int locked,const short int admin);

	bool SaveDB();
	string UserToString(User &user);

//=============================================================================
//	function to unlock / unlock user status
//	get username and new value 
//	return	1	if saccess	/0	not saccess	/-1	some error
	short int ChangeLockStat(const string uName,const bool &Stat);

};
