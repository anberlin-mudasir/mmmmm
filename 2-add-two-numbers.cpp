/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(-1);
        ListNode* tail = ret;
        int carry = 0;
        while(l1 || l2){
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int sum = v1 + v2 + carry;
            carry = sum / 10;
            sum %= 10;
            tail->next = new ListNode(sum);
            tail = tail->next;
            // remember to move cursor!
            l1 && (l1 = l1->next);
            l2 && (l2 = l2->next);
        }
        if(carry){
            tail->next = new ListNode(carry);
        }
        return ret->next;
    }
};
