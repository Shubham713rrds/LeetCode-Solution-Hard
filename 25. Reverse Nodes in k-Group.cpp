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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int n=0;
        ListNode *temp=head;
        while(temp){
            temp=temp->next;
            n++;
        }
        ListNode *p=head, *q=NULL, *r=NULL, *front=head, *back;
        ListNode *pseudoNode=new ListNode(0);
        back=pseudoNode;
        while(n>=k){
            int cntReverse=k;
            front=p;
            q=NULL;
            r=NULL;
           
            while(cntReverse!=0){
                r=q;
                q=p;
                p=p->next;
                q->next=r;
                cntReverse--;
            }
            back->next=q;
            front->next=p;
            back=front;
            n=n-k;
        }
        return pseudoNode->next;
    }
};
