#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                tail->next = l1;
                l1 = l1->next;
            } else {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1 ? l1 : l2;

        return dummy.next;
    }
};

// Utility function to print the linked list
void printList(ListNode* head) {
    while (head) {
        std::cout << head->val;
        if (head->next) std::cout << " -> ";
        head = head->next;
    }
    std::cout << std::endl;
}

int main() {
    Solution sol;

    // Creating List A: 5 -> 10
    ListNode* listA = new ListNode(5);
    listA->next = new ListNode(10);

    // Creating List B: 7 -> 12
    ListNode* listB = new ListNode(7);
    listB->next = new ListNode(12);

    std::cout << "List A: ";
    printList(listA);

    std::cout << "List B: ";
    printList(listB);

    // Merging lists A and B
    ListNode* mergedList = sol.mergeTwoLists(listA, listB);

    std::cout << "Merged List: ";
    printList(mergedList);

    return 0;
}

