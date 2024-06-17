import java.util.*;

class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> s= new HashSet<>();
        Arrays.sort(nums);
        for(int i=0 ;i<nums.length; i++){
            int target=-(nums[i]);
            for(int j=i+1, k=nums.length-1; j<k; ){
                int sum=nums[j]+nums[k];
                if(sum==target){
                    List<Integer> li=new ArrayList<>();
                    li.add(nums[i]);
                    li.add(nums[j]);
                    li.add(nums[k]);
                    s.add(li);
                    j++;
                    k--;
                }
                else if(sum>target){
                    k--;
                }
                else{
                    j++;
                }
            }

        }

         List<List<Integer>> arr = new ArrayList<>();
        arr.addAll(s);
        return arr;
    }
}
public class threesum {
    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] nums1 = {-1, 0, 1, 2, -1, -4};
        List<List<Integer>> result1 = solution.threeSum(nums1);
        System.out.println("Result 1: " + result1);
        // Expected output: [[-1, -1, 2], [-1, 0, 1]]

        int[] nums2 = {0, 0, 0};
        List<List<Integer>> result2 = solution.threeSum(nums2);
        System.out.println("Result 2: " + result2);
        // Expected output: [[0, 0, 0]]

        int[] nums3 = {1, -1, -1, 0};
        List<List<Integer>> result3 = solution.threeSum(nums3);
        System.out.println("Result 3: " + result3);
        // Expected output: [[-1, 0, 1]]

        // Add more test cases as needed
    }
}
