import java.util.*;
class Complex
{	double real,imag;
	Complex()
	{	real=0.0;
		imag=0.0;
	}
	Complex(double real,double imag)
	{	this.real=real;
		this.imag=imag;
	}
	Complex(Complex c)
	{	this.real=c.real;
		this.imag=c.imag;
	}
	void add(Complex h1,Complex h2)
	{	real=h1.real+h2.real;
		imag=h1.imag+h2.imag;
	}
	void display()
	{	System.out.println("Result is "+real+"+i"+imag);
	}
}
class ComplexMain
{	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		Complex c1=new Complex();
		Complex c2=new Complex(7.2,8.6);
		Complex c3=new Complex(c2);
		c1.add(c2,c3);
		c1.display();
	}
}