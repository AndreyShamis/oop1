#include "UsersDB.h"
#include <iostream>
#include <string>

using namespace std;


//Admin menu constants
#define ADD 1 
#define REMOVE 2 
#define LOCK 3 
#define UNLOCK 4 
#define RESET 5 
#define DISPLAY_ALL 6 
#define DISPLAY_LOCKED 7 
#define EXIT 8 


string displayLoginMenu();
void displayAdminMenu();
void displayUserMenu(string userName);
bool reportSuccess(int success,string badMsg, string goodMsg);
void exitSystem();


int main(){
	cout << "Hello And Welcome!!" << endl;
	string userName = displayLoginMenu();
	//User provided correct username and password
	if (UsersDB::getInstance()->isAdmin(userName))
		displayAdminMenu();
	else{
		displayUserMenu(userName);
	}
	exitSystem();
}

/*********************************************************************
* Display the login menu
**********************************************************************/
string displayLoginMenu(){
	bool isAuth = false;
	string userName="",password="";
	do{
		cout << "Please Choose an option: " << endl;
		cout << "1. login " << endl;
		cout << "2. leave " << endl;
		int userChoise = 0;
		cin >> userChoise;
		string badMsg = "Wrong user name OR password";
		string goodMsg = "";
		switch(userChoise){
			case 1:
				cout << "Please Enter your user name and password" << endl;
				cin >> userName >> password;
				isAuth = reportSuccess(UsersDB::getInstance()->validateUser(userName, password),badMsg,goodMsg);
				break;
			case 2:
				cout << "Bye..." << endl;
				exitSystem();
				break;
			default:
				cout << "Option not supported" << endl;
		}
		if(UsersDB::getInstance()->isLocked(userName)){
			cout << "Sorry your account is locked, Please report to your administrator" << endl;
			isAuth = false;
		}
	}while(!isAuth);
	//Login was successful
	return userName;
}

/*********************************************************************
* Display the admin menu
**********************************************************************/
void displayAdminMenu(){
	int adminChoise;
	do{
		string newUserName="",newPassword="";
		cout << "Please Choose an option: " << endl;
		cout << "1. Add user " << endl;
		cout << "2. Remove user " << endl;
		cout << "3. Lock user " << endl;
		cout << "4. Unlock user " << endl;
		cout << "5. Reset user password " << endl;
		cout << "6. Display all users " << endl;
		cout << "7. Display locked users " << endl;
		cout << "8. Exit " << endl;
		cin >> adminChoise;
		bool success = false;
		string badMsg = "";
		string goodMsg = "";
		int numOfUsers = 0;
		string* users = 0;
		switch(adminChoise){
			case ADD:
				cout << "Please Enter the new user name and password" << endl;
				cin >> newUserName >> newPassword;
				badMsg = "Not a Valid credentials OR user already exists";
				goodMsg = "User Added ";
				success = reportSuccess(UsersDB::getInstance()->addUser(newUserName,newPassword),badMsg,goodMsg);
				break;
			case REMOVE:
				cout << "Please Enter the user name you want to remove " << endl;
				cin >> newUserName;
				badMsg  = "No such user... ";
				goodMsg  = "User removed ";
				success = reportSuccess(UsersDB::getInstance()->removeUser(newUserName),badMsg,goodMsg);
				break;
			case LOCK:
				cout << "Please Enter the user name you want to lock " << endl;
				cin >> newUserName;
				badMsg  = "No such user... ";
				goodMsg  = "User locked ";
				success = reportSuccess(UsersDB::getInstance()->lockUser(newUserName),badMsg,goodMsg);
				break;
			case UNLOCK:
				cout << "Please Enter the user name you want to unlock " << endl;
				cin >> newUserName;
				badMsg  = "No such user... ";
				goodMsg  = "User unlocked ";
				success = reportSuccess(UsersDB::getInstance()->unlockUser(newUserName),badMsg,goodMsg);
				break;
			case RESET:
				cout << "Please Enter the user name you want to reset " << endl;
				cin >> newUserName;
				badMsg  = "No such user... ";
				goodMsg  = "User password was reset to default ";
				success = reportSuccess(UsersDB::getInstance()->resetUserPassword(newUserName),badMsg,goodMsg);
				break;
			case DISPLAY_ALL:
				badMsg  = "No Users...";
				goodMsg  = "Users retrieved";
				success =  reportSuccess(UsersDB::getInstance()->getAllUsers(numOfUsers,users),badMsg,goodMsg);
				if (success){
					for(int i=0; i< numOfUsers;i++){
						cout << users[i] << endl;
					}
					delete[] users;
				}
				break;
			case DISPLAY_LOCKED:
				badMsg  = "No Locked Users...";
				goodMsg  = "Locked Users retrieved";
				success =  reportSuccess(UsersDB::getInstance()->getLockedUsers(numOfUsers,users),badMsg,goodMsg);
				if (success){
					for(int i=0; i< numOfUsers;i++){
						cout << users[i] << endl;
					}
					delete[] users;
				}
				break;
			case EXIT:
				cout << "Bye..." << endl;
				break;
			default:
				cout << "Option not supported" << endl;
		}
	}while(adminChoise!=EXIT);
}

/*********************************************************************
* Display the User menu
**********************************************************************/
void displayUserMenu(string userName){
	cout << "Hello " << userName << " You are now logged in " << endl << endl;
	cout << "	          .88888888:. " << endl;
	cout << "                88888888.88888." << endl;
	cout << "              .8888888888888888. "<< endl;
	cout << "              888888888888888888 "<< endl;
	cout << "              88' _`88'_  `88888 "<< endl;
	cout << "              88 88 88 88  88888 "<< endl;
	cout << "              88_88_::_88_:88888 "<< endl;
	cout << "              88:::,::,:::::8888 "<< endl;
	cout << "              88`:::::::::'`8888 "<< endl;
	cout << "             .88  `::::'    8:88. "<< endl;
	cout << "            8888            `8:888. "<< endl;
	cout << "          .8888'             `888888. "<< endl;
	cout << "         .8888:..  .::.  ...:'8888888:. "<< endl;
	cout << "        .8888.'     :'     `'::`88:88888 "<< endl;
	cout << "       .8888        '         `.888:8888. "<< endl;
	cout << "      888:8         .           888:88888 "<< endl;
	cout << "    .888:88        .:           888:88888: "<< endl;
	cout << "    8888888.       ::           88:888888 "<< endl;
	cout << "    `.::.888.      ::          .88888888 "<< endl;
	cout << "   .::::::.888.    ::         :::`8888'.:. "<< endl;
	cout << "  ::::::::::.888   '         .:::::::::::: "<< endl;
	cout << "  ::::::::::::.8    '      .:8::::::::::::. "<< endl;
	cout << " .::::::::::::::.        .:888::::::::::::: "<< endl;
	cout << " :::::::::::::::88:.__..:88888:::::::::::' "<< endl;
	cout << "  `'.:::::::::::88888888888.88:::::::::' "<< endl;
	cout << "        `':::_:' -- '' -'-' `':_::::'` "<< endl;
}

/*********************************************************************
* Display the relevant message according to the DB return value.
*   1 = Success
*   0 = Logical Fail
*  -1 or all other = Crash
**********************************************************************/
bool reportSuccess(int success, string badMsg, string goodMsg){
	bool result = false;
	if (success==1){
		cout <<  goodMsg << endl; 
		 result = true;
	}else if (success==0){
		cout << badMsg << endl; 
		 result = false;
	}else {
		cerr << "Operation failed "  << endl;
		exitSystem();
	}
	return result;
}

void exitSystem(){

}

