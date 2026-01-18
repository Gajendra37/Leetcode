/*
Description:

Given an integer array nums, return the third distinct maximum number in this array. If the third maximum does not exist, return the maximum number.

Example 1:
Input: nums = [3,2,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2.
The third distinct maximum is 1.

Example 2:
Input: nums = [1,2]
Output: 2
Explanation:
The first distinct maximum is 2.
The second distinct maximum is 1.
The third distinct maximum does not exist, so the maximum (2) is returned instead.

Example 3:
Input: nums = [2,2,3,1]
Output: 1
Explanation:
The first distinct maximum is 3.
The second distinct maximum is 2 (both 2's are counted together since they have the same value).
The third distinct maximum is 1.
*/

//Solution:

int thirdMax(int* nums, int numsSize) {

    for(int i=0;i<numsSize;i++) 
    {
        for(int j=0;j<numsSize-1;j++) 
        {
            if(nums[j]<nums[j+1]) 
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    int count=1; 
    int prev=nums[0];
    for(int i=1;i<numsSize;i++) 
    {
        if(nums[i]!=prev) 
        {
            count++;
            prev=nums[i];
            if(count==3)
                return nums[i];
        }
    }
    return nums[0];
}
