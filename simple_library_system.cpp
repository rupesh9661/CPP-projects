// code for online library system 
#include<iostream>
#include<fstream>  // for file handling 
#include<string.h>
#include<stdio.h>
#include<conio.h>  // for getch use
using namespace std;
int roll,  id , choice , wish; 
char b[20] , an[20];
void function();
// code for login page 
void login()
{
    system("cls");
	cout<<" ************welcome to online library***************\n .......... please! login to use this library............" <<endl;

	char p[20] = "welcome123";
	cout<<"NOte :  roll no  or teacher id or employee id is user id for student or teacher or admin respectively and  initial password for everyone is 'welcome123' "<<endl;
	char pas[20];
	
	cout<<" \t 1 : student \t 2 : teacher \t 3: admin\n";
	cout<<" ..........choose uor catogary.............."<<endl;
	cin>>choice;  // login choice 
	switch(choice)
	{
		 // case for student login 
		case 1: 
			system("cls");
			cout<<"............student login.............."<<endl;
			again:  // level for enter user id if it become incorrect 
			cout<<" enter user id  : ";
			cin>>roll;
			if(roll>700 && roll<750)
			{
			 password: // level for enter password again 
			cout<<" enter password : ";
			cin>>pas;
		   }
			else
			{
				cout<<" incorrect user id ! enter again \n";
				goto again;  // enter user id agin 
			}
			 
			if(strcmp(pas ,p)==0)
			cout<<" login successful !  ";
			else
			{
					cout<<" incorrect password ! try again \n";
					goto password ; // goto for enter password again 
				
			}
			
			break;
			
			
		 // case for teacher login 	
			
		case 2:
		     system("cls");
			cout<<"............teacher login.............."<<endl;
			
	    	user:  // level for enter user id if it become incorrect 
			cout<<" enter user id : ";
			cin>>id;
			
			if(id>100 && id<200)
			{
			 passw: // level for enter password again 
			cout<<" enter password : ";
			cin>>pas;
		   }
			else
			{
				cout<<" incorrect user id ! enter again \n";
				goto user;  // enter user id agin 
			}
			 
			if(strcmp(pas ,p)==0)
			cout<<" login successful ! ";
			else
			{
					cout<<" incorrect password ! try again \n";
					goto passw ; // goto for enter password again 
				
			}
			
			break;
		
		// case for admin
		
		case 3:
		    system("cls");
			cout<<"............admin login.............."<<endl;
				ad:  // level for enter user id if it become incorrect 
			cout<<" enter user id : ";
			cin>>id;
			
			if(id>10 && id<20)
			{
			 pass: // level for enter password again 
			cout<<" enter password : ";
			cin>>pas;
		   }
			else
			{
				cout<<" incorrect user id ! enter again \n";
				goto ad;  // enter user id agin 
			}
			 
			if(strcmp(pas ,p)==0)
			cout<<" login successful ! ";
			else
			{
					cout<<" incorrect password ! try again \n";
					goto pass ; // goto for enter password again 
				
			}
	}
	
}

// code for dashboard 

void dashboard()
{
	  system("cls");
	if(choice==1)
	{
		system("cls");
		cout<<"\n dashboard \n 1: show all books \t 2: search \t 3: borrow a book \t 4: return a book \t 5: logout  "<<endl;
	}
	if(choice==2)
	{
	    system("cls");
		cout<<" \ndashboard \n 1: show all books \t 2: search \t 3: borrow a book \t 4: return a book \t 5: logout  "<<endl;
	}
	
		if(choice==3)
	{
	     system("cls");
		cout<<" \ndashboard \n 1: show all books \t 2: search \t 11: add book \t 12: update book details \t 13: delete book  \t 5: logout "<<endl;
	}
	
}


 // code for book 
 class book{
 	int id ;
	 public:
 	char bname[30] , aname[50] , pname[100] , edition[10] ;
	 void setdata()
	 {

	 	char a;
	 	
	 	cout<<" enter book id : ";
	 	cin>>id;
		 cin.ignore();
	 	cout<<" enter book name : ";
	 	gets(bname);
	 	cout<<" enter author name : ";
	 	gets(aname);
	 	cout<<" enter publisher name : ";
	 	gets(pname);
	 	cout<<" enter edition of book : ";
	 	gets(edition);
	 	cout<<" your data has been saved successfully ! "<<endl;
	 	
	  } 

	 void showbooks()   // this shows entered data of book 
	 {
		 
		 cout<<"\n " <<id <<"\t"<<bname<<"\t"<<aname<<"\t"<<edition <<"\t"<<pname <<endl;
	 } 

	int store();  // store book details in file 
	void viewallbooks(); // view all book from file  
 	void search();   // for searching desired book
	void deletebook();
	void updatebook();
 };

// code for storing book data in a file ,enterd by admin
 int book ::store()
 {
	 ofstream fout; // storing entered data in a file 
	 fout.open("book list.txt" ,ios::app | ios::binary);
	 fout.write((char*)this , sizeof(*this)) ; // write function is predifined and formal argument is char type of pointer in their defintion
	 fout.close();
	 return 1;
 }
 
 //code for show book list from file 
 void book::viewallbooks()
 {
	 ifstream fin;
	 fin.open("book list.txt" , ios::app | ios::binary);
	 fin.read((char*)this , sizeof(*this));
	 while(!fin.eof())
	 {
		 showbooks();  // it will show stored data in caller object from file 

		 fin.read((char*)this , sizeof(*this));

	 }
	 fin.close();

 }

 //code for search
void book::search()
{
	int counter=0;
	char bn[30];
	cin.ignore();

	cout<<" enter book name : ";
	
	gets(bn);
	ifstream fin;
	fin.open("book list.txt" , ios::in | ios::binary);
	fin.read((char*)this , sizeof(*this));
	while(!fin.eof())
	{
		if(!strcmp(bn, bname ))
		{
			showbooks();
			counter++;
		}
		fin.read((char*)this ,sizeof(*this));
	}
	fin.close();
	if(counter==0)  // if record does not match 
	cout<<"record not found ! ";
}

//code for delete book
void book::deletebook()
{
	char bn[30];
	cin.ignore();
	cout<<" enter the book name ";
	gets(bn);
	ifstream fin;
	ofstream fout;
	fin.open("book list.txt" , ios::in | ios::binary);
	fin.read((char*)this , sizeof(*this));
	fout.open("temp.txt" , ios::out | ios::binary);
	while(!fin.eof())
	{
		if(strcmp(bn ,bname))

		fout.write((char*)this , sizeof(*this));
		fin.read((char*)this , sizeof(*this));
		
		
	}
	fin.close();
	fout.close();
	remove("book list.txt");

	rename("temp.txt" , "book list.txt");
}

// code for update book 
void book::updatebook()
{
	char bn[30];
	cin.ignore();
	cout<<"enter the book name ";
    gets(bn);
	fstream file;
	file.open("book list.txt" , ios::in | ios::ate| ios::out |ios::binary);
	file.seekg(0);  // seekg function move pointer to offset place , it is same as fseekp function
	file.read((char*)this , sizeof(*this));
	while(!file.eof())
	{
		if(!strcmp(bn , bname))
		{
			setdata();
			file.seekg(file.tellp()-sizeof(*this)); // tellp function tells about current position of pointer
			file.write((char*)this , sizeof(*this));

		}
		file.read((char*)this , sizeof(*this));
	
	}

}

// code for return to previous page 

void prevpage()
{
	char ch;
	
	cout<<" \n if you want to go on previous page , press p  \n if you want to logout press any key "<<endl;
		     cin>>ch;
			   system("cls");
	         
		     if(ch=='p')
		    {
              dashboard();
			  function();
		    }
			else
			cout<<"log out successful";
}

 // code for functionallity choice
void function()
{
	book b1;
	cin>>wish;  // functionallity wish
	 
 	switch(wish)
 	{
		 case 1:
		 system("cls");
		 b1.viewallbooks();
            prevpage();
		 break;
		 
		 case 2:
		 system("cls");
		 b1.search(); 
		   prevpage();
		 break;

		 case 3:
		  system("cls");
		 cout<<" sorry ! this feature is coming soon  "<<endl;
		  prevpage();
		break;
       
		 case 4:
		  system("cls");
		 cout<<" sorry ! this feature is coming soon  "<<endl;
		  prevpage();
		break;

 		case 11:
		 system("cls");
 			b1.setdata();  // add book
			 b1.store(); // data stored in a permanant file 
			 prevpage();
 		break;

		 case 12:
		   system("cls");
		   b1.updatebook();
		   prevpage();

		 break;

		case 13:
		   system("cls");
		   b1.deletebook();
		   prevpage();
		 break;

		 case 5:
		     system("cls");
		     cout<<"log out successful";
		 break;

	 }
	
}

// driver code
 int main()
 {
	 
 	 login();
	  getch();  // it will stop the programme until a key not pressed
    dashboard();
	 function();
 	
 	return 0;
 }
  


