import java.util.Scanner;
import java.io.*;
class Circle
    {
        double radius;
            public Circle(double r)
                {
                    radius=r;
                }
            public double area()
                {
                    return 3.14*radius*radius;
                }
    }
class Cylinder extends Circle
    {
        double height;
        public Cylinder(double r,double h)
            {
                super(r);
                height=h;
            }
        public double volume()
            {
                return super.area()*height;
            }
    }
class Cone extends Circle
    {
        double height;
        public Cone(double r, double h)
            {
                super(r);
                height=h; 
            }
            public double volume()
            {
                return (super.area()*height)/3;
            }
    }
public class Cir
{
    public static void main(String a[])
        {
            double r,h;
            Scanner s=new Scanner(System.in);
            System.out.println("Enter the radius of the circle");
            r=s.nextDouble();
            System.out.println("enter the height");
            h=s.nextDouble();
            Cylinder C=new Cylinder(r, h);
            Cone Cn=new Cone(r, h);
            System.out.println("Volume of Cylinder : " + C.volume());
            System.out.println("Volume of Cone : " + Cn.volume());  
        }
}