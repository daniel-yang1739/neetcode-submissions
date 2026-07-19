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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* tmp = head;
        for (int i = 0; i < n; ++i) tmp = tmp->next;
        if (!tmp) return head->next;
        ListNode* last = head;
        ListNode* curr = head->next;
        while (tmp->next) {
            curr = curr->next;
            last = last->next;
            tmp = tmp->next;
        }
        last->next = curr->next;
        return head;
    }
};
