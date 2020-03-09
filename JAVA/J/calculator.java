/*
PROGRAM: CALCULATOR
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
class Calculator // declares class calculator
{
	int x, y;
	
	
	Calculator()
	{
		x = 3;
		y = 5; 
	}	
	

	void add()	// Function add
	{
		System.out.println(x + y);
	}

	void subtract()	// Function subtract
	{
		System.out.println(x - y);
	}

	void multiplication()	// Function Multiply
	{
		System.out.println(x * y);
	}

	void division()	// Function Division
	{
		System.out.println((float)x/y);
	}

	void modulus()	// Function Modulus
	{
		System.out.println(x%y);
	}

	
}
class Democalculator	// Declares Class Democalculator
{
	public static void main(String[] args)	// Main Function
	{
		Calculator calcy = new Calculator();	// Object Calling 
		calcy.add();
		calcy.subtract();
		calcy.multiplication();
		calcy.division();
		calcy.modulus();
	}
}
/*
OUTPUT:
D:\JAVA>javac calculator.java

D:\JAVA>java Democalculator
8
-2
15
0.6
3
*/