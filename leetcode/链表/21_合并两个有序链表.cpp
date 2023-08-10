//
// Created by guessever on 23-7-31.
//
/*
  将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 */
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode():val(0), next(nullptr){}
  ListNode(int x): val(x), next(nullptr){}
  ListNode(int x, ListNode* next): val(x), next(next){}
};

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* cur1 = list1;
    ListNode* cur2 = list2;
    ListNode* head1 = new ListNode(-1);
    ListNode* head = head1;


    while(cur1 != nullptr && cur2 != nullptr){
      if(cur1->val >= cur2->val){
        head->next = cur2;
        cur2 = cur2->next;
      }else{
        head->next = cur1;
        cur1 = cur1->next;
      }
      head = head->next;
    }
    if(cur1 != nullptr){
      head->next = cur1;
    }
    if(cur2 != nullptr){
      head->next = cur2;
    }
    return head1->next;
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