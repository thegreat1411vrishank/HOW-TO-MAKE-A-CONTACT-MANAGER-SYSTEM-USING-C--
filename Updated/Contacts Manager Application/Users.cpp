#include<iostream>
#include<cstring>
using namespace std;
class Users
{
	string name;
	public:
		Users(string name_): name(name_){}
		void checkIn()
		{
			ofstream fout;
			fout.open("Users.txt",ios::app);
			fout<<name<<"\n"<<__TIMESTAMP__<<"\n";
		}
};
