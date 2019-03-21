/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
这个题目最大的问题就是你不能把链表换成数字去相加，因为有溢出问题，所以只能
自己实现一个满十进一的运算*/


struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       int num1,num2,num3;
       int next = 0;
        ListNode* ans = new ListNode(0);
        ListNode* move = ans;
        while(l1||l2){
            if(l1==NULL){
                num1 = 0;
            }
            else num1 = l1->val;
            if(l2==NULL){
                num2 = 0;
            }
            else num2 = l2->val;
            if((num1+num2)/10){
                num3 = (num1+num2)%10+next;
                next = 1;
            }
            else{
                num3 = num1+num2+next;
                if(num3/10)
                {
                    num3 = num3%10;
                    next = 1;
                }
                else next = 0;
            }
            ListNode* n = new ListNode(0);
            n->val = num3;
            move->next = n;
            move = move->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if(next==1) {
            ListNode* n = new ListNode(0);
            n->val = next;
            move->next = n;
        }
        ans = ans->next;
        return ans;
    }
};