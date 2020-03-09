/*
PROGRAM: POWER USING RECURSION
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Power{	// Class Power Declaration
	public static int calpower(int a, int b){
		if(b == 0){
			return 1;
		}
		else if(a == 1){
			return a;
		}
		else if(b == 1){
			return a;
		}
		else{
			return a*calpower(a, b - 1);
		}
	}
}
class Demo{	// class Demo Declaration
	public static void main(String[] args){	// Main Function
		int x;
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the Base and Radix");
		x = Power.calpower(sc.nextInt(), sc.nextInt());
		System.out.println(x);		
	}
}
/*
OUTPUT:
D:\JAVA>javac power.java

D:\JAVA>java Demo
Enter the Base and Radix
3
2
9	
*/