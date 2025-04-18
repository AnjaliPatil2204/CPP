#include<iostream>
using namespace std;
class Animal{
	public:
		void eat(){
			cout<<"Eating..."<<endl;
		}
};
class Dog : public Animal{
	    public : void Bark(){
	    	cout<<"Barking"<<endl;
		}
	
};
int main(){
Dog d;
d.eat();
d.Bark();
}
