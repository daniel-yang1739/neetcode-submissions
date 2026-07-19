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
        ListNode* curr = dummy->next;
        while (true) {
            ListNode* kNode = prev;
            for (int i = 0; i < k; ++i) {
                kNode = kNode->next;
                if (!kNode) {
                    return dummy->next;
                }
            }
            ListNode* prevGroupEnd = prev;
            ListNode* nextGroupStart = kNode->next;
            while (curr != nextGroupStart) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            ListNode* currGroupStart = prevGroupEnd->next;
            prevGroupEnd->next = prev;
            currGroupStart->next = nextGroupStart;
            prev = currGroupStart;
        }
        return dummy->next;
    }
};
