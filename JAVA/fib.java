import java.util.*;
import java.lang.*;
class f extends Thread
{	public void run()
	{	try{
		int f1=0;
		int f2=1;
		int sum=0;
		int i;
		System.out.println(f1);
		System.out.println(f2);
		for(i=0;i<=10;i++)
		{	sum=f1+f2;
			System.out.println(sum);
			f1=f2;
			f2=sum;
			Thread.sleep(234);
			
		}}
	catch(Exception e)
	{	System.out.println(e);
	}
	}
}
class A implements Runnable
{
	public void run()
	{	
		for(int i=1;i<=30;i++)
		{	System.out.println("j="+i);
			
		}
	}
}

	
class fib
{	public static void main(String []args)
	{	f b=new f();
		A a=new A();
		Thread t=new Thread(a);
		t.start();
		b.start();
	}
}
		