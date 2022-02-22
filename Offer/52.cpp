/*
输入两个链表，找出它们的第一个公共节点。
*/

#include <iostream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode *curA = headA;
         ListNode *curB = headB;
         while(curA != curB) {
              curA = curA ? curA->next : headB;
              curB = curB ? curB->next : headA;
              //注意此处的指针交换
         }
         return curA;
    }
};

int main() {
     Solution s;
     ListNode *a1 = new ListNode(4);
     ListNode *a2 = new ListNode(1);
     ListNode *b1 = new ListNode(5);
     ListNode *b2 = new ListNode(0);
     ListNode *b3 = new ListNode(1);
     ListNode *c1 = new ListNode(8);
     ListNode *c2 = new ListNode(4);
     ListNode *c3 = new ListNode(5);

     a1->next = a2;
     a2->next = c1;
     b1->next = b2;
     b2->next = b3;
     b3->next = c1;
     c1->next = c2;
     c2->next = c3;

     ListNode *ans = s.getIntersectionNode(a1, b1);
     cout << ans->val << endl;

     system("pause");
     return 0;
}