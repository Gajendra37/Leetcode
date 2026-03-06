/*
Description:

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward.
Alphanumeric characters include letters and numbers.
Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:
Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
  
Example 2:
Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
  
Example 3:
Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
*/

//Solution:

bool isPalindrome(char* s) {
    
    int len=strlen(s);
    char str[len+1];
    int j=0;
    for(int i=0;i<len;i++)
    {
        char ch=tolower(s[i]);
        if(isalnum(ch))
            str[j++]=ch;
    }
    str[j]='\0';
    char rev[j+1];
    for(int i=0;i<j;i++)
        rev[i]=str[i];
    rev[j]='\0';
    int l=0;
    int r=j-1;
    while(l<r)
    {
        char temp=rev[l];
        rev[l]=rev[r];
        rev[r]=temp;
        l++;
        r--;
    }
    if(strcmp(str,rev)==0)
        return true;
    else
        return false;
    
}
