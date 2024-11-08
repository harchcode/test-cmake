#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x) {
    if (!head || !head->next)
        return head;

    ListNode *p1 = nullptr;
    ListNode *p2 = nullptr;
    ListNode *cur = head;
    ListNode *r1 = nullptr;
    ListNode *r2 = nullptr;

    while (cur) {
        if (cur->val < x) {
            if (!p1) {
                p1 = cur;
                r1 = p1;
            } else {
                p1->next = cur;
                p1 = p1->next;
            }
        } else {
            if (!p2) {
                p2 = cur;
                r2 = p2;
            } else {
                p2->next = cur;
                p2 = p2->next;
            }
        }

        cur = cur->next;
    }

    if (!p1) {
        return r2;
    } else if (!p2) {
        return r1;
    }

    p1->next = r2;
    p2->next = nullptr;

    return r1;
}

void test() {
}