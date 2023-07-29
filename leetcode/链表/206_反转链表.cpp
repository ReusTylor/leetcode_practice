/*
    给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。 
*/
#include<iostream>
#include<vector>
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
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur != nullptr){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = new ListNode();
    ListNode* cur = head;
    for(int i = 0; i < nums.size(); i++){
        ListNode* node = new ListNode(nums[i]);
        cur->next = node;
        cur = cur->next;
    }
    Solution s;
    ListNode* res = s.reverseList(head);
    while(res != nullptr){
        cout << res->val << " ";
        res = res->next;
    }
    return 0;
}
