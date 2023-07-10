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

int main(){
    ListNode* l1 = new ListNode(1);
    ListNode* l2 = new ListNode(2);
    ListNode* l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;

    Solution s;
    ListNode* res = s.ReverseList(l1);
    while(res != nullptr){
        cout << res->val << endl;
        res = res->next;
    }
    return 0;
}