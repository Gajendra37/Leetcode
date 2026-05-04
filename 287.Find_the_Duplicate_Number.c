/*
Description:

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and using only constant extra space.
  
Example 1:
Input: nums = [1,3,4,2,2]
Output: 2
  
Example 2:
Input: nums = [3,1,3,4,2]
Output: 3
  
Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
*/

//Solution:

int findDuplicate(int* nums, int numsSize) {
    
    int freq[1000000]={0};
    for(int i=0;i<numsSize;i++)
        freq[nums[i]]++;
    for(int i=1;i<=1000000;i++)
        if(freq[i]>1)
            return i;
    return -1;
}
