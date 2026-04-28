/*
Description:

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
  
Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
*/

//Solution:

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {

    int seen[1001]={0};   
    int used[1001]={0};   

    for(int i=0;i<nums1Size;i++) 
        seen[nums1[i]]=1;

    int* result=malloc(1001*sizeof(int));
    int k=0;

    for(int i=0;i<nums2Size;i++) 
    {
        int val=nums2[i];
        if(seen[val] && !used[val]) 
        {
            result[k++]=val;
            used[val]=1;
        }
    }

    *returnSize=k;
    return result;
}
