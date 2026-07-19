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
    ListNode* mergeTwoList(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* node = dummy;
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
        return dummy->next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        while (lists.size() > 1) {
            // Devide and Conquer
            vector<ListNode*> mergedLists;
            for (int i = 0; i < lists.size(); i+=2) {
                if (i + 1 >= lists.size()) {
                    mergedLists.push_back(lists[i]);
                    break;
                }
                mergedLists.push_back(
                    mergeTwoList(lists[i], lists[i + 1]));
            }
            lists = mergedLists;
        }
        return lists.back();
    }
};
