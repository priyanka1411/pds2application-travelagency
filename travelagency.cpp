#include<iostream>
#include<cstdlib>
using namespace std;

class travel
{
	char name[30];
	int age;
	char bloodgrp[10];
	public:
	struct dob
	{
		int date,month,year;
	}d;
	void get_data();
	struct dob set_dob();
	char* set_name();
	int set_age();
	//void display(int p)=0;
		
};
void travel::get_data()
{
	cout<<endl<<"Enter the name";
	cin>>name;
	cout<<endl<<"Enter the age";
	cin>>age;
	cout<<endl<<"Enter date of birth in dd/mm/yyyy";
	cin>>d.date>>d.month>>d.year;
	cout<<endl<<"Enter the blood group";
	cin>>bloodgrp;
}
char* travel::set_name()
{
	return name;
}
int travel::set_age()
{
	return age; 
}
/*struct dob set_dob()
{
	return d;
}*/
class package
{
	float rate;
	public:
	void show_package();	
	float calc_rate(int p);
	
};
void package::show_package()
{
	cout<<endl<<"Package 1: "<<"Madurai, Rameshwaram, Kannyakumai, Trivandrum";
	cout<<endl<<"Rate without travel charges: "<<calc_rate(1);
	cout<<endl<<"Package 2: "<<"Bangalore, Mysore, Coorg, Mangalore";
	cout<<endl<<"Rate without travel charges: "<<calc_rate(2);
	cout<<endl<<"Package 3: "<<"Delhi, Agra, Chandigarh, Shimla, Kulu-Manali";
	cout<<endl<<"Rate without travel charges: "<<calc_rate(3);
	cout<<endl<<"Package 4 : "<<"Kasi, Rishikesh, Haridwar, Benares";
	cout<<endl<<"Rate without travel charges: "<<calc_rate(4);
}
float package::calc_rate(int p)
{
	if(p==1)
	rate=12000.00;
	else if(p==2)
	rate=14000.00;
	else if(p==3)
	rate=15000.00;
	else if(p==4)
	rate=10000.00;
	return rate;
}
class flight:public travel,public package
{   
    public:
	float flight_fare,total_fare;
	float calc_fare(int p);
	void display(int p);
};
float flight::calc_fare(int p)
{ 
    int f_age=set_age();
	if(p==1)
	{
		if(f_age<=5)
		 flight_fare=10000.00;
		else
		 flight_fare=15000.00;
    }
    else if(p==2)
    {
    	if(f_age<=5)
    	flight_fare=7500.00;
    	else
    	flight_fare=12000.00;
	}
	else if(p==3)
	{
		if(f_age<=5)
		flight_fare=12000.00;
		else
		flight_fare=16000.00;
	}
	else if(p==4)
	{
		if(f_age<=5)
		flight_fare=5000.00;
		else
		flight_fare=7500.00;
	}
	total_fare=flight_fare+calc_rate(p);
	return total_fare;
}
void flight::display(int p)
{
	flight f1;
	cout<<endl<<"Package: "<<p;
	cout<<endl<<"Passenger's name: ";
	cout<<set_name();
	cout<<endl<<"Passenger's age: ";
	cout<<set_age();
	cout<<endl<<"Date of birth: ";
	cout<<d.date<<"/"<<d.month<<"/"<<d.year;
	cout<<endl<<"Total cost: ";
	cout<<calc_fare(p);
}
int main()
{
 package pack;
 flight f;
 int p;
 pack.show_package();
 f.get_data();
 cout<<"Enter the package of your choice";
 cin>>p;
 f.display(p);
 return 0;
 	
}	

		



