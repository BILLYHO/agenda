/*---Meeting.h--------------------------
 * Meeting definition
 *------------------------------------*/

#ifndef MEETING_H
#define MEETING_H

#include "Date.h"
//#include "Date.cpp"
#include <string>

using std::string;
/*
 * define Meeting class
 */
class Meeting {
private:
	 string title;
	 string sponsor;
	 string participator;
	 Date   startDate;
	 Date   endDate;

public:
	Meeting(string t, string s, string p, Date st, Date et );

	string getTitle( ) ;
	void setTitle(string t);
    
	string getSponsor( ) ;
	void setSponsor(string s);

	string getParticipator( ) ;
	void setParticipator(string p);

	Date getStartDate( ) ;
	void setStartDate(const Date st);

	Date getEndDate( ) ;
	void setEndDate(const Date et);


};


#endif
