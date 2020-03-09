import java.util.*;
abstract class Account
{
  /* *** VARIABLES OF ACCOUNT *** */
  int accid;
  float bal;
  String c;
  /* *** METHODS OF CUSTOMER *** */
  Account(int accid, float bal)
  {
     this.accid=accid;
     this.bal=bal;
  }
  void setCustomer(String c)
  {
     this.c = c;
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
     System.out.println("ACC ID:" + accid + " BAL: " + bal + "CUST ID: " + c.custid);
  }
  /* *** ABSTRACT METHOD IMPLEMENTED BY CURRENT AND SAVING ACCOUNT *** */
  abstract boolean wdm(float amt);
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
   public boolean wdm(float amt) /* *** OVERRIDDEN METHOD *** */
   {
      if((bal - amt)>0)
      {
            bal = bal-amt;
            return true;
      }
      else
         return false;
   }
   public void updateBal()
   {
      bal = bal + (bal * roi)/100;
   }
}




class CurrentAccount extends Account
{
   /* *** VARIABLES OF CURRENT ACCOUNT *** */
   int minbal;
   int penaulty;
   /* *** METHODS OF CURRENT ACCOUNT *** */
   CurrentAccount(int accid, float amt, int minbal, int penaulty)
   {
      super(accid, amt);
      this.minbal = minbal;
      this.penaulty = penaulty;
   }
   public boolean wdm(float amt) /* *** OVERRIDDEN METHOD *** */
   {
      if((bal - amt)>0)
      {
         if((bal-amt)>=minbal)
         {
            bal = bal-amt;
            return true;
         }
         else if(bal-amt-penaulty>0)
         {
            bal = bal-amt-penaulty;
            return true;
         }
         else
            return false;
      }
      else
         return false;
   }
}



public class BankDemoApp1 {
   public static void main(String[] args) {
      Bank b = new Bank("XYZ BANK LTD", "BANDRA-W"); //create a bank
      Account a;
      System.out.println("Enter AccType");
      Scanner sc = new Scanner(System.in);
      String acctype = sc.nextLine();
      if(acctype.equals("current"))
         a = new CurrentAccount(1, 25000, 10000, 1000);
      else
         a = new SavingsAccount(1, 55000, 5);
      b.createCust(1, "CUST1", a);
      //b.createCust(2, "CUST2", sa);
      System.out.println("*** FIRST CUSTOMER CURRENT ACCOUNT WITH 25000***");
      b.cust[0].operateAcc("viewbal");
      System.out.println("*** DEPOSIT 30000***");
      b.cust[0].operateAcc("depo", 30000);
      b.cust[0].operateAcc("viewbal");
      System.out.println("*** WITHDRAW MONEY 10000***");
      b.cust[0].operateAcc("wdm", 10000);
      b.cust[0].operateAcc("viewbal");
      System.out.println("*** CUSTOMER IS ****");
      b.displayAllCust();
   }
}

