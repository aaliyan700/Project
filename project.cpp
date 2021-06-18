#include<iostream>
#include<conio.h>
#include<string.h>
#include<unistd.h>
using namespace std;
struct student
{
	int id;
	char name[30];
	float cgpa;
}s[100];


void title();           //used for title
void frontpage();       //used for frontpage
int login();            //used for password login
void menu();            //used for dispalying main menu
void add();             //used for adding record
void view_search();     //used for viewing / searching record
void del();             //used for deleteing record
void update();          //used for updating record
void exit();            //used to exit


int login()
{
	char pass[30]={"aliyan123"};
	char cpass[30],ch;
	int i=0,attempt=0;
	do
	{
		i=0;
		system("cls");
	    cout<<"\n\n";
	    cout<<"\t\t\t------------\n";
	    cout<<"\t\t\t|USER LOGIN|\n";
	    cout<<"\t\t\t------------\n";
		cout<<"\n\n\n\t\tEnter your password\n\t\t";
		while((ch=getch())!='\r')
		{
		
			if(ch==8)
			{
				cout<<"\b \b";
				i--;
			}
		
			cout<<"*";
			cpass[i]=ch;
			i++;
			if(ch==8)
			{
				cout<<"\b \b";
				i--;
			}
		}
		cpass[i]='\0';
		if(strcmp(cpass,pass)==0)
		{
		cout<<"\n\t\tValid Password";
		system("cls");
		cout<<"\n\n";
		cout<<"\t\t\t  ---------\n";
		cout<<"\t\t\t  |WELCOME|\n";
		cout<<"\t\t\t  ---------\n";
		cout<<"\n\n\n\n\t\t  <--You are accessed to the system--> \n\n";
		cout<<"\t\t      Press Enter to continue ";
		getch();
		system("cls");
		menu();
		}
		else
		{
			system("cls");
			attempt=attempt+1;
			cout<<"\n\n\n\n\n\n\n\n\n\n\t\t\tInvalid Password !";
			cout<<"\n\n\n\n\n\t\tNumber of attempts remaining:"<<3-attempt;
			getch();
			system("cls");
			
		if(attempt>=3)
		{
			cout<<"\t\t\t\t\t\t\n\n\n\n\n\n\t\t";
			cout<<"No permission to enter the system !";
			getch();
			exit();
			getch();
		}
}
 }
while(true);
}

void exit()
{
	system("cls");
	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t";
	cout<<"    <--You are out of system--> \n\n\n";
	cout<<"\t\t\t   ---------\n";
	cout<<"\t\t\t   |GOODBYE|\n";
	cout<<"\t\t\t   ---------";
	exit(0);
}

void title()
{
	system("color B");
	cout<<"\n\n\n";
	cout<<"\t\t\t\t\t";
	cout<<"\n";
	cout<<"\t\t    ---------------------------\n";
	cout<<"\t\t    |STUDENT MANAGEMENT SYSTEM|\n";
	cout<<"\t\t    ---------------------------\n";
	cout<<"\n\n";
	cout<<"\t\t";
}

void frontpage()
{
	
	
	cout<<"PROJECT PREPARED BY     :";
	cout<<"\t(Muhammad Aaliyan)\n\n\n";
	cout<<"\t\t\tPress Enter to Continue...\n\n\n";
	getch();
	system("cls");
	
	cout<<"\n\n\n\n\n\n\n\t\t\tLOADING";
    for(int process=0;process<6;process++)
	{
		sleep(1);
		cout<<".";
}
}

void menu()
{
	int choice;
	system("cls");
	cout<<"\n\n";
	cout<<"\t\t    ---------------------------\n";
	cout<<"\t\t    |STUDENT MANAGEMENT SYSTEM|\n";
	cout<<"\t\t    ---------------------------\n\n";
	cout<<"\t\tWhat would you like to choose ?\n\n";
	cout<<"\t\t1.ADD RECORD\n";
	cout<<"\t\t2.VIEW /SEARCH RECORD\n";
	cout<<"\t\t3.UPDATE RECORD\n";
	cout<<"\t\t4.DELETE RECORD\n";
	cout<<"\t\t5.EXIT\n\n";
	cout<<"\t\tChoose Options:[1/2/3/4/5]";
	cin>>choice;
	switch(choice)
	{
		case 1:
			system("cls");
			add();
			break;
		case 2:
			system("cls");
			view_search();
			break;
		case 3:
			system("cls");
			update();
			break;
		case 4:
			system("cls");
			del();
			break;
		
		case 5:
			system("cls");
			exit();
		
		default:
			cout<<"Invalid Choice!";
			
	}
}

void add()
{
	record:
	int n,f=0;
	char ch;
	cout<<"\n\n";
	cout<<"\t\t        ------------\n";
	cout<<"\t\t        |ADD RECORD|\n";
	cout<<"\t\t        ------------\n\n\n\n";
	cout<<"\t\tHow many records you want to enter?";
	cin>>n;
	system("cls");

	for(int i=0;i<n;i++)
	{
	cout<<"\n\n";
	cout<<"\t\t        ------------\n";
	cout<<"\t\t        |ADD RECORD|\n";
	cout<<"\t\t        ------------\n\n\n\n";
	cout<<"\t\t       Enter Information Below...\n\n\n";
	cout<<"\t\t       Enter Student ID     :   ";
	cin>>s[i].id;
	cout<<"\t\t       Enter Student Name   :  ";
	cin.ignore();
	cin.get(s[i].name,30);
	cout<<"\t\t       Enter Student CGPA   :   ";
	cin>>s[i].cgpa;	
	f++;
	system("cls");

	}
	system("cls");
	cout<<"\n\n";
	cout<<"\t\t        ------------\n";
	cout<<"\t\t        |ADD RECORD|\n";
	cout<<"\t\t        ------------\n\n\n\n";
	cout<<"\n\n\t\t<--Record added successfully-->\n\n";
	cout<<"\t\t  Do you want to add more?(Y/N)";
	cin>>ch;
	system("cls");
	if(ch=='Y'||ch=='y')
	goto record;
	if(ch=='N'||ch=='n')
	menu();
}


void view_search()
{
	int search,f=0,i;
	search:
	cout<<"\n";
	cout<<"\t\t        ----------------------\n";
	cout<<"\t\t        |VIEW / SEARCH RECORD|\n";
	cout<<"\t\t        ----------------------\n\n\n\n";
	cout<<"\t\tEnter ID to search student's record:";
	cin>>search;
	system("cls");
	for(i=0;i<search;i++)
	{
	if(search==s[i].id)
	{
		f++;
		break;
	}
}
	if(search!=s[i].id)
	{
		cout<<"\n";
	    cout<<"\t\t        ----------------------\n";
	    cout<<"\t\t        |VIEW / SEARCH RECORD|\n";
	    cout<<"\t\t        ----------------------\n\n\n\n";
		cout<<"\n\n\t\t<--Record not found-->\n\n\t\tPlease Enter record first";
		getch();
		system("cls");
		add();
	}
	else
	{
		for(;i<search;i++)
		{
		cout<<"\n";
	    cout<<"\t\t        ----------------------\n";
	    cout<<"\t\t        |VIEW / SEARCH RECORD|\n";
	    cout<<"\t\t        ----------------------\n\n\n\n";
	    cout<<"\t\t      <--Record searched successfuly -->\n\n\n";
	    cout<<"\t\t        Press any key to view record";
	    getch();
	    system("cls");
	    cout<<"\n";
	    cout<<"\t\t        ----------------------\n";
	    cout<<"\t\t        |VIEW / SEARCH RECORD|\n";
	    cout<<"\t\t        ----------------------\n\n\n\n";
	    
		cout<<"\t\t     Record is as follow:\n\n\n";
		cout<<"\t\t     Student ID        :     "<<s[i].id<<"\n";
		cout<<"\t\t     Student Name      :    "<<s[i].name<<"\n";
		cout<<"\t\t     Student CGPA      :     "<<s[i].cgpa<<"\n\n";
		char choice;
		cout<<"\t\t     Do you want to search another record?(Y/N)";
		cin>>choice;
		system("cls");
		if(choice=='Y'||choice=='y')
		goto search;
		if(choice=='N'||choice=='n')
		menu();
}

}
}

void update()
{
	int i,id,size,f=0,choice;
	upd:
	cout<<"\n";
	cout<<"\t\t        ---------------\n";
	cout<<"\t\t        |UPDATE RECORD|\n";
	cout<<"\t\t        ---------------\n\n\n\n";
	cout<<"\t\tEnter Student ID to update record:";
	cin>>id;
	system("cls");
	for(i=0;i<id;i++)
	{
	if(id==s[i].id)
	{
		cout<<"\n";
	    cout<<"\t\t        ---------------\n";
	    cout<<"\t\t        |UPDATE RECORD|\n";
	    cout<<"\t\t        ---------------\n\n\n\n";
		cout<<"\t\tEnter new ID      :   ";
		cin>>s[i].id;
		cout<<"\t\tEnter new Name    :  ";
		cin>>s[i].name;
		cout<<"\t\tEnter new CGPA    :   ";
		cin>>s[i].cgpa;
		f++;
		system("cls");
		
	cout<<"\n";
	cout<<"\t\t        ---------------\n";
	cout<<"\t\t        |UPDATE RECORD|\n";
	cout<<"\t\t        ---------------\n\n\n\n";
	cout<<"\t\t     <--Record updated suucessfully-->\n\n\n";
	cout<<"\t\t     Press any key to view updated record";
	getch();
	system("cls");

	for(i;i<id;i++)
	{
	cout<<"\n";
	cout<<"\t\t        ---------------\n";
	cout<<"\t\t        |UPDATE RECORD|\n";
	cout<<"\t\t        ---------------\n\n\n\n";
	cout<<"\t\t     Updated record is as follow:\n\n\n";
	cout<<"\t\t     Student ID       :  "<<s[i].id<<"\n";
	cout<<"\t\t     Student Name     : "<<s[i].name<<"\n";
	cout<<"\t\t     Student CGPA     : "<<s[i].cgpa<<"\n\n";
	
}
break;	
}
}

	if(f==0)
	{
		cout<<"\n";
	    cout<<"\t\t        ---------------\n";
	    cout<<"\t\t        |UPDATE RECORD|\n";
	    cout<<"\t\t        ---------------\n\n\n\n";
		cout<<"\t\t<--Record not found-->\n\n\t\tPlease Enter record first";
		getch();
		system("cls");
		add();
	}


	cout<<"\t\tDo you want to update another record?(Y/N)";
	char ch;
	cin>>ch;
	system("cls");
	if(ch=='Y'||ch=='y')
	goto upd;
	if(ch=='N'||ch=='n')
	menu();
}

void del()
{
	char ch;
	int id,f=0,i,p;
	del:
	cout<<"\n";
	cout<<"\t\t        ----------------\n";
	cout<<"\t\t        |DELETE  RECORD|\n";
	cout<<"\t\t        ----------------\n\n\n\n";
	cout<<"\t\tEnter ID to delete record:";
	cin>>id;
	system("cls");
	for(i=0;i<30;i++)
	{
	 if(id==s[i].id)
	{
		f++;
		p=i;
		cout<<"\n";
	    cout<<"\t\t        ----------------\n";
	    cout<<"\t\t        |DELETE  RECORD|\n";
	    cout<<"\t\t        ----------------\n\n\n\n";
		cout<<"\t\t<--Record deleted successfully--> ";
		break;

	}
	}
		

	if(f>0)
	{
		for(i=p;i<30;i++)
		{
           s[i].id=s[i+1].id;
		   s[i].cgpa=s[i+1].cgpa;
		   strcpy(s[i].name," ");  			
		}
	}
	else
	{
		cout<<"\n";
	    cout<<"\t\t        ----------------\n";
	    cout<<"\t\t        |DELETE  RECORD|\n";
    	cout<<"\t\t        ----------------\n\n\n\n"; 
		cout<<"\t\t<--Record not found-->\n\n\t\tPress any key to add record";
		getch();
		system("cls");
		add();
}

}


int main()
{
	
	title();
	frontpage();
	system("cls");
	login();
	menu();
	
	return 0;
}
