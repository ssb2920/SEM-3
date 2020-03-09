import java.io.*;
import java.util.*;
class lcm
{	int a,b,lc,gc;
	lcm()
	{	Scanner in=new Scanner(System.in);
		System.out.println("Enter 2 numbers");
		a=in.nextInt();
		b=in.nextInt();
	}
	void calculategcd()
	{	int n1,n2;
		n1=a;n2=b;
		while(n1!=n2)
		{	if(n1>n2)
				n1=n1-n2;
			else 
				n2=n2-n1;
		}
		gc=n1;
	}
	void calculatelcm()
	{	lc=a*b/gc;
	}
	void display()
	{	System.out.println("The lcm is= "+lc);
		System.out.println("Gcd is= "+gc);
	}
}
public class lmain
{	public static void main(String[]args)
	{	lcm l=new lcm();
		l.calculategcd();
		l.calculatelcm();
		l.display();
	}
}
