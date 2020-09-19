#include<fstream>
#include<cstring>
#include<iostream>
using namespace std;
class Contact
{
	public:
	string details[5]={"Name","Phone(Mobile)","Address","Email",""};
	void adding()
	{
		ofstream fout;
    	fout.open("ContactBook.txt",ios::app);
    	char inpt[30];
    	fout<<"\n";
    	for(int i=0;i<4;i++)
    	{
    		cin.getline(inpt,30);
    		cout<<details[i]<<": ";
    		fout<<inpt<<"\n";
		}
		cin.getline(inpt,30);
		fout<<inpt;
	}
	void listing()
	{
		ifstream fin;
    	fin.open("ContactBook.txt",ios::in);
    	char inpt[30];
    	int i=0;
    	while(fin)
    	{
    		fin.getline(inpt,30);
    		if(i!=4)
    		cout<<details[i]<<" : "<<inpt<<endl;
    		else
    		cout<<details[i]<<inpt<<endl;
    		i++;
    		if(i==5)
    		i=0;
    	}		
	}
	void searching()
	{
    	string name;
    	cout<<"Enter name whose contact is to be searched: ";
    	getline(cin>>ws,name);
    	ifstream fin;
    	fin.open("ContactBook.txt",ios::in);
    	string inpt;
    	int c=0;
    	while(fin)
    	{
    		getline(fin>>ws,inpt);
    		if(inpt==name)
			{
    			c++;
    			for(int i=0;i<4;i++)
    			{
					cout<<details[i]<<": "<<inpt<<endl;
					getline(fin>>ws,inpt);
    			}
			}
			if(c>0)
			break;
		}
	}
	void editing()
	{
		string name;
    	cout<<"Enter name whose contact is to be Edited: ";
    	getline(cin>>ws,name);
    	ifstream fin;
    	ofstream fout;
    	fin.open("ContactBook.txt",ios::in);
    	fout.open("ContactBookTemporary.txt",ios::out|ios::trunc);
    	string inpt;
    	int b=0;
    	int c=0;
    	while(!fin.eof())
    	{
    		getline(fin>>ws,inpt);
    		b++;
    		if(inpt==name)
			{
    			c++;
    			cout<<"Enter new details: \n";
    			for(int i=0;i<4;i++)
    			{
					string newdetail;
					cout<<"New "<<details[i]<<": ";
					getline(cin>>ws,newdetail);
					b++;
					fout<<newdetail<<"\n";
				}
    			for(int i=0;i<=3;i++,b++)
    				getline(fin>>ws,inpt);
    			fout<<"\n"<<inpt<<"\n";
			} 
			else
			{
				if(fin.eof()!=1)
				fout<<inpt<<"\n";
				else
				fout<<inpt;
				if(b%4==0 && fin.eof()!=1)
					fout<<"\n";
			}
		}
	}
	void deleting()
	{
		string name;
    	cout<<"Enter name whose contact is to be Deleted: ";
    	getline(cin>>ws,name);
    	ifstream fin;
    	ofstream fout;
    	fin.open("ContactBook.txt",ios::in);
    	fout.open("ContactBookTemporary.txt",ios::out|ios::trunc);
    	string inpt;
    	int b=0;
    	int c=0;
    	while(!fin.eof())
    	{
    		getline(fin>>ws,inpt);
    		b++;
    		if(inpt==name)
				c++;
    		else
			{
				if(c>=1&&c<=3)
					c++;
				else
				{
					if(fin.eof()!=1)
					fout<<inpt<<"\n";
					else
					fout<<inpt;
					if(b%4==0 && fin.eof()!=1)
					fout<<"\n";
				}
			}
		}
	}
	void temporary_to_original()
	{
		ofstream fout1;
		ifstream fin1;
		fout1.open("ContactBook.txt",ios::out|ios::trunc);
		fin1.open("ContactBookTemporary.txt",ios::in);
		char reading[30];
		while(!fin1.eof())
		{
			fin1.getline(reading,30);
			if(fin1.eof()==0)
			fout1<<reading<<"\n";
			else
			fout1<<reading;
		}
	}
	void exiting()
	{
		cout<<"\n\nThank You For Using Contact Management System\n\n";
		exit(0);
	}
	
};
 
int main()
{
	Contact object;
	cout<<"\n\t\t\t\t\t**** Welcome to Contacts Manager Application ****"<<endl;
	cout<<"INSTRUCTION: YOU CAN ONLY VIEW/SEARCH FOR A CONTACT IF YOU ARE A USER. TO EDIT, DELETE AN EXISTING CONTACT OR ADD ANY NEW CONTACT, SIGN IN AS ADMINISTRATOR."<<endl;
block:
	cout<<"\nSelect your identity(1/2)\n[1]USER\n[2]ADMIN\nEnter the choice:";
	int identity;
	int flag=0;
	int flag1=0;
	cin>>identity;
	if(identity==2)
	{
		char pass[5];
		cout<<"\n\nEnter Admin 5 digits Passcode: ";
		for(int i=0;i<5;i++)
		{
			cin>>pass[i];
		}
		ifstream fin_pass("password.txt");
		char corr_pass;
		for(int i=0;i<5;i++)
		{
			fin_pass.get(corr_pass);
			if(pass[i]!=corr_pass)
			flag1++;
		}
	
		if(flag1==0)
			cout<<"\n\nWELCOME ADMIN\n\n";
		else
		{
			identity=1;
			cout<<"WRONG PASSCODE, YOU ARE SIGNED IN AS USER ONLY\n\n\nWELCOME USER\n\n";
		}
	}
	else
		cout<<"\n\nWELCOME USER\n\n";
	while(1)
	{
		cout<<"\n\n\t\t\t\t\t\tMAIN MENU\n\t\t\t\t\t=====================\n\t\t\t\t\t[1] Add a new Contact\n\t\t\t\t\t[2] List all Contacts\n\t\t\t\t\t[3] Search for contact\n\t\t\t\t\t[4] Edit a Contact\n\t\t\t\t\t[5] Delete a Contact\n\t\t\t\t\t[0] Exit\n\t\t\t\t\t=================\n\t\t";
    	cout<<"\t\t\tEnter the choice:";
    	int op;
    	cin>>op;
    	switch(op)
    	{
			case 1:
    		{
    			if(identity==1)
    			{
				cout<<"\n\nSign in as Admin to add a new contact.\n\n";
				flag++;
				}
    			else
    			{
				object.adding();
				cout<<"\nSuccessfully Added.\n";
				}
    			break;
		 	}
    		case 2:
    		{
				object.listing();
    			break;
    		}
    		case 3:
    		{
    			object.searching();
				break;
			}
			case 4:
			{
				if(identity==1)
				{
					cout<<"\n\nSign in as Admin to add a new contact.\n\n";
					flag++;
				}
    			else
    			{
					object.editing();
    				object.temporary_to_original();
    				cout<<"\nSuccessfully Edited.\n";
    			}
				break;
			}
			case 5:
    		{
    			if(identity==1)
    			{
					cout<<"\n\nSign in as Admin to add a new contact.\n\n";
					flag++;
				}
    			else
    			{
					object.deleting();
    				object.temporary_to_original();
    				cout<<"\nSuccessfully Deleted.\n";
    			}
				break;
			}
			case 0:
			{
				object.exiting();
			}
			default:
				cout<<"\n\nInvalid choice. Try again\n\n";
		}
		if(flag==1)
		{
			flag=0;
			goto block;
		}
	}
	return 0;
}
