/*
Description:

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
If target is not found in the array, return [-1, -1].
You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

//Solution:

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    
    int *arr=malloc(sizeof(int)*2);
    *returnSize=2;

    int f=0,l=0,c=0;
    for(int i=0;i<numsSize;i++)
    {
        if(nums[i]==target && f==0)
        {
            arr[0]=i;
            f=1;
            c++;
        }
    }
    for(int i=numsSize-1;i>=0;i--)
    {
        if(nums[i]==target && l==0)
        {
            arr[1]=i;
            l=1;
            c++;
        }
    }
    if(c!=2)
    {
        arr[0]=-1;
        arr[1]=-1;
    }
    return arr;
}
