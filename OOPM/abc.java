class Room
{	int length,breadth;
	Room(int x,int y)
	{	length=x;
		breadth=y;
	}
	int area()
	{	return length*breadth;
	}
}
class BedRoom extends Room
{	int height;
	BedRoom(int x,int y,int z)
	{	super(x,y);
		height=z;
	}
	int volume()
	{ return length*breadth*height;
	}
}
class abc
{	public static void main(String[]args)
	{	BedRoom r=new BedRoom(4,5,6);
		System.out.println("Area= "+r.area());
		System.out.println("Volume= "+r.volume());
	}
}
		