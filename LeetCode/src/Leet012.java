import java.util.Scanner;

public class Leet012 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int num = scan.nextInt();

		System.out.println(solve(num));
		
		
		/*while (num >= 1000) {
			num -= 1000;
			Mcount++;
		}
		for (int i = 0; i < Mcount; i++) {
			sb = sb + "M";				
		}
		while (num >= 500) {
			num -= 500;
			Dcount++;
		}
		while (num >= 100) {
			num -= 100;
			Ccount++;				
		}
		if (Ccount == 4) {
			if (Dcount == 1) sb +="CM";
			else sb +="CD";
		}
		else {
			if (Dcount == 1) sb +="D";
			for (int i = 0; i < Ccount; i++) {
				sb +="C";
			}
		}
		while (num >= 50) {
			num -= 50;
			Lcount++;	
		}
		while (num >= 10) {
			num -= 10;
			Xcount++;	
		}
		if (Xcount == 4) {
			if (Lcount == 1) sb +="XC";
			else sb +="XL";
		}
		else {
			if (Lcount == 1) sb +="L";
			for (int i = 0; i < Xcount; i++) {
				sb +="X";
			}
		}
		while (num >= 5) {
			num -= 5;
			Vcount++;	
		}
		while (num >= 1) {
			num -= 1;
			Icount++;	
		}
		if (Icount == 4) {
			if (Vcount == 1) sb +="IX";
			else sb +="IV";
		}
		else {
			if (Vcount == 1) sb +="V";
			for (int i = 0; i < Icount; i++) {
				sb +="I";
			}
		}*/				
	}
	
	public static String solve(int num) {
		
		String[] dig1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
		String[] dig2 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
		String[] dig3 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
		String[] dig4 = {"", "M", "MM", "MMM", "MMMM", "MMMMM", "MMMMMM", "MMMMMMM", "MMMMMMMM", "MMMMMMMMM"};
		
		StringBuffer sb = new StringBuffer("");
		
		sb.append(dig4[num/1000]);
		num %= 1000;
		sb.append(dig3[num/100]);
		num %= 100;
		sb.append(dig2[num/10]);
		num %= 10;
		sb.append(dig1[num]);
	
		return sb.toString();
		
	}
}
