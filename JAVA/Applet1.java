import java.applet.*;
import java.awt.*;
import java.lang.*;
/*<applet code ="Applet1.class" height=800 width=1000>Applet1</applet>*/
public class Applet1 extends Applet
{	Font f1;
	public void init()
	{	f1=new Font("Times New Roman",Font.PLAIN,25) ;
		setForeground(Color.red);
	}
	public void paint(Graphics g)
	{	g.setFont(f1);
		g.drawString("Hello",20,46);
		g.drawRect(60,120,20,20);
		g.drawLine(100,69,45,36);
		g.drawOval(50,100,50,50);
		g.drawRect(200,200,100,100);
		g.drawRect(250,250,100,100);
		g.drawLine(200,200,250,250);
		g.drawLine(300,200,350,250);
		g.drawLine(200,300,250,350);
		g.drawLine(300,300,350,350);
		try {int xpoints[]={20,100,250,60};
 		int ypoints[]={10,400,150,20};
 		int nun=5;
 		g.drawPolygon(xpoints,ypoints,nun);}
		catch(Exception e)
		{	System.out.println(e);
		}
		finally
		{	System.out.println("This shit works");
		}
	}
	public static void main(String[]args)
	{	System.out.println("This shit works");
	}
}