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

ListNode *rotateRight(ListNode *head, int k) {
    if (!head || !head->next)
        return head;

    int count = 0;
    ListNode *end = head;

    while (end->next) {
        count++;
        end = end->next;
    }
    count++;

    k = k % count;

    if (k == 0)
        return head;

    int new_end_index = count - k;

    ListNode *new_end = head;

    for (int i = 0; i < new_end_index - 1; i++) {
        new_end = new_end->next;
    }

    ListNode *start = new_end->next;

    new_end->next = nullptr;
    end->next = head;

    return start;
}

void test() {
}