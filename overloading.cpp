#include<iostream.h>
#include<conio.h>
class space
{
int x;
int y;
int z;
public :
void getdata(int a,int b,int c);
void display();
void operators();
};
void space :: getdata(int a,int b,int c)
{
x=a;
y=b;
z=c;
}
void space :: operators()
{
x=-x;
y=-y;
z=-z;
}

void space :: display()
{
cout<<x<<" ";
cout<<y<<" ";
cout<<z<<" ";
}
void main()
{
clrscr();
space s;
s.getdata(10,-20,30);
cout<<"s";
s.operators();
s.display();
//-s;
cout<<"s";
s.display();
//return 0;
getch();
}
