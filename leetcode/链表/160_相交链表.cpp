//
// Created by guessever on 23-8-2.
//


/*

 给你两个单链表的头节点 headA 和 headB ，
 请你找出并返回两个单链表相交的起始节点。
 如果两个链表不存在相交节点，返回 null 。
*/
#include <iostream>
using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode():val(0), next(nullptr){};
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int lengthA = 0;
    int lengthB = 0;
    int n = 0;
    ListNode* curLong = headA;
    ListNode* curShort = headB;
    while(curLong != nullptr){
      lengthA++;
      curLong = curLong->next;
    }
    while(curShort != nullptr){
      lengthB++;
      curShort = curShort->next;
    }
    if(lengthA > lengthB){
      curLong = headA;
      curShort = headB;
      n = lengthA - lengthB;
    }else{
      curLong = headB;
      curShort = headA;
      n = lengthB - lengthA;
    }

    while(n--){
      curLong = curLong->next;
    }
    while(curLong != nullptr){
      if(curLong == curShort){
        return curLong;
      }
      curShort = curShort->next;
      curLong = curLong->next;
    }
    return nullptr;
  }
};
int main(){
  ListNode* headA = new ListNode();
  ListNode* headB = new ListNode();
  Solution s;
  ListNode* result = s.getIntersectionNode(headA, headB);
  cout << result << endl;
  return 0;
}

