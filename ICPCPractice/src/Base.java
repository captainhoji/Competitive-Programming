import java.util.Scanner;

public class Base {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		for (int i = 0; i < N; i++) {
			int ix = scan.nextInt();
			int n = scan.nextInt();
			int nc = n;
			
			int oct = 0;
			int hex = 0;
			int octd = 1;
			int hexd = 1;
			boolean o = true;
			while (n > 0) {
				int d = n%10;
				if (d >= 8) {
					oct = 0;
					o = false;
				}
				hex += d * hexd;					
				if (o) {
					oct += d * octd;					
				}
				n /= 10;
				octd *= 8;
				hexd *= 16;
			}
			System.out.println(ix + " " + oct + " " + nc + " " + hex);
		}
	}
}
