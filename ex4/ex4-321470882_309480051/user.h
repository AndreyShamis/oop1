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
	User(const string &UserName);
	User(const string &UName,const string &uPass,const short int &invLogins,
		const bool &locked,const bool &admin);
	User operator=(const User &otherUser);
	bool operator==(const User &otherUser)const;
	string getName()const;
	string getPass()const;
	void setIncreaseInvalidLogin();
	void setLocked();
	void setName(const string &newName);
	void setPass(const string &NewPass);
	bool getLockStatus()const;
	bool getAdmin()const;
	void setUnLocked();
	void Login();

	unsigned int getNumberInvalidLogin()const;
protected:

	struct UserStruct _user;
};
