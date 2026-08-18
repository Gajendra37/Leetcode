/*
Description:

You are given a 0-indexed integer array nums of size n.
Define two arrays leftSum and rightSum where:
leftSum[i] is the sum of elements to the left of the index i in the array nums. If there is no such element, leftSum[i] = 0.
rightSum[i] is the sum of elements to the right of the index i in the array nums. If there is no such element, rightSum[i] = 0.
Return an integer array answer of size n where answer[i] = |leftSum[i] - rightSum[i]|.

Example 1:
Input: nums = [10,4,8,3]
Output: [15,1,11,22]
Explanation: The array leftSum is [0,10,14,22] and the array rightSum is [15,11,3,0].
The array answer is [|0 - 15|,|10 - 11|,|14 - 3|,|22 - 0|] = [15,1,11,22].
  
Example 2:
Input: nums = [1]
Output: [0]
Explanation: The array leftSum is [0] and the array rightSum is [0].
The array answer is [|0 - 0|] = [0].
*/

//Solution:

int* leftRightDifference(int* nums, int numsSize, int* returnSize) {
    
    int *arr=malloc(sizeof(int)*numsSize);
    int left[numsSize],right[numsSize];
    left[0]=0;
    for(int i=1;i<numsSize;i++)
    {
        int val=0;
        for(int j=0;j<i;j++)
        {
            val+=nums[j];
        }
        left[i]=val;
    }

    for(int i=0;i<numsSize-1;i++)
    {
        int val=0;
        for(int j=i+1;j<numsSize;j++)
        {
            val+=nums[j];
        }
        right[i]=val;
    }
    right[numsSize-1]=0;

    for(int i=0;i<numsSize;i++)
        arr[i]=abs(right[i]-left[i]);

    *returnSize=numsSize;
    return arr;
}
