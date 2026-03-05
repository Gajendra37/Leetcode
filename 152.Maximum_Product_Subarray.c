/*
Description:

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.
  
Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
  
Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
*/

//Solution:

int Max(int arr,int max)
{
    return (arr>arr*max)?arr:arr*max;
}

int Min(int arr,int min)
{
    return (arr<arr*min)?arr:arr*min;
}

int maxProduct(int* nums, int numsSize) {
    
    int result=nums[0],max=nums[0],min=nums[0];
    for(int i=1;i<numsSize;i++)
    {
        if(nums[i]>0)
        {
            max=Max(nums[i],max);
            min=Min(nums[i],min);
            if(max>result)
                result=max;
        }
        else
        {
            int temp=max;
            max=min;
            min=temp;
            
            max=Max(nums[i],max);
            min=Min(nums[i],min);
            if(max>result)
                result=max;
        }
    }
    return result;
}
