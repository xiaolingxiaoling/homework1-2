#ifdef _WIN32
#define  _CRT_SECURE_NO_WARNINGS
#endif
 
#include<stdio.h>
int Isleap(int year)
{
	if ((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0)))
		return 1;
	else
		return 0;
}

int Max_day(int year, int month)
{
	int Day[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (Isleap(year) == 1)
		Day[1] = 29;
	return Day[month - 1];
}

int Total_day(int year, int month, int day)
{
	int sum = 0;
	int i = 1;
	for (i = 1; i < month; i++)
		sum = sum + Max_day(year, i);
	sum = sum + day;
	return sum;
}

int Weekday(int year, int month, int day)
{
	int count;
	count = (year - 1) + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400 + Total_day(year, month, day);
	count = count % 7;
	return count;
}

void display_week(int year, int month, int day)
{
	int count;
	count = Weekday(year, month, day);
	switch (count)
	{
	case 0:printf("\t%d-%d-%d is Sunday\n", year, month, day); break;
	case 1:printf("\t%d-%d-%d is Monday\n", year, month, day); break;
	case 2:printf("\t%d-%d-%d is Tuesday\n", year, month, day); break;
	case 3:printf("\t%d-%d-%d is Wednesday\n", year, month, day); break;
	case 4:printf("\t%d-%d-%d is Thursday\n", year, month, day); break;
	case 5:printf("\t%d-%d-%d is Friday\n", year, month, day); break;
	case 6:printf("\t%d-%d-%d is Saturday\n", year, month, day); break;
	default: system("cls"); printf("error\n");
	}
}

void display_month(int year, int month, int day)
{
	int i = 0, j = 1;
	int week, max;
	week = Weekday(year, month, 1);
	max = Max_day(year, month);
	printf("\n\t\t\t%d��%d��", year, month);
	printf("\n\tSUN\tMON\tTUE\tWED\tTHU\tFRI\tSAT\n");
	for (i = 0; i < week; i++)
		printf("\t");
	for (j = 1; j <= max; j++)
	{
		printf("\t%d", j);
		if (i % 7 == 6)
			printf("\n");
		i++;
	}
	printf("\n");
}

int main()
{
	int year, month, day;
	printf("\tplease enter year,month,day: ");
	scanf("%d,%d,%d", &year, &month, &day);
	if (month<1 || month>12 || day<1 || day>31)
	{
		printf("error...\n");
		return -1;
	}
	printf(" \t%d��%d��%d������һ��ĵ�%d��\n\ ", year, month, day, Total_day(year, month, day));
	display_week(year, month, day);
	display_month(year, month, day);
	return 0;
}