#include<iostream>
#include "DeleteHelper.cpp"
using namespace std;
class Contact
{
	private:
		string contactName;
		string contactNumber;
		string contactAddress;
		string contactEmail;
	public:
		Contact(string name,string number,string address,string mail): contactName(name), contactNumber(number), contactAddress(address), contactEmail(mail) {}
		void display()
		{
			cout<<"\nName: "<<contactName;
			cout<<"\nNumber: "<<contactNumber;
			cout<<"\nAddress: "<<contactAddress;
			cout<<"\nEmail: "<<contactEmail;
		}
		void add()
		{
			ofstream fout;
			fout.open("ContactBook.txt",ios::app);
			fout<<"\n";
			fout<<contactName<<"\n";
			fout<<contactNumber<<"\n";
			fout<<contactAddress<<"\n";
			fout<<contactEmail<<"\n";
		}
};
