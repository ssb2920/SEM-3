import java.util.Scanner;
public class Number
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int n;
		System.out.println("Enter positive integer");
		n=input.nextInt();
		while(n!=1&&n>0)
		{	if(n%2==0)
				n=n/2;
			else
				n=n*3+1;
				System.out.println("n= "+n);
		}
		
	}
}
/*Output
  Enter positive integer
  6
  n=3
  n=10
  n=5
  n=16
  n=8
  n=4
  n=2
  n=1 */