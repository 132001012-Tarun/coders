//ADD TWO NUMBERS

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           ListNode*ans=new ListNode();
            ListNode*p=ans;
        if(l1==NULL&&l2==NULL)
        {
            return NULL;
        }
        if(!l1&&l2)
        {
            return l1;
        }
        if(l1&&!l2)
        {
            return l2;
        }
        int c=0;
        while(l1||l2||c)
        {
            int sum=0;
            sum=((l1?l1->val:0)+(l2?l2->val:0))+c;
            c=sum/10;
            ListNode*temp=new ListNode(sum%10);
            p->next=temp;
            p=p->next;
            if(l1)l1=l1->next;
            if(l2)l2=l2->next;
        }
       return ans->next;  
    }
};
