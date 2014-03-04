/*-------AgendaControl.h---------------
 *
 *-----------------------------------*/

#ifndef AGENDACONTROLLER_H
#define AGENDACONTROLLER_H

#include <iostream>
#include "AgendaService.h"

using namespace std;

class AgendaController {
private:
	User *currentUser;
	AgendaService agendaService;

	bool executeOperation( string op );

	void userLogIn( );
	void userRegister( );
	void userLogOut( );
	void deleteUser( );
	void listAllUsers( );
	
	void createMeeting( );
	void listAllMeetings( );
	void listAllSponsorMeetings( );
	void listAllParticipateMeetings( );
	void queryMeetingByTitle( );
	void queryMeetingByTimeInterval( );
	void deleteMeetingByTitle( );
	void deleteAllMeetings();

    void updateMeetingParticipator();
    void updateMeetingStartDate();
    void updateMeetingEndDate();
    void updateUserPassword();
    void updateUserEmail();
    void updateUserPhone();

	void printMeetings( list<Meeting> meetings );
	void printMenu();

public:
	AgendaController( );
	void getOperation( );

};

#endif
