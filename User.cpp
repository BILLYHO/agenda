#include "User.h"
#include <string>
#include <list>

User::User(string n, string pw, string e, string ph)
{
    name = n;
    password = pw;
    email = e;
    phone = ph;
    meetingManage = NULL;
}

string User::getName()
{
    return name;
}

void User::setName(string n)
{
    name = n;
}

string User::getPassword()
{
    return password;
}

void User::setPassword(string pw)
{
    password = pw;
}

string User::getEmail()
{
    return email;
}

void User::setEmail(string e)
{
    email = e;
}

string User::getPhone()
{
    return phone;
}

void User::setPhone(string ph)
{
    phone = ph;
}

list<Meeting> User::getAllMeetings()
{
    return MeetingManage::getInstance()->listAllMeetings(User::name);
}

list<Meeting> User::getAllSponsorMeetings()
{
    return MeetingManage::getInstance()->listAllSponsorMeetings(User::name);
}

list<Meeting> User::getAllParticipateMeetings()
{
    return MeetingManage::getInstance()->listAllParticipateMeetings(User::name);
}
