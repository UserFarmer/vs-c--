/*
定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

输入: 1->2->3->4->5->NULL
输出: 5->4->3->2->1->NULL
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
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = NULL;
        ListNode *post = head;
        while(post) {
            ListNode *tmp = post->next;
            post->next = cur;
            cur = post;
            post = tmp;
        }
        return cur;
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

    ListNode *head = s.reverseList(p1);
        
    cout << head->val << ' ';

    system("pause");
    return 0;
}