#pragma once

class user
{
public:
	user(void);
	//	function which select user from db by name
	//	return struct User
	struct	User Select(string userName);

	bool	Insert(const struct User &user);
//=============================================================================
//	Function wich deleteing user from db by user name
//	get username will be delete
//	return true if saccess and false if not
	bool	Delete(const string usrName);
	~user(void);
};
