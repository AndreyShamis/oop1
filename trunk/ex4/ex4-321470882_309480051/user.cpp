#include "user.h"

User::User()
{
	
	_user._name				=	"";
	_user._invalid_login	=	0;
	_user._locked			=	false;
	_user._pass				=	"";
	_user._admin			=	false;
		
}
User::User(const string UserName)
{
	
	_user._name				=	UserName;
	_user._invalid_login	=	0;
	_user._locked			=	false;
	_user._pass				=	"";
	_user._admin			=	false;
		
}
void User::setPass(const string NewPass)
{
	_user._pass = NewPass;
}
string User::getName()
{
	return(_user._name);
}
string User::getPass()
{
	return(_user._pass);

}
void User::Login()
{
	_user._invalid_login = 0;
}
void User::setIncreaseInvalidLogin()
{
	_user._invalid_login+=1;
}
unsigned int User::getNumberInvalidLogin()
{
	return(_user._invalid_login);
}
User User::operator=(const User &otherUser)
{
	_user = otherUser._user;
	return(*this);
}
void User::setLocked()
{
	_user._locked = true;
}
bool User::getLockStatus()
{
	return(_user._locked);
}
bool User::getAdmin()
{
	return(_user._admin);
}
void User::setUnLocked()
{
	_user._invalid_login	=	0;
	_user._locked			=	false;
}
bool User::operator==(const User &otherUser)
{
	if(_user._name == otherUser._user._name)
		return(true);

	return(false);
}


