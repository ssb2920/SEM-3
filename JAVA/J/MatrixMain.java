import java.util.*;
import java.io.*;
class Matrix
{	int r,c;
	int [][]a;
	Matrix(int r,int c)
	{	this.r=r;
		this.c=c;
		a=new int [r][c];
	}
	void enterElements(){	
		Scanner in = new Scanner(System.in);
		for(int i = 0; i<this.r; i++){
			System.out.println("Elements of row"+" "+i);
			                         
			for(int j = 0; j<this.c; j++){
				this.a[i][j] = in.nextInt();      
			}
		}
	}
	void display(){	// Function Display 
		for(int i = 0; i<this.r; i++){
			System.out.println("Elements of row"+" "+i);
			for(int j =0; j<this.c;j++){
				System.out.println(this.a[i][j]);
			}
		}
	}
	void mul(Matrix m){	// Function for multiplication of two matrix
		Matrix result = new Matrix (this.r, m.c); 
		for(int i = 0; i<this.r; i++){
			for(int j=0; j<m.c; j++){
				int sum = 0;
				for(int k=0; k<this.c; k++){
					sum += this.a[i][k] + m.a[k][j];
				}
				result.a[i][j] = sum;
			}
		}
		for(int i = 0; i<this.r; i++){
			System.out.println("Elements of row"+" "+i);
			for(int j =0; j<m.c; j++){
				System.out.println(result.a[i][j]);
			}
		}
	}
}
class MatrixMain
{	public static void main(String[]args)
	{	Matrix m1=new Matrix(2,2);
		Matrix m2=new Matrix(2,3);
		m1.enterElements();
		m2.enterElements();
		m1.mul(m2);
	}
}
	