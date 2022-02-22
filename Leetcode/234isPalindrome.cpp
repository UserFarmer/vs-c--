/*
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。
如果是，返回 true ；否则，返回 false 。
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
    bool isPalindrome(ListNode* head) {
        if(!head)
            return true;
        ListNode *halfhead;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        halfhead = slow->next; //找到后半部分节点的第一个
        halfhead = reverseList(halfhead); //反转后半部分

        ListNode *p1 = head;
        ListNode *p2 = halfhead;
        while(p1 && p2) { //比较两个链表的内容
            if(p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
    }

    ListNode *reverseList(ListNode* head) {
        ListNode *pre = NULL;
        ListNode *cur = head;
        while(cur) {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

int main() {
    Solution s;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(3);
    ListNode *p5 = new ListNode(2);
    ListNode *p6 = new ListNode(1);
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;

    bool ans = s.isPalindrome(p1);
    cout << boolalpha << ans << endl;

    system("pause");
    return 0;
}