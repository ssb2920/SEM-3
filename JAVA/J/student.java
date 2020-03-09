/*
PROGRAM: FRCRCE SITE
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
import college.*;
public class Frcrce{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		Student s = new Student(sc.nextInt(), sc.next());
		Staff st = new Staff(sc.nextInt(), sc.next());
		s.display();
		st.display();
	}
}
package college;
public class Staff{
	int id;
	String name;
	Staff(int id, String name){
		this.id = id;
		this.name = name;
	}
	public void display(){
		System.out.println("ID: "+this.name+"\nName: "+this.name);
	}
}
package college;
public class Student{
	int id;
	String name;
	Student(int id, String name){
		this.id = id;
		this.name = name;
	}
	public void display(){
		System.out.print("Id: "+this.id+"\nName: "+this.name);
	}
}
/*
OUTPUT:

*/