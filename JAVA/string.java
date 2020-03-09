import java.util.Scanner;
public class string
{
	public static void main(String[] args) 
	{
		Scanner input = new Scanner(System.in);
		int n,x,rev=0;
		System.out.println("Enter number:");
		n=input.nextInt();
		while(n!=0)
		{
			x=n%10;
			n=n/10;
			rev=rev*10+x;
		}
		while(rev!=0)
		{
			x=rev%10;
			rev=rev/10;
			switch(x)
			{ 
				case 0:System.out.print("zero"+" ");
					break;
			  	case 1:System.out.print("one"+" ");
					break;
				case 2:System.out.print("two"+" ");
					break;
				case 3:System.out.print("three"+" ");
					break;
				case 4:System.out.print("four"+" ");
					break;
				case 5:System.out.print("five"+" ");
					break;
				case 6:System.out.print("six"+" ");
					break;
				case 7:System.out.print("seven"+" ");
					break;
				case 8:System.out.print("eight"+" ");
					break;
				case 9:System.out.print("nine"+" ");
					break;
				default:System.out.print("Wrong Choice");
					break;
			}
		}
	}
}
/*Output
  Enter number:
  123
  one two three */
				
		