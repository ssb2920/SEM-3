import java.util.*;

class SlashThread extends Thread{
	SlashThread(){
		super("Thread2");
	
	}
	public void run(){
		long i;
		for(i =0; i< 100; i++){
			System.out.print("/");
			try{
				Thread.sleep(1);
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
	}
}
class Star implements Runnable{
	public void  run(){
		long i;
		for(i =0; i< 100; i++){
			System.out.print("*");
			try{
				    Thread.sleep(1);
			}
			catch(Exception e){
				System.out.println(e);
			}
		}
	}
}
class DemoThread{
	public static void main(String[] args){
		SlashThread t1 = new SlashThread();
		Star s = new Star();
		Thread t2 = new Thread(s);
		t1.start();
		t2.start();
	
	}
}