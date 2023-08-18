//copy List with Random Pointer  

// intution is like you need a key such that key must be original and its value must be copy of that

class Solution {
public:
    Node* copyRandomList(Node* head) {
       unordered_map<Node*, Node*> m; 
       Node* cursor = head; 
       while(cursor){
           Node* temp = new Node(cursor->val); 
           m[cursor] = temp; 
           cursor = cursor->next; 
       }
       cursor = head; 
       while(cursor){
           if(cursor->next != NULL) m[cursor]->next = m[cursor->next]; 
           if(cursor->random != NULL) m[cursor]->random = m[cursor->random]; 
           cursor = cursor->next; 
       }

       return m[head]; 
        
    }
};
