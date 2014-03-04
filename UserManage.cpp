#include "UserManage.h"
#include <iostream>


using namespace std;

bool UserManage::instanceFlag = false;
UserManage* UserManage::instance = NULL;

UserManage::UserManage(){}

UserManage* UserManage::getInstance()
{
    if(!instanceFlag)
    {
        instance = new UserManage();
        instanceFlag = true;
    }
    return instance; 
}

UserManage::~UserManage()
{
    instanceFlag = false;
}

User* UserManage::findUserByName(string name)
{
    list<User>::iterator it;

    for(it=users.begin(); it!=users.end(); it++)
    {
        if((*it).getName() == name)
	    {
            return &(*it);
	    }   
    }
    return NULL;
}

bool UserManage:: createUser( string name, string password, string email, string phone )
{
	if( findUserByName(name) != NULL )
    {
        cout << "User already exit." << endl;
        return false;
    }

	User newUser( name, password, email, phone );
	users.insert( users.end(), newUser );
	return true;
}

bool UserManage::deleteUser(User u)
{
    if((u.getAllMeetings()).empty())
    {
        for(list<User>::iterator it=users.begin(); it!=users.end(); it++)
        {
            if((*it).getName() == u.getName())
            {
                users.erase(it);
                return true;
            }
        }
    }
    else
    {
        cout << "[warning] Meetings exist. Delete all meetings sponsored by " << u.getName() << " ? (y/n) ";
        char c;
        cin >> c;
        if(c=='y')
        {
            MeetingManage::getInstance()->deleteAllMeetings(u.getName());
            for(list<User>::iterator it=users.begin(); it!=users.end(); it++)
            {
                if((*it).getName() == u.getName())
                {
                    users.erase(it);
                    return true;
                }

            }
        }
    }
    return false;
}

bool UserManage::updateUserPassword( User u, string newPassword )
{
	list<User>::iterator it;

	for(it = users.begin(); it != users.end();it++)
    {
		if( (*it).getName() == u.getName() )
        {
			(*it).setPassword( newPassword );
			return true;
		}
	}
    return false;
}

bool UserManage::updateUserEmail(User u, string newEmail)
{
    list<User>::iterator it;

    for(it=users.begin(); it!=users.end(); it++)
    {
        if((*it).getName() == u.getName())
        {
            (*it).setEmail(newEmail);
            return true;
        }
    }
    return false;
}

bool UserManage::updateUserPhone(User u, string newPhone)
{
    list<User>::iterator it;

    for(it=users.begin(); it!=users.end(); it++)
    {
        if((*it).getName() == u.getName())
        {
            (*it).setPhone(newPhone);
            return true;
        }
    }
    return false;
}

list<User> UserManage::listAllUsers()
{
    return users;
}

