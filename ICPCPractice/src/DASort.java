import java.util.Collections;
import java.util.Scanner;
import java.util.Vector;

public class DASort {
	public static Vector<Integer> arr;
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int K = scan.nextInt();
		for (int i = 0; i < K; i++) {
			int ix = scan.nextInt();
			int n = scan.nextInt();
			
			arr = new Vector<Integer>();
			Vector<Integer> sarr = new Vector<Integer>();
			
			int read;
			for (int j = 0 ; j < n; j++) {
				read = scan.nextInt();
				arr.add(read);
				sarr.add(read);
			}
			Collections.sort(sarr);
			
			int max = sarr.size();
			int count = 0;
			//while (true) {
				int x = 0;
				Vector<Integer> vec = new Vector<Integer>();
				for (int j = 0; j < n; j++) {
					if (arr.get(j) > sarr.get(x)) {
						vec.add(arr.get(j));
					}
					else {
						x++;
					}
				}
//				if (x == max) break;
//				Collections.sort(vec);
//				for (int j = 0; j < vec.size(); j++) {
//					dna(vec.get(j));
//				}
				count += vec.size();
			//}
			
			System.out.println(ix + " " + count);
		}
	}
//	public static void dna(int val) {
//		arr.remove(arr.lastIndexOf(val));
//		arr.add(val);
//	}
}
