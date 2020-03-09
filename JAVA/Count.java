import java.util.*;
class Vowels
{
    Scanner sc=new Scanner(System.in);
    int vowels = 0, consonants = 0, digits = 0, spaces = 0;
    public void countv()
    {
        System.out.println(" Enter the String ");
        String line=sc.nextLine();
        line = line.toLowerCase();
        for(int i = 0; i < line.length(); ++i)
        {
            char ch = line.charAt(i);
            if(ch == 'a' || ch == 'e' || ch == 'i'
                || ch == 'o' || ch == 'u') {
                ++vowels;
            }
            else if((ch >= 'a'&& ch <= 'z')) {
                ++consonants;
            }
            else if( ch >= '0' && ch <= '9')
            {
                ++digits;
            }
            else if (ch ==' ')
            {
                ++spaces;
            }
        }

    }

    public void display()
    {
        System.out.println("Vowels: " + vowels);
        System.out.println("Consonants: " + consonants);
        System.out.println("Digits: " + digits);
        System.out.println("Spaces: " + spaces);
    }
}
 class Count {

    public static void main(String[] args) {
             
            Vowels v=new Vowels();
            v.countv();
            v.display();
       
    }
}