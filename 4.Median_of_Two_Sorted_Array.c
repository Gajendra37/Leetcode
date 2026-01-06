/*
Description:
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/

//Solution:
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int len=nums1Size+nums2Size;
    int arr[len],j=0,k=0;
    for(int i=0;i<len;i++)
    {
        if(i<nums1Size)
        {
            arr[i]=nums1[j];
            j++;
        }
        else
        {
            arr[i]=nums2[k];
            k++;
        }
    }
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    double op;
    int val;
    if(len%2!=0)
    {
        val=len/2;
        op=(double)arr[val];
    }
    else
    {
        val=len/2;
        int sum=arr[val]+arr[val-1];
        op=(double)sum/2;
    }
    return op;
}
