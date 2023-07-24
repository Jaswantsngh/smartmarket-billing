#include<iostream>
#include<fstream>
using namespace std;

class shopping
{
private:
	int pcode;
	float price;
	float dis;
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
	string email;
	int password;
	cout<<"\t\t\t\t_______________________\n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t  Supermarket main menu \n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t_______________________\n";
	cout<<"\t\t\t\t                       \n";
	cout<<"\t\t\t\t   1)Administrator \n";
	cout<<"\t\t\t\t   2)Buyer         \n";
	cout<<"\t\t\t\t   3)Exit          \n";
	cout<<"\n\t\t\t Please selesct!";
	cin>>choice;
	switch(choice){
	   case 1:
		cout<<"\t\t\t Please login \n";
		cout<<"\t\t\t Enter Email   \n";
		cin>>email;
		cout<<"\t\t\t Password     \n";
		cin>>password;
		if(email=="jas@gmail.com" && password==9770){
			administrator();
		}else {
			cout<<"Invalid email and password \n";
		}
		break;
	   case 2:
	   {
	   	buyer();
	   }
	   case 3:
	   {
	   	exit(0);
	   }
       default :
       {
       	cout<<"Please select from the given option";
       }



	}
	goto m;
	

}

void shopping :: administrator(){
	m:
     int choice ;
     cout<<"\n\n\n\t\t\t Administrator menu";
     cout<<"\n\t\t\t____1)Add the product_____|";
     cout<<"\t\t\t\t                          |";
	
     cout<<"\n\t\t\t____2)Modify the product__|";
     cout<<"\t\t\t\t                          |";
	
     cout<<"\n\t\t\t____3)Delete the product__|";
     cout<<"\t\t\t\t                         |";
	cout<<"\n\t\t\t____4)Back to menu____|";
	  cout<<"\n\n\t Please enter your choice";
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
	  	default :
	  	    cout<<"Invalid choice!";

	  }
   cout<<"\n\t\t\t Do you want to further proceed? press y else n |";
   char c;
   cin>>c;
   if(c=='n')return;
   goto m;
}

void shopping :: buyer(){
	m:
	int choice;
	cout<<"\t\t\t   Buyer \n";
	cout<<"\t\t\t____________\n";
	cout<<"                  \n";
	cout<<"\t\t\t 1)Buy product \n";
	cout<<"                  \n";
	cout<<"\t\t\t 2) Go back \n";
	cout<<"                  \n";
	cout<<"\t\t\t enter you choice: ";
	cin>>choice;
	switch(choice){
		case 1:
		    receipt();
		    break;
		case 2:
		     menu();
		default :
		     cout<<"Invalid choice";    
	}
	goto m;
}


void shopping :: add(){
	m:
	fstream data;
	int c;
	int token=0;
	float p;
	float d;
	string n;
	cout<<"\n\n\t\t Add New product ";
	cout<<"\n\n\t Product code of the product";
	cin>>pcode;
	cout<<"\n\n name of the product ";
	cin>>pname;
	cout<<"\n\n\t Price of the product";
	cin>>price;
	cout<<"\n\n\t discount on the product ";
	cin>>dis;
	data.open("database.txt",ios::in);
	if(!data){
		data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
	}
	else {
		data>>c>>n>>p>>d;

		while(!data.eof()){
			if(c==pcode){
				token++;
			}
			data>>c>>n>>p>>d;
		}
		data.close();
	}
	if(token==1)goto m;
	else {
		data.open("database.txt",ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
	}
	cout<<"\n\n\t\t Record inserted !";
}


void shopping :: edit(){
	fstream data,data1;
	int pkey;
	int token;
	int c;
	float p;
	float d;
	string n;
	cout<<"\n\t\t\t Modify the record";
	cout<<"\n\t\t\t Product code :";
	cin>>pkey;
	data.open("database.txt" ,ios::in);
	if(!data){
		cout<<"\n\n File doesn't exist!";
	}else {

		data1.open("database1.txt",ios::app|ios::out);
        
        data>>pcode>>pname>>price>>dis;
        while(!data.eof()){
        	if(pkey==pcode){
        		cout<<"\n\n\t\t product new code: ";
        		cin>>c;
        		cout<<"\n\n\t name of the product: ";
        		cin>>n;
        		cout<<"\n\t\t price: ";
        		cin>>p;
        		cout<<"\n\t\t discount: ";
        		cin>>d;
        		data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
        		cout<<"\n\n\t\t Record edited ";
        		token++;
        	}
        	else 
        	{
        		data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        	}
        	data>>pcode>>pname>>price>>dis;
        }
        data.close();
        data1.close();

        remove("database.txt");
        rename("database1.txt","database.txt");
	}
	if(token==0){
		cout<<"\n\n\t\t Record not found! ";
	}

}



void shopping :: rem()
{
	fstream data,data1;
	int pkey;
	int token=0;
	cout<<"\n\n\t Delete product ";
	cout<<"\n\n\t product code: ";
	cin>>pkey;
	data.open("database.txt",ios::in);
	if(!data){
		cout<<"File dosen't exist ";
	}
	else
	{
		data1.open("database1.txt",ios::app|ios::out);
		data>>pcode>>pname>>price>>dis;
		while(!data.eof())
		{
			if(pcode==pkey)
			{
				cout<<"\n\n\t Product deleted succesfully ";
				token++;
			}
			else 
			{
				data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
			}
			data>>pcode>>pname>>price>>dis;
		}
		data.close();
		data1.close();
		remove("database.txt");
		rename("database1.txt","database.txt");
        if(token==0){
        	cout<<"\n\n Record not found ";
        }

	}
}


void shopping :: list()
{
	fstream data;
	data.open("database.txt",ios::in);
	cout<<"\n\n|_________________________________\n";
	cout<<"proNo\t\t Name \t\tPrice\n";
	cout<<"\n\n|_________________________________\n";
	data>>pcode>>pname>>price>>dis;
	while(!data.eof())
	{
		cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
		data>>pcode>>pname>>price>>dis;
	}
	data.close();

}



void shopping :: receipt()
{
	fstream data;
	int arrc[100];
	int arrq[100];
	char choice;
	int c=0;
	float amount;
	float dis=0;
	float total=0;
    cout<<"\n\n\t\t\t Reciept ";
    data.open("database.txt",ios::in);
    if(!data)
    {
    	cout<<"\n\n Empty database";
    }
    else 
    {
    	data.close();
    	list();
    	cout<<"\n____________________\n";
    	cout<<"\n|                    \n";
    	cout<<"\n   Place the order    \n";
    	cout<<"\n|                    \n";
        cout<<"\n____________________\n";
        do
        {
        	m:
        	cout<<"\n\n Enter Product code : ";
        	cin>>arrc[c];
        	cout<<"\n\n enter the quantity : ";
        	cin>>arrq[c];
        	for(int i=0; i<c; i++){
        		if(arrc[i]==arrc[c]){
        			cout<<"\n\n duplicate product code Please try again ";
        			goto m;
        		}
        	}
        	c++;
        	cout<<c;
        	cout<<"\n\n do you want to buy another product if yes then press y else n";
        	cin>>choice;
        }
        while(choice=='y');
        cout<<"\n\n\t\t\t __________Receipt____________\n";
        cout<<"\nProduct No \t product name \t Product quantity\t price\t amount\tamount with discount \n ";
        for(int i=0;i<c; i++){
        	data.open("database.txt",ios::in);
        	data>>pcode>>pname>>price>>dis;
        	while(!data.eof()){
        		if(arrc[i]==pcode)
        		{
        			cout<<"Ha ho gyab be \n";
        			amount=price*arrq[i];
        			dis=amount-(amount*dis/100);
        			total=total+dis;
        			cout<<"\n"<<pcode<<"\t"<<pname<<"\t"<<arrq[i]<<"\t"<<price<<"\t"<<amount<<"\t"<<dis;
        		}
        		data>>pcode>>pname>>price>>dis;
        	}
        	data.close();

        }
        data.close();
    }
    cout<<"\n\n______________________________";
    cout<<"\n Total amount : "<<total;
}


int main(){
	shopping s;
	s.menu();
}
