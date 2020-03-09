import java.awt.*;
import java.applet.Applet;
class Demo extends Applet
{
	String iname;
	Image image;
	String cname;
	public static start()
	{
		cname = getParameter("clientname");
	}
	public void init()
	{
		String iname = "logo.jpg";
		img = getImage(getDocumentBase(),Graphics);
	}
	public static paint(Graphics G)
	{
		g.drawString("ABC Linked", 100,50);
		g.drawLine(0,60,200,60);
		g.drawImage(img, 40, 80);
		g.drawOval(200,80,100,50);
		g.drawRect(225,90,70,40);
		g.drawPolygon(xpoints.ypoints.nun);
		int xpoints[] = {230,240,250,260,240,230};
		int ypoints[] = {110,105,110,120,130,120};
		int nun = 86;
		g.drawString("Hello " +cname);
	}
}
