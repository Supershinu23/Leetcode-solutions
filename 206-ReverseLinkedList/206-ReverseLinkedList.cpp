// Last updated: 14/07/2026, 00:54:58
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head)return head ;
        ListNode* prev = nullptr ;
        ListNode* temp = head ;

        while(temp->next!=nullptr){
            ListNode* n = temp->next ;
            temp->next = prev ;
            prev = temp;
            temp = n ;
        }
        temp->next = prev;
        return temp;
    }
};