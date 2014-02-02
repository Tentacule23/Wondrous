/*
*  doomsday.c
*  A program to test a function dayOfWeek which determines which
*  day of the week a particular date falls on.
*  (only for dates after the start of the Gregorian calendar).
*
*  Program stub created by Richard Buckland on 27/03/12
*  This program by YOUR-NAME-HERE
*  Freely licensed under Creative Commons CC-BY-3.0
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define THURSDAY 0
#define FRIDAY   1
#define SATURDAY 2
#define SUNDAY   3
#define MONDAY   4
#define TUESDAY  5
#define WEDNESDAY 6

#define START_OF_GREG 1582

#define TRUE 1
#define FALSE 0
#define DAYS_PER_WEEK 7

char dayOfWeek(int zeDoomsDay(int year), int isLeapYear(int year), int month, int day);
int isLeapYear(int year);
int zeDoomsDay(int year);

int day;
int month;
int year;
int doomsDay;
int leapYear;
char ansDayOfWeek;

int main(int argc, char *argv[]) 
{

	//Test
	assert(dayOfWeek(THURSDAY, FALSE, 4, 4) == THURSDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 6, 6) == FRIDAY);
	assert(dayOfWeek(MONDAY, FALSE, 8, 8) == MONDAY);
	assert(dayOfWeek(WEDNESDAY, FALSE, 10, 10) == WEDNESDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 12, 12) == FRIDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 9, 5) == THURSDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 5, 9) == FRIDAY);
	assert(dayOfWeek(SUNDAY, FALSE, 7, 11) == SUNDAY);
	assert(dayOfWeek(TUESDAY, FALSE, 11, 7) == TUESDAY);
	assert(dayOfWeek(WEDNESDAY, FALSE, 3, 7) == WEDNESDAY);

	assert(dayOfWeek(THURSDAY, FALSE, 4, 5) == FRIDAY);
	assert(dayOfWeek(SATURDAY, FALSE, 6, 5) == FRIDAY);
	assert(dayOfWeek(MONDAY, FALSE, 8, 9) == TUESDAY);
	assert(dayOfWeek(WEDNESDAY, FALSE, 10, 9) == TUESDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 12, 20) == SATURDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 9, 9) == MONDAY);
	assert(dayOfWeek(FRIDAY, FALSE, 5, 5) == MONDAY);
	assert(dayOfWeek(SUNDAY, FALSE, 7, 7) == WEDNESDAY);
	assert(dayOfWeek(TUESDAY, FALSE, 11, 11) == SATURDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 3, 30) == SATURDAY);

	assert(dayOfWeek(TUESDAY, FALSE, 2, 28) == TUESDAY);
	assert(dayOfWeek(TUESDAY, FALSE, 2, 27) == MONDAY);
	assert(dayOfWeek(THURSDAY, FALSE, 1, 3) == THURSDAY);
	assert(dayOfWeek(TUESDAY, TRUE, 01, 20) == THURSDAY);

	printf("all tests passed - You are awesome!\n");

	//Demande Date
	printf("Enter Day(DD)\n");
	scanf("%d", &day);
	//check les date negative et les date au dessus de 31
	assert(day < 32);
	assert(0 < day);

	printf("Enter Month(MM)\n");
	scanf("%d", &month);
	//check les date negative et les date au dessus de 12
	assert(month < 13);
	assert(0 < month);

	printf("Enter Year(YYYY)\n");
	scanf("%d", &year);
	//check le debut du calendrier greg
	assert(year > START_OF_GREG);
	
	isLeapYear(year);
	zeDoomsDay(year);
	dayOfWeek(zeDoomsDay(year), isLeapYear(year), month, day);

	ansDayOfWeek = dayOfWeek(zeDoomsDay(year), isLeapYear(year), month, day);
	
	printf("The %d/%d/%d is a %s /n", day, month, year, ansDayOfWeek);

	//tranforme ansdayofweek en jour de semaine parce que je sais pas comment faire autrement
	/**if (ansDayOfWeek == 0)
	{
		printf("The %d/%d/%d is a Thursday!\n", day, month, year);
	}
	else if (ansDayOfWeek == 1)
	{
		printf("The %d/%d/%d is a Friday!\n", day, month, year);
	}
	else if (ansDayOfWeek == 2)
	{
		printf("The %d/%d/%d is a Saturday!\n", day, month, year);
	}
	else if (ansDayOfWeek == 3)
	{
		printf("The %d/%d/%d is a Sunday!\n", day, month, year);
	}
	else if (ansDayOfWeek == 4)
	{
		printf("The %d/%d/%d is a Monday!\n", day, month, year);
	}
	else if (ansDayOfWeek == 5)
	{
		printf("The %d/%d/%d is a Tuesday!\n", day, month, year);
	}
	else if (ansDayOfWeek == 6)
	{
		printf("The %d/%d/%d is a Wednesday!\n", day, month, year);
	}
	**/

	return EXIT_SUCCESS;
}

// given the doomsday for a year, and whether or not it is a
// leap year, this function return the day of the week for any
// given month and day in the year.

char dayOfWeek(int doomsDay, int leapYear, int month, int day) 
{
	
	char dayOfWeek;
	int doomsDate;

	//doomsday = 31/1(32ifleap), 28/2(29ifleap), 0/3, 4/4, 9/5, 6/6, 11/7, 8/8, 5/9, 10/10, 7/11, 12/12
	//aka if doomsday = jeudi = le 4 avril est un jeudi

	if (month == 1)
	{
		if (leapYear == TRUE)
		{
			doomsDate = 32;
		}
		else
		{
			doomsDate = 31;
		}
	}
	else if (month == 2)
	{
		if (leapYear == TRUE)
		{
			doomsDate = 29;
		}
		else
		{
			doomsDate = 28;
		}
	}
	else if (month == 3)
	{
		doomsDate = 0;
	}
	else if (month == 4)
	{
		doomsDate = 4;
	}
	else if (month == 5)
	{
		doomsDate = 9;
	}
	else if (month == 6)
	{
		doomsDate = 6;
	}
	else if (month == 7)
	{
		doomsDate = 11;
	}
	else if (month == 8)
	{
		doomsDate = 8;
	}
	else if (month == 9)
	{
		doomsDate = 5;
	}
	else if (month == 10)
	{
		doomsDate = 10;
	}
	else if (month == 11)
	{
		doomsDate = 7;
	}
	else if (month == 12)
	{
		doomsDate = 12;
	}
		
	//3 patern de dayofweek
	//dayof week est positif toute est beau
	if ((doomsDay - ((doomsDate - day) % 7)) > 0)
	{
		dayOfWeek = (doomsDay - ((doomsDate - day)) % 7 );
	}
	//dayofweek est negatif MAIS (doomsdate - day) = 0
	else if ((doomsDate - day) == 0)
	{
		dayOfWeek = ((doomsDay + ((day - doomsDate) % 7)) % 7);
	}
	//dayofweek est negatif 
	else
	{
		dayOfWeek = ((doomsDay + ((day - doomsDate)%7)) % 7 ) + 7;
	}
	//corrige les reponse au dessus de 6
	if (dayOfWeek > 6)
	{
		dayOfWeek = dayOfWeek - 7 ;
	}
	
	return (dayOfWeek);

}

int isLeapYear(int year)
{

	int leapYear;

	//check si leap year
	if ((year % 4) == 0) {
		if ((year % 100) == 0) 
		{
			if ((year % 400) == 0) 
			{
				leapYear = TRUE;
			}
			else
			{
				leapYear = FALSE;
			}
		}
		else
		{
			leapYear = TRUE;
		}
	}
	else
	{
		leapYear = FALSE;
	}
	
	return leapYear;

}

int zeDoomsDay(int year)
{

	int doomsDay;

	//merci wikipedia
	//http://en.wikipedia.org/wiki/Doomsday_rule
	doomsDay = (TUESDAY + year + (year / 4) - (year / 100) + (year / 400)) % 7;

	return doomsDay;

}