import java.io.*;
import java.util.*;
class Person
{	public String name;
	public int id;
	Person()
	{	System.out.println("Constructor works");
	}
	Person(String a,int b)
	{	name=a;
		id=b;
	}
	public String toString()
	{	return name+"  "+id;
	}
}
 public class PMain
{	public static void main(String[]args)
	{	Person p1=new Person("John",1);
		Person p2=new Person("joy",2);
		Person p3=new Person();
		System.out.println(p1);
		System.out.println(p2);
		System.out.println(p1.getClass());
	}
}