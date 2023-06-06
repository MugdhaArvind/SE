#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
class student
  {
	typedef struct s
	{
		int roll_no;
		char name[10];
		char division;
		char address[10];
		
	}s;
	s record;
	public:
	  void create();
	  void display();
	  int search();
	  void Delete();
  };
void student::create()
  {
	char ch;
	ofstream o;
	o.open("student.dat",ios::out|ios::binary);
	do
	  {
		cout<<"\n\tEnter Roll No of Student    : ";
		cin>>record.roll_no;
		cout<<"\n\tEnter a Name of Student     : ";
		cin>>record.name;
		cout<<"\n\tEnter a Division of Student : ";
		cin>>record.division;
		cout<<"\n\tEnter a Address of Student  : ";
		cin>>record.address;
		o.write((char *)&record,sizeof(s))<<flush;
		cout<<"\n\tEnter 'y' if you want to Add More Records or else 'n': ";
		cin>>ch;
	  }
	  while(ch=='y'||ch=='Y');
	o.close();
  }
void student::display()
  {
	ifstream i;
	i.open("student.dat",ios::in|ios::binary);
	i.seekg(0,ios::beg);
	cout<<"\n\tThe Content of File are:\n";
	cout<<"\n\tRoll\tName\tDiv\tAddress";
	while(i.read((char *)&record,sizeof(s)))
	  {
		if(record.roll_no!=-1)
       		  cout<<"\n\t"<<record.roll_no<<"\t"<<record.name<<"\t"<<record.division<<"\t"<<record.address;
	  }
	i.close();
  }
int student::search()
  {
	int r,j=0;
	ifstream i;
	i.open("student.dat",ios::in|ios::binary);
	i.seekg(0,ios::beg);
	cout<<"\n\tEnter a Roll No: ";
	cin>>r;
	while(i.read((char *)&record,sizeof(s)))
	  {
		if(record.roll_no==r)
		  {
			cout<<"\n\tRecord Found...\n";
			cout<<"\n\tRoll\tName\tDiv\tAddress";
			cout<<"\n\t"<<record.roll_no<<"\t"<<record.name<<"\t"<<record.division<<"\t"<<record.address;
			return j;
		  }
		j++;
	  }
	i.close();
	return 0;
  }
void student::Delete()
  {
	int pos;
	pos=search();
	fstream f;
	f.open("student.dat",ios::in|ios::out|ios::binary);
	f.seekg(0,ios::beg);
	if(pos==0)
	  {
		cout<<"\n\tRecord Not Found";
		return;
	  }
	int offset=pos*sizeof(s);
	f.seekp(offset);
	record.roll_no=-1;
	strcpy(record.name,"NULL");
	record.division='N';
	strcpy(record.address,"NULL");
	f.write((char *)&record,sizeof(s));
	f.seekg(0);
	f.close();
	cout<<"\n\tRecord Deleted";
  }
	
int main()
  {
	student stud;
	int choice,key;
	char ch1;
	do
	  {
            cout<<"\n-----------------------------------------------------------------";
		cout<<"\n\t Student Data ";
		cout<<"\n\t1. Create\n\t2. Display\n\t3. Delete\n\t4. Search\n\t5. Exit";
            cout<<"\n-----------------------------------------------------------------";
            cout<<"\n\tEnter Your Choice: ";
		cin>>choice;
		switch(choice)
		  {
			case 1: stud.create();
			        break;
			case 2: stud.display();
				  break;
			case 3: stud.Delete();
				  break;
			case 4: key=stud.search();
				   if(key==0)
				       cout<<"\n\tRecord Not Found...\n";
				  break;
			case 5:
				  break;
		  }
		cout<<"\n\tDo You Want to Continue in Main Menu???If yes then press 'y' else 'n': ";
		cin>>ch1;
	  }while(ch1=='y'||ch1=='Y');
return 1;
  }