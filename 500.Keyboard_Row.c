/*
Descripton:
  
Given an array of strings words, return the words that can be typed using letters of the alphabet on only one row of American keyboard like the image below.
Note that the strings are case-insensitive, both lowercased and uppercased of the same letter are treated as if they are at the same row.

In the American keyboard:
the first row consists of the characters "qwertyuiop",
the second row consists of the characters "asdfghjkl", and
the third row consists of the characters "zxcvbnm".

Example 1:
Input: words = ["Hello","Alaska","Dad","Peace"]
Output: ["Alaska","Dad"]
Explanation:
Both "a" and "A" are in the 2nd row of the American keyboard due to case insensitivity.

Example 2:
Input: words = ["omk"]
Output: []

Example 3:
Input: words = ["adsdf","sfd"]
Output: ["adsdf","sfd"]
*/

//Solution:

int top(char **words,int i)
 {
    int len=strlen(words[i]);
    for(int j=0;j<len;j++)
    {
        char ch=tolower(words[i][j]);
        if(ch!='q' && ch!='w' && ch!='e' && ch!='r' && ch!='t' && ch!='y' && ch!='u' && ch!='i' && ch!='o' && ch!='p')
                return 0;
    }
    return 1;
 }

 int mid(char **words,int i)
 {
    int len=strlen(words[i]);
    for(int j=0;j<len;j++)
    {
        char ch=tolower(words[i][j]);
        if(ch!='a' && ch!='s' && ch!='d' && ch!='f' && ch!='g' && ch!='h' && ch!='j' && ch!='k' && ch!='l')
            return 0;
    }
    return 1;
 }

 int low(char **words,int i)
 {
    int len=strlen(words[i]);
    for(int j=0;j<len;j++)
    {
        char ch=tolower(words[i][j]);
        if(ch!='z' && ch!='x' && ch!='c' && ch!='v' && ch!='b' && ch!='n' && ch!='m')
            return 0;
    }
    return 1;
 }

char** findWords(char** words, int wordsSize, int* returnSize) {
    
    char **arr=malloc(wordsSize*sizeof(char*));
    int j=0;
    for(int i=0;i<wordsSize;i++)
    {
        if(top(words,i) || mid(words,i) || low(words,i))
            arr[j++]=words[i];
    }
    *returnSize=j;
    return arr;
}
