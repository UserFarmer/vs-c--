/*
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。

输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *head = new ListNode(0);
        ListNode *cur = head;
        while(l1 && l2) {
            if(l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = l1 == NULL ? l2 : l1;
        return head->next;
    }
};

int main() {
    Solution s;
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(4);
    ListNode *t1 = new ListNode(1);
    ListNode *t2 = new ListNode(3);
    ListNode *t3 = new ListNode(4);

    l1->next = l2;
    l2->next = l3;
    t1->next = t2;
    t2->next = t3;

    ListNode *ans = s.mergeTwoLists(l1, t1);

    while(ans) {
        cout << ans->val << ' ';
        ans = ans->next;
    }

    system("pause");
    return 0;
}