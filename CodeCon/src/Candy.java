import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.Vector;

public class Candy {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int C = scan.nextInt();
		int n = scan.nextInt();
		Vector<HashSet<String>> record = new Vector<HashSet<String> >();
		HashSet<String> child = new HashSet<String>();
		HashSet<String> parent = new HashSet<String>();
		
		int[] candies = new int[n];
		for (int i = 0;i < n; i++) {
			record.add(new HashSet<String>());
			candies[i] = scan.nextInt();
			String str = scan.nextLine();
			String[] sarr = str.split(" ");
			for (int j = 1; j < sarr.length; j++) {
				record.get(i).add(sarr[j]);
				parent.add(sarr[j]);
			}
		}
		
		
		int c = C;
		for (int i = 0; i < n; i++) {
			if (candies[i] < c) {
				if (child.isEmpty()) {
					for (String name : record.get(i)) {
						child.add(name);
					}					
				}
				else {
					child.retainAll(record.get(i));
				}
				parent.removeAll(record.get(i));
				c = candies[i];
			}
		}
		for (String name : child) {
			c = C;
			for (int i = 0; i < n; i++) {
				if (record.get(i).contains(name) && record.get(i).size() == 1) {
					if (candies[i] == c) {
						child.remove(name);
						break;
					}
				}
				c = candies[i];
			}
		}
		for (String name : child) {
			HashSet<String> p = new HashSet<String>();
			for (String xxx : parent) {
				p.add(xxx);
			}
			c = C;
			for (int i = 0; i < n; i++) {
				if (record.get(i).contains(name)) {
					if (candies[i] == c) {
						p.retainAll(record.get(i));
					}
				}
				c = candies[i];
			}
			if (p.size() == 2) {
				if (p.contains(name)) {
					parent = p;
					break;
				}
			}
		}
		if (child.size() == 1) {
			String[] x = new String[1];
			x = child.toArray(x);
			System.out.print(x[0] + " ");
			if (parent.size() == 1) {
				x = parent.toArray(x);
				System.out.println(x[0]);
			}
			else {
				System.out.println("UNKNOWN");
			}
		}
		else {
			System.out.println("UNKNOWN");
		}
	}
}
