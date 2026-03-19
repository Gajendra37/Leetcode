/*
Description:

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital, like "Google".
Given a string word, return true if the usage of capitals in it is right.

Example 1:
Input: word = "USA"
Output: true
  
Example 2:
Input: word = "FlaG"
Output: false
*/

//Solution:

bool detectCapitalUse(char* word) {
    
    int cap=0,low=0;
    int len=strlen(word);
    for(int i=0;i<len;i++)
    {
        char ch=word[i];
        if(isupper(ch))
            cap++;
        else
            low++;
    }
    if(cap==len || low==len || (isupper(word[0]) && low==len-1))
        return true;
    else
        return false;
}
