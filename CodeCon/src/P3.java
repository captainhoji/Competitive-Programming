import java.util.Scanner;

public class P3 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int R = scan.nextInt();
		int C = scan.nextInt();
		int K = scan.nextInt();
		
		char[][] map = new char[R][C];
		
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				map[i][j] = scan.next().charAt(0);		
			}
		}
		
		int x = 0;
		int y = 0;
		char curr = map[x][y];
		char down, up, left, right, choose;
		int cx, cy;
		System.out.print(curr);
		for (int i = 0; i < K; i++) {	
			cx = -1;
			cy = -1;
			choose = 'a';
			if (x + 1 != R) {
				down = map[x+1][y];
				if (down != curr) {
					choose = down;
					cx = x+1;
					cy = y;
				}
			}
			else {
				down = 'a';
			}
			if (x - 1 != -1) {
				System.out.println("x: " + x);
				up = map[x-1][y];
				if (up != curr) {
					if (choose != 'a') {
						if (up < choose) {
							choose = up;
							cx = x-1;
							cy = y;
						}
						else if (up == choose) {
							if (x-1 < cx) {
								choose = up;
								cx = x-1;
								cy = y;
							}
							else if (x-1 == cx) {
								if (y < cy) {
									choose = up;
									cx = x-1;
									cy = y;
								}
							}
						}						
					}
					else {
						choose = up;
						cx = x-1;
						cy = y;
					}
				}
			}
			else {
				up = 'a';
			}
			if (y + 1 != C) {
				right = map[x][y+1];
				if (right != curr) {
					if (choose != 'a') {
						if (right < choose) {
							choose = right;
							cx = x-1;
							cy = y;
						}
						else if (right == choose) {
							if (x-1 < cx) {
								choose = right;
								cx = x-1;
								cy = y;
							}
							else if (x-1 == cx) {
								if (y < cy) {
									choose = right;
									cx = x-1;
									cy = y;
								}
							}
						}						
					}
					else {
						choose = up;
						cx = x-1;
						cy = y;
					}
				}
			}
			else {
				right = 'a';
			}
			if (y - 1 != -1) {
				left = map[x][y-1];
				if (left != curr) {
					if (choose != 'a') {
						if (left < choose) {
							choose = left;
							cx = x-1;
							cy = y;
						}
						else if (left == choose) {
							if (x-1 < cx) {
								choose = left;
								cx = x-1;
								cy = y;
							}
							else if (x-1 == cx) {
								if (y < cy) {
									choose = left;
									cx = x-1;
									cy = y;
								}
							}
						}						
					}
					else {
						choose = up;
						cx = x-1;
						cy = y;
					}
				}
			}
			else {
				left = 'a';
			}
			System.out.print(choose);
			x = cx;
			y = cy;
		}
	}
}
