/*
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。
它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。

思路：
 与从左往右进位不同，这里是从右往左进位，对于链表来说相当于逆序的相加
 对于逆序的操作，首先想到的是栈。
*/
#include<iostream>
#include<stack>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1;
        stack<int> s2;
        // 放在栈中
        for(ListNode* p = l1; p != nullptr; p = p->next){
            s1.push(p->val);
        }
        for(ListNode* p = l2; p != nullptr; p = p->next){
            s2.push(p->val);
        }

        ListNode* dummyHead = new ListNode(-1);
        ListNode* cur = dummyHead;
        int carry = 0;
        // 如果s1,s2都为空，carry不为0,说明还应该向前进位，继续做一步循环。
        while(!s1.empty() || !s2.empty() || carry){
            if(!s1.empty()) {
                carry += s1.top();
                s1.pop();
            }

            if(!s2.empty()){
                carry += s2.top();
                s2.pop();
            } 
            
            ListNode* node = new ListNode(carry % 10);
            node->next = cur->next;
            cur->next = node;

            carry = carry / 10;
        }
        return dummyHead->next;
    }
};