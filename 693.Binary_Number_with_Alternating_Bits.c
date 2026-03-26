/*
Description:

Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

Example 1:
Input: n = 5
Output: true
Explanation: The binary representation of 5 is: 101

Example 2:
Input: n = 7
Output: false
Explanation: The binary representation of 7 is: 111.

Example 3:
Input: n = 11
Output: false
Explanation: The binary representation of 11 is: 1011.
*/

//Solution:

bool hasAlternatingBits(int n) {
    
    int temp=n;
    int arr[10000],x=0;
    while(temp>0)
    {
        arr[x++]=temp%2;
        temp/=2;
    }
    for(int i=x;x>0;x--)
    {
        if(arr[x]==arr[x-1])
            return false;
    }
    return true;
}
