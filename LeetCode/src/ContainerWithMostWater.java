
public class ContainerWithMostWater {
	public static void main(String[] args) {
		ContainerWithMostWater cont = new ContainerWithMostWater();
		int[] height = {2, 1};
		int ans = cont.maxArea(height);
		System.out.println(ans);
	}
	public int maxArea(int[] height) {
        int r = height.length- 1;
        int l = 0;
        int maxArea = 0;
       
        while (l != r) {
            if (height[l] > height[r]) {
            	if (height[r] * (r-l) > maxArea) {
            		maxArea = height[r] * (r-l);
            	}
                r--;
            }
            else {
            	if (height[l] * (r-l) > maxArea) {
            		maxArea = height[l] * (r-l);
            	}
                l++;
            }
        }
        return maxArea;
    }
}
