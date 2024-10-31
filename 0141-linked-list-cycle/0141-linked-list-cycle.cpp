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

        ListNode* tortoise = head; // slow turtle
        ListNode* hare = head->next; // fast rabbit

        while (tortoise != hare) // meet up condition
        {
            if (hare == NULL || hare->next == NULL) // hare reached the end
                return false;

            tortoise = tortoise->next; // turtle move 1 step
            hare = hare->next->next; // rabbit move 2 steps
        }
        return true;
    }
};