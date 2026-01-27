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
    int i=strlen(num1)-1;
    int j=strlen(num2)-1;
    int carry=0;
    int maxLen=(i>j?i:j)+2;
    char* result=(char*)malloc(maxLen);
    int k=maxLen-1;
    result[k--]='\0';
    while(i>=0||j>=0||carry) 
    {
        int sum=carry;
        if(i>=0)
            sum+=num1[i--]-'0';
        if(j>=0)
            sum+=num2[j--]-'0';
        result[k--]=(sum%10)+'0';
        carry=sum/10;
    }
    return result+k+1;
}
