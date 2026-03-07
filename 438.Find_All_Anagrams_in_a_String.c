/*
Description:

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
  
Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

//Solution:

int isAnagram(char *s,int start,int end,int freq[])
{
    int temp[26]={0};
    for(int i=0;i<26;i++)
        temp[i]=freq[i];
    for(int i=start;i<end;i++)
    {
        temp[s[i]-'a']--;
    }
    for(int i=0;i<26;i++)
    {
        if(temp[i]!=0)
            return 0;
    }
    return 1;

}
int* findAnagrams(char* s, char* p, int* returnSize) {
    
    int len=strlen(s);
    int len2=strlen(p);
    int *arr=malloc(sizeof(int)*len);
    *returnSize=0;
    int freq[26]={0};

    for(int i=0;p[i];i++)
    {
        freq[p[i]-'a']++;
    }
    int j=0;
    for(int i=0;i<=len-len2;i++)
    {
        if(isAnagram(s,i,i+len2,freq))
            arr[j++]=i;
    }
    *returnSize=j;
    return arr;
}
