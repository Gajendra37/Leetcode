/*
Description:
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order. 

Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
  
Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
*/

//Solution:

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    int *arr=malloc(numsSize*sizeof(int));
    *returnSize=numsSize;
    for(int i=0;i<numsSize;i++)
    {
        arr[i]=nums[i]*nums[i];
    }
    for(int i=0;i<numsSize-1;i++)
    {
        for(int j=0;j<numsSize-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    return arr;
}
