import java.util.Scanner;
class Person
{
	String name;
	int age;
	Person()
	{
		name = "XYZ";
		age = 0;
	}
}
class Emp extends Person
{
	int id;
	float salary;
	Emp()
	{
		id = 0;
		salary = 0;		
	}
	Emp(String name , int age, int id, float salary)
	{	
		super();
		this.name = name;
		this.age = age;
		this.id = id;
		this.salary = salary;
	}
	void display()
	{
		System.out.print(" Name is " +name+ ", Age is " +age+ ", ID is " +id+ ", Salary is " +salary);
	}	
}
class Mng extends Emp
{
	float incent;
	Mng(String name , int age, int id, float salary, float incent)
	{
		super();
		this.name = name;
		this.age = age;
		this.id = id;
		this.salary = salary;
		this.incent = incent;
	}
	void display()
	{
		super.display();
		System.out.print("Incentive is " +incent);
	}
}
class Company
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		/*Mng m = new Mng("Bill Gates", 65, 1, 55000.00, 25000.00); 
		m.diplay();*/
		int n, id, salary;
		System.out.println("Enter the number of employee in the company");
		n = sc.nextInt();
		Emp[]e = new Emp[n];
		for(int i=0; i<e.length; i++)
		{	e[i] = new Emp();
			System.out.println("Enter name of employee");
			e[i].name = sc.next();
			System.out.println("Enter id of employee");
			e[i].id = sc.nextInt();
			System.out.println("Enter salary of employee");
			e[i].salary = sc.nextInt();
			System.out.println("Enter age of employee");
			e[i].age = sc.nextInt();		
			e[i].display();
			System.out.println();	
		}
		
	}	
}

