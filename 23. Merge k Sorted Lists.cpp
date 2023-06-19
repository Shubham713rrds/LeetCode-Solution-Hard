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
    ListNode *solve(ListNode *l1, ListNode *l2){
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        ListNode *l3=NULL, *last=NULL;
        if(l1->val<l2->val){
            l3=last=l1;
            l1=l1->next;
            last->next=NULL;
        }
        else{
            l3=last=l2;
            l2=l2->next;
            last->next=NULL;
        }
        while(l1 && l2){
            if(l1->val<l2->val){
               last->next=l1;
               l1=l1->next;
               last=last->next;
               last->next=NULL;
            }
            else{
               last->next=l2;
               l2=l2->next;
               last=last->next;
               last->next=NULL;
            }
        }
        if(l1){
            last->next=l1;
        }
        if(l2){
            last->next=l2;
        }
        return l3;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        if(lists.size()==1)return lists[0];

        ListNode *temp=lists[0];
        for(int i=1;i<lists.size();i++){
           temp=solve(temp, lists[i]);
        }
        return temp;
    }
};
