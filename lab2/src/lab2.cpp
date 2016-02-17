//============================================================================
// Name        : lab2.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

//============================================================================
// Name        : lab2.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<fstream>
#include<sstream>
#include<string>
#define MAX 100
using namespace std;
class student
{
 string name,usn,branch,buffer,f;
 int sem;
 fstream f1;
public:

void read()
{
	 cout<<"enter name";
	 cin>>name;
	 cout<<"enter usn";
	 cin>>usn;
	 cout<<"enter branch";
     cin>>branch;
	 cout<<"enter sem";
	 cin>>sem;
 }
void pack()
{
	string sem1,temp;
	stringstream out;
	out<<sem;
	 sem1=out.str();
	 temp.erase();
	temp=usn+'|'+name+'|'+branch+'|'+sem1;
	 for(int i=temp.size();i<100;i++)
	   temp+='|';
	 buffer+=temp;
}
void write()
{
	f1.open("data.txt",ios::out|ios::app);
	f1<<buffer;
	f1.close();
}
void search(key)
{
	string key;int pos;
	f1.open("data.txt",ios::in);
	f1.getline(buffer,100);
	pos=f1.tellp();
	cout<<"buffer:"<<buffer;
	unpack();
}
void unpack()
{
	int i,flag=0;string key,pos;
	while(buffer[i]!='|')
		usn+=buffer[i++];
        i++;
    while(buffer[i]!='|')
		name+=buffer[i++];
        i++;

    while(buffer[i]!='|')
         branch+=buffer[i++];
          i++;
     while(buffer[i]!='|')
      sem+=buffer[i++];
           i++;
      if(usn==key)
      {
    	  flag=1;
    	  cout<<"key found";
          return pos;
      }
}
int main()
{
	int choice;string key;
	student s;
	cout<<"enter a choice";
	cout<<"1.insert 2.search 3.delete 4.modify";
	cin>>choice;
	switch(choice)
	{
	case 1:s.read();
		   s.pack();
		   s.write();
		   break;
	case 2:cout<<"enter the key";
	       cin>>key;
	       s.search(key);
	}
return 0;
}
