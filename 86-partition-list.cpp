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
    ListNode* partition(ListNode* head, int x) {
        ListNode* lt = new ListNode(0);
        ListNode* leq = new ListNode(0);
        ListNode* lti = lt;
        ListNode* leqi = leq;
        
        ListNode* i = head;
        while (i) {
            if (i->val < x) {
                lti->next = i;
                lti = i;
                i = i->next;
                lti->next = NULL;
            }
            else {
                leqi->next = i;
                leqi = i;
                i = i->next;
                leqi->next = NULL;
            }
        }
        lti->next = leq->next;
        return lt -> next;
    }
};