/*
Description:

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.
You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"
  
Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"
  
Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"
*/

//Solution:

char* addStrings(char* num1, char* num2) {

    int i = strlen(num1) - 1;
    int j = strlen(num2) - 1;
    int carry = 0;

    char* res = (char*)malloc( ( (i > j ? i : j) + 3 ) * sizeof(char) );

    int k = 0;

    while(i >= 0 || j >= 0 || carry) 
    {
        int d1 = (i >= 0) ? num1[i--] - '0' : 0;
        int d2 = (j >= 0) ? num2[j--] - '0' : 0;

        int sum = d1 + d2 + carry;
        carry = sum / 10;

        res[k++] = (sum % 10) + '0';
    }

    res[k] = '\0';

    for(int l = 0, r = k - 1; l < r; l++, r--) 
    {
        char temp = res[l];
        res[l] = res[r];
        res[r] = temp;
    }
    return res;
}
