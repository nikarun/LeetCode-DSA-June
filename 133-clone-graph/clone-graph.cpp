/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node *node, unordered_map<Node*,Node*>&mp){
        vector<Node*>neighbors;
        Node *clone = new Node(node->val);
        mp[node]=clone;
        for(int i=0;i<node->neighbors.size();++i){
            Node *temp=node->neighbors[i];
            if(mp.find(temp)!=mp.end()){
                neighbors.push_back(mp[temp]);
            }
            else{
                neighbors.push_back(dfs(temp,mp));
            }
        }
        clone->neighbors = neighbors;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL) return NULL;
        if(node->neighbors.size()==0) { 
            Node *clone = new Node(node->val);
            return clone;
        }
        unordered_map<Node*,Node*>mp;//to keep track of already created nodes.
        return dfs(node,mp);

    }
    
};