#include<iostream>
#include<fstream>
using namespace std;
class ContactBook
{

	string details[5]={"Name","Phone(Mobile)","Address","Email",""};
	public:
		void adding()
		{
			string vals[4];
			for(int i=0;i<4;i++)
			{
				cout<<details[i]<<": ";
				getline(cin>>ws,vals[i]);	
			}
			Contact contact(vals[0],vals[1],vals[2],vals[3]);
			contact.add(); 
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
			DeleteHelper deletehelperObject(name);
			deletehelperObject.deleteFromContactbook();
		}
};
