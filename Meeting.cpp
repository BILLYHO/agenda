#include "Meeting.h"
#include <string>

Meeting::Meeting(string t, string s , string p , Date st, Date et)
{
    title = t;
    sponsor = s;
    participator = p;
    startDate = st;
    endDate = et;
}

string Meeting::getTitle()
{
    return title;
}

void Meeting::setTitle(string t)
{
    title = t;
}

string Meeting::getSponsor()
{
    return sponsor;
}

void Meeting::setSponsor(string s)
{
    sponsor = s;
}

string Meeting::getParticipator()
{
    return participator;
}

void Meeting::setParticipator(string p)
{
    participator = p;
}

Date Meeting::getStartDate()
{
    return startDate;
}

void Meeting::setStartDate(Date st)
{
    startDate = st;
}

Date Meeting::getEndDate()
{
    return endDate;
}

void Meeting::setEndDate(Date et)
{
    endDate = et;
}

