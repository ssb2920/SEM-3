import java.util.*;
import java.io.*;
class Employee
{	String name;
	int id,salary;
	Scanner in=new Scanner(System.in);
	Employee()
	{	System.out.println("Enter name,id,salary");
		name=in.next();
		id=in.nextInt();
		salary=in.nextInt();
	}
	Employee(String name,int id,int salary)
	{	this.name=name;
		this.id=id;
		this.salary=salary;
	}
	public String toString()
	{	return "Id: "+id+"\nName: "+name+"\nSalary: Rs"+salary;
	}
}
class EMain
{	public static void main(String []args)
	{	
		Employee e[]=new Employee[3];
		for( int i=0;i<3;i++)
		{	e[i]=new Employee();
		}
		for(int g=0;g<e.length-1;g++){
		for(int j=0;j<e.length-1;j++)
		{	Employee temp;
			if(e[j].salary<e[j+1].salary)
			{	temp=e[j];
				e[j]=e[j+1];
				e[j+1]=temp;
			}
		}}
		for(int k=0;k<e.length;k++)
		System.out.println(e[k]);
	}
}