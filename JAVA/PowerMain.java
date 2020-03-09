import java.util.*;
class Power
{	int x,n;
	Scanner in=new Scanner(System.in);
	Power()
	{	System.out.println("Enter number and power");
		x=in.nextInt();
		n=in.nextInt();
	}
	int calculate(int x,int n)
	{	if(n==0)
			return 1;
		else if(n==1)
			return x;
		else
			return x*calculate(x,n-1);
	}
	public String toString()
	{	return x+" raised to "+n+" is "+calculate(x,n);
	}
}
class PowerMain
{	public static void main(String[]args)
	{	Power p=new Power();
		System.out.println(p);
	}
}