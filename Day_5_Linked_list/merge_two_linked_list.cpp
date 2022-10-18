/*
taking auxilary space 
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *third;
        if(!list1 && list2)
            return list2;
        else if(!list2 && list1)
            return list1;
        else if(!list1 && !list2)
            return NULL;
        if(list1->val > list2->val)
          return mergeTwoLists(list2,list1);
        ListNode *t=new ListNode(list1->val);
        third=t;
        ListNode *p=third;
        list1=list1->next;
        while(list1 && list2){
            if(list1->val > list2->val){
                t=new ListNode(list2->val);
               list2=list2->next;
            }
            else{
                t=new ListNode(list1->val);
               list1=list1->next;
            }
            p->next=t;
            p=p->next;
        }
        
        while(list1){
            t=new ListNode(list1->val);
            p->next=t;
            p=p->next;
            list1=list1->next;
        }
         while(list2){
            t=new ListNode(list2->val);
            p->next=t;
            p=p->next;
             list2=list2->next;
        }
       return third;
    }
};

//without extra space

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *third;
        if(!list1 && list2)
            return list2;
        else if(!list2 && list1)
            return list1;
        else if(!list1 && !list2)
            return NULL;
        if(list1->val > list2->val)
          return mergeTwoLists(list2,list1);
        
         third=list1;
         ListNode *last=third;
        list1=list1->next;
        
        while(list1 && list2){
            if(list1->val > list2->val){
               last->next=list2;
                list2=list2->next;
            }
            else{
                 last->next=list1;
                list1=list1->next;
            }
           last=last->next;
        }
        
        if(list1){
          last->next=list1;
        }
         if(list2){
            last->next=list2;
        }
       return third;
    }
};