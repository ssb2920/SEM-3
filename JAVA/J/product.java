/*
PROGRAM: PRODUCT 
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Product{	// Class Product Declaration
	private int id;
	private String brand;
	private double price;
	Product(int id, String brand, double price){	// Constructor
		this.id = id;
		this.brand = brand;
		this.price = price;
	}
}
class Demo{	// class Demo Declaration
	public static void main(String[] args){	// Main Function
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the no of customers");
		int n = sc.nextInt();
		Product [][] sale = new Product[n][]; 
		for(int i = 0; i<n; i++){
			System.out.println("Enter the no of products you bought");
			int m = sc.nextInt();
			sale[i] = new Product[m];
			for(int j = 0; j<m; j++){
				System.out.println("Enter id, brand and price of product"+" "+j);
				sale[i][j] = new Product(sc.nextInt(), sc.next(), sc.nextDouble());
			}
		}
	}
}
/*
OUTPUT:
D:\JAVA>javac product.java

D:\JAVA>java Demo
Enter the no of customers
3
Enter the no of products you bought
1
Enter id, brand and price of product 0
1
Samsung
15000
Enter the no of products you bought
1
Enter id, brand and price of product 0
2
Apple
100000
Enter the no of products you bought
1
Enter id, brand and price of product 0
3
redmi
15000
*/