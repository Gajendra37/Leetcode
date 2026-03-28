/*
Description:

You are given a sorted unique integer array nums.
A range [a,b] is the set of all integers from a to b (inclusive).
Return the smallest sorted list of ranges that cover all the numbers in the array exactly.
That is, each element of nums is covered by exactly one of the ranges, and there is no integer x such that x is in one of the ranges but not in nums.
Each range [a,b] in the list should be output as:
"a->b" if a != b
"a" if a == b

Example 1:
Input: nums = [0,1,2,4,5,7]
Output: ["0->2","4->5","7"]
Explanation: The ranges are:
[0,2] --> "0->2"
[4,5] --> "4->5"
[7,7] --> "7"
  
Example 2:
Input: nums = [0,2,3,4,6,8,9]
Output: ["0","2->4","6","8->9"]
Explanation: The ranges are:
[0,0] --> "0"
[2,4] --> "2->4"
[6,6] --> "6"
[8,9] --> "8->9"
*/

//Solution:

char** summaryRanges(int* nums, int numsSize, int* returnSize) {

    char** result=malloc(numsSize*sizeof(char*));
    *returnSize=0;

    if(numsSize==0) 
        return result;

    int start=nums[0];
    for(int i=0;i<numsSize;i++) 
    {
        if(i==numsSize-1 || nums[i]+1!=nums[i+1]) 
        {
            char* temp=malloc(25*sizeof(char));
            if(start==nums[i])
                sprintf(temp,"%d",start); 
            else 
                sprintf(temp,"%d->%d",start,nums[i]);

            result[*returnSize]=temp;
            (*returnSize)++;

            if(i!=numsSize-1)
                start=nums[i+1];
        }
    }
    return result;
}
