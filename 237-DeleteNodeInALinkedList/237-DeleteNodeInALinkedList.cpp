// Last updated: 14/07/2026, 00:54:43
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
    void deleteNode(ListNode* node) {
        ListNode* t = node ;
        while(t->next!=NULL){
        node = t ;
        t->val = t->next->val;
        t = t->next;
        }
        node->next = NULL;
        
    }
};