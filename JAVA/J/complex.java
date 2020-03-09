/*
PROGRAM: COMPLEX EQUATIONS
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Complex{	// Declares class Complex
	double real, img;
	Complex(){	// Constructor
		this.real = 0.0;
		this.img = 0.0;	
	} // THis will create Operator overloading
	Complex(double real, double img){
		this.real = real;
		this.img = img;
	}
	Complex add(Complex c){	// Function add
		Complex c3 = new Complex();
		c3.real = this.real + c.real;
		c3.img = this.img + c.img;
		return c3;
	}

	void display(){	// Function Display
		System.out.println("("+this.real+")"+"i"+"("+this.img+")");
	}

}

class Demo{	// Declares class Demo
	public static void main(String[] args){	// Main Function
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter elements of first complex number");
		Complex c1 = new Complex(sc.nextDouble(), sc.nextDouble());	// Object Calling
		System.out.println("Enter elements of second complex number");
		Complex c2 = new Complex(sc.nextDouble(), sc.nextDouble());	// Object Calling
		Complex c3 = c1.add(c2);
		System.out.println("The first expression is:");
		c1.display();
		System.out.println("The second expression is:");
		c2.display();
		System.out.println("The result expression is:");
		c3.display();
	}
	
}
/*
OUTPUT:
D:\JAVA>javac complex.java

D:\JAVA>java Demo
Enter elements of first complex number
2
2
Enter elements of second complex number
1
2
The first expression is:
(2.0)i(2.0)
The second expression is:
(1.0)i(2.0)
The result expression is:
(3.0)i(4.0)
*/