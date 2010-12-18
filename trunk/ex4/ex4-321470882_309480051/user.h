#pragma once
#include <string>
using namespace std;
//	struct User provide full information about one user
struct UserStruct
{
	string		_name;			//	user name
	string		_pass;			//	user pass
	bool		_locked;		//	if locked true=yes
	bool		_admin;			//	if admin true = yes
	short int	_invalid_login;	//	number of incorect trys to login

};
class User
{
public:
	User();
	User(const string UserName);
	User operator=(const User &otherUser);
	bool operator==(const User &otherUser);
	struct UserStruct _user;
	string getName();
	string getPass();
	void setIncreaseInvalidLogin();
	void setLocked();
	void setPass(const string NewPass);
	bool getLockStatus();
	bool getAdmin();
	void setUnLocked();
	void Login();
	unsigned int getNumberInvalidLogin();
protected:
};
