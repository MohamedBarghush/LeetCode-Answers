/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; ++i)
            prev = prev->next;

        ListNode* current = prev->next;
        ListNode* next = nullptr;
        ListNode* reverseTail = current;

        for (int i = left; i <= right; i++) {
            next = current->next;
            current->next = prev->next;
            prev->next = current;
            current = next;
        }

        reverseTail->next = current;

        return dummy->next;
    }
};