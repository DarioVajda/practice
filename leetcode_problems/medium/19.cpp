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
    pair<ListNode*, int> removeNthFromEnd_recursive(ListNode* head, int n) {
        // returns <new head, tail size>

        if(!head) return { head, 0 };

        pair<ListNode*, int> res = removeNthFromEnd_recursive(head->next, n);

        int tail_len = res.second;

        if(tail_len == n-1) {
            ListNode* rm = head;
            head = res.first;
            delete rm;
        }
        else {
            head->next = res.first;
        }

        return { head, tail_len+1 };
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        return removeNthFromEnd_recursive(head, n).first;
    }
}
