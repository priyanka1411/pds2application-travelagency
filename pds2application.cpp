#include<iomanip>
#include<string.h>
#include<iostream>

using namespace std;
using std::setw;
class travel
{
	char name[20];
	int age;
	char bldgrp[4];
	public:
		travel()
		{
		}
		void get_data()
		{
			cout<<"\n Enter passenger's name:";
			cin>>name;
			cout<<"\n Enter passenger's age:";
			cin>>age;
			cout<<"\n Enter passenger's bldgrp:";
			cin>>bldgrp;
		}
		void display_personal_details()
		{
			cout<<"\nYour ticket is confirmed!!HAVE A SAFE JOURNEY\nYour Personal Details:";
			cout<<"\n Name:"<<name<<"\n Age:"<<age<<"\n Blood Group:"<<bldgrp<<endl;
		}
		int getAge()
		{
			cout<<'\n'<<age<<endl;
			return age;
		}
};
class package
{

	char package_name[20];
	int days;
	float food_rate;
	float accdm_rate;
	float package_rate;
	public:
		//static int count;
		package()
		{
		//	count=0;
			cout<<"\n welcome to XYZ TRAVELS..";
		}
		package(char  *p_name,int d,float f_rate,float a_rate)
		{
			//count+=1;
			//cout<<"\n Package "<<count<<endl;
			strcpy(package_name,p_name);
			cout<<"\n*****The "<<package_name<<" tourist package includes:*****\n"<<endl;
			days=d;
			food_rate=f_rate;
			accdm_rate=a_rate;
			cout<<'\n'<<days<<" Days and "<<days-1<<" Nights accomodation (food inclusive)";
			cout<<"\nThe rate of food per day		:"<<food_rate;
			cout<<"\nThe rate of accomadation per day	:"<<accdm_rate;
		}

		float calc_rate();
};
float package::calc_rate()
{
	float sum;
	sum+=food_rate+accdm_rate;
	sum*=days;
	package_rate=sum;
	cout<<"\n the rate for the entire package "<<package_name<<" 	:"<<package_rate;
	cout<<"\n\n";	
	return sum;
}
class bus:public travel,public package
{
	float total_charge;
	float ticket_rate;
	public:
		bus(char *p_name,int d,float f_rate,float a_rate,float t_rate):package(p_name,d,f_rate,a_rate)
		{
			cout<<"\nThe ticket charge per head is		:"<<t_rate<<endl;
			ticket_rate=t_rate;			
		}
		void print()
		{
			if(getAge()<=12)
			{
				ticket_rate/=2;					
			}
			total_charge=ticket_rate+calc_rate();
			cout<<"\n\nTHANK YOU!!!\nThe bill is	:"<<total_charge<<endl;
		}
};
class flight:public travel,public package
{
	float total_fare;
	float flight_fare;
	public:
		flight(char *p_name,int d,float f_rate,float a_rate,float fl_rate):package(p_name,d,f_rate,a_rate)
		{
			cout<<"\nTicket charge per head is :"<<fl_rate<<endl;
			cout<<"70% deduction for children upto 5 yrs"<<endl;
			flight_fare=fl_rate;
		}
		void display()
		{
			if(getAge()<=5)
			{
				flight_fare=0.7*flight_fare;
			}
			total_fare=flight_fare+calc_rate();
			cout<<"\n\nTHANK YOU!!!\nThe total cost is :"<<total_fare<<endl;
		}
};
int main()
{
int ch,ch_1;

cout<<"\n*******Welcome To XYZ Travels*******\n";
cout<<"\n1.Domestic 2.International\nEnter your choice:";
cin>>ch;
switch(ch)
{
case 1:
	cout<<"*****Domestic Tourist Packages*****\n1.North India(NI)\n2.South India(SI)\n\n";
	bus b11((char*)"NorthIndia",07,900.00,700.00,3500.00);
	bus b12((char*)"SouthIndia",06,1000.00,800.00,2000.00);
	cout<<"\n Your choice:";	
	cin>>ch_1;
	switch(ch_1)
	{
		case 1:
			
			b11.get_data();
			b11.print();
			b11.display_personal_details();
			break;
		case 2:
		
			b12.get_data();
			b12.print();
			b12.display_personal_details();
			
			break;
		default:
			cout<<"\nWrong choice!!";
	}
	break;
case 2:
   cout<<"*****International Tour Packages*****\n1.Singapore and Malayasia\n2.Europe tour\n\n";
   flight f1((char*)"Singapore and Malayasia",01,1500.00,2000.00,30000.00);
   flight f2((char*)"Europe",02,2500.00,3000.00,60000.00);
   cout<<"\nYour choice: ";
   cin>>ch_1;
   switch(ch_1)
   {
   	case 1:
   		f1.get_data();
   		f1.display();
   		f1.display_personal_details();
   		break;
   	case 2:
	    f2.get_data();
		f2.display();
		f2.display_personal_details();
		break;
	default:
	    cout<<"\nPlease anter a valid choice";		
   }
   break;	
}
return 0;
}
