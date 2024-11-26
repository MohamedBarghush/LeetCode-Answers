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
        if(head == NULL) return NULL; // specific
        Node* newHead = new Node(head->val); // will return this
        Node* newFirst = newHead;
        Node* oldFirst = head;

        unordered_map<Node*, Node*> ref;
        ref[head] = newHead;

        while (oldFirst->next) {
            oldFirst = oldFirst->next;
            Node* newNode = new Node(oldFirst->val);
            newFirst->next = newNode;
            newFirst = newFirst->next;
            ref[oldFirst] = newFirst;
        }

        oldFirst = head;
        newFirst = newHead;
        while (oldFirst) {
            if (oldFirst->random)
                newFirst->random = ref[oldFirst->random];
            oldFirst = oldFirst->next;
            newFirst = newFirst->next;
        }

        return newHead;
    }
};