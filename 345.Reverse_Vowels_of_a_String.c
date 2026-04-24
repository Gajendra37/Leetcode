/*
Description:

Given a string s, reverse only all the vowels in the string and return it.
The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

Example 1:
Input: s = "IceCreAm"
Output: "AceCreIm"
Explanation:
The vowels in s are ['I', 'e', 'e', 'A']. On reversing the vowels, s becomes "AceCreIm".

Example 2:
Input: s = "leetcode"
Output: "leotcede"
*/

//Solution:

char* reverseVowels(char* s) {
    
    int len=strlen(s);
    int vow=0;
    for(int i=0;i<len;i++)
    {
        char ch=tolower(s[i]);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
            vow++;
    }
    char vowel[vow+1];
    int x=0;
    for(int i=0;i<len;i++)
    {
        char ch=s[i];
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
            vowel[x++]=ch;
    }
    for(int i=0;i<len;i++)
    {
        char ch=s[i];
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' || ch=='A' || ch=='E' || ch=='I' || ch=='O' || ch=='U')
                s[i]=vowel[--x];
    }
    return s;
}
