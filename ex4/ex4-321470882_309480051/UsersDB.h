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

//=============================================================================
//	
	static UsersDB* getInstance();
//=============================================================================
	void destroyInsatnce();
//=============================================================================
//	function to validate user
//	get username and user Password
//	return	1	if saccess	/0	not saccess	/-1	some error
	int validateUser(const string &userName,const string &password);

//=============================================================================
//	function which check if the user locked
//	function get user name
//	return true if locked and return false if not
	bool isLocked(const string &userName);

//=============================================================================
//	function which check if the user is admin
//	function get user name
//	return true if admin and return false if not
	bool isAdmin(const string &userName);
//=============================================================================
//	Add user to DB. Geting strings NewUserName And Password
//	return	1	if saccess	/0	not saccess	/-1	some error
	int addUser(const string &newUName,const string &newPassword);

//=============================================================================
//	function to remove user from db
//	get username
//	return	1	if saccess	/0	not saccess	/-1	some error
	int removeUser(const string &UserName);

//=============================================================================
//	function to lock User
//	get username
//	return	1	if saccess	/0	not saccess	/-1	some error
	int lockUser(const string &UserName);

//=============================================================================
//	function to unlock
//	get username
//	return	1	if saccess	/0	not saccess	/-1	some error
	int unlockUser(const string &UserName);

//=============================================================================
//	function which reset user password to default password
//	return	1	if saccess /0	not saccess/	-1	some error
	int resetUserPassword(const string &UserName);

//=============================================================================
//	function which return in pointer reference all users 
//	also update the counter
	int getAllUsers(int &numOfUsers,string *&users);
//=============================================================================
//	 Function which return all users are locked , by referense
//	and number of them also by reference
	int getLockedUsers(int &numOfUsers,string *&users);
	
	//	encrupt algorithm
	string sham(const string &input);

	static UsersDB* _instance;

protected:

//=============================================================================
//	 Find user by name Return pointer to user
	User *Select(const string &userName);
//=============================================================================
//	 Load database from text file to main memory
	bool	LoadList();
//=============================================================================
//	function which know insert new user into database
	bool	Insert(const User &user);

//=============================================================================
//	Function wich deleteing user from db by user name
//	get username will be delete
//	return true if saccess and false if not
	bool	Delete(const string &usrName);
//=============================================================================
//	return number of users counted in data base
	int		getUsersCount()const;
//=============================================================================
//	constructor
	UsersDB();

//=============================================================================
//	destructor
	~UsersDB();

//=============================================================================
//	Convert the digit geted from DB to lock status and admin status
//	Get the db value in first parameter and return lock status
//	and admin status in refrenses
	void dbUsrTypToProg(const int &inp,bool &locked,bool &admin)const;
	
//	function which fill the Class User from string which was
//	returned from db. return struct User
	User dbStrToClass(const string &db_string);
	
	//	convert locked and admin to one number to save in DB
	short int getLokAdm(const short int &locked,const short int &admin);
//=============================================================================
//	Save data base from memory to data base text
	bool SaveDB();

//=============================================================================
//	 Covert class object to string for saving in data base
	string UserToString(const User &user);

//=============================================================================
//	function to unlock / unlock user status
//	get username and new value 
//	return	1	if saccess	/0	not saccess	/-1	some error
	short int ChangeLockStat(const string &uName,const bool &Stat);

	list <User> _users;		//	list of users
};
