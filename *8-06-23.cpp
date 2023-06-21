// Clone Graph



/// used dfs to search and and store the neighbour
class Solution {
public:
    Node* dfs(Node*curr,unordered_map<Node*,Node*>&mp)
    {
         vector<Node*>neighbour;
         Node*clone=new Node(curr->val);
         mp[curr]=clone;
         for(auto p:curr->neighbors){
             if(mp.find(p)!=mp.end()){
                 neighbour.push_back(mp[p]);    // if it is already visited then store its node directly as its neighbours are already stored
             }
             else{
                 neighbour.push_back(dfs(p,mp));   // if it is not visited then store all its neighbours and then to the curr neighbour
             }
         }
             clone->neighbors=neighbour;
             return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*>mp;
        if(node==NULL)
        {
            return NULL;
        }
        if(node->neighbors.size()==0)
        {
            Node*clone=new Node(node->val);
            return clone;
        }
        return dfs(node,mp);
    }
};
