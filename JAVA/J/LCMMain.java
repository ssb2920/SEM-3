import java.io.*;
import java.util.*;
class Lcm	// Declares Class LCM
{
	int a, b, res1, res2, n1, n2;
	Lcm(String[] args)
	{
		a = Integer.parseInt(args[0]);
		b = Integer.parseInt(args[1]);
	}
	void lcm()	//Function LCM
	{
		res2 = a*b/res1;
	}
	void gcd()	// Function GCD
	{
		n1 = a;
		n2 = b;		
		while(n1 != n2)
		{
			if(n1>n2)
				n1 = n1 - n2;
			else
				n2 = n2 - n1;			
		}
		res1 = n1;
	}
	void display()	// Function Display
	{
		System.out.println("The Lcm is = " + res2);
		System.out.println("The Gcd is = " + res1);
	}
}
public class LCMMain// Declares Class Demo
{
	public static void main(String[] args)	// Main Function
	{
		Lcm l =  new Lcm(args);
		l.gcd();
		l.lcm();
		l.display();
	}
}