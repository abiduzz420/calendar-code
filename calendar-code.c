#include <stdio.h>             //STDIO header file which includes printf and scanf functions
int onecent_odd();              //Function:tells how many odd days are there in one century year
void find_month(int arg);	//Function:displays the month of the date given
int century_odd(int arg1);      //Function:tells how many odd days are there in many century years
int ordinary_odd(int arg2);     //Function:tells how many odd days are there in preceding years
int leap_year(int arg3);        //Function:checks if the leap year is leap or not
int month_odd(int arr[],int arg4,int arg5);  //Function:finds no of odd days of the months of the given year
void find_day(int arg6);        //Function:gives information about the day which falls on that date
int main()
{
    int day,month,year;                   //declaration of the variables used
    int a,b,c,temp1;
    int calendar[12]={3,0,3,2,3,2,3,3,2,3,2,3}; 	//declaration of the calendar months odd days
    printf("enter the date(dd/mm/yyyy):");      	//system is asking to enter a date
    scanf("%d/%d/%d",&day,&month,&year);        //reading values of date
    a=century_odd(year);                        //to find no of century odd days
    b=ordinary_odd(year);                       /*to find no of odd days in between nearest century leap year
                                                        and the given year*/
    find_month(month);
    temp1=leap_year(year);                       //checking if the year is leap or not
    if(temp1==1||temp1==2)                          //initializing February to 1 odd days
    {
        calendar[1]=1;
        if(temp1==1) printf("Type of year:Century Leap Year\n");
        else printf("Type of year:Ordinary Leap Year\n");
    }
    else printf("Type of year:Non-Leap Year\n");
    c=month_odd(calendar,month,day);            /*to find no of odd days in the given year
                                                        			up to the date mentioned*/

    find_day(a+b+c);                         //calling for function to find the day which falls on the date
    return 0;
}

int century_odd(int num)
{
    int c1=(num/100)%4;                         

    return (onecent_odd()*c1);
}


int onecent_odd()
{
    int i=100;      //for one century year
    short int j=(i/4)-1;                        //no of leap years in one century year
    short int k=i-j;                            //no of ordinary years in one century year
    return (k+j*2);
}

int ordinary_odd(int num)
{
    int c2=(num%100)-1;                         //finds no of years preceding that year after century leap
    int c3=(c2/4);                              //no of leap years in that period
    return ((c3*2)+c2-c3);                      //leap year has 2 odd days,ordinary year has 1 odd day
}

void find_month(int num)
{
    switch(num)
    {
    case 1:
        printf("Month:January\n");
        break;
    case 2:
        printf("Month:February\n");
        break;
    case 3:
        printf("Month:March\n");
        break;
    case 4:
        printf("Month:April\n");
        break;
    case 5:
        printf("Month:May\n");
        break;
    case 6:
        printf("Month:June\n");
        break;
    case 7:
        printf("Month:July\n");
        break;
    case 8:
        printf("Month:August\n");
        break;
    case 9:
        printf("Month:September\n");
        break;
    case 10:
        printf("Month:October\n");
        break;
    case 11:
        printf("Month:November\n");
        break;
    case 12:
        printf("Month:December\n");
        break;
    }
}

int leap_year(int num)
{
    if(num%100==0)                              //checks if a year is century or not
    {
        if(num%400==0) return 1;                /*checks if a year is century leap year or not
      		                                              returns value 1 for leap and 0 for non leap*/
        else return 0;
    }
    else
    {
        if(num%4==0) return 2;                 /*checks if a year is ordinary leap year or not
		                                                    returns value 1 for leap and 0 for non leap*/
        else return 0;
    }
}

int month_odd(int arr[],int m,int n)
{
    int sum=0;
    for(int i=0;i<(m-1);i++)
    {
        sum+=arr[i];                        /*finding sum of all odd days of months
	                                                until the given month is encountered*/
    }
    return (sum+n);                         //returning the value with sum and the day of the given month
}

void find_day(int num)
{
    int result=num%7;                       //assigns the day according to the remainder obtained
    switch(result)
    {
    case 0:
        printf("It is Sunday\n");
        break;
    case 1:
        printf("It is Monnday\n");
        break;
    case 2:
        printf("It is Tuesday\n");
        break;
    case 3:
        printf("It is Wednesday\n");
        break;
    case 4:
        printf("It is Thursday\n");
        break;
    case 5:
        printf("It is Friday\n");
        break;
    case 6:
        printf("It is Saturday\n");
        break;
    }
}

