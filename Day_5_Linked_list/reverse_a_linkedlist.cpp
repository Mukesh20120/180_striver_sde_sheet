class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *p,*q,*r;
        q=r=NULL;
        p=head;
        while(p){
           r=q;
            q=p;
            q->next=r;
        }
        return q;
    }
};