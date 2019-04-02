import java.util.Scanner;
import java.util.Vector;

public class RatSequence {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		
		int K = scan.nextInt();
		int ix;
		long n;
		
		for (int i = 0; i < K; i++) {
			ix = scan.nextInt();
			n = scan.nextLong();
			
			Vector<Boolean> vec = new Vector<Boolean>();
			long x = 1;
			while (n >= x) {
				x = x*2;
			}
			x = x/2;
			while (x > 0) {
				if (x <= n) {
					vec.add(true);
					n = n-x;		
				}
				else {
					vec.add(false);
				}
				x = x/2;
			}
			long l = 1;
			long r = 1;
			for (int j = 1; j < vec.size(); j++) {
				if (vec.get(j)) {
					l = l + r;
				}
				else {
					r = l + r;
				}
			}
			System.out.println(ix + " " + l + "/" + r);
		}
	}
}
