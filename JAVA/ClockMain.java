import java.util.*;
class Clock
{	int hr,min,sec;
	Clock(int hr,int min,int sec)
	{	this.hr=hr;
		this.min=min;
		this.sec=sec;
	}
	public String toString()
	{	return hr+":"+min+":"+sec;
	}
}
class DigitalClock extends Clock
{	String t;
	int hh;
	Scanner in=new Scanner(System.in);
	DigitalClock(int hr,int min,int sec)
	{	
		super(hr,min,sec);
		if(hr>12)
		{	hh=hr-12;
			System.out.println(hh);
			t="PM";}
		else
		{hh=hr;
		t="AM";}
	}
	public String toString()
	{	return hh+":"+min+":"+sec+" "+t;
	}
}
class ClockMain
{	public static void main(String []args)
	{	DigitalClock d=new DigitalClock(18,25,32);
		System.out.println(d.toString());
	}
}
		