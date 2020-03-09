import java.util.*;
import java.lang.*;
class ABC
{	public static void main(String []args)
	{	int x=10;
		int y=5;
		int z=5;
		try
		{	int a=x/(y-z);
		}
		catch(Exception e)
		{	System.out.println(e);
		}
		finally
		{
		System.out.println(x+y);
		}
		int a[]={5,2};
		try
		{	a[4]=6;
		}
		catch(Exception e)
		{	System.out.println(e);
		}
		
	}
}
