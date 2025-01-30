#include<iostream>
using namespace std;
int main()
{
	int balance=2000;
	int choice,amount;
	do{
		cout<<"\nBANK MENU"<<endl;
		cout<<"---------------"<<endl;
		cout<<"1.Check Balance"<<endl;
		cout<<"2.Deposite"<<endl;
		cout<<"3.Withdraw"<<endl;
		cout<<"4.Exit"<<endl;
		cout<<"Enter your choice";
		cin>>choice;
		if(choice==1)
		{
			cout<<"Balance:Rs."<<balance<<endl;
		}
		else if(choice==2)
		{
			cout<<"enter deposite amount:Rs.";
			cin>>amount;
			balance+=amount;
			cout<<"deposite successful!"<<endl;
			cout<<"new balance=Rs."<<balance<<endl;
		}
		else if(choice==3)
		{
		  cout<<"enter withdraw amount:Rs.";
		  cin>>amount;
	      if(balance>=amount)
	    	{
		    	balance-=amount;
			    cout<<"withdrawal successful!"<<endl;
		    	cout<<"new balance=Rs."<<balance<<endl;
	    	}
		   else
	     	{
			    cout<<"insufficient balance!"<<endl;
	     	}
	     }
        else if(choice==4)
          	{
		        cout<<"Your Total Amount is : Rs."<<balance<<endl;
				cout<<"exiting----"<<endl;
	        } 
	    else
	    {
		  cout<<"Invalide hoice!"<<"\n"<<"Please try again"<<endl;
	    }
    }
     while(choice!=4);
     return 0;
}
