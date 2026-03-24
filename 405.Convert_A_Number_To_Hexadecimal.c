Description:

Given a 32-bit integer num, return a string representing its hexadecimal representation. For negative integers, two’s complement method is used.
All the letters in the answer string should be lowercase characters, and there should not be any leading zeros in the answer except for the zero itself.
Note: You are not allowed to use any built-in library method to directly solve this problem.

Example 1:
Input: num = 26
Output: "1a"
  
Example 2:
Input: num = -1
Output: "ffffffff"
*/

//Solution:
  
char* toHex(int num) {

    if(num==0) 
    {
        char* res=(char*)malloc(2);
        res[0]='0';
        res[1]='\0';
        return res;
    }
    char hex[]="0123456789abcdef";
    char* res=(char*)malloc(9);  
    int i=8;
    res[i]='\0';

    unsigned int n=num;  
    while(n>0) 
    {
        res[--i]=hex[n%16];
        n/=16;
    }
    return res+i;
}
