/*
Description:

A word is considered valid if:
It contains a minimum of 3 characters.
It contains only digits (0-9), and English letters (uppercase and lowercase).
It includes at least one vowel.
It includes at least one consonant.

You are given a string word.
Return true if word is valid, otherwise, return false.

Notes:
'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
A consonant is an English letter that is not a vowel.
 
Example 1:
Input: word = "234Adas"
Output: true
Explanation:
This word satisfies the conditions.

Example 2:
Input: word = "b3"
Output: false
Explanation:
The length of this word is fewer than 3, and does not have a vowel.
  
Example 3:
Input: word = "a3$e"
Output: false
Explanation:
This word contains a '$' character and does not have a consonant.
*/

//Solution:
bool isValid(char* word) {
    
    int vow=0,cons=0;
    for(int i=0;word[i];i++)
    {
        if(isalpha(word[i]))
        {
            char ch=tolower(word[i]);
            if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vow++;
            else
                cons++;
        }
        if(ispunct(word[i]))
            return false;
    }
    if(strlen(word)>=3 && vow>=1 && cons>=1)
        return true;
    else
        return false;
}
