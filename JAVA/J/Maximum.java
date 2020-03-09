class Maximum
{
	int a, b, c, result;

	Maximum(String[] args)
	{
		a = Integer.parseInt(args[0]);
		b = Integer.parseInt(args[1]);
		c = Integer.parseInt(args[2]);
	}
	
	void maximum()
	{
		result = (a>b ? ((a>c)?a:c):((b>c)?b:c));
		
	}
	void display()
	{
		System.out.println(result);
	}
	
	public static void main(String[] args)
	{
		Maximum max = new Maximum(args);
		max.maximum();
		max.display();
		
	}
	
}