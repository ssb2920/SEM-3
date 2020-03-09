/*
PROGRAM: NUMBER PATTERN
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
class Numpattern	// Class Numpattern declaration
{
	int i, j,m;
	Numpattern()	// Constructor
	{
		m = 5;
	}
	void displayPattern()	// Displaying Pattern
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
class DemoNumpattern	// Class DemoNumpattern Declaration
{
	public static void main(String[] args)	// Main Function
	{
		Numpattern numpat = new Numpattern();
		numpat.displayPattern();
	}
}
/*
OUTPUT:
D:\JAVA>javac numpattern.java

D:\JAVA>java DemoNumpattern
1
22
333
4444
55555
*/