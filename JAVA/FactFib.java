class Fibo implements Runnable
{
	public void run()
	{
		try
		{
		int a=0;
		int b=1;
		int c=5;int i=1;int temp=0;
		//System.out.println(a);
		//System.out.println(b);
		while(i<=c)
		{
			System.out.println("Fibonacci"+(i)+"term:= "+a);
			temp=a+b;
			a=b;
			b=temp;
			//System.out.println("Fibonacci"+(i+1)+"term:= "+temp);
			Thread.sleep(1000);//thread sleeps for 1000 ms
			i++;
		}
		}
		catch (InterruptedException e)
		{
			System.out.println(e);
		}
	}
}
class Fact extends Thread
{
	public void run()
	{
		int i;int ans=1;
		try
		{
		for(i=1;i<=5;i++)
		{
			ans=ans*i;
			System.out.println("Fact of "+i+" is "+ans);
			Thread.sleep(500);//thread sleeps for 500 ms
		}
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}
	}
}
class FactFib
{
	public static void main( String [] args)
	{
		Fibo fb=new Fibo();
		Thread t1=new Thread(fb,"Fibon");
		Thread t2=new Fact();
		t1.start();
		t2.start();
		try
		{
			t1.join();
			t2.join();
		}
		catch(InterruptedException e)
		{
			System.out.println(e);
		}
	}
}
	
	
	
	
