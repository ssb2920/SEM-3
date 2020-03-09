import java.lang.*;
import java.io.*;
import java.util.*;

class Clock
{
	int hr,min,sec;
	Clock()
	{
		hr=0;
		min=0;
		sec=0;
	}
	Clock(int hr,int min,int sec)
	{
		this.hr=hr;
		this.min=min;
		this.sec=sec;
	}
}
class Digitalclock extends Clock
{
	String time;
	Digitalclock(int hr,int min,int sec)
	{
		super(hr,min,sec);
		if(hr<=12)
		{
			time="PM";
		}
		else
		{
			time="AM";
		}
	}
	void displaytime()
	{
		System.out.println(""+hr+"."+""+min+"."+""+sec);
	}
	void tick()
	{
		sec++;
		if(sec>=60)
		{
			sec=0;
			min++;
		}
		 if(min>=60)
		{
			min=0;
			hr++;
		}
		 if(hr>=24)
		{
			hr=0;
		}
		if(hr>=12)
		{
			time="PM";
		}
		else
		{
			time="AM";
		}
	}
			
	
	public static void main(String[] args)
	{
		Digitalclock c=new Digitalclock(10,20,30);
		c.displaytime();
		c.tick();
		c.displaytime();
		c.tick();
		c.tick();
		c.tick();
		c.tick();
		c.tick();
		c.tick();
		c.displaytime();
	}
		
}

/*
 OUTPUT::
10.20.30
10.20.31
10.20.37
*/
