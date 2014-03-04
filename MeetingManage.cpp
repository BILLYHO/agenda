#include "MeetingManage.h"
#include <list>
#include <iostream>

using namespace std;

bool MeetingManage::instanceFlag = false;
MeetingManage* MeetingManage::instance = NULL;

MeetingManage* MeetingManage::getInstance()
{
    if(!instanceFlag)
    {
        instance = new MeetingManage();
        instanceFlag = true;
    }
    return instance;
}

MeetingManage::~MeetingManage()
{
    instanceFlag = false;
}

bool MeetingManage::addMeeting(string t, string s, string p, Date st, Date et)
{
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getTitle() == t)
        {
            cout << "[error] Meeting already exist." << endl;
            return false;
        }
    }
	
	
    if(st > et)
    {
        cout << "[error] Invalid time interval." << endl;
        return false;
    }
    
    if( ! ((queryMeetingsByTime(s,st,et)).empty()) )
    {
        cout << "[error] Sponsor already have a meeting at this time." << endl;
        return false;
    }

    if( ! ((queryMeetingsByTime(p,st,et)).empty()) )
    {
        cout << "[error] Participator already have a meeting at this time." << endl;
        return false;
    }
	
	if(!Date::isValid(st) || !Date::isValid(et))
    {
        cout << "[error] Invalid date. Please check your input." << endl;
        return false;
    }

    Meeting temp(t,s,p,st,et);
    meetings.push_back(temp);
    return true;

}

bool MeetingManage::deleteMeeting(string userName, string title)
{
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getTitle()==title)
        {
            if((*it).getSponsor() == userName)
            {
                meetings.erase(it);
                return true;
            }
            else if ((*it).getParticipator() == userName)
            {
                cout << "[error] You can't delete this meeting because you are not sponsor." << endl;
                return false;
            }
            else
            {
                cout << "[error] Permission denied. You are not relevant to " << (*it).getTitle() << "." << endl;
                return false;
            }
        }
    }
    cout << "[error] Meeting not found." << endl;
    return false;
}

bool MeetingManage::deleteAllMeetings(string userName)
{
    bool flag=false;
	list<Meeting>::iterator it=meetings.begin();
    while( it!=meetings.end())
    {
        if((*it).getSponsor() == userName )
        {
            flag = true;
            it = meetings.erase(it);
        }
		else
			it++;
    }
    return flag;
}

bool MeetingManage::updateMeetingParticipator(string title, string newParticipator)
{
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getTitle() == title)
        {
            (*it).setParticipator(newParticipator);
            return true;
        }
    }
    return false;
}

bool MeetingManage::updateMeetingStartDate(string title, Date newStartDate)
{
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getTitle() == title)
        {
            (*it).setStartDate(newStartDate);
            return true;
        }
    }
    return false;
}

bool MeetingManage::updateMeetingEndDate(string title, Date newEndDate)
{
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getTitle() == title)
        {
            (*it).setEndDate(newEndDate);
            return true;
        }
    }
    return false;
}

Meeting* MeetingManage::queryMeetingByTitle(string title)
{
    Meeting* temp = NULL;
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getTitle() == title)
        {
            temp = &(*it);
            return temp;
        }
    }
    return temp;
}

list<Meeting> MeetingManage::queryMeetingsByTime(string userName, Date st, Date et)
{
    list<Meeting> temp;
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if( ((*it).getSponsor() == userName || (*it).getParticipator() == userName) && (  ((*it).getStartDate()>=st && (*it).getStartDate()<=et) || ((*it).getEndDate()<=et && (*it).getEndDate()>=st) || ((*it).getStartDate()<=st && (*it).getEndDate()>=et)) )
        temp.push_back(*it);
    }
    return temp;
}

list<Meeting> MeetingManage::listAllMeetings(string userName)
{
    list<Meeting> temp;
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getSponsor()==userName || (*it).getParticipator()==userName)
            temp.push_back(*it);
    }
    return temp;
}

list<Meeting> MeetingManage::listAllSponsorMeetings(string userName)
{
    list<Meeting> temp;
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getSponsor()==userName)
            temp.push_back(*it);
    }
    return temp;
}

list<Meeting> MeetingManage::listAllParticipateMeetings(string userName)
{
    list<Meeting> temp;
    for(list<Meeting>::iterator it=meetings.begin(); it!=meetings.end(); it++)
    {
        if((*it).getParticipator() == userName)
            temp.push_back(*it);
    }
	return temp;
}


















