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
private:
    ListNode* conquer(ListNode* list1, ListNode* list2) {
        ListNode dummy;  // allocate on stack
        ListNode* node = &dummy;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                node->next = list1;
                list1 = list1->next;
                node = node->next;
            } else {
                node->next = list2;
                list2 = list2->next;
                node = node->next;
            }
        }
        if (list1) node->next = list1;
        else node->next = list2;
        return dummy.next;
    }

    ListNode* divide(vector<ListNode*>& lists, int l, int r) {
        if (l > r) return nullptr;
        if (l == r) return lists[l];
        int mid = l + (r - l) / 2;  // avoid integer overflow
        ListNode* left = divide(lists, l, mid);
        ListNode* right = divide(lists, mid + 1, r);
        return conquer(left, right);
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        return divide(lists, 0, lists.size() - 1);
    }
};
