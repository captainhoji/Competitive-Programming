import java.util.Scanner;

public class Mary {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = scan.nextInt();
		
		for (int i = 0; i < N; i++) {
			int ix = scan.nextInt();
			int m = scan.nextInt();
			int n = scan.nextInt();
			
			int k = m;
			int c = 1;
			while (k <= n) {
				k *= m;
				c++;
			}
			k /= m;
			
			int[] arr = new int[c];
			for (int j = 0; j < c; j++) {
				if (k <= n) {
					arr[j]++;
					n -= k;
				}
				k /= m;
			}
			
			long tmp = 0;
			long count = 0;
			for (int j = 0; j < c; j++) {
				if (arr[j] > 0) {
					arr[j] += tmp*m;
					count += arr[j];
					tmp = arr[j];
					arr[j] = 0;
				}
			}
			1 - 1
			3 - 2
			9 - 5
			27 - 27 99[5] 9[7] [10] 23
			27x1 + 9x2 + 3x3 + x4 = 27
			[0, 3, 0]
			System.out.println(ix + " " + count);
			
			
		}
	}
}
