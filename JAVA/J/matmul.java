/*
PROGRAM: MATRIX MULTIPLICATION
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Matrix{	// Class Matrix Declaration
	int rows, columns; // ele
	int[][] a;	// ele
	Matrix(int rows, int columns){ // Constructor 1
		this.rows = rows;
		this.columns = columns;
		a = new int[rows][columns];
	}
	void enterElements(){	// Elements recording
		Scanner sc = new Scanner(System.in);
		for(int i = 0; i<this.rows; i++){
			System.out.println("Elements of row"+" "+i);
			                         
			for(int j = 0; j<this.columns; j++){
				this.a[i][j] = sc.nextInt();      
			}
		}
	}
	void display(){	// Function Display 
		for(int i = 0; i<this.rows; i++){
			System.out.println("Elements of row"+" "+i);
			for(int j =0; j<this.columns; j++){
				System.out.println(this.a[i][j]);
			}
		}
	}
	boolean checking(Matrix B){
		if(this.columns == B.rows){
			return true;
		}
		else{
			return false;
			}
	}
	void mul(Matrix m){	// Function for multiplication of two matrix
		Matrix result = new Matrix (this.rows, m.columns); 
		for(int i = 0; i<this.rows; i++){
			for(int j=0; j<m.columns; j++){
				int sum = 0;
				for(int k=0; k<this.columns; k++){
					sum += this.a[i][k] + m.a[k][j];
				}
				result.a[i][j] = sum;
			}
		}
		for(int i = 0; i<this.rows; i++){
			System.out.println("Elements of row"+" "+i);
			for(int j =0; j<m.columns; j++){
				System.out.println(result.a[i][j]);
			}
		}
	}
}
class Demo{	// Class Declaration
	public static void main(String[] args){	Main Function
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter no of Rows And Columns for matrix 1");
		Matrix mat1 = new Matrix(sc.nextInt(), sc.nextInt());
		System.out.println("Enter no of Rows And Columns for matrix 2");
		Matrix mat2 = new Matrix(sc.nextInt(), sc.nextInt());
		mat1.enterElements();
		mat2.enterElements();
		if(mat1.checking(mat2)){
			mat1.mul(mat2);
		}
		else{
			System.out.println("Invalid Entry");
		}
	}
}
/*
OUTPUT:
D:\JAVA>javac matmul.java

D:\JAVA>java Demo
Enter no of Rows And Columns for matrix 1
2
2
Enter no of Rows And Columns for matrix 2
2
2
Elements of row 0
1
0
Elements of row 1
0
1
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