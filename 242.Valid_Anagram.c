/*
Description:
  
Given two strings s and t, return true if t is an anagram of s, and false otherwise. 

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false
*/

//Solution:

#include <stdbool.h>

bool isAnagram(char* s, char* t) {
    int count[26]={0};

    for (int i=0;s[i]!='\0';i++) 
    {
        count[s[i]-'a']++;
    }
    for (int i=0;t[i]!='\0';i++) 
    {
        count[t[i]-'a']--;
    }
    for(int i=0;i<26;i++) 
    {
        if(count[i]!=0)
            return false;
    }
    return true;
}
