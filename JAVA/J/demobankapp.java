/*
PROGRAM: DEMO BANK APP
NAME: SHERWIN PILLAI
CLASS: SE COMPS
BATCH: C 
ROLL NO.: 8358	
*/
import java.util.*;
abstract class Account
{
  /* *** VARIABLES OF ACCOUNT *** */
  int accid;
  float bal;
  int penalty;
    /* *** METHODS OF CUSTOMER *** */
  Account(int accid, float bal)
  {
     this.accid=accid;
     this.bal=bal;
  }
    void deposit(float amt)
  {
     bal = bal + amt;
  }
  void viewBal()
  {
     System.out.println("BALANCE : " + bal);
  }
  void displayAcc()
  {
     System.out.println("ACC ID:" + accid + " BAL: " + bal + penalty);
  }
  /* *** ABSTRACT METHOD IMPLEMENTED BY CURRENT AND SAVING ACCOUNT *** */
}
class SavingsAccount extends Account
{
   /* *** VARIABLES OF SAVINGS ACCOUNT *** */
   int roi;
   /* *** METHODS OF SAVINGS ACCOUNT *** */
   SavingsAccount(int accid, float amt, int roi)
   {
      super(accid, amt);
      this.roi = roi;
   }
    boolean wdm(float amt) /* *** OVERRIDDEN METHOD *** */
   {
      if((bal - amt)>0)
      {
            bal = bal-amt;
            return true;
      }
      else
         return false;
   }
    void updateBal()
   {
      bal = bal + (bal * roi)/100;
   }
}
class CurrentAccount extends Account
{
   /* *** VARIABLES OF CURRENT ACCOUNT *** */
   int minbal;
   int penalty;


   /* *** METHODS OF CURRENT ACCOUNT *** */
   CurrentAccount(int accid, float amt, int minbal, int penalty)
   {
      super(accid, amt);
      this.minbal = minbal;
      this.penalty = penalty;
   }
    boolean wdm(float amt) /* *** OVERRIDDEN METHOD *** */
   {
      if((bal - amt)>0)
      {
         if((bal-amt)>=minbal)
         {
            bal = bal-amt;
            return true;
         }
         else if(bal-amt-penalty>0)
         {
            bal = bal-amt-penalty;
            return true;
         }
         else
            return false;
      }
      else
         return false;
   }
}
class BankDemoApp1 {
   public static void main(String[] args) {
      Account a;
      System.out.println("Enter AccType");
      Scanner sc = new Scanner(System.in);
      String acctype = sc.nextLine();
      if(acctype.equals("current"))
         a = new CurrentAccount(sc.nextInt(),sc.nextInt(),sc.nextInt(), 1000);
      else
         a = new SavingsAccount(sc.nextInt(),sc.nextInt(), 5);
      a.displayAcc();
   }
}
/*
OUTPUT:

*/