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
    int get_val(ListNode *l) {
        if(l) return l->val;
        return 0;
    }

    ListNode* get_next(ListNode *l) {
        if(l) return l->next;
        return nullptr;
    }

    ListNode* addTwoNumbers_recursive(ListNode *l1, ListNode* l2, int carry) {
        if(!l1 && !l2 && !carry) return nullptr;

        ListNode* res = new ListNode();
        int sum = get_val(l1) + get_val(l2) + carry;
        res->val = sum % 10;
        res->next = addTwoNumbers_recursive(get_next(l1), get_next(l2), sum/10);
        return res;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, sum;
        ListNode *res;
        ListNode *curr = nullptr;
        while(true) {
            if(!curr) {
                curr = new ListNode();
                res = curr;
            }
            sum = get_val(l1) + get_val(l2) + carry;
            carry = sum/ 10;
            curr->val = sum%10;
            
            l1 = get_next(l1);
            l2 = get_next(l2);

            if(!(l1 || l2 || carry)) break;
            curr->next = new ListNode();
            curr = curr->next;
        }
        return res;
    }
}
