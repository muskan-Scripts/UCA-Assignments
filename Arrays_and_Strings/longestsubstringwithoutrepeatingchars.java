import java.util.*;
class Solution {
    public int lengthOfLongestSubstring(String s) {
       Set<Character> set= new HashSet<>();
       int max=0;
       int i=0; 
       int j=0;
       char[] arr= s.toCharArray();
       while(j<s.length() && i<s.length()){
           if(set.contains(arr[j])){
               set.remove(arr[i]);
               i++;
           }
           else{
               set.add(arr[j]);
               j++;
               max=Math.max(j-i, max);
           } 
       }
       return max;
    }
}
public class longestsubstringwithoutrepeatingchars {
    public static void main(String[] args) {
        Solution solution = new Solution();

        String s1 = "abcabcbb";
        int result1 = solution.lengthOfLongestSubstring(s1);
        System.out.println("Result 1: " + result1);
        // Expected output: 3

        String s2 = "bbbbb";
        int result2 = solution.lengthOfLongestSubstring(s2);
        System.out.println("Result 2: " + result2);
        // Expected output: 1

        String s3 = "pwwkew";
        int result3 = solution.lengthOfLongestSubstring(s3);
        System.out.println("Result 3: " + result3);
        // Expected output: 3

        // Add more test cases as needed
    }
}
