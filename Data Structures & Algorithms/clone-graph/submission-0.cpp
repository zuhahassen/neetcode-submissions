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
    void dfs (Node* node, Node* clone) {
        if (!node || !clone) {
            return; 
        }

        for (Node* nei: node->neighbors) {
            Node* newNode = new Node(); 
            newNode->val = nei->val; 
            clone->neighbors.push_back(newNode);

            dfs(nei, newNode);
        }
    }

    unordered_map<Node*, Node*> newNode; 

    Node* cloneGraph(Node* node) {
        if (!node) {
            return nullptr; 
        }

        if (newNode.count(node)) {
            return newNode[node];
        }

        Node* clone = new Node; 
        clone->val = node->val; 
        newNode[node] = clone;
        
        for (Node* nei: node->neighbors) {
            clone->neighbors.push_back(cloneGraph(nei));
        }

        return clone; 
        
    }
};
