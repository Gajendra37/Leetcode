/*
Description:

Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.
Return any array that satisfies this condition.

Example 1:
Input: nums = [3,1,2,4]
Output: [2,4,3,1]
Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.

Example 2:
Input: nums = [0]
Output: [0]  
*/

//Solution:

int* sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    
    int *arr=malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=0;j<numsSize-i-1;j++)
        {
            if(nums[j]>nums[j+1])
            {
                int temp=nums[j];
                nums[j]=nums[j+1];
                nums[j+1]=temp;
            }
        }
    }
    int j=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]%2==0)
            arr[j++]=nums[i];
    }
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]%2!=0)
            arr[j++]=nums[i];
    }
    return arr;
}
