/*
PROGRAM: MATRIX 
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Matrix{	// Declares class Matrix
	int rows, columns;
	int[][] a;
	Scanner sc = new Scanner(System.in);
	Matrix(int rows, int columns){	// Constructor
		this.rows = rows;
		this.columns = columns;
		a = new int[rows][columns];
		
	}
	void enterElements(){	// Function for entering elements
		for(int i = 0; i<a.length; i++){
			System.out.println("Elements of row"+" "+i);                         
			for(int j = 0; j<a[i].length; j++){
				a[i][j] = sc.nextInt();      
			}
		}  
	}
	void display(){	// Display Function
		for(int i = 0; i<a.length; i++){
			System.out.println("Elements of row"+" "+i);
			for(int j =0; j<a[i].length; j++){
				System.out.println(a[i][j]);
			}
		}
	}
}
class Demo{	// Declares class Demo
	public static void main(String[] args){	// Main Function
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no of Rows And Columns");
		Matrix mat = new Matrix(sc.nextInt(), sc.nextInt());
		mat.enterElements();
		mat.display();
	}
}
/*
OUTPUT:
D:\JAVA>javac matrix.java

D:\JAVA>java Demo
Enter no of Rows And Columns
2
2
Elements of row 0

1
2
Elements of row 1
3
4
Elements of row 0
1
2
Elements of row 1
3
4
*/