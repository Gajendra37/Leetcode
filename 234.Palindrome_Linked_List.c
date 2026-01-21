/*
Description:
  
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true
  
Example 2:
Input: head = [1,2]
Output: false
*/

//Solution:

bool isPalindrome(struct ListNode* head) {
    
    struct ListNode *prev=NULL;
    struct ListNode *curr=head;
    struct ListNode *next=NULL;

    while(curr!=NULL)
    {
        next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
    }
    while(curr!=NULL){
    if(head==prev)
        return true;
    }
    return false;
}
