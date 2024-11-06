/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return false;

        ListNode* tortoise = head; // slow tortoise
        ListNode* hare = head->next; // quick hare

        while (tortoise != hare)
        {
            if (hare == NULL || hare->next == NULL) 
                return false;

            tortoise = tortoise->next;
            hare = hare->next->next;
        }
        return true;
    }
};
