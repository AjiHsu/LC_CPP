 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = new ListNode(-1);
        ListNode* it = res;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr) {
            if (l1 != nullptr && l2 != nullptr) {
                int newCarry = (carry + l1->val + l2->val) / 10;
                it->next = l1;
                it = it->next;
                it->val = (carry + l1->val + l2->val) % 10;
                carry = newCarry;

                l1 = l1->next;
                l2 = l2->next;
            }
            else if (l1 == nullptr) {
                int newCarry = (carry + l2->val) / 10;
                it->next = l2;
                it = it->next;
                it->val = (carry + l2->val) % 10;
                carry = newCarry;

                l2 = l2->next;
            }
            else { // l2 == nullptr
                int newCarry = (carry + l1->val) / 10;
                it->next = l1;
                it = it->next;
                it->val = (carry + l1->val) % 10;
                carry = newCarry;

                l1 = l1->next;
            }
        }
        if (carry != 0) it->next = new ListNode(carry);

        ListNode* temp = res;
        res = res->next;
        delete temp;
        return res;
    }
};