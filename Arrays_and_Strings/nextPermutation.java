import java.util.*;
class Solution {
    public void nextPermutation(int[] nums) {
        int i=-1;
        int j=-1;
        for(int k=0; k<nums.length-1; k++){
            if(nums[k]<nums[k+1]){
                i=k;
            }
        }

        if(i!=-1){
            for(int k=i; k<nums.length; k++){
                if(nums[k]>nums[i]){
                    j=k;
                }
            }

            int tt=nums[i];
            nums[i]=nums[j];
            nums[j]=tt;

          
        }
  for(int k=i+1,o=nums.length-1;k<o;){
            int y=nums[k];
            nums[k]=nums[o];
            nums[o]=y;
            k++;
            o--;
        }
       
        return;
        
    }
}
public class nextPermutation {

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {1, 2, 3};
        solution.nextPermutation(nums1);
        System.out.println(Arrays.toString(nums1)); // Expected output: [1, 3, 2]

        int[] nums2 = {3, 2, 1};
        solution.nextPermutation(nums2);
        System.out.println(Arrays.toString(nums2)); // Expected output: [1, 2, 3]

        int[] nums3 = {1, 1, 5};
        solution.nextPermutation(nums3);
        System.out.println(Arrays.toString(nums3)); // Expected output: [1, 5, 1]
    }
}