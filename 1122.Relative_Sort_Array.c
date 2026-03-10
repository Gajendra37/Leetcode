/*
Description:
  
Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.

Example 1:
Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
  
Example 2:
Input: arr1 = [28,6,22,8,44,17], arr2 = [22,28,8,6]
Output: [22,28,8,6,17,44]
*/

//Solution:

 int compare(const void* a, const void* b) {
   return (*(int*)a - *(int*)b);
}

int* relativeSortArray(int* arr1, int arr1Size, int* arr2, int arr2Size, int* returnSize) {

    int *arr=malloc(arr1Size*sizeof(int));
    int x=0;
    int freq[1000]={0};

    qsort(arr1,arr1Size,sizeof(int),compare); 

    for(int i=0;i<arr2Size;i++)
    {
        for(int j=0;j<arr1Size;j++)
        {
            if(arr1[j]==arr2[i])
                arr[x++]=arr1[j];
        }
    }
    for(int i=0;i<arr1Size;i++)
    {
        int f=0;
        for(int j=0;j<arr2Size;j++)
        {
            if(arr1[i]==arr2[j])
                f=1;
        }
        if(f==0)
            arr[x++]=arr1[i];
    }

    *returnSize=arr1Size;
    return arr;
}
