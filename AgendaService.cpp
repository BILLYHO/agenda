#include "AgendaService.h"
#include <string>
#include <iostream>

using namespace std;

AgendaService::AgendaService()
{
   userManage = userManage->getInstance(); 
   meetingManage = meetingManage->getInstance();
}

User* AgendaService::userLogIn(string n, string pw)
{
    User* temp = userManage->findUserByName(n);
    if(temp == NULL)
        cout << "[error] User not found." << endl;
    else if(temp->getPassword()!=pw)
        cout << "[error] Wrong password." << endl;
    else
        return temp;
    return NULL;
}

bool AgendaService::userRegister(string s, string pw, string e, string ph)
{
    return userManage->createUser(s,pw,e,ph);
}

bool AgendaService::deleteUser(User user)
{
    return userManage->deleteUser(user);
}

list<User> AgendaService::listAllUsers()
{
    return userManage->listAllUsers();
}


bool AgendaService::createMeeting(string t, string n, string p, Date st, Date et)
{
	if(userManage->findUserByName(p)==NULL)
    {
        cout << "[error] Participator not found." << endl;
        return false;    
    }
	return meetingManage->addMeeting(t,n,p,st,et);
}

Meeting* AgendaService::queryMeetingByTitle(string t)
{
    return meetingManage->queryMeetingByTitle(t);
}

list<Meeting> AgendaService::queryMeetingsByTime(string n,Date st, Date et)
{
    return meetingManage->queryMeetingsByTime(n,st,et);
}

bool AgendaService::deleteMeeting(string n, string t)
{
    return meetingManage->deleteMeeting(n,t);
}

bool AgendaService::deleteAllMeetings(string n)
{
    return meetingManage->deleteAllMeetings(n);
}

list<Meeting> AgendaService::listAllMeetings(string u)
{
    return meetingManage->listAllMeetings(u);
}

list<Meeting> AgendaService::listAllSponsorMeetings(string u)
{
    return meetingManage->listAllSponsorMeetings(u);
}

list<Meeting> AgendaService::listAllParticipateMeetings(string u)
{
    return meetingManage->listAllParticipateMeetings(u);
}

bool AgendaService::updateMeetingParticipator(string t, string np)
{
    return meetingManage->updateMeetingParticipator(t,np);
}

bool AgendaService::updateMeetingStartDate(string t, Date nsd)
{
    return meetingManage->updateMeetingStartDate(t,nsd);
}

bool AgendaService::updateMeetingEndDate(string t, Date ned)
{
    return meetingManage->updateMeetingEndDate(t,ned);
}

bool AgendaService::updateUserPassword(User u, string npw)
{
    return userManage->updateUserPassword(u,npw);
}

bool AgendaService::updateUserEmail(User u, string ne)
{
    return userManage->updateUserEmail(u,ne);
}

bool AgendaService::updateUserPhone(User u, string nph)
{
    return userManage->updateUserPhone(u,nph);
}

