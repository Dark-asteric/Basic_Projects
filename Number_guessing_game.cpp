#include <iostream>
using namespace std;
int main(){
	int num,guess,tries=0;
	srand(time(NULL));
	num = rand()%100 + 1;
	
	cout<<"********** NUMBER Guessing GaMe **********\n\n";
	cout<<" ________________________________\n";
	do{
		cout<<"|Enter number between 1-100 : ";
		cin>>guess;
		cout<<"|";
		tries++;
		if(guess>num) cout<<"Too high!\n";
		else if(guess<num) cout<<"Too low!\n";
		else
			cout<<"Correct! # of tries : "<<tries<<"\n|\n";
	}while(num != guess);
	
	cout<<"|You Finish the Number guessing game.\n|Congratulation ! you found the number.\n|\n|Thank you.\n";
	cout<<" ________________________________\n";
	return 0;
}