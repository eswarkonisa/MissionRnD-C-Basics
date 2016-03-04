/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/


#include<stdio.h>
#include<conio.h>
int isOlder(char *dob1, char *dob2);
int isdayvalid(char * dob1, int y1, int m1, int d1);

int isOlder(char *dob1, char *dob2) {
	//check whether the date is valid or not
	int d1, m1, y1, d2, m2, y2, valid1,valid2,i=0;
	
	

	d1 = (dob1[0] - '0') * 10 + (dob1[1] - '0');
	d2 = (dob2[0] - '0') * 10 + (dob2[1] - '0');
	m1 = (dob1[3] - '0') * 10 + (dob1[4] - '0');
	m2 = (dob2[3] - '0') * 10 + (dob2[4] - '0');
	y1 = (dob1[6] - '0') * 1000 + (dob1[7] - '0') * 100 + (dob1[8] - '0') * 10 + (dob1[9] - '0');
	y2 = (dob2[6] - '0') * 1000 + (dob2[7] - '0') * 100 + (dob2[8] - '0') * 10 + (dob2[9] - '0');

	//check if the year is leap year or not

	////////////////////////////

	valid1 = isdayvalid(dob1, y1, m1, d1);
	valid2 = isdayvalid(dob2, y2, m2, d2);


	//if date is valid return 1 else return -1
///////////////////////////////
	if (valid1 == 1 && valid2 == 1)
	{


		if (y1 > y2)
		{
			return 2;

		}
		else if (y2 > y1)
		{
			return 1;

		}
		else
		{
			if (m1 > m2)
			{
				return 2;
			}
			else if (m1 < m2)
			{
				return 1;
			}
			else{
				if (d1>d2)
				{
					return 2;
				}
				else if (d2 > d1)
				{
					return 1;
				}
				else
				{
					return 0;
				}
			}

		}

	}
	else
	{
		return -1;
	}

	}


	



int isdayvalid(char * dob1, int y1, int m1, int d1)
{

	//check if the year is the leap year
	int i = 0;
	while (dob1[i] != '\0')
	{
		i++;

	}
	if (i != 10)
	{
		return -1;
	}

	//
	while (dob1[i] != '\0')
	{
		if (dob1[i] == '-')
		{
			i++;
		}
		else if ((dob1[i]<48 || dob1[i]>57))
		{
			return -1;
		}
		else{
			i++;
		}

	}

	if (dob1[2] == '-' &&dob1[5] == '-'&& y1 >= 0 && m1 > 0 && m1 <= 12)
	{
		if ((y1 % 400 == 0 || (y1 % 100 != 0 && y1 % 4 == 0)))
		{
			//leap year
			if (m1 == 2)
			{
				if (d1 < 0 || d1 > 29)
				{
					return -1;
				}
			}

		}

		else{
			//not a leap year



			if (m1 == 2)
			{
				if (d1<0 || d1>28)
				{
					return -1;
				}
			}
		}


		if (m1 % 2 == 1)
		{
			if (d1 <= 0 || d1>31)
			{
				return -1;
			}
		}
		else if ((m1 % 2 != 1))
		{
			if (d1 <= 0 || d1>30)
			{
				return -1;
			}

		}


		return 1;
	}
	else
	{
		return -1;
	}

	
}
