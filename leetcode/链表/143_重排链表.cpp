//
// Created by guessever on 23-7-31.
//
/*
  给定一个单链表 L 的头节点 head ，单链表 L 表示为：
  L0 → L1 → … → Ln - 1 → Ln
  请将其重新排列后变为：
  L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 */


#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
  int val;
  ListNode* next;
  ListNode():val(0), next(nullptr){}
  ListNode(int x): val(x), next(nullptr){}
  ListNode(int x, ListNode* next): val(x), next(next){}
};

/*
 * 链表不支持下标访问，所以考虑线性表。
 * 利用线性表存储该链表，然后利用可以线性访问的特点进行顺序访问，然后重建
 */
class Solution {
 public:
  void reorderList(ListNode* head) {
    if(head == nullptr) return;
    vector<ListNode*> vec;
    ListNode* cur = head;
    while(cur != nullptr){
      vec.emplace_back(cur);
      cur = cur->next;
    }

    int i = 0;
    int j = vec.size() - 1;
    while (i < j){
      vec[i]->next = vec[j];
      i++;
      if(i == j){
        break;
      }
      vec[j]->next = vec[i];
      j--;
    }
    vec[i]->next == nullptr;
  }
};

/*
 * 找链表中点 + 逆序右边的部分 + 链表合并
 */
class Solution1 {
 public:
  ListNode* midList(ListNode* node){
    ListNode* slow = node;
    ListNode* fast = node;

    while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  ListNode* reverseList(ListNode* node){
    ListNode* pre = nullptr;
    ListNode* cur = node;
    while(cur != nullptr){
      ListNode* temp = cur->next;
      cur->next = pre;
      pre = cur;
      cur = temp;
    }
    return pre;
  }


  void addList(ListNode* head1, ListNode* head2) {
    ListNode *cur1 = head1;
    ListNode *cur2 = head2;
    while (cur1 != nullptr && cur2 != nullptr) {
      cur1 = head1->next;
      cur2 = head2->next;

      head1->next = head2;
      head1 = cur1;

      head2->next = head1;
      head2 = cur2;
    }

  }
  void reorderList(ListNode* head) {
    if(head == nullptr){
      return;
    }
    ListNode* mid = midList(head);
    ListNode* l1 = head;
    ListNode* l2 = mid->next;
    mid->next = nullptr;
    l2 = reverseList(l2);
    addList(l1, l2);
  }
};


int main(){
  ListNode* head = new ListNode(1);
  ListNode* node1 = new ListNode(2);
  ListNode* node2 = new ListNode(3);
  ListNode* node3 = new ListNode(4);
  ListNode* node4 = new ListNode(5);
  head->next = node1;
  node1->next = node2;
  node2->next = node3;
  node3->next = node4;
  Solution1 s;
  s.reorderList(head);
  while(head != nullptr){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  return 0;
}


