import java.util.*;
class Shape
{	public static void Area(int x)
	{	System.out.println("The area of square is "+x*x);
	}
	public static void Area(float r)
	{	System.out.println("The area of circle is "+22*r*r/7);
	}
	public static void Area(float a,float b)
	{	System.out.println("The area of rectangle is "+a*b);
	}
}
class ShapeMain
{	public static void main(String[]args)
	{	int ch;
		Scanner in=new Scanner(System.in);
		System.out.println("Enter 1:square 2:circle 3:rectangle");
		ch=in.nextInt();
		switch(ch)
		{	case 1:Shape.Area(in.nextInt());
					break;
			case 2:Shape.Area(in.nextFloat());
					break;
			case 3:Shape.Area(in.nextFloat(),in.nextFloat());
					break;
			default:System.out.println("WRONG");
					break;
		}
	}
}