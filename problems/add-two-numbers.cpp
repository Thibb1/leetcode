#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int reminder = 0, ListNode* root = nullptr) {
        if (root == nullptr) root = l1;
        if (l1 != nullptr) {
            l1->val += reminder;
            if (l2 != nullptr) {
                l1->val += l2->val;
            }
            reminder = l1->val > 9;
            l1->val -= reminder ? 10 : 0;
            if (l1->next == nullptr && ((l2 != nullptr && l2->next != nullptr) || reminder)) {
                l1->next = new ListNode();
            }
            return addTwoNumbers(l1->next, l2 != nullptr ? l2->next : l2, reminder, root);
        } else {
            return root;
        }
    }
};