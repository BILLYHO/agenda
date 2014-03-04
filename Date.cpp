/*---Date.cpp--------------------------
 * Date definition
 *-----------------------------------*/

#include "Date.h"
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

Date::Date()
{
	setYear( -1 );
	setMonth( -1 );
	setDay( -1 );
	setHour( -1 );
	setMinute( -1 );
}

Date::Date( int y, int mo, int d, int h, int mu )
{
	setYear(y);
	setMonth(mo);
	setDay(d);
	setHour(h);
	setMinute(mu);
}



int Date::getYear( ) const
{
	return year;
}

void Date::setYear( int y )
{
	year = y;	
}

int Date::getMonth( ) const
{
	return month;
}

void Date::setMonth( int m ) 
{
	month = m;
}

int Date::getDay( ) const
{
	return day;
}

void Date::setDay( int d )
{
	day = d;
}

int Date::getHour( ) const
{
	return hour;
}

void Date::setHour( int h )
{
	hour = h;
}

int Date::getMinute( ) const
{
	return minute;
}

void Date::setMinute( int m )
{
	minute = m;
}

bool Date::isValid( Date date ) 
{
	int mon[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	if((date.year%4==0 && date.year%100!=0)||date.year%400==0)
		mon[1]++;
	if(date.year<1000 || date.year>9999)
		return false;
	else if(date.month<1 || date.month>12)
		return false;
	else if(date.day<1 || date.day>mon[date.month-1])
		return false;
	else if(date.hour<0 || date.hour>23)
		return false;
	else if(date.minute<0 || date.month>59)
		return false;
	else 
		return true;
}

Date Date::convertStringToDate(string ds)
{
    Date temp;
    if(ds[4]=='-')
    {
		temp.setYear( (ds[0]-'0')*1000 + (ds[1]-'0')*100 + (ds[2]-'0')*10 + ds[3]-'0');
		
		int i=4;
		if(ds[i+3]=='-')
		{
			i+=3;
			temp.setMonth(( ds[i-2]-'0')*10 + ds[i-1]-'0');
		}
		else if(ds[i+2]=='-')
		{
			i+=2;
			temp.setMonth(ds[i-1]-'0');
		}

		if(ds[i+3]=='/')
		{
			i+=3;
			temp.setDay(( ds[i-2]-'0')*10 + ds[i-1]-'0');
		}
		else if(ds[i+2]=='/')
		{
			i+=2;
			temp.setDay(ds[i-1]-'0');
		}

		if(ds[i+3]==':')
		{
			i+=3;
			temp.setHour(( ds[i-2]-'0')*10 + ds[i-1]-'0');
		}
		else if(ds[i+2]==':')
		{
			i+=2;
			temp.setHour(ds[i-1]-'0');
		}

			i+=3;
			temp.setMinute(( ds[i-2]-'0')*10 + ds[i-1]-'0');
		
        //temp.setMonth(( ds[5]-'0')*10 + ds[6]-'0');
		
        //temp.setDay( (ds[8]-'0')*10 + ds[9]-'0');
        //temp.setHour((ds[11]-'0')*10 + ds[12]-'0');
        //temp.setMinute( (ds[14]-'0')*10 + ds[15]-'0');

    }
    return temp;
}
string Date::convertDateToString(Date date)
{
    string s(16,'0');
    for(int i=3,t=date.year; i>=0 ;i--)
    {
        s[i] = '0' + t%10;
        t /= 10;
    }

    s[4] = '-';
    s[6] = '0' + date.month%10;
    s[5] = '0' + date.month/10;

    s[7] = '-';
    s[9] = '0' + date.day%10;
    s[8] = '0' + date.day/10;

    s[10] = '/';
    s[12] = '0' + date.hour%10;
    s[11] = '0' + date.hour/10;

    s[13] = ':';
    s[15] = '0' + date.minute%10;
    s[14] = '0' + date.minute/10;

	return s;

}

Date& Date::operator=( const Date& t ){
	setYear( t.getYear() );
	setMonth( t.getMonth() );
	setDay( t.getDay() );
	setHour( t.getHour() );
	setMinute( t.getMinute() );

	return *this;
}

bool Date::operator==( const Date& t ) const{
	if ( year   == t.getYear()  &&
		 month  == t.getMonth() &&
		 day    == t.getDay()   &&
		 hour   == t.getHour()  &&
		 minute == t.getMinute() )
		 return true;
	return false;
}

bool Date::operator>( const Date& t ) const
{
	if(year > t.getYear())
		return true;
	else if(year == t.getYear())
	{
		if(month > t.getMonth())
	    	return true;
		else if(month == t.getMonth())
		{
			if(day > t.getDay())
				return true;
			else if(day == t.getDay())
			{
				if(hour > t.getHour())
					return true;
				else if(hour == t.getHour())
				{
					if(minute > t.getMinute())
						return true;
				}
			}
		}
	}
	return false;
}

bool Date::operator<( const Date& t ) const
{
	if(t > (*this))
		return true;
	return false;
}

bool Date::operator>=( const Date& t ) const
{
	if( (*this) > t  || (*this) == t)
		return true;
	else
		return false;
}

bool Date::operator<=( const Date& t ) const
{
	if((*this) < t || (*this) == t )
		return true;
	return false;
}


