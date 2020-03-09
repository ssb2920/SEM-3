/*
PROGRAM: SHAPE OF THE OBJECT 
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Shape{	// Class Shape Declaration
	public static void calArea(int s){
		System.out.println("Area of square:"+(s*s));
	}
	public static void calArea(float r){
		System.out.println("Area of circle:"+(3.14*r*r));
	}
	public static void calArea(float a, float b){
		System.out.println("Area of rectangle:"+(a*b));
	}
}
class shape{	// Class Demo Declaration
	public static void main(String[] args){	// Main Function
	int x;
	Scanner sc = new Scanner(System.in); 
	System.out.println("Enter 1:Circle 2:Square 3: Rectangle");
	x = sc.nextInt();
	switch(x){
		case 1: System.out.println("Enter the Radius");
				Shape.calArea(sc.nextFloat());
				break;
		case 2: System.out.println("Enter the Side");
				Shape.calArea(sc.nextInt());
				break;
		case 3: System.out.println("Enter the Dimensions");
				Shape.calArea(sc.nextFloat(), sc.nextFloat());
				break;
		default : System.out.println("Entered choice is wrong");
		}
	}
}
/*
OUTPUT:
D:\JAVA>javac shape.java

D:\JAVA>java Demo
Enter 1:Circle 2:Square 3: Rectangle
1
Enter the Radius
12
Area of circle:452.15999999999997
*/