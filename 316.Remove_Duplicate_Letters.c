/*
Description:

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Example 1:
Input: s = "bcabc"
Output: "abc"
  
Example 2:
Input: s = "cbacdcbc"
Output: "acdb"
*/

//Solution:

char* removeDuplicateLetters(char* s) {

    int n=strlen(s);
    int lastIndex[26];
    bool used[26]={false};
    for(int i=0;i<n;i++) 
    {
        lastIndex[s[i]-'a']=i;
    }
    char stack[27];
    int top=-1;
    for(int i=0;i<n;i++)
    {
        int curr=s[i]-'a';
        if(used[curr])
            continue;
        while(top>=0 && stack[top]>s[i] && lastIndex[stack[top]-'a']>i)
        {
            used[stack[top]-'a']=false;
            top--;
        }
        stack[++top]=s[i];
        used[curr]=true;
    }
    stack[top+1]='\0';
    return strdup(stack);
}

