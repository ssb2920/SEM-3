/*
PROGRAM: EMPLOYEES DETAILS
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Emp{	// Declares Emp Class
	int id;
	String name;
	double sal;
	Emp(int id, String name, double sal){	// Constructor
		this.id = id;
		this.name = name;
		this.sal = sal;
	}
	void display(){	// Function Display
		System.out.println("name:"+this.name+" id:"+this.id+" Salary:"+this.sal);
	}
}
class Demo{	// Declares class Demo
	public static void main(String[] args){ // Main Function
		Scanner sc = new Scanner(System.in);			
		System.out.println("Enter the number of Employees");
		Emp[] e = new Emp[sc.nextInt()];	// Employee Array
		for(int i = 0; i<e.length; i++){
			System.out.println("Enter the details of employee"+" "+(i+1));
			e[i] = new Emp(sc.nextInt(), sc.next(), sc.nextDouble());
		}
		for(int i = 0; i<e.length-1; i++){
			for(int j = 0; j<e.length-1; j++){
				Emp temp;
				if(e[j].sal>= e[j+1].sal){
					temp = e[j];
					e[j] = e[j+1];
					e[j+1] = temp;
				}
			}
		}
		System.out.println("The Sorted employee details are as follows:");
		for(int i = 0; i<e.length;i++){
			System.out.println("The details of "+(i+1)+" employee");
			e[i].display();
		}
	}
}
/*
OUTPUT:
D:\JAVA>javac emp1.java

D:\JAVA>java Demo
Enter the number of Employees
2
Enter the details of employee 1
1
Sherwin
10000
Enter the details of employee 2
2
Mayank
15000
The Sorted employee details are as follows:
The details of 1 employee
name:Sherwin id:1 Salary:10000.0
The details of 2 employee
name:Mayank id:2 Salary:15000.0
*/