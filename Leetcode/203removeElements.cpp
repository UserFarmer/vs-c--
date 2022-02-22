/*
给你一个链表的头节点 head 和一个整数 val ，
请你删除链表中所有满足 Node.val == val 的节点，并返回 新的头节点 。
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
    ListNode* removeElements(ListNode* head, int val) {
        if(!head)
            return NULL;
        ListNode *dum = new ListNode(0, head);
        ListNode *cur = head;
        ListNode *pre = dum;
        while(cur) {
            if(cur->val == val) {
                pre->next = cur->next;
                cur = cur->next;
            }
            else {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dum->next;
    }
};

int main() {
    Solution s;
    int val = 6;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(6);
    ListNode *p4 = new ListNode(3);
    ListNode *p5 = new ListNode(4);
    ListNode *p6 = new ListNode(5);
    ListNode *p7 = new ListNode(6);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;

    ListNode *ans = s.removeElements(p1, val);
    if(!ans)
        cout << "NULL" << endl;
    while (ans)
    {
        cout << ans->val << endl;
        ans = ans->next;
    }

    system("pause");
    return 0;
}