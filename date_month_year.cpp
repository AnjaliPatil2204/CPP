#include<iostream>
#include<iomanip>
using namespace std;
class Date{
	private:
		int day;
		int month;
		int year;
	public:
		int getInfo()
		{
			
			cout<<setw(2)<<setfill('0')<<day<<"-"<<setw(2)<<setfill('0')<<month<<"-"<<year<<endl;
		}
		int setInfo()
		{
			cout<<"enter the day"<<endl;
			cin>>day;
			cout<<"enter the month"<<endl;
			cin>>month;
			cout<<"enter the year"<<endl;
			cin>>year;
		}
};
int main()
{
	Date d1;
	d1.setInfo();
	d1.getInfo();
	
	
	
	
}


