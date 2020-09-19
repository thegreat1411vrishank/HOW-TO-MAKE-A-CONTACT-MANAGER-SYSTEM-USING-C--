#include<iostream>
#include<fstream>
using namespace std;
class Administrator
{
	string Username;
	string Password;
	public:
		Administrator()
		{
			ifstream fin;
			fin.open("password.txt",ios::in);
			string user,pass;
			getline(fin,user);
			getline(fin,pass);
			Username=user;
			Password=pass;
		}
		Administrator(string Username_,string Password_): Username(Username_),Password(Password_)
		{
			ofstream fout;
			fout.open("password.txt",ios::out);
			fout<<Username<<"\n";
			fout<<Password;
			cout<<"Admin Created\n";
		}
		void setUser(string newUsername)
		{
			Username=newUsername;
			ofstream fout;
			fout.open("password.txt",ios::out);
			fout<<Username;
			fout<<Password;
		}
		void changeUsername()
		{
			cout<<"Enter new Username: ";
			string newUsername;
			cin>>newUsername;
			setUser(newUsername);
		}
		void setPass(string newPassword)
		{
			Password=newPassword;
			ofstream fout;
			fout.open("password.txt",ios::out);
			fout<<Username;
			fout<<Password;
		}
		void changePassword()
		{
			cout<<"Enter new Password: ";
			string newPassword;
			cin>>newPassword;
			setUser(newPassword);
		}
		void display_mydetails()
		{
			cout<<"Username: "<<Username<<endl;
			cout<<"Password: "<<Password<<endl;
		}
};

