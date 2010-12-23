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
	User();							//	default constructor
	User(const string &UserName);	//	constructor by name
	User(const string &UName,const string &uPass,const short int &invLogins,
		const bool &locked,const bool &admin);
	User operator=(const User &otherUser);	//	operator = overloading
	bool operator==(const User &otherUser)const;	//	operator == overloading
													//	binary comapre
	string getName()const;							//	return user name
	string getPass()const;			//	function to set password
	void setIncreaseInvalidLogin();	//	function which increase the invalid 
									//  login counter by 1
	void setLocked();				//	lock user
	void setName(const string &newName);	//	return user name
	void setPass(const string &NewPass);	//	function to set password
	bool getLockStatus()const;				//	return lock status
	bool getAdmin()const;					//	return admin status
	void setUnLocked();						//	Unlock user
	void Login();	//	login function. need to update invalid ligin counter

	unsigned int getNumberInvalidLogin()const;	//	return number of invalid 
												//  logins
protected:

	struct UserStruct _user;
};
