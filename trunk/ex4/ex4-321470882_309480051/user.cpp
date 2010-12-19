#include "user.h"

//=============================================================================
//	default constructor
User::User()
{
	
	_user._name				=	"";
	_user._invalid_login	=	0;
	_user._locked			=	false;
	_user._pass				=	"";
	_user._admin			=	false;
		
}
//=============================================================================
void User::setName(const string newName)
{
	_user._name = newName;
}

//=============================================================================

User::User(const string UName,const string uPass,const short int invLogins,
	const bool locked,const bool admin)
{
	_user._name				=	UName;
	_user._pass				=	uPass;
	_user._invalid_login	=	invLogins;
	_user._locked			=	locked;
	_user._admin			=	admin;
}
//=============================================================================
//	constructor by name
User::User(const string UserName)
{
	
	_user._name				=	UserName;
	_user._invalid_login	=	0;
	_user._locked			=	false;
	_user._pass				=	"";
	_user._admin			=	false;
		
}
//=============================================================================
//	function to set password
//	getinf new password
void User::setPass(const string NewPass)
{
	_user._pass = NewPass;
}

//=============================================================================
//	return user name
string User::getName()
{
	return(_user._name);
}

//=============================================================================
//	return password (in hash form)
string User::getPass()
{
	return(_user._pass);

}

//=============================================================================
//	login function. need to update invalid ligin counter
void User::Login()
{
	_user._invalid_login = 0;
}

//=============================================================================
//	function which increase the invalid login counter by 1
void User::setIncreaseInvalidLogin()
{
	_user._invalid_login+=1;
}

//=============================================================================
//	return number of invalid logins
unsigned int User::getNumberInvalidLogin()
{
	return(_user._invalid_login);
}

//=============================================================================
//	operator = overloading
User User::operator=(const User &otherUser)
{
	_user = otherUser._user;
	return(*this);
}

//=============================================================================
//	lock user
void User::setLocked()
{
	_user._locked = true;
}

//=============================================================================
//	return lock status
bool User::getLockStatus()
{
	return(_user._locked);
}

//=============================================================================
//	return admin status
bool User::getAdmin()
{
	return(_user._admin);
}

//=============================================================================
//	Unlock user
void User::setUnLocked()
{
	_user._invalid_login	=	0;
	_user._locked			=	false;
}

//=============================================================================
//	operator == overloading binary comapre
bool User::operator==(const User &otherUser)
{
	if(_user._name == otherUser._user._name)
		return(true);

	return(false);
}