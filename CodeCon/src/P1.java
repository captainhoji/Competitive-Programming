import java.util.Scanner;
//Your submission should *ONLY* use the following class name
public class P1
{
    public static void main(String[] args)
    {

       Scanner stdin = new Scanner(System.in);
       String str = stdin.next();
       for (int i = 0; i < 32; i++) {

    	   if (str.charAt(i) == '0') {
    		   int l = 0;
    		   StringBuffer sb = new StringBuffer(str);
    		   sb.setCharAt(i, '1');
    		   boolean one = false;
    		   int max = 0;
    		   for (int j = 0; j < 32; j++) {
    			   if (one) {
    				   if (sb.charAt(j) == '1') {
    					   l++;
    					   if (l > max) {
    						   max = l;
    					   }
    				   }
    				   else {
    					   one = false;
    					   l = 0;
    				   }
    			   }
    			   else if (sb.charAt(j) == '1') {
    					   l++;
    					   one = true;
    					   if (l > max) {
    						   max = l;
    					   }
    			   }
				   else {
					   one = false;
					   l = 0;
				   }
    	   }
           
       }
       
    }

}
    }