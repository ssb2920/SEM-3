/*
PROGRAM: LIST 
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class List{	// Declares class List
	Scanner sc = new Scanner(System.in);
	int[] a;
	List(int x){	// Constructor
		a = new int[x];
		System.out.println("Enter the elements");
		for(int i = 0; i<a.length;i++){
			a[i] = sc.nextInt();
		}
	}
	void display(){	//Function Display
		System.out.println("The elements are:-");
		for(int i = 0; i<a.length;i++){
			System.out.println(a[i]);
		}
	} 
}
class Demo{	// Declares Class Demo
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter the number of terms");		
		List ls = new List(sc.nextInt());
		ls.display();
	}
}
/*
OUTPUT:
D:\JAVA>javac list.java

D:\JAVA>java Demo
Enter the number of terms
3
Enter the elements
10
20
30
The elements are:-
10
20
30
*/