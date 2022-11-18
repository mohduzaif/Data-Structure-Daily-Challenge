/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> unmp;
        
        Node* temp = head;
        while(temp) {
            unmp[temp] = new Node(temp->val);
            temp = temp->next;
        }
        
        temp = head;
        while(temp) {
            unmp[temp]->next = unmp[temp->next];
            unmp[temp]->random = unmp[temp->random];
            temp = temp->next;
        }
        return unmp[head];
    }
};