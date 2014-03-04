#include "AgendaController.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

AgendaController::AgendaController()
{
    currentUser = NULL;
    printMenu();
}

void AgendaController::getOperation()
{
    string c;
    if(currentUser == NULL)
        cout << "Agenda : ~$ ";
    else
        cout << "Agenda@" << currentUser->getName() << " : ~# ";
    cin >> c;
    executeOperation(c);
}

bool AgendaController::executeOperation(string op)
{
    if(op == "p")
    {
        printMenu();
        getOperation();
        return true;
    }
    if(currentUser == NULL)
    {
        if(op == "l")
        {
            userLogIn();
            return true;
        }
        else if(op == "r")
        {
            userRegister();
            return true;
        }
        else if(op == "q")
        {
            cout << "Thanks for using! Bye!" << endl;
            return true;
        }
        else
        {
            cout << "[error] Command not found. Please try again. Type p to print menu." << endl << endl;
            getOperation();
            return false;
        }
    }
    else
    {
        if (op == "o")
        {
            userLogOut();
            return true;
        }
        else if(op == "dc")
        {
            deleteUser();
            return true;
        }
        else if(op == "lu")
        {
            listAllUsers();
            return true;
        }
        else if(op == "cm")
        {
            createMeeting();
            return true;
        }
        else if(op == "la")
        {
            listAllMeetings();
            return true;
        }
        else if(op == "las") 
        {
            listAllSponsorMeetings();
            return true;
        }
        else if(op == "lap") 
        {
            listAllParticipateMeetings();
            return true;
        }
        else if(op == "qm")
        {
            queryMeetingByTitle();
            return true;
        }
        else if(op == "qt")
        {
            queryMeetingByTimeInterval();
            return true;
        }
        else if (op == "dm")
        {
            deleteMeetingByTitle();
            return true;
        }
        else if(op == "da")
        {
            deleteAllMeetings();
            return true;
        }
        else if(op == "ump")
        {
            updateMeetingParticipator();
            return true;
        }
        else if(op == "ums")
        {
            updateMeetingStartDate();
            return true;
        }
        else if(op == "ume")
        {
            updateMeetingEndDate();
            return true;
        }
        else if(op == "npw")
        {
            updateUserPassword();
            return true;
        }
        else if(op == "nem")
        {
            updateUserEmail();
            return true;
        }
        else if(op == "nph")
        {
            updateUserPhone();
            return true;
        }
        else
        {
            cout << "[error] Command not found. Please try again. Type p to print menu." << endl << endl;
            getOperation();
            return false;
        }
    }
}

void AgendaController::userLogIn()
{
    string n, pw;
    cout << "[login] [username] [password]\n[login] ";
    cin >> n >> pw;
    currentUser = agendaService.userLogIn(n,pw);

    if(currentUser == NULL)
    {
        cout << "[error] login fail! " << endl << endl;
        getOperation();
    }
    else
    {
        cout << endl << "Welcome to Agenda, " << currentUser->getName() << "!" << endl;
        printMenu();   
        getOperation();
    }
}

void AgendaController::userRegister()
{
    bool flag;
    string n, pw, e, ph;
    cout << "[register] [username] [password] [email] [phone]\n[register] ";
    cin >> n >> pw >> e >> ph;
    flag = agendaService.userRegister(n,pw,e,ph);
    if(flag)
    {
        cout << "[register] succeed!" << endl << endl;
        getOperation();
    }
    else
    {
        cout << "[error] register fail! " << endl << endl;
        getOperation();
    }
}

void AgendaController::userLogOut()
{
    currentUser = NULL;
    cout << "Log out succeed!" << endl << endl;
    printMenu();
    getOperation();
}

void AgendaController::deleteUser()
{
    bool flag = agendaService.deleteUser(*currentUser);
    if(flag)
    {
        cout << "[delete agenda account] succeed!" << endl << endl;
        currentUser = NULL;
        getOperation();
    }
    else
    {
        cout << "[error] delete agenda account fail! " << endl << endl;
        getOperation();
    }
}

void AgendaController::listAllUsers()
{
    list<User> temp(agendaService.listAllUsers());

    cout << endl << "[list all users]" << endl;
    cout << setiosflags(ios::left) << setw(15) << "name" << setw(20) << "email" << "phone" << endl;
    for(list<User>::iterator it=temp.begin(); it!=temp.end(); it++)
        cout << setiosflags(ios::left) << setw(15) << (*it).getName() << setw(20) << (*it).getEmail() << (*it).getPhone() << endl;
	cout << endl;
    getOperation();
}

void AgendaController::createMeeting()
{
    string t,p,st,et;
    bool flag;
    cout << "[create meeting] [title] [participator] [start time(yyyy-mm-dd/hh:mm)] [end time(yyyy-mm-dd/hh:mm)]\n[create meeting] ";
    cin >> t >> p >> st >> et;
    Date tmp;
    Date sd(tmp.convertStringToDate(st)),ed(tmp.convertStringToDate(et));
    flag = agendaService.createMeeting(t, currentUser->getName(), p, sd, ed);
    if(flag)
    {
        cout << "[create meeting] succeed!" << endl << endl;
        getOperation();
    }
    else
    {
        cout << "[error] create meeting fail! " << endl << endl;
        getOperation();
    }
}

void AgendaController::listAllMeetings()
{
    list<Meeting> temp(agendaService.listAllMeetings(currentUser->getName() ));
    if(temp.empty())
        cout << "[error] Meeting not found. "  << endl;
    else
    {
        cout << endl << "[list all meetings]" << endl;
        printMeetings(temp);
    }
    getOperation();
}

void AgendaController::listAllSponsorMeetings()
{
    list<Meeting> temp(agendaService.listAllSponsorMeetings(currentUser->getName() ));
    if(temp.empty())
        cout << "[error] Meeting not found. " << endl;
    else
    {
        cout << endl << "[list all sponsor meetings]"  << endl;
        printMeetings(temp);
    }
    getOperation();
}

void AgendaController::listAllParticipateMeetings()
{
    list<Meeting> temp(agendaService.listAllParticipateMeetings(currentUser->getName() ));
    if(temp.empty())
        cout << "[error] Meeting not found." << endl;
    else
    {
        cout << endl << "[list all participate meetings]" << endl;
        printMeetings(temp);
    }
    getOperation();

}

void AgendaController::queryMeetingByTitle()
{
    string t;
    cout << "[query meeting] [title]:\n[query meeting] ";
    cin >> t;

    Meeting* temp(agendaService.queryMeetingByTitle(t));
    if(temp == NULL)
        cout << "[error] Meeting dosen't exist!" << endl;
    else if( (*temp).getSponsor()==currentUser->getName() || (*temp).getParticipator()==currentUser->getName())
    {
        cout << setiosflags(ios::left)  
             << setw(15) << "sponsor" 
             << setw(15) << "participator" 
             << setw(20) << "start time"
             << setw(20) << "ent time" << endl;
        cout << setiosflags(ios::left)  
             << setw(15) << (*temp).getSponsor()  
             << setw(15) << (*temp).getParticipator()  
             << setw(20) << (*temp).getStartDate().convertDateToString(temp->getStartDate())
             << setw(20) << (*temp).getEndDate().convertDateToString(temp->getEndDate()) << endl << endl;
    }
    else
        cout << "[error] Permission denied. You are not relevant to " << temp->getTitle() << " ." << endl << endl;
    getOperation();
}

void AgendaController::queryMeetingByTimeInterval()
{
    string st, et;
    cout << "[query meetings] [start time(yyyy-mm-dd/hh:mm)] [start time(yyyy-mm-dd/hh:mm)]\n[query meetings] ";
    cin >> st >> et;

    Date tmp;
    Date sd(tmp.convertStringToDate(st)),ed(tmp.convertStringToDate(et));

    if(sd > ed)
    {
        cout << "[error] Invalid time interval. " << endl << endl;
        getOperation();
        return;
    }
    else if(!Date::isValid(sd) || !Date::isValid (ed))
    {
        cout << "[error] Invalid date. Please check your input." << endl << endl;
        getOperation();
        return;
    }
    list<Meeting> temp(agendaService.queryMeetingsByTime(currentUser->getName(),sd,ed));
	if(temp.empty())
		cout << "[error] No meeting found in this time interval." << endl << endl;
	else
    {
        cout << endl << "[query meetings]" << endl;
		printMeetings(temp);
    }
    getOperation();
}

void AgendaController::deleteMeetingByTitle()
{
    bool flag;
    string t;
    cout << "[delete meeting] [title]\n[delete meeting] ";
    cin >> t;
    flag = agendaService.deleteMeeting(currentUser->getName(), t);
    if(flag)
    {
        cout << "[delete meeting by title] succeed!" << endl << endl;
        getOperation();
    }
    else
    {
        cout << "[error] delete meeting fail!" << endl << endl;
        getOperation();
    }
}

void AgendaController::deleteAllMeetings()
{
    cout << "[warning] Do you really want to delete all meeting? (y/n) ";
    char c;
    cin >> c;
    if(c == 'y')
    {
        agendaService.deleteAllMeetings(currentUser->getName());
        cout << "[delete all meeting] succeed!" << endl << endl;
    }
    else
        cout << "[error] delete cancelled." << endl << endl;
    getOperation();
}

void AgendaController::updateMeetingParticipator()
{
    if(agendaService.listAllSponsorMeetings(currentUser->getName()).empty())
        cout << "[error] You don't have any meeting to update." << endl << endl;
    else
    {
        cout << "[update meeting participator] [title]\n[update meeting participator] ";
        string t;
        cin >> t;
        Meeting* temp(agendaService.queryMeetingByTitle(t));
        if(temp == NULL)
            cout << "[error] meeting not found." << endl << endl;
        else if(currentUser->getName() == temp->getSponsor())
        {
            cout << "[update meeting participator] [newParticipator]\n[update meeting participator] ";
            string npa;
            cin >> npa;
            bool flag = agendaService.updateMeetingParticipator(t,npa); 
            if(flag)
                cout << "[update meeting participator] succeed!" << endl << endl;
        }
        else
            cout << "[error] Premission denied. You are not the sponsor of the meeting." << endl << endl;
        getOperation();
    }
}


void AgendaController::updateMeetingStartDate()
{
    if(agendaService.listAllSponsorMeetings(currentUser->getName()).empty())
        cout << "[error] You don't have any meeting to update." << endl << endl;
    else
    {
        cout << "[update meeting start date] [title]\n[update meeting start date] ";
        string t;
        cin >> t;
        Meeting* temp(agendaService.queryMeetingByTitle(t));
        if(temp == NULL)
            cout << "[error] meeting not found." << endl << endl;
        else if(currentUser->getName() == temp->getSponsor())
        {
            cout << "[update meeting start date] [new start date]\n[update meeting start date] ";
            string nst;
            cin >> nst;
            Date tmp;
            Date sd(tmp.convertStringToDate(nst));
            if(!Date::isValid(sd))
                cout << "[error] Invalid date." << endl << endl;
            else if(sd > temp->getEndDate())
                cout << "[error] Invalid time interval" << endl << endl;
            else
            {
                bool flag = agendaService.updateMeetingStartDate(t,sd); 
                if(flag)
                    cout << "[update meeting start date] succeed!" << endl << endl;
            }
        }
        else
            cout << "[error] Premission denied. You are not the sponsor of the meeting." << endl << endl;
        getOperation();
    }
}
void AgendaController::updateMeetingEndDate()
{
    if(agendaService.listAllSponsorMeetings(currentUser->getName()).empty())
        cout << "[error] You don't have any meeting to update." << endl << endl;
    else
    {
        cout << "[update meeting end date] [title]\n[update meeting end date] ";
        string t;
        cin >> t;
        Meeting* temp(agendaService.queryMeetingByTitle(t));
        if(temp == NULL)
            cout << "[error] meeting not found." << endl << endl;
        else if(currentUser->getName() == temp->getSponsor())
        {
            cout << "[update meeting end date] [new end date]\n[update meeting end date] ";
            string net;
            cin >> net;
            Date tmp;
            Date ed(tmp.convertStringToDate(net));
            if(!Date::isValid(ed))
                cout << "[error] Invalid date." << endl << endl;
            else if(ed < temp->getStartDate())
                cout << "[error] Invalid time interval" << endl << endl;
            else
            {
                bool flag = agendaService.updateMeetingEndDate(t,ed); 
                if(flag)
                    cout << "[update meeting end date] succeed!" << endl << endl;
                else
                    cout << "[error] upadte fail!" << endl << endl;
            }
        }
        else
            cout << "[error] Premission denied. You are not the sponsor of the meeting." << endl << endl;
        getOperation();
    }
}

void AgendaController::updateUserPassword()
{
    cout << "[update password] Please input your old password: ";
    string pw;
    cin >> pw;
    if(pw == currentUser->getPassword())
    {
        string npw1, npw2;
        cout << "[update password] Please input your new password: ";
        cin >> npw1;
        cout << "[update password] Please input your new password again: ";
        cin >> npw2;
        if(npw1 == npw2)
        {
            bool flag = agendaService.updateUserPassword(*currentUser, npw1);
            if(flag)
                cout << "[update password] succeed!" << endl << endl;
            else        
                cout << "[error] upadte fail!" << endl << endl;
        }
    }
    else
       cout <<  "[error] Wrong password." << endl << endl;
    getOperation();
}

void AgendaController::updateUserEmail()
{
    cout << "[update user email] [new email]\n[update user email] ";
    string s;
    cin >> s;
    bool flag = agendaService.updateUserEmail(*currentUser,s);
    if(flag)
        cout << "[update user email] succeed!" << endl << endl;
    else
        cout << "[error] upadte fail!" << endl << endl;
    getOperation();
}

void AgendaController::updateUserPhone()
{
    cout << "[update user phone] [new phone]\n[update user phone] ";
    string s;
    cin >> s;
    bool flag = agendaService.updateUserPhone(*currentUser,s);
    if(flag)
        cout << "[update user phone] succeed!" << endl << endl;
    else
        cout << "[error] upadte fail!" << endl << endl;
    getOperation();
}


void AgendaController::printMeetings(list<Meeting> m)
{
    cout << setiosflags(ios::left) 
         << setw(15)<< "title" 
         << setw(15) << "sponsor" 
         << setw(15) << "participator"
         << setw(20) << "start time"
         << setw(20) << "ent time" << endl;
    for(list<Meeting>:: iterator it=m.begin(); it!=m.end(); it++)
	{	
		cout << setiosflags(ios::left) 
             << setw(15)<< (*it).getTitle() 
             << setw(15) << (*it).getSponsor() 
             << setw(15) << (*it).getParticipator() 
             << setw(20) << (*it).getStartDate().convertDateToString((*it).getStartDate()) 
             << setw(20) << (*it).getEndDate().convertDateToString((*it).getEndDate()) << endl;
	}
    cout << endl;

}


void AgendaController::printMenu() 
{
    if(currentUser == NULL)
        cout << "--------------------Agenda--------------------" << endl
             << "Action :" << endl
             << "l - log in Agenda by user name and password" << endl
             << "r - register an Agenda account" << endl
             << "q - quit Agenda" << endl
             << "p - print menu" << endl
             << "----------------------------------------------" << endl << endl;

    else
	   cout  << "-----------------------Agenda-----------------------" << endl
             << "Action :" << endl
             << "o   -  log out Agenda" << endl
             << "dc  -  delete Agenda account" << endl
             << "lu  -  list all Agenda account" << endl
             << "cm  -  create a meeting" << endl
             << "la  -  list all meetings" << endl
             << "las -  list all sponsor meetings" << endl
             << "qm  -  query meeting by title" << endl
             << "qt  -  query meetings by time interval" << endl
             << "dm  -  delete meeting bi title" << endl
             << "da  -  delete all meetings" << endl
             << "ump -  update meeting participator" << endl
             << "ums -  update meeting start date" << endl
             << "ume -  update meeting end date" << endl
             << "npw -  update user password" << endl
             << "nem -  update user email" << endl
             << "nph -  update user phone" << endl
             << "p   -  print menu" << endl
             << "----------------------------------------------------" << endl;
}























































