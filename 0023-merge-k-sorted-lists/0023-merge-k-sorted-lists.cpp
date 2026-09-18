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
    ListNode*merge(ListNode*l1,ListNode*l2){
        ListNode*c=new ListNode(100);
        ListNode*temp=c;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                temp->next=l1;
                l1=l1->next;
                temp=temp->next;
            }
            else{
                temp->next=l2;
                l2=l2->next;
                temp=temp->next;
            }
        }
            if(l1==NULL)temp->next=l2;
            else temp->next=l1;
            return c->next;
        
    }
    ListNode*mergeklisthelper(vector<ListNode*>&lists,int start,int end){
        if(start==end){
            return lists[start];
        }
        if(start+1==end){
            return merge(lists[start],lists[end]);
        }
        int mid=start+(end-start)/2;
        ListNode*left=mergeklisthelper(lists,start,mid);
        ListNode*right=mergeklisthelper(lists,mid+1,end);
        return merge(left,right);
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        return mergeklisthelper(lists,0,lists.size()-1);
        
    }
};