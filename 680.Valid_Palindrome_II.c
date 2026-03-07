/*
Description:

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:
Input: s = "aba"
Output: true
  
Example 2:
Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
  
Example 3:
Input: s = "abc"
Output: false
*/

//Solution:

int check(char *s,int l,int r)
{
    while(l<r)
    {
        if(s[l]!=s[r])
            return 0;
        l++;
        r--;
    }
    return 1;
}

bool validPalindrome(char* s) {
    
    int l=0;
    int r=strlen(s)-1;
    while(l<r)
    {
        if(s[l]==s[r])
        {
            l++;
            r--;
        }
        else
        {
            return check(s,l+1,r) || check(s,l,r-1);
        }
         
    }
    return true;
    
}
