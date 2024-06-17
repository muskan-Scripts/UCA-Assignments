import java.util.*;
class Solution {
    public int maxArea(int[] height) {
        int max=-1;
        for(int i=0, j=height.length-1; i<j;){
            int min= Math.min(height[i],height[j]);
           
                    max=Math.max(min*(j-i), max);
                    if(height[i]>=height[j]){
                        j--;
                    }
                    else{
                        i++;
                    }
            
        }

        return max;
    }
}
public class containerwithmostwater {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] height1 = {1, 8, 6, 2, 5, 4, 8, 3, 7};
        int result1 = solution.maxArea(height1);
        System.out.println("Result 1: " + result1);
        // Expected output: 49

        int[] height2 = {1, 1};
        int result2 = solution.maxArea(height2);
        System.out.println("Result 2: " + result2);
        // Expected output: 1

        int[] height3 = {4, 3, 2, 1, 4};
        int result3 = solution.maxArea(height3);
        System.out.println("Result 3: " + result3);
        // Expected output: 16

        // Add more test cases as needed
    }
}
