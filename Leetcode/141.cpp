/*
检测环形链表
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
    bool hasCycle(ListNode *head) {
        if(!head||!head->next)
            return false;
        ListNode *fast = head->next;
        ListNode *slow = head;
        while (fast != slow)
        {
            if(!fast||!fast->next)
                return false;
            fast = fast->next->next;
            slow = slow->next;
        }
        return true;
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

    bool ans = s.hasCycle(p1);
    cout << boolalpha << ans << endl;

    system("pause");
    return 0;
}    