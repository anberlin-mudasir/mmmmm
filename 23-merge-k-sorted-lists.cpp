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
    // pop smallest node, and remove the list when empty
    ListNode* popSmallest(vector<ListNode*>& heads){
        // heads.size() always > 0
        int smallestIndex = 0;
        int val = heads[smallestIndex]->val;
        
        for(int i=1; i<heads.size(); i++){
            if(val > heads[i]->val){
                val = heads[i]->val;
                smallestIndex = i;
            }
        }
        
        ListNode* ret = heads[smallestIndex];
        ListNode* next = ret->next;
        if(ret->next){
            heads[smallestIndex] = ret->next;
        }
        else{
            heads.erase(heads.begin() + smallestIndex);
        }
        return ret;
    }
    void ensureDoesNotContainEmpty(vector<ListNode*>& lists){
        for(int i=0; i<lists.size(); i++){
            if(!lists[i]){
                lists.erase(lists.begin()+i);
                i--;
            }
        }
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* leader = new ListNode(0);
        // tail->next always equals NULL
        ListNode* tail = leader;
        ensureDoesNotContainEmpty(lists);
        while(lists.size()){
            tail->next = popSmallest(lists);
            tail = tail->next;
        }
        ListNode* ret = leader->next;
        delete leader;
        return ret;
    }
};
