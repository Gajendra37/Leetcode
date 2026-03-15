/*
Description:

You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers 
in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
You are given an integer array nums representing the data status of this set after the error.
Find the number that occurs twice and the number that is missing and return them in the form of an array.

Example 1:
Input: nums = [1,2,2,4]
Output: [2,3]
  
Example 2:
Input: nums = [1,1]
Output: [1,2]
*/

//Solution:

int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    
    int *freq=calloc(numsSize+1,sizeof(int));
    for(int i=0;i<numsSize;i++)
        freq[nums[i]]++;
    int x,y;
    for(int i=1;i<=numsSize;i++)
    {
        if(freq[i]>1)
            x=i;
        if(freq[i]==0)
            y=i;
    }
    int *arr=malloc(2*sizeof(int));
    arr[0]=x;
    arr[1]=y;
    *returnSize=2;
    return arr;
}
