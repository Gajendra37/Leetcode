/*
Description:

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
  
Example 2:
Input: n = 1
Output: ["()"]
*/

//Solution:

void backtrack(char **result, int *returnSize, char *current, int pos, int open, int close, int n) {
    if (pos == 2 * n) {
        result[*returnSize] = (char *)malloc((2 * n + 1) * sizeof(char));
        strcpy(result[*returnSize], current);
        (*returnSize)++;
        return;
    }

    if (open < n) {
        current[pos] = '(';
        backtrack(result, returnSize, current, pos + 1, open + 1, close, n);
    }

    if (close < open) {
        current[pos] = ')';
        backtrack(result, returnSize, current, pos + 1, open, close + 1, n);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    char **result = (char **)malloc(10000 * sizeof(char *)); 
    *returnSize = 0;

    char *current = (char *)malloc((2 * n + 1) * sizeof(char));
    current[2 * n] = '\0';

    backtrack(result, returnSize, current, 0, 0, 0, n);

    return result;
}
