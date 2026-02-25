/*
Description:

Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.
  
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
  
Example 2:
Input: nums = [1,1]
Output: [2]
*/

//Solution:

int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {

    for(int i=0;i<numsSize;i++) 
    {
        int idx=abs(nums[i])-1;
        if(nums[idx]>0)
            nums[idx]=-nums[idx];
    }
    int count=0;
    for (int i=0;i<numsSize;i++) 
    {
        if(nums[i]>0)
            count++;
    }
    int* res=malloc(count*sizeof(int));
    *returnSize=count;
    int k=0;
    for(int i=0;i<numsSize;i++) 
    {
        if(nums[i]>0)
            res[k++]=i+1;
    }
    return res;
}
