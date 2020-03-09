/*
PROGRAM: EMPLOYEES DETAILS
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
class Employ{	//Declares Class Employ
	int id;
	static int count = 0; 
	String name;
	float sal;
	Employ(){	// Constructor
		Scanner sc = new Scanner(System.in);
		count++;
		System.out.println("Enter the ID"); 
		id = sc.nextInt();
		System.out.println("Enter the Name");
		name = sc.next();
		System.out.println("Enter the Salary");
		sal = sc.nextFloat();
	} 
    void display(){	// Display Function
		System.out.println("Id:"+id+" "+"Salary:"+sal+" "+"Name:"+name);
	}
	static void display2(){	// Count Display
		System.out.println("The number of Employees is:"+count);
	}
}
class Organisation{	// Declares class Organisation
	public static void main(String[] args){	// Main Function
		Employ e1 = new Employ();
		Employ e2 = new Employ();
		Employ e3 = new Employ();
		e1.display();
		e2.display();
		e3.display();
		Employ.display2();
	}
}
/*
OUTPUT:
D:\JAVA>javac emp2.java

D:\JAVA>java Organisation
Enter the ID
1
Enter the Name
Sherwin
Enter the Salary
20000
Enter the ID
2
Enter the Name
Mayank
Enter the Salary
18000
Enter the ID
3
Enter the Name
Eric
Enter the Salary
21000
Id:1 Salary:20000.0 Name:Sherwin
Id:2 Salary:18000.0 Name:Mayank
Id:3 Salary:21000.0 Name:Eric
The number of Employees is:3
*/ 