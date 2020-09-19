#include<iostream>
using namespace std;
class DeleteHelper
{
	private:
		string contactName;
	public:
		DeleteHelper(string name): contactName(name){}
		void deleting()
		{
			string name=contactName;
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
		void deleteFromContactbook()
		{
			deleting();
    		temporary_to_original();
    		cout<<"\nSuccessfully Deleted.\n";
		}
};
