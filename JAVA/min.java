import java.util.*;
public class min
{
	public static void main(String[] x) 
	{
		Scanner input = new Scanner(System.in);
		int a,b,c,min;
		System.out.println("Enter 3 numbers");
		a=input.nextInt();
		b=input.nextInt();
		c=input.nextInt();
		if(a<b)
		{	if(a<c)
			min=a;
			else
			min=c;
		}
		else
		{	if(b<c)
			min=b;
			else
			min=c;
		}
		System.out.println("Mininmum Number is "+min);
	}
}
/* Output
   Enter 3 numbers
   5 9 3
   Minimum number is 3 */