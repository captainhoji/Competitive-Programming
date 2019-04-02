import java.util.Scanner;

class InOrOut {
	public static void main(String[] args) {
		InOrOut io = new InOrOut();
		Scanner scan = new Scanner(System.in);
		
		int n = scan.nextInt();
		int q = scan.nextInt();
		
		Point[] points = new Point[n];
		
		double x, y;
		for (int i = 0; i < n; i++) {
			x = scan.nextDouble();
			y = scan.nextDouble();
			points[i] = io.new Point(x, y);
		}
		
		for (int i = 0; i < q; i++) {
			x = scan.nextDouble();
			y = scan.nextDouble();
			boolean inside = true;
			for (int j = 0; j < n; j++) {
				int k = (j + 1) % n;
				double dx = points[k].x - points[j].x;
				double dy = points[k].y - points[j].y;
				double ex = x - points[j].x;
				double ey = y - points[j].y;
				double z = dx*ey - ex*dy;
				double eps = 1e-8;
				if (z < -eps) {
					inside = false;
					break;
				}
			}
			if (inside) {
				System.out.println("D");
			}
			else {
				System.out.println("F");
			}
		}
	}
	class Point {
		public double x;
		public double y;
		public Point(double x, double y) {
			this.x = x;
			this.y = y;
		}
	}
	
}
