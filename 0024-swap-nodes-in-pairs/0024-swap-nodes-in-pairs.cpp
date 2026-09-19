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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0,head);
        ListNode*prev=&dummy;
        while(prev->next!=NULL&&prev->next->next!=NULL){
            ListNode*l1=prev->next;
            ListNode*l2=prev->next->next;
            l1->next=l2->next;
            l2->next=l1;
            prev->next=l2;
            prev=l1;
        }
        return dummy.next;
 
        
    }
};