import java.util.Hashtable;
import java.util.Scanner;

public class FBINum {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		char[] arr = {'A', 'C', 'D', 'E', 'F', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'R', 'T', 'V', 'W', 'X'};
		Hashtable<Character, Integer> ht = new Hashtable<Character, Integer>();
		int x = 10;
		for (int i = 0; i < arr.length; i++) {
			ht.put(arr[i], x);
			x++;
		}
		
		int N = scan.nextInt();
		
		for (int i = 0; i < N; i++) {
			int ix = scan.nextInt();
			String str = scan.next();
			
			long[] varr = new long[9];
			for (int j = 0; j < 9; j++) {
				char ch = str.charAt(j);
				if ('0' <= ch && ch <= '9') {
					varr[j] = ch - '0';
				}
				else {
					varr[j] = ht.get(ch);					
				}
			}
			
			String ans;
			long u = (2*varr[0] + 4*varr[1] + 5*varr[2] + 7*varr[3] + 8*varr[4] + 10*varr[5] + 11*varr[6] + 13*varr[7])%27;
			if (u == varr[8]) {
				long d = 1;
				long val = 0;
				for (int j = 7; j >= 0; j--) {
					val += d * varr[j];
					d *= 27;
				}
				ans = val + "";
			}
			else {
				ans = "Invalid";
			}
			
			System.out.println(ix + " " + ans);
		}
	}
}
