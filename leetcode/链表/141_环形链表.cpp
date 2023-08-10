//
// Created by guessever on 23-7-29.
//

#include <iostream>
#include <unordered_set>
using namespace std;
struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr){}
};
class Solution {
 public:
  bool hasCycle(ListNode *head) {
    ListNode* slow = head;
    ListNode* fast = head;
    fast = fast->next;
    while(fast != slow){
      if(fast == nullptr || fast->next == nullptr)
          return false;
      slow = slow->next;
      fast = fast->next->next;
    }
    return true;
  }
};
// 哈希
class Solution1 {
 public:
  bool hasCycle(ListNode *head) {
    unordered_set<ListNode*> seen;
    while(head != nullptr){
      if(seen.count(head)){
        return true;
      }
      seen.insert(head);
      head = head->next;
    }
    return false;
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
  node4->next = node2;
  Solution s;
  cout << s.hasCycle(head) << endl;
  return 0;
}