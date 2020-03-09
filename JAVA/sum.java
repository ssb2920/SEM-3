import java.util.Scanner;

public class sum 
{
	public static void main(String[] args) 
	{	
		int i,sum=0,n;

		Scanner input = new Scanner(System.in);

		System.out.println("Enter value of n");

		n=input.nextInt();

		for(i=1;i<=n;i++)

		sum=sum+i;	 
			
		System.out.println("The Sum of  "+ n +" numbers is "+ sum);
	}
}
/*Output
  Enter value of n
  8
  The Sum of 8 numbers is 36 */