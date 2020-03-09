//import java.util.*;
//import java.lang.*;
class A extends Thread
{
	public void run()
	{	
		for(int i=1;i<=30;i++)
		{	System.out.println("j="+i);
		}
	}
}
class B implements Runnable
{	public void run()
	{	for(int i=0;i<31;i++)
		{	System.out.println("asdfghj="+i);
			try{if (i==20)
			Thread.sleep(20);}
			catch(Exception e)
			{	System.out.println(e);
			}
			
		}
	}
}
class C
{	public static void main(String []args)
	{	A a=new A();
		B b=new B();
		a.start();
		Thread t=new Thread(b);
		t.start();
		
	}
}
