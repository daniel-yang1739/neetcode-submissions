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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        ListNode* curr = head;
        while (true) {
            ListNode* k_node = prev;
            ListNode* prev_group = prev;
            for (int i = 0; i < k; ++i) {
                k_node = k_node->next;
                if (!k_node) return dummy->next;
                cout << k_node->val << " ";
            }
            ListNode* next_group = k_node->next;
            while (curr != next_group) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ListNode* curr_group = prev_group->next;
            prev_group->next = k_node;
            curr_group->next = next_group;
            prev = curr_group;
        }
        return dummy->next;
    }
};
