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
    vector<Node*>noderegister;
    void dfs(Node*actual,Node*clone){
        for(auto neighbour:actual->neighbors){
            if(not noderegister[neighbour->val]){
                Node*newNode=new Node(neighbour->val);
                noderegister[newNode->val]=newNode;
                clone->neighbors.push_back(newNode);
                dfs(neighbour,newNode);
            }
            else{
                clone->neighbors.push_back(noderegister[neighbour->val]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)return NULL;
        Node*clone=new Node (node->val);
        noderegister.resize(110,NULL);
        noderegister[clone->val]=clone;
        dfs(node,clone);
        return clone;

        
    }
};