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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
        while (lists.size() > 1) {
            ListNode* node1 = lists.back();
            lists.pop_back();
            ListNode* node2 = lists.back();
            lists.pop_back();
            // Merge Two List
            node = dummy;
            while (node1 && node2) {
                if (node1->val <= node2->val) {
                    node->next = node1;
                    node1 = node1->next;
                    node = node->next;
                } else {
                    node->next = node2;
                    node2 = node2->next;
                    node = node->next;
                }
            }
            if (node1) node->next = node1;
            else node->next = node2;
            lists.push_back(dummy->next);
            dummy->next = nullptr;
        }
        return lists[0];
        
    }
};
