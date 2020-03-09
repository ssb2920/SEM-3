class Numpattern
{
	int i, j,m;
	Numpattern()
	{
		m = 5;
		
	}

	void displayPattern()
	{	
		for(j = 1; j <= m ; j++)
		{
			for(i = 0; i <= j ; i++)
			{
				System.out.print(j);
			}
			System.out.println("");
		}
	}
	

}

class DemoNumpattern
{
	public static void main(String[] args)
	{
		Numpattern numpat = new Numpattern();
		numpat.displayPattern();
	}
}