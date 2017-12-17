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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head) return head;
        
        ListNode* p1, *p2;
        p1 = p2 = head;
        while(n--) p2 = p2->next;
        if(!p2) return head->next;
        
        while(p2->next){
            p2 = p2->next;
            p1 = p1->next;
        }
        p1->next=p1->next->next;
        return head;
    }
};
