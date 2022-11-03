#include <iostream>
using namespace std;

int main(){
	char op;
	long long n1,n2;
	cout<<"Enter 1st number : ";
	cin>>n1;
	cout<<"\nEnter an operation between (+, -, * ,/) : ";
	cin>>op;
	switch(op)
	{
		case '+':
			cout<<"\nEnter 2nd number : ";
			cin>>n2;
			cout<<"\nSum of two numbers : "<<n1<<" + "<<n2<<" = "<<n1+n2;
			break;
		case '-':
			cout<<"\nEnter 2nd number : ";
			cin>>n2;
			cout<<"\nSubtract of two numbers : "<<n1<<" - "<<n2<<" = "<<n1-n2;
			break;
		case '*':
			cout<<"\nEnter 2nd number : ";
			cin>>n2;
			cout<<"\nMultiplication of two numbers : "<<n1<<" * "<<n2<<" = "<<n1*n2;
			break;
		case '/':
			cout<<"\nEnter 2nd number : ";
			cin>>n2;
			if(n2 != 0)
				cout<<"\nDivision of two numbers : "<<n1<<" / "<<n2<<" = "<<(double)n1/n2;
			else
				cout<<"Syntax error.\n";
			break;
	}
	return 0;
}
