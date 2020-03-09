class Compute
{	static int x,y;
	Compute()
	{	x=10;
		y=20;
	}
	Compute(int x,int y)
	{	this.x=x;
		this.y=y;
	}
	static void calculate()
	{	System.out.print("ANSWER IS "+(x+y));
	}
}
class ComputeMain
{	public static void main(String[]args)
	{	Compute c1;
		c1=new Compute(45,87);
		c1.calculate();
	}
}
