// Reverse Nodes in K group



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
        ListNode*next=NULL;
        ListNode*curr=head;
        ListNode*prev=NULL;
        int length=0;
        if(head==NULL)
        {
            return NULL;
        }
        int count=0;
        while(curr!=NULL&&count<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next; 
            count++;
        }
        ListNode*temp=next;
        while(temp!=NULL)
        {
            length++;
            temp=temp->next;
        }
        if(length>=k)
        {
            head->next=reverseKGroup(next,k);
        }
        else{
            head->next=next;
        }  
        return prev;
    }
};
