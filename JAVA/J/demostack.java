/*
PROGRAM: STACK IMPLEMENTATION
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
interface Stack{	// Declares Interface
	
	public void push();
	public Object pop();
	public void display();
}

class MyStack implements Stack{	// Declares Class
	Scanner sc = new Scanner(System.in);	
	int top = -1;
	Object x;
	Object[] a = new Object[10]; 
	

	 public void push(){	// Push Function
		top ++;
		if(top == 10){
			System.out.println("StackOverFlow");
		}
		System.out.printf("Enter the integer");
		a[top] = (Integer)sc.nextInt();
	}
	
	public Object pop(){	// Pop Function
		if(top == -1){
			System.out.println("StackUnderFlow");
		}
		x = a[top];
		top --;
		return x;
	}
	
	public void display(){	// Display Function
		int temp = top;
		for(int i =temp;i>=0; i--){
			System.out.println(a[i]);
		}

	}
}
class DemoStack{	// Declares class DemoStack
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);	
		int Choice;
		MyStack s = new MyStack();	// Object Calling
		do{
			System.out.println("1.Enter To Push\n2.Enter To Pop\n3.Enter To Display\n4.To Exit");
			
		
			switch(Choice = sc.nextInt()){
				case 1: s.push();
						break;
				case 2: Object o = s.pop();
						System.out.println(o+": Has been deleted");
						break;

				case 3: s.display();
						break;
				default: break;
			}

		}while(Choice != 4);
			
	}
}
/*
OUTPUT:
D:\JAVA>javac demostack.java

D:\JAVA>java DemoStack
1.Enter To Push
2.Enter To Pop
3.Enter To Display
4.To Exit
1
Enter the integer10
1.Enter To Push
2.Enter To Pop
3.Enter To Display
4.To Exit
1
Enter the integer20
1.Enter To Push
2.Enter To Pop
3.Enter To Display
4.To Exit
1
Enter the integer30
1.Enter To Push
2.Enter To Pop
3.Enter To Display
4.To Exit
2
30: Has been deleted
1.Enter To Push
2.Enter To Pop
3.Enter To Display
4.To Exit
3
20
10
1.Enter To Push
2.Enter To Pop
3.Enter To Display
4.To Exit
4
*/