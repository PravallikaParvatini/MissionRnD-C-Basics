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

int isOlder(char *dob1, char *dob2) {
	int i, j = 0, count1 = 0, count2 = 0, t1 = 0, t2 = 0, a[10], b[10];
	if (*(dob1 + 2) != '-' || *(dob1 + 5) != '-' || *(dob2 + 2) != '-' || *(dob2 + 5) != '-')
		return -1;
	for (i = 0; *(dob1 + i) != '\0'; i++)
		count1++;
	for (i = 0; *(dob2 + i) != '\0'; i++)
		count2++;
	if (count1 > 10 || count2 > 10)
		return -1;
	for (i = 0; i <=10; i++)
	{
		if (*(dob1 + i) != '-'&&*(dob2 + i) != '-'&&*(dob1 + i) != '\0'&&*(dob2 + i) != '\0')
		{
			t1 = (t1 * 10) + (*(dob1 + i)-48);
			t2 = (t2 * 10) + (*(dob2 + i)-48);
		}
		else
		{
			a[j] = t1;
			b[j] = t2;
			j++;
			t1 = 0;
			t2 = 0;
		}
	}
	if (a[0] < 1 || a[0]>31 || b[0] < 1 || b[0]>31 || a[1] < 1 || a[1]>12 || b[1] < 1 || b[1]>12)
		return -1;
	if ((a[0] > 30 && (a[1] == 4 || a[1] == 6 || a[1] == 9 || a[1] == 11)) || (b[0] > 30 && (b[1] == 4 || b[1] == 6 || b[1] == 9 || b[1] == 11)))
		return -1;
	if ((a[0] > 29 && a[1] == 2) || (b[0] > 29 && b[1] == 2))
		return -1;
	if ((a[2] % 4 != 0 && a[1] == 2 && a[0] > 28) || (b[2] % 4 != 0 && b[1] == 2 && b[0] > 28))
		return -1;
	if (a[2] > b[2])
		return 2;
	if (b[2] > a[2])
		return 1;
	if (a[2] == b[2])
	{
		if (a[1] > b[1])
			return 2;
		if (b[1] > a[1])
			return 1;
		if (a[1] == b[1])
		{
			if (a[0] > b[0])
				return 2;
			if (b[0] > a[0])
				return 1;
			if (a[0] == b[0])
				return 0;
		}
	}
}
