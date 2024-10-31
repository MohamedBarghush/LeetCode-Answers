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

        ListNode* tortoise = head; // slow tortoise (turtle)
        ListNode* hare = head->next; // fast hare (rabbit)

        while (tortoise != hare) // rabbit and turtle meet up here
        {
            if (hare == NULL || hare->next == NULL) // hare reached the end of the linked-list
                return false;

            tortoise = tortoise->next; // tortoise moves 1 step
            hare = hare->next->next; // hare moves 2 steps
        }
        return true;
    }
};