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

        stack<int> values;
        ListNode* newHead = new ListNode(0);
        ListNode* it = newHead;
        int i = 0;

        while (head != NULL) {
            if (i == (left-1)) {
                while (i <= (right-1)) {
                    values.push(head->val);
                    head = head->next;
                    i++;
                }

                while (!values.empty()) {
                    ListNode* op = new ListNode(values.top());
                    values.pop();
                    it->next = op;
                    it = it->next;
                }

                continue;
            }

            i++;
            ListNode* oper = new ListNode(head->val);
            it->next = oper;
            it = it->next;
            head = head->next;
        }

        return newHead->next;
    }
};