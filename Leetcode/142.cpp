/*
检测环形链表，若有环则返回入环的第一个节点
*/

#include <iostream>
#include <unordered_set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) { //哈希表法来做
        unordered_set<ListNode *> vis;
        while(head != NULL) {
            if(vis.count(head))
                return head;
            vis.insert(head);
            head = head->next;
        }
        return NULL;
    }
};

int main() {
    Solution s;
    int val = 2;
    ListNode *p1 = new ListNode(3);
    ListNode *p2 = new ListNode(2);
    ListNode *p3 = new ListNode(0);
    ListNode *p4 = new ListNode(-4);

    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    bool ans = s.detectCycle(p1);

    system("pause");
    return 0;
}    