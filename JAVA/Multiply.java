import java.util.Scanner;
public class Multiply
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int n1,n2,product=0;
		System.out.println("Enter first number:");
		n1=input.nextInt();
		System.out.println("Enter second number:");
		n2=input.nextInt();
		if(n1%2!=0)
   		product=product+n2;
 		
  		while(n1!=1)
  		{
   		n1=n1/2;
   		n2=n2*2;
   		if(n1%2!=0)
    		product=product+n2;
  		
  		}
  		System.out.println("The product is: "+product);
 	}
}
/*Output
  Enter first number: 
  5
  Enter second number: 
  7
  The product is:35  */
  
