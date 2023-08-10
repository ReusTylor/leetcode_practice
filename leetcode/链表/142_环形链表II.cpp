//
// Created by guessever on 23-8-4.
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
  ListNode *detectCycle(ListNode *head) {
    ListNode* fast = head;
    ListNode* slow = head;

    while(fast != nullptr && fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast){
        ListNode* index1 = fast;
        ListNode* index2 = head;
        while(index1 != index2){
          index1 = index1->next;
          index2 = index2->next;
        }
        return index1;
      }
    }
    return nullptr;
  }
};


int