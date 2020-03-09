/*
PROGRAM: SHOP CART
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
import java.lang.*;
import java.io.*;
class Product
{
	int price;
	String name;
	Product(String name,int price)
	{
		this.price=price;
		this.name=name;
	}
}	
	

class Shopcart
{
	public static void main(String[] args)
	{
	
			
		Scanner sc=new Scanner(System.in);
		Vector v=new Vector();
		int ch,a;
		do
		{
			
			System.out.println( " -----------MENU------------    ");	
			System.out.println( " 1. Add an item to the cart ");	
			System.out.println( " 2. Delete an item from the cart ");	
			System.out.println( " 3. Print the cart items along with its price  ");	
			System.out.println( " 4. Total purchase ");
			System.out.println( " 5. Exit the MENU  ");
			ch=sc.nextInt();
			switch(ch)
			{
				case 1:	
						System.out.println( " Enter the product name and its price respectively ");
						Product p = new Product(sc.next(),sc.nextInt());
						v.add(p);
						break;
					
				case 2:	String n;
					 	int flag = 0;
					 	Iterator itr = v.iterator();
					 	System.out.println( " Enter the product name to be deleted ");
					 	n=sc.next();
					 	Product q;
					 	while(itr.hasNext())
						 {
					 		q = (Product)itr.next();
					 		if(q.name.equals(n))
					 		{
					 			itr.remove();
					 			flag=1;
					 			break;
					 		}
					 	}
						if(flag==1)
					 	{
					 		System.out.println( " The entered product is deleted ");				
						}
					 	else
					 	{
					 		System.out.println( " Entered product is not there in the cart ");
					 	}
						break;
					
				case 3:	 Iterator itr1 = v.iterator();
					 	 Product i;
						 while(itr1.hasNext())
					 	{
					 		i = (Product)itr1.next();
					 		System.out.println( " Product name : " + i.name);
					 		System.out.println( " Product price : " + i.price);
					 	} 	
					 	break;
						
				case 4:   int bill = 0;
						Iterator itr2 = v.iterator();
						Product z;
						while(itr2.hasNext())
						{
							z = (Product)itr2.next();
							bill = bill + z.price;
						}
						System.out.println( " Your shopping bill is  "  +  bill);
						break;
						
				case 5: 	System.exit(0);
						break;		
				default: 	System.out.println( " Wrong entry entered ");
			
			}
			
		
		}while(ch!=5);		
	}
}	
/*
OUTPUT:
D:\JAVA>javac shopcart.java

D:\JAVA>java Shopcart
 -----------MENU------------
 1. Add an item to the cart
 2. Delete an item from the cart
 3. Print the cart items along with its price
 4. Total purchase
 5. Exit the MENU
1
 Enter the product name and its price respectively
Samsung
150000
 -----------MENU------------
 1. Add an item to the cart
 2. Delete an item from the cart
 3. Print the cart items along with its price
 4. Total purchase
 5. Exit the MENU
2
 Enter the product name to be deleted
Apple
 Entered product is not there in the cart
 -----------MENU------------
 1. Add an item to the cart
 2. Delete an item from the cart
 3. Print the cart items along with its price
 4. Total purchase
 5. Exit the MENU
1
 Enter the product name and its price respectively
Apple 85000
 -----------MENU------------
 1. Add an item to the cart
 2. Delete an item from the cart
 3. Print the cart items along with its price
 4. Total purchase
 5. Exit the MENU
3
 Product name : Samsung
 Product price : 150000
 Product name : Apple
 Product price : 85000
 -----------MENU------------
 1. Add an item to the cart
 2. Delete an item from the cart
 3. Print the cart items along with its price
 4. Total purchase
 5. Exit the MENU
5
*/		