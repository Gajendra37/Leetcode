/*
Description:

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3. Note that "bca" and "cab" are also correct answers.
  
Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
  
Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

//Solution:

int lengthOfLongestSubstring(char* s) {

    int freq[128] = {0};

    int left = 0;
    int maxLen = 0;

    for (int right = 0; s[right] != '\0'; right++) {

        freq[s[right]]++;

        while (freq[s[right]] > 1) {
            freq[s[left]]--;
            left++;
        }

        int len = right - left + 1;

        if (len > maxLen)
            maxLen = len;
    }

    return maxLen;
}
