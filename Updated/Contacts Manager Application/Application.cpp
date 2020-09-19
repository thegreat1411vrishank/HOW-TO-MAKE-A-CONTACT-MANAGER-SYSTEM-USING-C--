#include<iostream>
#include "Admin.cpp"
#include "AdminLogin.cpp"
#include "UserInterface.cpp"
#include "Contact.cpp"
#include "Users.cpp"
#include "ContactBook.cpp"
enum Identity{User=1,Admin,NewAdmin};
int main()
{
	UserInterface UI;
	UI.displayStart();
	while(1)
	{
		int choice=UI.MenuDisplayStart();
		switch(choice)
		{
			case User:
			{
				string name;
				cout<<"Enter Your Full name to make an entry into Users.txt: "; 
				getline(cin>>ws,name);
				Users user(name);
				user.checkIn();
				ContactBook cb;
				int flag=0;
				while(1)
				{
					int choice=UI.MenuDisplayUser();
					switch(choice)
					{
						case 1:
						{
							cb.listing();
							break;
						}
						case 2:
						{
							cb.searching();
							break;
						}
						case 0:
						{
							flag=1;
							break;
						}
					}
					if(flag==1) break;
				}
				break;
			}
			case Admin:
			{
				string uname,pass;
				cout<<"Enter Username & Password\n";
				cout<<"Username: "; cin>>uname;
				cout<<"Password: "; cin>>pass;
				AdminLogin AL;
				bool isLoggedIn=AL.checkCredentials(uname,pass);
				if(isLoggedIn)
				{
					ContactBook cb;
					int flag=0;
					while(1)
					{
						int choice=UI.MenuDisplayAdmin();
						switch(choice)
						{
							case 1:
							{
								cb.adding();
								break;
							}
							case 2:
							{
								cb.listing();
								break;
							}
							case 3:
							{
								cb.searching();
								break;
							}
							case 4:
							{
								cb.editing();
								break;
							}
							case 5:
							{
								cb.deleting();
								break;
							}
							case 0:
							{
								flag=1;
								break;
							}
						}
						if(flag==1) break;
					}
				}
				else
				{
					cout<<"\nWrong Password.\nContact the Developer if you forgot the password.\n";
				}
				break;
			}
			case NewAdmin:
			{
				string uname,pass;
				cout<<"Enter the username for new Admin: ";
				cin>>uname;
				cout<<"Enter(Create) the Password: ";
				cin>>pass;
				Administrator A(uname,pass);
				A.display_mydetails();
				break;
			}
			case 0:
			{
				cout<<"\n\nThank You For Using Contact Management Application\n\n";
				exit(0);
			}
		}
	}
	
}
