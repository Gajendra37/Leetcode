/*
Description:

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6
  
Example 2:
Input: nums = [1,2,3,4]
Output: 24
  
Example 3:
Input: nums = [-1,-2,-3]
Output: -6
*/

//Solution:

class Solution {
    public int maximumProduct(int[] nums) {
        
        Arrays.sort(nums);
        int l=nums.length-1;

        if(nums[0]*nums[1]*nums[l] > nums[l]*nums[l-1]*nums[l-2])
            return nums[0]*nums[1]*nums[l];
        else
            return nums[l]*nums[l-1]*nums[l-2];

    }
}
