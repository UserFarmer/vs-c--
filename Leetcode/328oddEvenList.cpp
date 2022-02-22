/*
给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。
请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)
            return head; //空链表
        ListNode *evenhead = head->next;
        ListNode *odd = head;
        ListNode *even = evenhead;
        while (even && even->next) { //当even移动到链表尾
        //隔一个位置移动
            odd->next = even->next;
            even->next = even->next->next;
            odd = odd->next;
            even = even->next;
        }
        odd->next = evenhead; //拼接两个链表
        return head;
    }
};

int main() {
    Solution s;
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(3);
    ListNode *p4 = new ListNode(4);
    ListNode *p5 = new ListNode(5);
    ListNode *p6 = new ListNode(6);
    ListNode *p7 = new ListNode(7);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    p4->next = p5;
    p5->next = p6;
    p6->next = p7;

    ListNode *ans = s.oddEvenList(p1);
    if(!ans)
        cout << "NULL" << endl;
    while(ans) {
        cout << ans->val << endl;
        ans = ans->next;
    }

    system("pause");
    return 0;
}