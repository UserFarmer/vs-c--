/*
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
*/

#include <iostream>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *dum = new ListNode(0, head);
    ListNode *post = head;
    ListNode *pre = dum;

    for (int i = 1; i <= n; i++) {
      post = post->next;
    }
    while (post) {
      pre = pre->next;
      post = post->next;
    }

    pre->next = pre->next->next;
    return dum->next;
  }
};

int main() {
  Solution s;
  ListNode *p5 = new ListNode(5);
  ListNode *p4 = new ListNode(4, p5);
  ListNode *p3 = new ListNode(3, p4);
  ListNode *p2 = new ListNode(2, p3);
  ListNode *p1 = new ListNode(1, p2);
  int n = 2;

  ListNode *ans = s.removeNthFromEnd(p1, n);

  while (ans) {
    cout << ans->val << endl;
    ans = ans->next;
  }

  system("pause");
  return 0;
}