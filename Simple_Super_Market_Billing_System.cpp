#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class shopping{
	private:
		int pcode;
		float price,dis;
		string pname;
	public:
		void menu();
		void administrator();
		void buyer();
		void add();
		void edit();
		void rem();
		void list();
		void receipt();
};

void shopping :: menu(){
	m:
	int choice;
	string email,password;
	cout<<"\t\t\t\t_________________________\n";
	cout<<"\t\t\t\t|					   |\n";
	cout<<"\t\t\t\t| SuperMarket Main Menu |\n";
	cout<<"\t\t\t\t|				       |\n";
	cout<<"\t\t\t\t|_______________________|\n";
	cout<<"\t\t\t\t________________________\n";
	cout<<"\t\t\t\t|				      |\n";
	cout<<"\t\t\t\t|  1) Administrator    |\n";
	cout<<"\t\t\t\t|					  |\n";
	cout<<"\t\t\t\t|  2) Buyer            |\n";
	cout<<"\t\t\t\t|					  |\n";
	cout<<"\t\t\t\t|  3) Exit             |\n";
	cout<<"\t\t\t\t|					  |\n";
	cout<<"\t\t\t\t|______________________|\n";
	cout<<"\t\t\t\t________________________\n";
	cout<<"\t\t\t\t|  Please Select !     |\n";
	cin>>choice;
	switch(choice){
		case 1:
			cout<<"\t\t\tPlease Login \n";
			cout<<"\t\t\tEnter Your Email : \n";
			cin>>email;
			cout<<"\t\t\tEnter Password : \n";
			cin>>password;
			if(email == "abc@gmail.com" && password == "abc123")
				administrator();
			else
				cout<<"Invalid Email/Password\n";
			break;
		case 2:
			buyer();
		case 3:
			exit(0);
		default:
			cout<<"Please select from given value. Thank you.";
		}
	goto m;
}

void shopping :: administrator(){
	m:
	int choice;
	cout<<"\n\n\n\t\t\t  Administrator Menu ";
	cout<<"\n\t\t\t|_____ 1) Add the Product    _____|";
	cout<<"\n\t\t\t|    						         |";
	cout<<"\n\t\t\t|_____ 2) Modify the Product _____|";
	cout<<"\n\t\t\t|    						         |";
	cout<<"\n\t\t\t|_____ 3) Delete the Product _____|";
	cout<<"\n\t\t\t|    	 					         |";
	cout<<"\n\t\t\t|_____ 4) Back to Main Menu  _____|";
	cout<<"\n\n\t\t Please Enter your choice ";
	cin>>choice;
	switch(choice){
		case 1: 
			add();
			break;
		case 2:
			edit();
			break;
		case 3:
			rem();
			break;
		case 4:
			menu();
			break;
		default:
			cout<<"Invalid choice!";
	}
	goto m;
}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\t\t\t Buyer  \n";
	cout<<"									 \n";
	cout<<"\t\t\t|_____ 1) Buy Product _____|\n";
	cout<<"		 |							|\n";
	cout<<"\t\t\t|_____ 2)  Go Back    _____|\n";
	cout<<"\t\t\tEnter your choice : ";
	cin>>choice;
	switch(choice){
		case 1:
			receipt();
			break;
		case 2:
			menu();
			break;
		default:
			cout<<"Invalid choice !";
	}
	goto m;
}

void shopping :: add(){
	m:
	fstream data;
	int c, token = 0;
	float p,d;
	string n;
	cout<<"\n\n\t\t\t Add new product ";
	cout<<"\n\n\t\t Product code of the Product ";
	cin>>pcode;
	cout<<"\n\n\t\t Name of the Product ";
	cin>>pname;
	cout<<"\n\n\t\t Price of the Product ";
	cin>>price;
	cout<<"\n\n\t\t Discount on Product ";
	cin>>dis;
	data.open("database.txt",ios::in);
	if(!data){
		data.open("database.txt",ios::app|ios::out);
		data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
		data.close();
	}
	else{
		data>>c>>n>>p>>d;
		while(!data.eof()){
			if(c == pcode)
				token++;
			data>>c>>n>>p>>d;
			}
		data.close();
		if(token == 1)
			goto m;
		else{
			data.open("database.txt",ios::app|ios::out);
			data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data.close();
		}
	}
	cout<<"\n\n\t\t Record inserted succesfully.";
}

void shopping :: edit(){
	m:
	fstream data,data1;
	int pkey,token = 0, new_code;
	float price1,discount;
	string name;
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
		cout<<"\n\n File doesn't exist.";
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pkey == pcode){
				cout<<"\n\t\t Product new code : ";
				cin>>new_code;
				cout<<"\n\t\t Name of the Product : ";
				cin>>name;
				cout<<"\n\t\t Price : ";
				cin>>price1;
				cout<<"\n\t\t Discount : ";
				cin>>discount;
				data1<<" "<<new_code<<" "<<name<<" "<<price1<<" "<<discount<<"\n";
				cout<<"\n\n\t\t Record edited.";
				token++;
			}
			else{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
				}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token ==0)
			cout<<"\n\n Record Not Found, sorry!";
		}
}

void shopping :: rem(){
	fstream data,data1;
	int pkey,token = 0;
	cout<<"\n\n\t\t Delete Product ";
	cout<<"\n\n\t\t Product code : ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data)
		cout<<"File doesn't exist.";
	else{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof()){
			if(pcode == pkey){
				cout<<"\n\n\t\tProduct deleted succesfully. ";
				token++;
				}
			else
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
		if(token==0)
			cout<<"\n\nRecord not found.";
	}
}

void shopping :: list(){
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|_______________________\n";
	cout<<"Product_No\t\tName\t\tPrice \n";
	cout<<"\n\n|_______________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof()){
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();
}

void shopping :: receipt(){
	fstream data;
	int arrc[100],arrq[100],c=0;
	char choice;
	float amount = 0, dis = 0, total = 0;
	cout<<"\n\n\t\t\t RECEIPT ";
	data.open("database.txt",ios::in);
	if(!data.eof())
		cout<<"\n\n Empty database.";
	else{
		data.close();
		list();
		cout<<"\n__________________________\n";
		cout<<"\n|				   		  |\n";
		cout<<"\n| Please place the order |\n";
		cout<<"\n|________________________|\n";
		do{
			m:
			cout<<"\n\n Enter product code : ";
			cin>>arrc[c];
			cout<<"\n\n Enter product quantity : ";
			cin>>arrq[c];
			for(int i = 0; i<c; i++){
				if(arrc[c] == arrc[i]){
					cout<<"\n\n Duplicate product. Please try again.";
					goto m;
				}
			}
		c++;
		cout<<"\n\nDo you wanna buy other product ? If yes,Then press y/Y else n/N";
		cin>>choice;
		}
		while(choice == 'y' || choice == 'Y');
		cout<<"\n\n\t\t_____ Receipt _____\n";
		cout<<"\nProduct No\tProduct Name\tProduct quantity\tPrice\tAmount\tAmount with discount\n";
		for(int i = 0; i<c; i++){
			data.open("database.txt",ios::in);
			data>>pcode>>pname>>price>>dis;
			while(!data.eof()){
				if(pcode==arrc[i]){
					amount = price*arrq[i];
					dis = amount - (amount*dis/100);
					total += dis;
					cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
						}
					data>>pcode>>pname>>price>>dis;
				}
			}
		data.close();
	}
	cout<<"\n\n____________________________";
	cout<<"\nTotal Amount : "<<total;
}
int main(){
	shopping s;
	s.menu();
}
