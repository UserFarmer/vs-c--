/*
输入一个链表，输出该链表中倒数第k个节点。
本题从1开始计数，即链表的尾节点是倒数第1个节点。

例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。
这个链表的倒数第 3 个节点是值为 4 的节点。
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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        ListNode *pre = head;
        ListNode *post = head;

        for (int i = 0; i < k; i++) {
            post = post->next;
        }

        while (post)
        {
            post = post->next;
            pre = pre->next;
        }
        return pre;
    }
};

int main() {
    Solution s;
    int val = 2;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;

    ListNode *head = s.getKthFromEnd(p1, val);
        
    cout << head->val << ' ';

    system("pause");
    return 0;
}