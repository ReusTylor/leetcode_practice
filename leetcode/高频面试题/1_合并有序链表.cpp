//
// Created by Reus on 2023/8/12.
//
/*
 * 合并两个有序链表
 * 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
 *
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
 */

#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr){}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* cur1 = l1;
        ListNode* cur2 = l2;
        ListNode* l3 = new ListNode(-1);
        ListNode* cur3 = l3;
        while(cur1 != nullptr && cur2 != nullptr){
            if(cur1->val > cur2->val){
                cur3->next = cur2;
                cur2 = cur2->next;
            }else{
                cur3->next = cur1;
                cur1 = cur1->next;
            }
            cur3 = cur3->next;
        }
        if(cur1 != nullptr){
            cur3->next = cur1;
        }
        if(cur2 != nullptr){
            cur3->next = cur2;
        }
        return l3->next;
    }
};

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(4);
    ListNode* l5 = new ListNode(5);
    ListNode* l6 = new ListNode(6);
    l4->next = l5;
    l5->next = l6;

    Solution s;
    ListNode* res = s.mergeTwoLists(l1, l4);
    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}