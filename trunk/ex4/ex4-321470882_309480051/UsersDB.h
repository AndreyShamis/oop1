#pragma once
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

#define DEFAULT_DB_NAME "db.txt"
#define PAS				'!'
struct User
{
	string		_name;
	string		_pass;
	bool		_locked;
	bool		_admin;
	short int	_invalid_login;

};

class UsersDB
{
public:
	static UsersDB* getInstance();
	int validateUser(string userName,string password);
	bool isLocked(string userName);
	bool isAdmin(string userName);
	int addUser(string newUserName,string newPassword);
	int removeUser(string newUserName);
	int lockUser(string newUserName);
	int unlockUser(string newUserName);
	int resetUserPassword(string newUserName);
	int getAllUsers(int &numOfUsers,string *users);
	int getLockedUsers(int &numOfUsers,string *users);
	
private:
	bool createDB();
	string sham(string input);
	static UsersDB* _instance;

	
	
	struct	User Select(string userName);
	bool	Insert(const struct User &user);
	bool	Delete(const struct User &user);
	short int getUserTypebyLockedAdmin(const short int locked,
										const short int admin);

	void dbUsrTypToProg(const int inp,bool &locked,bool &admin);

	struct User dbStrToStruct(string db_string);

protected:
	UsersDB();
};
