#include<iostream.h>
#include<conio.h>

class employee
 {
 int code;
 char name[20];
 char designation[20];
 float hra,da,pf,gs,tax,netsalary,ta,bs;
 public:
 void getdata();
 void calculate();
 void display();
 };
void employee::getdata()
 {
 cout<<"enter name:";
 cin>>name;
 cout<<"enter code:";
 cin>>code;
 cout<<"enter basic salary:";
 cin>>bs;
 cout<<"enter the desgnation:";
 cin>>designation;
 }
 void employee::calculate()
 {

 int c;
 pf=0.12*bs;
 tax=0.10*bs;
 da=0.20*bs;
 hra=0.15*bs;
 gs=bs+da+hra;
 c=pf+tax;
 netsalary=gs-c;
 }
void employee::display()
 {
 cout<<"\nname:"<<name;
 cout<<"\ncode"<<code;
 cout<<"\ndesignation"<<designation;
 cout<<"\nda:"<<da;
 cout<<"\n tax:"<<tax;
 cout<<"\nhra:"<<hra;
 cout<<"\npf:"<<pf;
 cout<<"\nnetsalary:"<<netsalary;
 cout<<"\ngs:"<<gs;
 }

 void main()
  {
  clrscr();
  employee e[100];
  int i,n;
  cout<<"enter the numbver of employee:";
  cin>>n;
  for(i=0;i<n;i++)
   {
   e[i].getdata();
   }
  for(i=0;i<n;i++)
  {
   e[i].display();
  }
  for(i=0;i<n;i++)
   {
   e[i].calculate();
   }
  getch();
   }



