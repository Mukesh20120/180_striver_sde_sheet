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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p,*q;
        ListNode *dummy=new ListNode(-1);
        dummy->next=head;
        p=q=dummy;
        int i=0;
        while(p){
            if(i>n)
                q=q->next;
            p=p->next;
            i++;
        }
        ListNode *t=q->next;
        q->next=q->next->next;
        delete(t);
        return dummy->next;
    }
};