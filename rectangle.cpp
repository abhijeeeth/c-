#include <iostream.h>
#include <conio.h>
class area
{
	public :
	int l,b;
	void getarea();

};
class perimeter
{
	public :
	int l,b;
	void getperimeter();
};
	class rectangle:public perimeter, public area
		{
		 public :
		 int a;
		 void display();
		 };
	void area::getarea()
		{
		cout<<"Enter The Length And Breadth Of Rectangle";
		cin>>l>>b;
		cout<<"Area : "<<l*b;
		}
	void perimeter::getperimeter()
		{
		cout<<"Enter The Length And Breadth Of Rectangle";
		cin>>l>>b;
		cout<<"Perimeter Of Rectangle"<<2*(l+b);
		}
		void rectangle::display()
			{
			getperimeter();
			}
void main()
{
clrscr();
area a;
perimeter p;
rectangle r;
r.display();
getch();
}




















