/*---Date.h--------------------------
 * Date definition
 *----------------------------------*/

#ifndef Date_H
#define Date_H

#include <string>
using std::string;

class Date
{
private:
	int year;
	int month;
	int day;
	int hour;
	int minute;

public:
	Date();
	Date( int y, int mo, int d, int h, int mu );

	int getYear( ) const;
	void setYear( int y );

	int getMonth( ) const;
	void setMonth( int m );

	int getDay( ) const;
	void setDay( int d );

	int getHour( ) const;
	void setHour( int h );

	int getMinute( ) const;
	void setMinute( int m );

	static bool isValid( Date d );
	static Date convertStringToDate(string ds);
	static string convertDateToString(Date d);	

	Date& operator=( const Date& t );
	bool operator==( const Date& t ) const;
	bool operator>( const Date& t) const;
	bool operator<( const Date& t ) const;
	bool operator>=( const Date& t) const;
	bool operator<=( const Date& t ) const;
	
}; 

#endif
