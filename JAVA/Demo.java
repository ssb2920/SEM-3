import java.lang.*;
import java.util.*;
import java.io.*;
class NegativeMarksException extends Exception
{
	NegativeMarksException()
	{}
	public String toString() //To Return String
	{
	return "NegativeMarksException ";
	}
}
class Demo
{	public static void main(String[] args)
	{	try
		{
		Scanner in = new Scanner(System.in);
 		int []a=new int [5];
 		int sum=0;
 		int i;
 		float average;
			for(i=0;i<5;i++)
			{	System.out.println("ENTER THE MRKS IN SUBJECT" +i);
				a[i]= in.nextInt();
					if(a[i]<0) throw new NegativeMarksException();
				sum=sum+a[i];
			}
			average=sum/5;
		}
		
		catch(ArrayIndexOutOfBoundsException e)
		{
			System.out.println(e);
		}
		catch(ArithmeticException e)
		{
			System.out.println(e);
		}
		catch(NullPointerException e)
		{
			System.out.println(e);
		}
		catch(NumberFormatException e)
		{
			System.out.println(e);
		}
		catch(NegativeMarksException e)
		{	
		System.out.println(e);
		}
		finally
		{
			System.out.println("DONE WITH AVERAGE");
		}
	}
}
/*OUTPUT:
ENTER THE MRKS IN SUBJECT0
7
ENTER THE MRKS IN SUBJECT1
6
ENTER THE MRKS IN SUBJECT2
-4
NegativeMarksException 
*/	

