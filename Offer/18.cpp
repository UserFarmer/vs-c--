/*
给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
返回删除后的链表的头节点。
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
    ListNode* deleteNode(ListNode* head, int val) {
        if(head == NULL)
            return NULL;
        if(head->val == val) {
            head = head->next;
        }
        ListNode *pre = head;
        ListNode *cur = head->next;
        while(cur) {
            if(cur->val == val)
                pre->next = cur->next;
            pre = pre->next;
            cur = cur->next;
        }
        return head;
    }
};


int main() {
    Solution s;
    int val = 5;
    ListNode *p1 = new ListNode(4);
    ListNode *p2 = new ListNode(5);
    ListNode *p3 = new ListNode(1);
    ListNode *p4 = new ListNode(9);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    ListNode *head = s.deleteNode(p1, 5);
    while(head!=NULL) {
        cout << head->val << ' ';
        head = head->next;
    }

    system("pause");
    return 0;
}