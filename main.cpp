#include<iostream>
#include<conio.h>
#include<string.h>
#include<process.h>
using namespace std;

class books {
 public:
 int stock;
 char author[20], publisher[20];
 char bookname[20];
 float price;
 void loadbooks();
 void display();
};

void books::loadbooks() {
 cout<<"\nEnter Book Name:";
 cin>>bookname;
 cout<<"\nEnter Author Name:";
 cin>>author;
 cout<<"\nEnter Publisher Name:";
 cin>>publisher;
 cout<<"\nEnter Price:";
 cin>>price;
 cout<<"\nEnter Stock:";
 cin>>stock;
 cout<<"\n-------------\n";
}

void books::display() {
 cout<<"\nName of the Book:"<<bookname;
 cout<<"\nAuthor of the Book:"<<author;
 cout<<"\nPublisher of the Book:"<<publisher;
 cout<<"\nPrice of the Book:"<<price;
 cout<<"\nStock Present:"<<stock;
 cout<<"\n-------------\n";
}

int main() {
 books ob[10];
 int ch, n;

 do{
  cout<<"\n****\n";
  cout<<"\n1.Load Books\n2.Display\n3.Search\n4.Exit\n";
  cout<<"\n\nEnter your Choice:";
  cin>>ch;
  switch(ch)
  {
  case 1: cout<<"Enter Number of Books:";
   cin>>n;
   for(int i=0;i<n;i++)
   ob[i].loadbooks();
   break;
  case 2:
   for(int i=0;i<n;i++)
   ob[i].display();
   break;
  case 3:
  
   char bname[20], aname[20];
   cout<<"Enter name of the Book:";
   cin>>bname;
   cout<<"Enter name of the Author:";
   cin>>aname;
   for(int i=0;i<n;i++)
   {
    if(strcmp(bname, ob[i].bookname)==0&&strcmp(aname,ob[i].author))
    {
     cout<<"\nBook Present\n\n";
     cout<<"\nName of the Book:"<<ob[i].bookname;
     cout<<"\nAuthor of the Book:"<<ob[i].author;
     cout<<"\nPublisher of the Book:"<<ob[i].publisher;
     cout<<"\nPrice of the Book:"<<ob[i].price;
     cout<<"\nStock Present:"<<ob[i].stock;
     cout<<"\n-------------\n";
     break;
    }
    else
    {
     cout<<"Not Present!!";
     break;
    }
   }
   break;
   default: cout<<"Enter a valid choice!!";
  case 4: exit(1);
  }
 }while(1);
}
