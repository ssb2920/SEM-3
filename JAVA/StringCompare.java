import java.util.*;
import java.io.*;
class StringCompare
{	public static void main(String [] args)
	{	Scanner in=new Scanner(System.in);
		String s1=in.next();
		StringBuffer s2=new StringBuffer(s1);
		s2.reverse();
		System.out.println(s2);
		String s3=s2.toString();
		if(s1.equals(s3))
			System.out.println("Equal");
		else
			System.out.println("NO");
	}
}
		
		