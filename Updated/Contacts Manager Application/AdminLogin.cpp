#include<iostream>
#include<fstream>
using namespace std;
class AdminLogin
{
	string Username;
	string Password;
	public:
		AdminLogin()
		{
			ifstream fin;
			fin.open("password.txt",ios::in);
			string user,pass;
			getline(fin,user);
			getline(fin,pass);
			Username=user;
			Password=pass;
		}
		bool checkCredentials(string user,string pass)
		{
			if(user==Username && pass==Password)
				return true;
			else 
				return false;
		}
};
