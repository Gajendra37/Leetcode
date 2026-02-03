/*
Description:

Given a string s, return the string after replacing every uppercase letter with the same lowercase letter.

Example 1:
Input: s = "Hello"
Output: "hello"
  
Example 2:
Input: s = "here"
Output: "here"
  
Example 3:

Input: s = "LOVELY"
Output: "lovely"
*/

//Solution:

char* toLowerCase(char* s) {
    for(int i=0;s[i];i++)
    {
        if(isupper(s[i]))
            s[i]=tolower(s[i]);
    }
    return s;
}
