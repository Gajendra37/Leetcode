/*
Description:
  
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
An input string is valid if:
Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([])"
Output: true

Example 5:
Input: s = "([)]"
Output: false
*/

//Solution:

bool isValid(char* s) {
    
    int stack[100000],top=-1,balanced=1;
    for(int i=0;s[i]!='\0';i++)
    {
        char ch=s[i];
        if(ch=='('||ch=='{'||ch=='[')
        {
            stack[++top]=ch;
        }
        else if(ch==')'||ch=='}'||ch==']')
        {
            if(top==-1)
            {
                balanced=0;
                break;
            }
            char open=stack[top--];
            char close=ch;
            if(open=='(' && close==')')
                balanced=1;
            else if(open=='{' && close=='}')
                balanced=1;
            else if(open=='[' && close==']')
                balanced=1;
            else{
                balanced=0;
                break;
            }
        }
    }
    if(top!=-1)
        balanced=0;
    if(balanced==1)
        return true;
    else
        return false;
}
