/*
Description:

Given two strings s1 and s2, return true if s2 contains a permutation of s1, or false otherwise.
In other words, return true if one of s1's permutations is the substring of s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").
  
Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

//Solution:
  
bool checkInclusion(char* s1, char* s2) {

    int len1 = strlen(s1);
    int len2 = strlen(s2);

    if (len1 > len2)
        return false;

    int freq1[26] = {0};
    int freq2[26] = {0};

    for (int i = 0; i < len1; i++) {
        freq1[s1[i] - 'a']++;
        freq2[s2[i] - 'a']++;
    }

    if (memcmp(freq1, freq2, sizeof(freq1)) == 0)
        return true;

    for (int i = len1; i < len2; i++) {

        freq2[s2[i] - 'a']++;
        freq2[s2[i - len1] - 'a']--;
        if (memcmp(freq1, freq2, sizeof(freq1)) == 0)
            return true;
    }

    return false;
}
