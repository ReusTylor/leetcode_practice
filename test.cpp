/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。


注意：
因为是逆序排列的，所以相当于从左往右进位
*/
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2){
        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        int carry = 0;
        while(l1 || l2 || carry){
            if(l1 != nullptr) carry += l1->val;
            if(l2 != nullptr) carry += l2->val;


            ListNode* temp = new ListNode();
            temp->val = carry % 10;
            cur->next = temp;
            cur = cur->next;

            carry = carry / 10;
            if(l1 != nullptr) l1 = l1->next;
            if(l2 != nullptr) l2 = l2->next;
        }
        return dummyHead->next;
    }

};



int main(){
    ListNode* l1 = new ListNode(2);
    ListNode* l2 = new ListNode(4);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;

    ListNode* l4 = new ListNode(5);
    ListNode* l5 = new ListNode(6);
    ListNode* l6 = new ListNode(4);
    l4->next = l5;
    l5->next = l6;

    Solution s;
    ListNode* res = s.addTwoNumbers(l1, l4);
    while(res){
        cout << res->val << " ";
        res = res->next;
    }
    cout << endl;
    return 0;
}