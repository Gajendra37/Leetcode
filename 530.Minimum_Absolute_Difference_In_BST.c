/*
Description:

Given the root of a Binary Search Tree (BST), return the minimum absolute difference between the values of any two different nodes in the tree.

Example 1:
Input: root = [4,2,6,1,3]
Output: 1
  
Example 2:
Input: root = [1,0,48,null,null,12,49]
Output: 1
*/

//Solution:

void inorder(struct TreeNode* root, int* prev, int* minDiff) {
    if (root == NULL) return;

    inorder(root->left, prev, minDiff);

    if (*prev != -1) {
        int diff = root->val - *prev;
        if (diff < *minDiff)
            *minDiff = diff;
    }

    *prev = root->val;

    inorder(root->right, prev, minDiff);
}

int getMinimumDifference(struct TreeNode* root) {

    int prev = -1;
    int minDiff = INT_MAX;
    inorder(root, &prev, &minDiff);
    return minDiff;
}
