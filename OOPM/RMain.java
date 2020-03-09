import java.util.Scanner;
class Rectangle
{	int len,br;
	void setvalue(int a,int b)
	{	len=a;
		br=b;
	}
	int Findarea()
	{	return len*br;
	}
}
class RMain
{	public static void main(String[]args)
	{	Rectangle r=new Rectangle();
		r.setvalue(6,4);
		System.out.print("gg\tgg");
		System.out.print("\n");
		System.out.println("Area is "+r.Findarea());
	}
}