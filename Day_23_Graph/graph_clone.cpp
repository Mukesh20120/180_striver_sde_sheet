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
    Node* cloneGraph(Node* node) {
        //vector to check for visited node
       unordered_map<Node*,Node*>mp;
        if(node==NULL)return NULL;
        //making a new node with empty vector
        Node *copy=new Node(node->val,{});
        //marking in mp with nodes
        mp[node]=copy;
        //queue data structure for BFS traversal
        queue<Node*>q;
        q.push(node);
        while(!q.empty()){
            Node *cur=q.front();
            q.pop();
            //traversing through the all the neighbour
            for(auto neigh: cur->neighbors){
                if(mp.find(neigh)==mp.end()){
                    mp[neigh]=new Node(neigh->val,{});
                    q.push(neigh);
                }
                mp[cur]->neighbors.push_back(mp[neigh]);
            }
        }
        return copy;
    }
};



