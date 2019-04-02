//Problem        : Power Balance
//Language       : Java
//Compiled Using : javac
//Version        : Java 1.7.0_75
//Input for your program will be provided from STDIN
//Print out all output from your program to STDOUT

import java.util.Hashtable;
import java.util.Scanner;
//Your submission should *ONLY* use the following class name
public class P4
{
    public static void main(String[] args)
    {

       Scanner scan = new Scanner(System.in);
       scan.next();
       int N = scan.nextInt();
       Hashtable<String, Integer> ht = new Hashtable<String, Integer>();
       Hashtable<String, Hashtable<String, Integer>> buy = new Hashtable<String, Hashtable<String, Integer>>();
       for (int i = 0; i < N; i++) {
           scan.next();
           scan.nextInt();
           int actn = scan.nextInt();
           for (int j = 0; j < actn; j++) {
               String cmd = scan.next();
               if (cmd.equals("BUY_PLANT")) {
                   String company = scan.next();
                   if (!ht.containsKey(company)) {
                	   ht.put(company, 100);
                   }
                   
                   ht.put(company, ht.get(company) - scan.nextInt());
               }
               else if (cmd.equals("FUEL")) {
                   
               }
               else if (cmd.equals("BUY_FUEL")) {
                   
               }
           }
       }
       
    }

}
