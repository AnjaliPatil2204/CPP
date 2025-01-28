#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	string item[3]={"Rice","Oil","Soap"};
	int price[3]={50,100,30};
	int sum=0;
	cout<<"Items\tPrices";
	cout<<"\n---------------";
	for(int i=0;i<3;i++)
	{
		cout<<"\n"<<item[i]<<"\t"<<setw(5)<<price[i];
		sum+=price[i];
	}
	 cout<<"\n---------------";
	 cout<<"\n"<<"Total\t"<<setw(5)<<sum;
	
}
