/*--------AgendaService.h----------------
 *
 *-------------------------------------*/

#ifndef AGENDASERVICE_H
#define AGENDASERVICE_H

#include "UserManage.h"
#include "MeetingManage.h"

class AgendaService {
private:
	UserManage *userManage;
	MeetingManage *meetingManage;

public:
	AgendaService( );
	User* userLogIn( string userName, string password );
	bool userRegister( string userName, string password, string email, string phone );
	bool deleteUser( User user );
	list<User> listAllUsers( );

	bool createMeeting( string userName, string title, string participator, Date stime, Date etime);

	Meeting* queryMeetingByTitle( string title );
	list<Meeting> queryMeetingsByTime( string userName, Date stime, Date etime );

    list<Meeting> listAllMeetings(string userName);
    list<Meeting> listAllSponsorMeetings(string userName);
    list<Meeting> listAllParticipateMeetings(string userName);

	bool deleteMeeting( string userName, string title );
	bool deleteAllMeetings( string userName );

    bool updateMeetingParticipator(string title, string newParticipator);
    bool updateMeetingStartDate(string title , Date newStartDate);
    bool updateMeetingEndDate(string title, Date newEndDate);

    bool updateUserPassword(User u, string newPassword);
    bool updateUserEmail(User u, string newEmail);
    bool updateUserPhone(User u, string newPhone);
};

#endif
