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
        ListNode* hare = head->next; // fast hare

        while (tortoise != hare) // rabbit and turtle meet up here
        {
            if (hare == NULL || hare->next == NULL) 
                return false;

            tortoise = tortoise->next; // tortoise moves 1 step at a time
            hare = hare->next->next; // hare moves 2 steps at a time
        }
        return true;
    }
};