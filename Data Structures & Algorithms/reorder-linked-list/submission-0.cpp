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
    void reorderList(ListNode* head) {
        // Get center node
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        // Reverse right-half list
        ListNode* prev = nullptr;
        ListNode* node = slow->next;
        slow->next = nullptr;
        while (node) {
            ListNode* node_next = node->next;
            node->next = prev;
            prev = node;
            node = node_next;
        }
        // Cross linked to reorder list
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ListNode* node = second->next;
            second->next = first->next;
            first->next = second;
            first = second->next;
            second = node;
        }
    }
};
