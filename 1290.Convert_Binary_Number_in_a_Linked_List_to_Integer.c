/*
Description:

Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. 
The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
The most significant bit is at the head of the linked list.

Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10
  
Example 2:
Input: head = [0]
Output: 0
*/

//Solution:

int getDecimalValue(struct ListNode* head) {
    
    int stack[40];
    int top=-1;
    while(head!=NULL)
    {
        stack[++top]=head->val;
        head=head->next;
    }
    int sum=0,power=0;
    for(int i=top;i>=0;i--)
    {
        sum+=(stack[i]*pow(2,power++));
    }
    return sum;
}
