#include<iostream>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};


class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @return ListNode类
     */
    ListNode* ReverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* p1 = head->next;

        while(p1 != nullptr){
            ListNode* tmp = p1->next;
            p1->next = cur;
            cur->next = nullptr;
            cur = p1;
            p1 = tmp;
        }
        return p1;
    }
};

// 递归的逻辑和双指针的逻辑是类似的
/*
 * 递归三部曲
 *  1. 递归函数和参数
 *  2. 返回条件
 *  3. 单层的递归逻辑
 */
class Solution2{
 public:
  ListNode* reverse1(ListNode* pre, ListNode* cur){
    if(cur == nullptr) return pre;
    ListNode* tmp = cur->next;
    cur->next = pre;
    return reverse1(cur, tmp);

  }
  ListNode* ReverseList(ListNode* head){
    return reverse1(nullptr, head);
  }
};

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;

    Solution2 s;
    ListNode* res = s.ReverseList(l1);
    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}