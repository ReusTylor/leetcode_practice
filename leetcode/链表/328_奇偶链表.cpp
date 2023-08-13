//
// Created by Reus on 2023/8/13.
//
/*
 * 奇偶链表：
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    struct ListNode *next;
    explicit ListNode(int x) : val(x), next(nullptr) {}
};

class Solution{
public:
    ListNode* oddEvenList(ListNode* head){
        if(head == nullptr) return head;
        ListNode* evenHead = head->next;
        ListNode* odd = head;
        ListNode* even = evenHead;
        while(even != nullptr && even->next != nullptr){
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

void printList(ListNode* head) {
    while (head != nullptr) {
        std::cout << head->val << " -> ";
        head = head->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    // Create a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original Linked List: ";
    printList(head);

    Solution solution;
    ListNode* newHead = solution.oddEvenList(head);

    cout << "Odd-Even Linked List: ";
    printList(newHead);

    return 0;
}