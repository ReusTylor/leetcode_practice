class Solution1 {
 public:
  ListNode* midList(ListNode* node){
    ListNode* slow = node;
    ListNode* fast = node;

    while(fast != nullptr || fast->next != nullptr){
      slow = slow->next;
      fast = fast->next->next;
    }
    return slow;
  }

  void reverseList(){

  }



  ListNode* addList(){

  }
  void reorderList(ListNode* head) {
    ListNode* mid = midList(head);
  }
};

int main(){
  
}