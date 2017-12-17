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
    ListNode* swapPairs(ListNode* head) {
        ListNode* lead = new ListNode(0);
        ListNode* current = lead;
        while(head && head->next){
            ListNode* first = head;
            ListNode* second = head->next;
            ListNode* tail = head->next->next;
            current->next = second;
            second->next = first;
            first->next = tail;
            
            current = current->next->next;
            head = tail;
        }
        if(head){
            current->next = head;
        }
        return lead->next;
    }
};
