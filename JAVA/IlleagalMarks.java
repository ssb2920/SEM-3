import java.util.*;
import java.lang.*;
class NegativeMarksException extends Exception
{	public String toString()
	{	return "NegativeMarksException:Marks cannot be less than zero";
	}
}
public class IlleagalMarks
{	public static void main(String []args)
	{	try
		{	Scanner in=new Scanner(System.in);
			int []a=new int[5];
			int sum=0;
			int i;
			float avg;
			for(i=0;i<a.length;i++)
			{	System.out.println("Enter marks in subject "+(i+1));
				a[i]=in.nextInt();
				if (a[i]<0) throw new NegativeMarksException();
				
				sum=sum+a[i];
			}
			avg=sum/a.length;
			System.out.println(avg);
		}
		catch(ArithmeticException e)
		{	System.out.println(e);
		}
		catch(ArrayIndexOutOfBoundsException e)
		{	System.out.println(e);
		}
		catch(NegativeMarksException e)
		{	System.out.println(e);
		}
		finally
		{	System.out.println("DONE ");
		}
	}
}
