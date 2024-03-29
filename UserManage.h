/*-------UserManage.h--------------------
 *
 *-------------------------------------*/

#ifndef USERMANAGE_H
#define USERMANAGE_H

#include "User.h"
//#include "User.cpp"
#include <list>
#include <cstdlib>

using namespace std;

class UserManage{
private:
	static bool instanceFlag;
	static UserManage *instance;
	UserManage();

	list<User> users;

public:
	static UserManage *getInstance();
	~UserManage();

	User* findUserByName( string name );
	bool createUser( string name, string password, string email, string phone );
	bool deleteUser( User u );
	bool updateUserPassword( User u, string newPassword );
	bool updateUserEmail( User u, string newEmail );
	bool updateUserPhone( User u, string newPhone );
	list<User> listAllUsers( );
};

#endif
